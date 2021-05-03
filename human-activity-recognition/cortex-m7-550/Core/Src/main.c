/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "crc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>

#include "ai_platform.h"
#include "network.h"
#include "network_data.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
char buf[50];
int buf_len = 0;

ai_handle network;

uint32_t timer_counter = 0;
uint32_t timestamp = 0;

//test data
float aiInDataStationary[AI_NETWORK_IN_1_SIZE] = {
		138,	215,	-939,
		140,	201,	-935,
		138,	212,	-936,
		139,	205,	-934,
		139,	207,	-936,
		138,	208,	-935,
		140,	206,	-934,
		139,	207,	-932,
		139,	207,	-934,
		139,	207,	-935,
		140,	207,	-935,
		140,	207,	-934,
		139,	206,	-933,
		139,	207,	-934,
		140,	207,	-936,
		139,	206,	-933,
		302,	-989,	293,
		244,	-837,	263,
		219,	-686,	234,
		189,	-641,	196,
		140,	-701,	254,
		-35,	-868,	348,
		-63,	-974,	259,
		196,	-993,	190,
		345,	-1099,	293,
		596,	-847,	302
};
float aiInDataWalking[AI_NETWORK_IN_1_SIZE] = {
		612,	330,	338,
		922,	404,	347,
		1218,	572,	422,
		1307,	383,	801,
		1546,	836,	149,
		1505,	739,	378,
		989,	807,	-299,
		1131,	526,	-349,
		1042,	510,	-124,
		715,	477,	46,
		572,	197,	189,
		327,	166,	116,
		307,	112,	89,
		464,	113,	125,
		766,	136,	43,
		1134,	300,	230,
		1262,	397,	412,
		1339,	248,	653,
		1620,	462,	229,
		1430,	639,	99,
		1025,	400,	-396,
		942,	711,	-450,
		1137,	731,	359,
		886,	352,	32,
		624,	15,	-116,
		504,	-85,	120
};
float aiInDataRunning[AI_NETWORK_IN_1_SIZE] = {
		-276,	-85,	-309,
		315,	247,	-36,
		-338,	647,	-218,
		-272,	359,	-406,
		2747,	1189,	-793,
		2279,	-277,	-794,
		2249,	44,	297,
		2048,	-523,	1378,
		324,	291,	-671,
		-131,	412,	117,
		-147,	-169,	-101,
		-88,	-71,	-283,
		-13,	-51,	-115,
		905,	-93,	-956,
		3601,	189,	-447,
		2133,	451,	1035,
		1001,	-247,	715,
		526,	467,	87,
		-112,	102,	-340,
		144,	214,	-6,
		-134,	419,	-59,
		-191,	-166,	-127,
		1954,	1427,	-635,
		2756,	153,	-513,
		2201,	77,	420,
		2144,	-495,	1370
};


float aiOutData[3][AI_NETWORK_OUT_1_SIZE];
uint8_t activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];
const char* activities[AI_NETWORK_OUT_1_SIZE] = {
		"stationary", "walking", "running"
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static void AI_Init(ai_handle w_addr, ai_handle act_addr);
static void AI_Run(float *pIn, float *pOut);
static uint32_t argmax(const float * values, uint32_t len);
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
	//  normalise data to range [-1,1]
	for(int i = 0; i < AI_NETWORK_IN_1_SIZE; i++)
	{
		aiInDataStationary[i] = aiInDataStationary[i] / 4000.0;
		aiInDataWalking[i] = aiInDataWalking[i] / 4000.0;
		aiInDataRunning[i] = aiInDataRunning[i] / 4000.0;
	}
  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM16_Init();
  MX_USART3_UART_Init();
  MX_CRC_Init();
  /* USER CODE BEGIN 2 */
  AI_Init(ai_network_data_weights_get(), activations);

  //  Start timer/counter
  HAL_TIM_Base_Start_IT(&htim16);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  buf_len = sprintf(buf, "M7-550 HAT Running inference \n");
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);


	  timestamp = htim16.Instance->CNT;

	  //	  stationary
	  AI_Run(aiInDataStationary, aiOutData[0]);

	  //	  walking
	  AI_Run(aiInDataWalking, aiOutData[1]);

	  //	  running
	  AI_Run(aiInDataRunning, aiOutData[2]);


	  uint32_t predicted_class_1 = argmax(aiOutData[0], AI_NETWORK_OUT_1_SIZE);
	  uint32_t predicted_class_2 = argmax(aiOutData[1], AI_NETWORK_OUT_1_SIZE);
	  uint32_t predicted_class_3 = argmax(aiOutData[2], AI_NETWORK_OUT_1_SIZE);

	  buf_len = sprintf(buf, "Iference duration: (%lu s) + %lu*0.01ms \n", timer_counter, (htim16.Instance->CNT - timestamp));
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);

	  buf_len = sprintf(buf, "1 predicted class: %d - %s \n", (int) predicted_class_1, activities[predicted_class_1]);
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
	  buf_len = sprintf(buf, "2 predicted class: %d - %s \n", (int) predicted_class_2, activities[predicted_class_2]);
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
	  buf_len = sprintf(buf, "3 predicted class: %d - %s \n", (int) predicted_class_3, activities[predicted_class_3]);
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
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

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

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
  RCC_OscInitStruct.PLL.PLLN = 34;
  RCC_OscInitStruct.PLL.PLLP = 1;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 3072;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim16 )
	{
		++timer_counter;
	}
}


static void AI_Init(ai_handle w_addr, ai_handle act_addr)
{
	ai_error err;

	/* 1 - Create an instance of the model */
	err = ai_network_create(&network, AI_NETWORK_DATA_CONFIG);
	if (err.type != AI_ERROR_NONE) {
		printf("ai_network_create error - type=%d code=%d\r\n", err.type, err.code);
		Error_Handler();
	}

	/* 2 - Initialize the instance */
	const ai_network_params params = {
			AI_NETWORK_DATA_WEIGHTS(w_addr),
			AI_NETWORK_DATA_ACTIVATIONS(act_addr)
	};

	if (!ai_network_init(network, &params))
	{
		err = ai_network_get_error(network);
		printf("ai_network_init error - type=%d code=%d\r\n", err.type, err.code);
		Error_Handler();
	}
}
static void AI_Run(float *pIn, float *pOut)
{
	ai_i32 batch;
	ai_error err;

	/* 1 - Create the AI buffer IO handlers with the default definition */
	ai_buffer ai_input[AI_NETWORK_IN_NUM] = AI_NETWORK_IN;
	ai_buffer ai_output[AI_NETWORK_OUT_NUM] = AI_NETWORK_OUT;

	/* 2 - Update IO handlers with the data payload */
	ai_input[0].n_batches = 1;
	ai_input[0].data = AI_HANDLE_PTR(pIn);
	ai_output[0].n_batches = 1;
	ai_output[0].data = AI_HANDLE_PTR(pOut);

	batch = ai_network_run(network, ai_input, ai_output);
	if (batch != 1)
	{
		err = ai_network_get_error(network);
		buf_len = sprintf(buf, "AI ai_network_run error - type=%d code=%d \n", err.type, err.code);
		HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
		Error_Handler();
	}
}
static uint32_t argmax(const float * values, uint32_t len)
{
	float max_value = values[0];
	uint32_t max_index = 0;
	for (uint32_t i = 1; i < len; i++)
	{
		if (values[i] > max_value)
		{
			max_value = values[i];
			max_index = i;
		}
	}
	return max_index;
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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
