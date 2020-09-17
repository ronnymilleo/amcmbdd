/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include <functions.hpp>
#include <main.hpp>
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "arm_math.h"
#include "arm_common_tables.h"
#include "arm_const_structs.h"
#include "arm_nnsupportfunctions.h"
#include "arm_nn_tables.h"
#include "arm_nnfunctions.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"
#include "tensorflow/lite/micro/examples/hello_world/model.h"
#include "tensorflow/lite/micro/testing/micro_test.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define HSEM_ID_0 (0U) /* HW semaphore 0*/
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
// Read-only variables go to FLASH memory
const uint16_t frameSize = 1024;
const uint16_t bufferSize = 8192;
const uint8_t txHead[4] = {0xCA, 0xCA, 0xCA, 0xCA};
const uint8_t txTail[4] = {0xF0, 0xF0, 0xF0, 0xF0};

// Variables go to FLASH memory
union inst
{
	float32_t number[1024];
	uint8_t bytes[4096];
} instAbs, instPhase, instAbsPhase, instUnwrappedPhase, instFreq, instAbsFreq, instCNAbs;
union rxData
{
	float32_t number[2048];
	uint8_t bytes[8192];
} rxBuffer;
uint8_t received = 0;
uint8_t processed = 0;
char txStringBuffer[50] = {'\0'};
__IO ITStatus UartReady = RESET;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void clear_leds();
void light_leds();
void blink_red_fast();
void blink_red_slow();
void blink_orange_fast();
void blink_orange_slow();
void blink_green_fast();
void blink_green();
void blink_green_slow();
void reset_buffer(char *stringBuffer);
void resetDataBuffer(uint8_t *dataBuffer);
void echoReceived(float *processedBuffer, char *transmitBuffer);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */
	// char hello_world[50] = {"\r\nHello World!\r\n"};
	uint32_t counter = 0;
	float32_t mean_of_squared_value = 0.0f, std_dev_value = 0.0f;
	// float32_t moment = 0.0f, var = 0.0f;
	// uint32_t power = 2, max_index;
	/* USER CODE END 1 */

	/* USER CODE BEGIN Boot_Mode_Sequence_0 */
	int32_t timeout;
	/* USER CODE END Boot_Mode_Sequence_0 */

	/* Enable I-Cache---------------------------------------------------------*/
	SCB_EnableICache();

	/* Enable D-Cache---------------------------------------------------------*/
	SCB_EnableDCache();

	/* USER CODE BEGIN Boot_Mode_Sequence_1 */
	/* Wait until CPU2 boots and enters in stop mode or timeout*/
	timeout = 0xFFFF;
	while((__HAL_RCC_GET_FLAG(RCC_FLAG_D2CKRDY) != RESET) && (timeout-- > 0));
	if ( timeout < 0 )
	{
		Error_Handler();
	}
	/* USER CODE END Boot_Mode_Sequence_1 */
	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();
	/* USER CODE BEGIN Boot_Mode_Sequence_2 */
	/* When system initialization is finished, Cortex-M7 will release Cortex-M4 by means of
HSEM notification */
	/*HW semaphore Clock enable*/
	__HAL_RCC_HSEM_CLK_ENABLE();
	/*Take HSEM */
	HAL_HSEM_FastTake(HSEM_ID_0);
	/*Release HSEM in order to notify the CPU2(CM4)*/
	HAL_HSEM_Release(HSEM_ID_0,0);
	/* wait until CPU2 wakes up from stop mode */
	timeout = 0xFFFF;
	while((__HAL_RCC_GET_FLAG(RCC_FLAG_D2CKRDY) == RESET) && (timeout-- > 0));
	if ( timeout < 0 )
	{
		Error_Handler();
	}
	/* USER CODE END Boot_Mode_Sequence_2 */

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_USART3_UART_Init();
	MX_TIM2_Init();
	/* USER CODE BEGIN 2 */
	// Put UART peripheral in reception process
	if(HAL_UART_Receive_IT(&huart3, &rxBuffer.bytes[0], bufferSize) != HAL_OK)
	{
		Error_Handler();
	}
	// Wait for message
	while (UartReady != SET)
	{
		HAL_Delay(500);
		blink_green();
		blink_green();
	}
	UartReady = RESET;
	HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);

	if(rxBuffer.bytes[8191] != 0 && (processed == 0)){
		HAL_GPIO_WritePin(GPIOE, LD2_Pin, GPIO_PIN_SET);
	}

	// HRTimer enable
	__HAL_TIM_ENABLE(&htim2);
	__HAL_TIM_UIFREMAP_DISABLE(&htim2);
	HAL_TIM_Base_Start(&htim2);
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);

	/*****************************************************************************************************/
	// Instantaneous absolute value
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_absolute(&rxBuffer.number[0], &instAbs.number[0]);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Inst abs counter = %ld\r\n&", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	HAL_Delay(1000);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txHead[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &instAbs.bytes[0], 4096);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txTail[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}

	blink_orange_slow();
	blink_orange_slow();

	// Instantaneous phase value
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_phase(&rxBuffer.number[0], &instPhase.number[0]);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Inst phase counter = %ld\r\n&", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	HAL_Delay(1000);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txHead[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &instPhase.bytes[0], 4096);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txTail[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}

	blink_orange_slow();
	blink_orange_slow();

	// Instantaneous unwrapped phase value
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_phase(&rxBuffer.number[0], &instPhase.number[0]);
	unwrap(&instPhase.number[0], &instUnwrappedPhase.number[0]);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Inst unwrapped phase counter = %ld\r\n&", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	HAL_Delay(1000);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txHead[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &instUnwrappedPhase.bytes[0], 4096);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txTail[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}

	blink_orange_slow();
	blink_orange_slow();

	// Instantaneous frequency value
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_frequency(&rxBuffer.number[0], &instFreq.number[0]);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Inst freq counter = %ld\r\n&", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	HAL_Delay(1000);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txHead[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &instFreq.bytes[0], 4096);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txTail[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}

	blink_orange_slow();
	blink_orange_slow();

	// Instantaneous centered normalized absolute value
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_centralized_normalized_absolute(&rxBuffer.number[0], &instCNAbs.number[0]);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Inst CN abs counter = %ld\r\n&", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	HAL_Delay(1000);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txHead[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &instCNAbs.bytes[0], 4096);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txTail[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}

	/*****************************************************************************************************/
	// Mean of squared
	// Reset counter
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	// Processing
	mean_of_squared(&rxBuffer.number[0], &mean_of_squared_value);
	// Get counter
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Mean of squared = %f\r\n", mean_of_squared_value);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Cycles counter = %ld\r\n", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}

	// Standard deviation of the absolute instantaneous phase
	// Reset counter
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	// Processing
	// Absolute instantaneous phase
	inst_absolute(&instPhase.number[0], &instAbsPhase.number[0]);
	std_dev(&instAbsPhase.number[0], &std_dev_value);
	// Get counter
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Standard deviation = %f\r\n", std_dev_value);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Cycles counter = %ld\r\n", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}

	// Standard deviation of the instantaneous phase
	// Reset counter
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	// Processing
	std_dev(&instPhase.number[0], &std_dev_value);
	// Get counter
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Standard deviation = %f\r\n", std_dev_value);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Cycles counter = %ld\r\n", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}

	// Standard deviation of the absolute instantaneous frequency
	// Reset counter
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	// Processing
	inst_absolute(&instFreq.number[0], &instAbsFreq.number[0]);
	std_dev(&instAbsFreq.number[0], &std_dev_value);
	// Get counter
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Standard deviation = %f\r\n", std_dev_value);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Cycles counter = %ld\r\n", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}

	// Standard deviation of the instantaneous frequency
	// Reset counter
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	// Processing
	std_dev(&instFreq.number[0], &std_dev_value);
	// Get counter
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Standard deviation = %f\r\n", std_dev_value);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Cycles counter = %ld\r\n", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}

	// Standard deviation of the centralized normalized absolute amplitude
	// Reset counter
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	// Processing
	std_dev(&instCNAbs.number[0], &std_dev_value);
	// Get counter
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Standard deviation = %f\r\n", std_dev_value);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	// Transmission routine
	reset_buffer(&txStringBuffer[0]);
	sprintf(&txStringBuffer[0], "Cycles counter = %ld\r\n", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txStringBuffer[0], 50);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}


#ifdef GMAX
	// GMAX
	// Reset counter
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	// Processing
	gmax(processedBuffer, &length, &max, &max_index);
	// Get counter
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&transmitBuffer[0]);
	sprintf(&transmitBuffer[0], "Gmax = %f\r\n", max);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit(&huart3, (uint8_t*) &transmitBuffer[0], sizeof(transmitBuffer), 100);
	}
	// Transmission routine
	reset_buffer(&transmitBuffer[0]);
	sprintf(&transmitBuffer[0], "Cycles counter = %ld\r\n", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit(&huart3, (uint8_t*) &transmitBuffer[0], sizeof(transmitBuffer), 100);
	}
#endif
#ifdef MOMENT
	// Central moment
	// Reset counter
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	// Processing
	central_moment(processedBuffer, &length, &power, &moment);
	// Get counter
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	// Transmission routine
	reset_buffer(&transmitBuffer[0]);
	sprintf(&transmitBuffer[0], "Central moment = %f\r\n", moment);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &transmitBuffer[0], sizeof(transmitBuffer), 100);
	}
	// Transmission routine
	reset_buffer(&transmitBuffer[0]);
	sprintf(&transmitBuffer[0], "Cycles counter = %ld\r\n", counter);
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit(&huart3, (uint8_t*) &txStringBuffer[0], sizeof(txStringBuffer), 100);
	}
#endif
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	clear_leds();
	while (1)
	{
		blink_orange_slow();
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

	/** Supply configuration update enable
	 */
	HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);
	/** Configure the main internal regulator output voltage
	 */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 4;
	RCC_OscInitStruct.PLL.PLLN = 50;
	RCC_OscInitStruct.PLL.PLLP = 2;
	RCC_OscInitStruct.PLL.PLLQ = 2;
	RCC_OscInitStruct.PLL.PLLR = 2;
	RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
	RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
	RCC_OscInitStruct.PLL.PLLFRACN = 0;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
			|RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
	RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		Error_Handler();
	}
	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3;
	PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_HSI;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */
void clear_leds(){
	HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, LD2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
}
void light_leds(){
	HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE, LD2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
}
void blink_red_fast(){
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
	HAL_Delay(50);
}
void blink_red_slow(){
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
	HAL_Delay(500);
}
void blink_orange_fast(){
	HAL_GPIO_WritePin(GPIOE, LD2_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(GPIOE, LD2_Pin, GPIO_PIN_SET);
	HAL_Delay(50);
}
void blink_orange_slow(){
	HAL_GPIO_WritePin(GPIOE, LD2_Pin, GPIO_PIN_RESET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOE, LD2_Pin, GPIO_PIN_SET);
	HAL_Delay(500);
}
void blink_green_fast(){
	HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
	HAL_Delay(50);
}
void blink_green(){
	HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
	HAL_Delay(200);
}
void blink_green_slow(){
	HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
	HAL_Delay(500);
}
void reset_buffer(char *stringBuffer){
	for(uint16_t i = 1; i < 50; i++){
		stringBuffer[i] = '\0';
	}
}
void resetDataBuffer(uint8_t *dataBuffer){
	for(uint16_t i = 1; i < 8192; i++){
		dataBuffer[i] = 0;
	}
}
/*
void byte2float(uint8_t *rxDataBuffer, float *processedData){
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
	for(int i = 0; i < 2048; i = i + 4){
		memcpy(&processedData[i / 4], &rxDataBuffer[i], 4);
	}
	processed = 1;
	received = 1;
	// memcpy(&processedBuffer[0], &receiveBuffer[0], 4);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
}
void float2byte(uint8_t *txDataBuffer, float *processedData){
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
	for(int i = 0; i < 2048; i = i + 4){
		memcpy(&txDataBuffer[i], &processedData[i / 4], 4);
	}
	processed = 1;
	received = 1;
	// memcpy(&processedBuffer[0], &receiveBuffer[0], 4);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
}
 */
void echoReceived(float32_t *processedBuffer, char *transmitBuffer){
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
	for(int i = 0; i < 2048; i = i + 2){
		reset_buffer(&transmitBuffer[0]);
		sprintf(&transmitBuffer[0], "%d - (%.6f) + j(%.6f)\r\n", i, processedBuffer[i], processedBuffer[i+1]);
		if(UART_CheckIdleState(&huart3) == HAL_OK){
			if(HAL_UART_Transmit(&huart3, (uint8_t*) &transmitBuffer[0], 50, 100) == HAL_TIMEOUT){
				break;
			}
		}
	}
	reset_buffer(&transmitBuffer[0]);
	sprintf(&transmitBuffer[0], "&");
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit(&huart3, (uint8_t*) &transmitBuffer[0], 50, 100);
	}
	received = 0;
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart3){
	/* Set transmission flag: transfer complete */
	UartReady = SET;
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart3){
	/* Set transmission flag: transfer complete */
	UartReady = SET;
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
