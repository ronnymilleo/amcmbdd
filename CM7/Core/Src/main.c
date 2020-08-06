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
#include "main.h"
#include "rng.h"
#include "tim.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "arm_math.h"
#include "arm_common_tables.h"
#include "arm_const_structs.h"
#include "arm_nnsupportfunctions.h"
#include "arm_nn_tables.h"
#include "arm_nnfunctions.h"
#include "functions.h"

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void reset_buffer(char buffer[]){
	for(uint32_t i = 1; i < 30; i++){
		buffer[i] = '\0';
	}
}
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
	float32_t signal_array[2048] = {0};
	float32_t mean_value = 0.0f, mean_of_squared_value = 0.0f, std_dev_value = 0.0f, max = 0.0f;
	float32_t moment = 0.0f, var = 0.0f;
	float32_t * result;
	uint32_t power = 2;
	uint32_t random32bit, counter, length=2048, max_index;
	char rand32[30] = {'\0'};
	char hello_world[17] = {"\n\nHello World!\n\r"};
	char size_of_signal_array[30] = {'\0'};
	char counter_str[30] = {'\0'};
	char buffer_0[30] = {'\0'};
	char buffer_1[30] = {'\0'};
	char buffer_2[30] = {'\0'};
	char buffer_3[30] = {'\0'};
	char buffer_4[30] = {'\0'};
	char buffer_5[30] = {'\0'};
	char receiveBuffer[9] = {'\0'};
  /* USER CODE END 1 */
  /* USER CODE BEGIN Boot_Mode_Sequence_0 */
    int32_t timeout; 
  /* USER CODE END Boot_Mode_Sequence_0 */

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
  MX_USB_OTG_FS_PCD_Init();
  MX_RNG_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  // Send Hello World via UART3
  if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
	  HAL_UART_Transmit(&huart3, (uint8_t*) &hello_world[0], sizeof(hello_world), 100);
  }

  // Initialization of signal array using random numbers
  __HAL_RNG_ENABLE(&hrng);

  for (int i = 0; i < length; i++){
  	HAL_RNG_GenerateRandomNumber(&hrng, &random32bit);
  	signal_array[i] = (float) random32bit / UINT32_MAX; // Generates numbers between 0 and 1
  }

  // HRTimer enable
  __HAL_TIM_ENABLE(&htim2);
  __HAL_TIM_UIFREMAP_DISABLE(&htim2);
  HAL_TIM_Base_Start(&htim2);
  __HAL_TIM_SET_COUNTER(&htim2, 0x0U);

  if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
	  HAL_UART_Receive(&huart3, (uint8_t*) &receiveBuffer[0], 8, 20);
  }

	// Array size
	sprintf(size_of_signal_array, "Size of signal array = %ld \n\r", length);
		if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &size_of_signal_array[0], sizeof(size_of_signal_array), 20);
		while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX){}
	}
	// Random number examples
	sprintf(rand32, "Random = %f \n\r", signal_array[0]);
		if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &rand32[0], sizeof(rand32), 20);
	}
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	sprintf(&counter_str[0], "Test counter = %ld \n\r", counter);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &counter_str[0], sizeof(counter_str), 20);
	}
	reset_buffer(counter_str);

	// Instantaneous absolute value
	result = (float32_t *) malloc(length * sizeof(float32_t));
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	inst_absolute(signal_array, result, &length);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	sprintf(&counter_str[0], "Inst abs counter = %ld \n\r", counter);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &counter_str[0], sizeof(counter_str), 20);
	}
	free(result);
	reset_buffer(counter_str);

	// Mean
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	mean(signal_array, &mean_value, &length);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	sprintf(&buffer_0[0], "Mean = %f \n\r", mean_value);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &buffer_0[0], sizeof(buffer_0), 20);
	}
	sprintf(&counter_str[0], "Counter = %ld \n\r", counter);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &counter_str[0], sizeof(counter_str), 20);
	}
	reset_buffer(counter_str);

	// Mean of squared
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	mean_of_squared(signal_array, &mean_of_squared_value, &length);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	sprintf(&buffer_1[0], "Mean of squared = %f \n\r", mean_of_squared_value);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &buffer_1[0], sizeof(buffer_1), 20);
	}
	sprintf(&counter_str[0], "Counter = %ld \n\r", counter);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &counter_str[0], sizeof(counter_str), 20);
	}
	reset_buffer(counter_str);

	// Standard deviation
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	std_dev(signal_array, &std_dev_value, &length);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	sprintf(&buffer_2[0], "Std dev = %f \n\r", std_dev_value);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &buffer_2[0], sizeof(buffer_2), 20);
	}
	sprintf(&counter_str[0], "Counter = %ld \n\r", counter);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &counter_str[0], sizeof(counter_str), 20);
	}
	reset_buffer(counter_str);

	// GMAX
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	gmax(signal_array, &length, &max, &max_index);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	sprintf(&buffer_3[0], "Gmax = %f \n\r", max);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &buffer_3[0], sizeof(buffer_3), 20);
	}
	sprintf(&counter_str[0], "Counter = %ld \n\r", counter);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &counter_str[0], sizeof(counter_str), 20);
	}
	reset_buffer(counter_str);

	// Variance
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	variance(signal_array, &var, &length);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	sprintf(&buffer_4[0], "Variance = %f \n\r", var);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &buffer_4[0], sizeof(buffer_4), 20);
	}
	sprintf(&counter_str[0], "Counter = %ld \n\r", counter);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &counter_str[0], sizeof(counter_str), 20);
	}
	reset_buffer(counter_str);

	// Central moment
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
	central_moment(signal_array, &length, &power, &moment);
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	sprintf(&buffer_5[0], "Central moment = %f \n\r", moment);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &buffer_5[0], sizeof(buffer_5), 20);
	}
	sprintf(&counter_str[0], "Counter = %ld \n\r", counter);
	if(HAL_UART_GetState(&huart3) == HAL_UART_STATE_READY){
		HAL_UART_Transmit(&huart3, (uint8_t*) &counter_str[0], sizeof(counter_str), 20);
	}
	reset_buffer(counter_str);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage 
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_HSI
                              |RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 96;
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
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_RNG
                              |RCC_PERIPHCLK_USB;
  PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_HSI;
  PeriphClkInitStruct.RngClockSelection = RCC_RNGCLKSOURCE_HSI48;
  PeriphClkInitStruct.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable USB Voltage detector 
  */
  HAL_PWREx_EnableUSBVoltageDetector();
}

/* USER CODE BEGIN 4 */

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
