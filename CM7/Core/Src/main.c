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
#include <functions.h>
#include <main.h>
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
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define HSEM_ID_0 (0U) /* HW semaphore 0*/
#define IMAGE_SIZE 28 * 28
#define FT_INPUT_VECTOR_SIZE 2048
#define RX_DATA_SIZE FT_INPUT_VECTOR_SIZE*2
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
// Read-only variables go to FLASH memory
const uint16_t frameSize = FT_INPUT_VECTOR_SIZE;
const uint8_t txHead[4] = {0xCA, 0xCA, 0xCA, 0xCA};
const uint8_t txTail[4] = {0xF0, 0xF0, 0xF0, 0xF0};

uint8_t inputPicture[IMAGE_SIZE];
float32_t f32_digitToClassify[IMAGE_SIZE];
q15_t q15_digitToClassify[IMAGE_SIZE];

// Variables go to FLASH memory
union inst
{
	float32_t number[FT_INPUT_VECTOR_SIZE];
	uint8_t bytes[FT_INPUT_VECTOR_SIZE*4];
} instAbs, instPhase, instAbsPhase, instUnwrappedPhase, instFreq, instAbsFreq = {0}, instCNAbs, instAbsCNAbs;
union rxData
{
	float32_t number[RX_DATA_SIZE];
	uint8_t bytes[RX_DATA_SIZE*4];
} rxBuffer;
uint8_t received = 0;
uint8_t processed = 0;
char txStringBuffer[100] = {'\0'};
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
void transmit_features(uint8_t *value, uint8_t *counter);
void transmit_array(uint8_t *array, uint16_t size, uint8_t *counter);
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
	union cycles_counter
	{
		uint32_t number;
		uint8_t bytes[4];
	} counter;

	union features
	{
		float32_t number;
		uint8_t bytes[4];
	} ft0, ft1, ft2, ft3, ft4, ft5, ft6, ft7,
	  ft8, ft9, ft10, ft11, ft12, ft13, ft14,
	  ft15, ft16, ft17, ft18, ft19, ft20, ft21;
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
	if(HAL_UART_Receive_IT(&huart3, &rxBuffer.bytes[0], RX_DATA_SIZE*4) != HAL_OK)
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
	complex_inst_absolute(&rxBuffer.number[0], &instAbs.number[0]);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_array(&instAbs.bytes[0], FT_INPUT_VECTOR_SIZE*4, &counter.bytes[0]);

	blink_orange_slow();
	blink_orange_slow();

	// Instantaneous phase value
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_phase(&rxBuffer.number[0], &instPhase.number[0]);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_array(&instPhase.bytes[0], FT_INPUT_VECTOR_SIZE*4, &counter.bytes[0]);

	blink_orange_slow();
	blink_orange_slow();

	// Instantaneous unwrapped phase value
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_phase(&rxBuffer.number[0], &instPhase.number[0]);
	unwrap(&instPhase.number[0], &instUnwrappedPhase.number[0]);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_array(&instUnwrappedPhase.bytes[0], FT_INPUT_VECTOR_SIZE*4, &counter.bytes[0]);

	blink_orange_slow();
	blink_orange_slow();

	// Instantaneous frequency value
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_frequency(&rxBuffer.number[0], &instFreq.number[0]);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_array(&instFreq.bytes[0], FT_INPUT_VECTOR_SIZE*4, &counter.bytes[0]);

	blink_orange_slow();
	blink_orange_slow();

	// Instantaneous centered normalized absolute value
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_centralized_normalized_absolute(&rxBuffer.number[0], &instCNAbs.number[0]);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_array(&instCNAbs.bytes[0], FT_INPUT_VECTOR_SIZE*4, &counter.bytes[0]);

	blink_orange_slow();
	blink_orange_slow();

	/*****************************************************************************************************/
	// Standard deviation of the instantaneous phase
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	std_dev(&instPhase.number[0], &ft0.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft0.bytes[0], &counter.bytes[0]);

	// Standard deviation of the absolute instantaneous phase
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_absolute(&instPhase.number[0], &instAbsPhase.number[0]);
	std_dev(&instAbsPhase.number[0], &ft1.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft1.bytes[0], &counter.bytes[0]);

	// Standard deviation of the instantaneous frequency
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	std_dev(&instFreq.number[0], &ft2.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft2.bytes[0], &counter.bytes[0]);

	// Standard deviation of the absolute instantaneous frequency
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_absolute(&instFreq.number[0], &instAbsFreq.number[0]);
	std_dev(&instAbsFreq.number[0], &ft3.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft3.bytes[0], &counter.bytes[0]);

	// Standard deviation of the centralized normalized absolute amplitude
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	std_dev(&instCNAbs.number[0], &ft4.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft4.bytes[0], &counter.bytes[0]);

	// Standard deviation of the absolute centralized normalized absolute amplitude
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_absolute(&instCNAbs.number[0], &instAbsCNAbs.number[0]);
	std_dev(&instAbsCNAbs.number[0], &ft5.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft5.bytes[0], &counter.bytes[0]);

	// Mean Value of the Signal Magnitude
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	mean_of_signal_magnitude(&instAbs.number[0], &ft6.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft6.bytes[0], &counter.bytes[0]);

	// Squared Mean of the Signal Magnitude
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	squared_mean_of_signal_magnitude(&instAbs.number[0], &ft7.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft7.bytes[0], &counter.bytes[0]);

	// Normalized Sqrt Value of Sum of Amplitude
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	normalized_sqrt_of_sum_of_amp(&instAbs.number[0], &ft8.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft8.bytes[0], &counter.bytes[0]);

	// Ratio of I/Q Components
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	ratio_iq(&rxBuffer.number[0], &ft9.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft9.bytes[0], &counter.bytes[0]);

	// Gmax
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	gmax(&rxBuffer.number[0], &ft10.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft10.bytes[0], &counter.bytes[0]);

	// Kurtosis of the Absolute Amplitude
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	kurtosis_of_abs_amplitude(&instAbs.number[0], &ft11.number, frameSize);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft11.bytes[0], &counter.bytes[0]);

	// Kurtosis of the Absolute Frequency
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	kurtosis_of_abs_freq(&instAbsFreq.number[0], &ft12.number, frameSize - 1);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft12.bytes[0], &counter.bytes[0]);

	// Cumulant 20
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	cumulant_20(&rxBuffer.number[0], &ft13.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft13.bytes[0], &counter.bytes[0]);

	// Cumulant 21
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	cumulant_21(&rxBuffer.number[0], &ft14.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft14.bytes[0], &counter.bytes[0]);

	// Cumulant 40
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	cumulant_40(&rxBuffer.number[0], &ft15.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft15.bytes[0], &counter.bytes[0]);

	// Cumulant 41
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	cumulant_41(&rxBuffer.number[0], &ft16.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft16.bytes[0], &counter.bytes[0]);

	// Cumulant 42
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	cumulant_42(&rxBuffer.number[0], &ft17.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft17.bytes[0], &counter.bytes[0]);

	// Cumulant 60
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	cumulant_60(&rxBuffer.number[0], &ft18.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft18.bytes[0], &counter.bytes[0]);

	// Cumulant 61
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	cumulant_61(&rxBuffer.number[0], &ft19.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft19.bytes[0], &counter.bytes[0]);

	// Cumulant 62
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	cumulant_62(&rxBuffer.number[0], &ft20.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft20.bytes[0], &counter.bytes[0]);

	// Cumulant 63
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	cumulant_63(&rxBuffer.number[0], &ft21.number);
	counter.number = __HAL_TIM_GET_COUNTER(&htim2);
	transmit_features(&ft21.bytes[0], &counter.bytes[0]);

	/* USER CODE END 2 */
	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
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
void transmit_features(uint8_t *value, uint8_t *counter){
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txHead[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &value[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &counter[0], 4);
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
}
void transmit_array(uint8_t *array, uint16_t size, uint8_t *counter){
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txHead[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &array[0], size);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &counter[0], 4);
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
}
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
