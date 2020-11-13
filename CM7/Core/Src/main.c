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
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define HSEM_ID_0 (0U) /* HW semaphore 0*/
#define FT_INPUT_VECTOR_SIZE 2048
#define RX_DATA_SIZE FT_INPUT_VECTOR_SIZE*2
#define NUMBER_OF_FEATURES 6
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
// Read-only variables go to FLASH memory
const uint32_t frameSize = FT_INPUT_VECTOR_SIZE;
const uint8_t txHead[4] = {0xCA, 0xCA, 0xCA, 0xCA};
const uint8_t txTail[4] = {0xF0, 0xF0, 0xF0, 0xF0};
q15_t layer_1_out_Buf[L1_OUT_DIM] = {0};
q15_t layer_2_out_Buf[L2_OUT_DIM] = {0};
q15_t layer_3_out_Buf[L3_OUT_DIM] = {0};
q15_t layer_4_out_Buf[L4_OUT_DIM] = {0};
q15_t layer_5_out_Buf[L5_OUT_DIM] = {0};
q15_t output_data[L5_OUT_DIM] = {0};
q15_t aq15_layer_1_weights[L1_IN_DIM*L1_OUT_DIM] = {0};
q15_t aq15_layer_1_biases[L1_OUT_DIM] = {0};
q15_t aq15_layer_2_weights[L2_IN_DIM*L2_OUT_DIM] = {0};
q15_t aq15_layer_2_biases[L2_OUT_DIM] = {0};
q15_t aq15_layer_3_weights[L3_IN_DIM*L3_OUT_DIM] = {0};
q15_t aq15_layer_3_biases[L3_OUT_DIM] = {0};
q15_t aq15_layer_4_weights[L4_IN_DIM*L4_OUT_DIM] = {0};
q15_t aq15_layer_4_biases[L4_OUT_DIM] = {0};
q15_t aq15_layer_5_weights[L5_IN_DIM*L5_OUT_DIM] = {0};
q15_t aq15_layer_5_biases[L5_OUT_DIM] = {0};
// Variables go to FLASH memory
union inst
{
	float32_t number[FT_INPUT_VECTOR_SIZE];
	uint8_t bytes[FT_INPUT_VECTOR_SIZE*4];
} instAbs = {0}, instPhase = {0}, instAbsPhase = {0}, instUnwrappedPhase = {0}, instFreq = {0}, instAbsFreq = {0}, instCNAbs = {0}, instAbsCNAbs = {0};
union rxData
{
	float32_t number[RX_DATA_SIZE];
	uint8_t bytes[RX_DATA_SIZE*4];
} rxBuffer = {0};
union rxWeightsAndBiases
{
	int16_t number[WEIGHTS + BIASES];
	uint8_t bytes[(WEIGHTS + BIASES) * 2];
} rxWandB = {0};
union rxStandardizer
{
	float32_t number[NUMBER_OF_FEATURES * 2];
	uint8_t bytes[NUMBER_OF_FEATURES * 2 * 4];
} rxScaler = {0};
union array_of_counter_numbers
{
	uint32_t number[5 + NUMBER_OF_FEATURES + 1];
	uint8_t bytes[4*(5 + NUMBER_OF_FEATURES + 1)];
} counter_array = {0};
union array_of_features
{
	float32_t number[NUMBER_OF_FEATURES];
	uint8_t bytes[NUMBER_OF_FEATURES * 4];
} ft_array = {0}, scaled_ft_array = {0};
union single_float
{
	float32_t number;
	uint8_t bytes[4];
} predicted = {0}, min_range = {0}, max_range = {0};
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
void transmit_prediction(uint8_t *value, uint8_t *counter);
void transmit_features(uint8_t *value, uint8_t *counter);
void transmit_array(uint8_t *array, uint16_t size, uint8_t *counter);
void transmit_echo_wandb(uint8_t *array, uint16_t size);
void transmit_echo_data(uint8_t *array, uint16_t size);
void preprocess_features(float32_t in[], float32_t out[]);
void quantize_features(float32_t in[], float32_t min_float_range, float32_t max_float_range, q15_t out[]);
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
	/*****************************************************************************************************/
	q15_t q15_input_vector[NUMBER_OF_FEATURES] = {0};
	uint8_t ft_counter = 0;
	/*****************************************************************************************************/
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
	/*****************************************************************************************************/
	// HRTimer enable
	__HAL_TIM_ENABLE(&htim2);
	__HAL_TIM_UIFREMAP_DISABLE(&htim2);
	HAL_TIM_Base_Start(&htim2);
	__HAL_TIM_SET_COUNTER(&htim2, 0x0U);

	// Put UART peripheral in reception process
	if(HAL_UART_Receive_IT(&huart3, &rxWandB.bytes[0], (WEIGHTS + BIASES) * 2) != HAL_OK)
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
	if(rxWandB.bytes[(WEIGHTS + BIASES) * 2 - 1] != 0){ // Means: received everything
		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
	}
	// Echo
	transmit_echo_wandb(&rxWandB.bytes[0], (WEIGHTS + BIASES) * 2);

	// Copying weights
	arm_copy_q15(&rxWandB.number[0], &aq15_layer_1_weights[0], L1_IN_DIM*L1_OUT_DIM);
	arm_copy_q15(&rxWandB.number[L1_IN_DIM*L1_OUT_DIM], &aq15_layer_2_weights[0], L2_IN_DIM*L2_OUT_DIM);
	arm_copy_q15(&rxWandB.number[L1_IN_DIM*L1_OUT_DIM + L2_IN_DIM*L2_OUT_DIM], &aq15_layer_3_weights[0], L3_IN_DIM*L3_OUT_DIM);
	arm_copy_q15(&rxWandB.number[L1_IN_DIM*L1_OUT_DIM + L2_IN_DIM*L2_OUT_DIM + L3_IN_DIM*L3_OUT_DIM], &aq15_layer_4_weights[0], L4_IN_DIM*L4_OUT_DIM);
	arm_copy_q15(&rxWandB.number[L1_IN_DIM*L1_OUT_DIM + L2_IN_DIM*L2_OUT_DIM + L3_IN_DIM*L3_OUT_DIM + L4_IN_DIM*L4_OUT_DIM], &aq15_layer_5_weights[0], L5_IN_DIM*L5_OUT_DIM);

	// Copying biases
	arm_copy_q15(&rxWandB.number[WEIGHTS], &aq15_layer_1_biases[0], L1_OUT_DIM);
	arm_copy_q15(&rxWandB.number[WEIGHTS + L1_OUT_DIM], &aq15_layer_2_biases[0], L2_OUT_DIM);
	arm_copy_q15(&rxWandB.number[WEIGHTS + L1_OUT_DIM + L2_OUT_DIM], &aq15_layer_3_biases[0], L3_OUT_DIM);
	arm_copy_q15(&rxWandB.number[WEIGHTS + L1_OUT_DIM + L2_OUT_DIM + L3_OUT_DIM], &aq15_layer_4_biases[0], L4_OUT_DIM);
	arm_copy_q15(&rxWandB.number[WEIGHTS + L1_OUT_DIM + L2_OUT_DIM + L3_OUT_DIM + L4_OUT_DIM], &aq15_layer_5_biases[0], L5_OUT_DIM);

	// Put UART peripheral in reception process
	if(HAL_UART_Receive_IT(&huart3, &rxScaler.bytes[0], NUMBER_OF_FEATURES * 2 * 4) != HAL_OK)
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
	if(rxScaler.bytes[NUMBER_OF_FEATURES * 2 * 4 - 1] != 0){ // Means: received everything
		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
	}
	// Echo
	transmit_echo_data(&rxScaler.bytes[0], NUMBER_OF_FEATURES * 2 * 4);
	/*****************************************************************************************************/
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	/*****************************************************************************************************/
	while (1)
	{
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
		HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
		if(rxBuffer.bytes[8191] != 0){ // Means: received everything
			HAL_GPIO_WritePin(GPIOE, LD2_Pin, GPIO_PIN_SET);
		}

		// Echo
		// transmit_echo_data(&rxBuffer.bytes[0], RX_DATA_SIZE*4);

		// Instantaneous absolute value
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		complex_inst_absolute(&rxBuffer.number[0], &instAbs.number[0]);
		counter_array.number[0] = __HAL_TIM_GET_COUNTER(&htim2);
		// Instantaneous phase value
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		inst_phase(&rxBuffer.number[0], &instPhase.number[0]);
		counter_array.number[1] = __HAL_TIM_GET_COUNTER(&htim2);
		// Instantaneous unwrapped phase value
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		inst_phase(&rxBuffer.number[0], &instPhase.number[0]);
		unwrap(&instPhase.number[0], &instUnwrappedPhase.number[0]);
		counter_array.number[2] = __HAL_TIM_GET_COUNTER(&htim2);
		// Instantaneous frequency value
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		inst_frequency(&rxBuffer.number[0], &instFreq.number[0]);
		counter_array.number[3] = __HAL_TIM_GET_COUNTER(&htim2);
		// Instantaneous centered normalized absolute value
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		inst_centralized_normalized_absolute(&rxBuffer.number[0], &instCNAbs.number[0]);
		counter_array.number[4] = __HAL_TIM_GET_COUNTER(&htim2);


		//transmit_array(&instAbs.bytes[0], FT_INPUT_VECTOR_SIZE*4, &counter_array.bytes[0]);
		//transmit_array(&instPhase.bytes[0], FT_INPUT_VECTOR_SIZE*4, &counter_array.bytes[4]);
		//transmit_array(&instUnwrappedPhase.bytes[0], FT_INPUT_VECTOR_SIZE*4, &counter_array.bytes[8]);
		//transmit_array(&instFreq.bytes[0], FT_INPUT_VECTOR_SIZE*4, &counter_array.bytes[12]);
		//transmit_array(&instCNAbs.bytes[0], FT_INPUT_VECTOR_SIZE*4, &counter_array.bytes[16]);


		/*****************************************************************************************************/
		ft_counter = 0;
		/*
		// 0 - Standard deviation of the instantaneous phase
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		std_dev(&instPhase.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 1 - Standard deviation of the absolute instantaneous phase
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		inst_absolute(&instPhase.number[0], &instAbsPhase.number[0]);
		std_dev(&instAbsPhase.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 2 - Standard deviation of the instantaneous frequency
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		std_dev(&instFreq.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		*/

		// 3 - Standard deviation of the absolute instantaneous frequency
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		inst_absolute(&instFreq.number[0], &instAbsFreq.number[0]);
		std_dev(&instAbsFreq.number[0], &ft_array.number[ft_counter]);
		counter_array.number[8] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;

		/*
		// 4 - Standard deviation of the centralized normalized absolute amplitude
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		std_dev(&instCNAbs.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		*/

		// 5 - Standard deviation of the absolute centralized normalized absolute amplitude
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		inst_absolute(&instCNAbs.number[0], &instAbsCNAbs.number[0]);
		std_dev(&instAbsCNAbs.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 6 - Mean Value of the Signal Magnitude
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		mean_of_signal_magnitude(&instAbs.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;

		/*
		// 7 - Squared Mean of the Signal Magnitude
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		squared_mean_of_signal_magnitude(&instAbs.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 8 - Normalized Sqrt Value of Sum of Amplitude
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		normalized_sqrt_of_sum_of_amp(&instAbs.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 9 - Ratio of I/Q Components
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		ratio_iq(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 10 - Gmax
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		gmax(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		*/

		// 11 - Kurtosis of the Absolute Amplitude
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		kurtosis_of_abs_amplitude(&instAbs.number[0], &ft_array.number[ft_counter], frameSize);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;

		/*
		// 12 - Kurtosis of the Absolute Frequency
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		kurtosis_of_abs_freq(&instAbsFreq.number[0], &ft_array.number[ft_counter], frameSize - 1);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 13 - Cumulant 20
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		cumulant_20(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 14 - Cumulant 21
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		cumulant_21(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		*/

		// 15 - Cumulant 40
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		cumulant_40(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;

		/*
		// 16 - Cumulant 41
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		cumulant_41(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		*/

		// 17 - Cumulant 42
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		cumulant_42(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;

		/*
		// 18 - Cumulant 60
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		cumulant_60(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 19 - Cumulant 61
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		cumulant_61(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 20 - Cumulant 62
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		cumulant_62(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		// 21 - Cumulant 63
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		cumulant_63(&rxBuffer.number[0], &ft_array.number[ft_counter]);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		ft_counter++;
		*/

		transmit_features(&ft_array.bytes[0], &counter_array.bytes[4 * 5]);

		// Scale features (mean and var)
		preprocess_features(&ft_array.number[0], &scaled_ft_array.number[0]);
		min_range.number = -8.0f;
		max_range.number = 7.99951171875f;

		// Evaluate neural network
		__HAL_TIM_SET_COUNTER(&htim2, 0x0U);
		quantize_features(&scaled_ft_array.number[0], min_range.number, max_range.number, &q15_input_vector[0]);
		fully_connected_run(&q15_input_vector[0], &predicted.number);
		counter_array.number[ft_counter + 5] = __HAL_TIM_GET_COUNTER(&htim2);
		transmit_prediction(&predicted.bytes[0], &counter_array.bytes[4*(ft_counter + 5)]);
		/*************************************************************************************************/
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
void transmit_prediction(uint8_t *value, uint8_t *counter){
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
	blink_orange_slow();
	clear_leds();
}
void transmit_features(uint8_t *value, uint8_t *counter){
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txHead[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &value[0], 4 * NUMBER_OF_FEATURES);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &counter[0], 4 * NUMBER_OF_FEATURES);
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
	clear_leds();
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
	blink_orange_slow();
	clear_leds();
}
void transmit_echo_wandb(uint8_t *array, uint16_t size){
	if(UART_CheckIdleState(&huart3) == HAL_OK){
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txHead[0], 2);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &array[0], size);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txTail[0], 2);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	blink_orange_slow();
	clear_leds();
}
void transmit_echo_data(uint8_t *array, uint16_t size){
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
		HAL_UART_Transmit_IT(&huart3, (uint8_t*) &txTail[0], 4);
		while(UartReady != SET){
			blink_red_fast();
		}
		UartReady = RESET;
	}
	blink_orange_slow();
	clear_leds();
}
void preprocess_features(float32_t in[], float32_t out[]){
	for(uint8_t i = 0; i < NUMBER_OF_FEATURES; i++){
		out[i] = (in[i] - rxScaler.number[i]) / rxScaler.number[i + NUMBER_OF_FEATURES];
	}
}
void quantize_features(float32_t in[], float32_t min_float_range, float32_t max_float_range, q15_t out[]){
	const int16_t min_int16_t = SHRT_MIN;
	const int16_t max_int16_t = SHRT_MAX;
	const float32_t max_float = FLT_MAX;

	float32_t scale_factor_from_min_side = 0.0f;
	float32_t scale_factor_from_max_side = 0.0f;
	float32_t scale_factor = 0.0f;

	scale_factor_from_min_side = (min_int16_t * min_float_range > 0) ? min_int16_t / min_float_range : max_float;
	scale_factor_from_max_side = (max_int16_t * max_float_range > 0) ? max_int16_t / max_float_range : max_float;
	scale_factor = fminf(scale_factor_from_min_side, scale_factor_from_max_side);

	min_float_range = min_int16_t / scale_factor;
	max_float_range = max_int16_t / scale_factor;

	for(uint8_t i = 0; i < NUMBER_OF_FEATURES; i++){
		out[i] = (int16_t) roundf(fminf(max_float_range, fmaxf(min_float_range, in[i])) * scale_factor);
	}
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
