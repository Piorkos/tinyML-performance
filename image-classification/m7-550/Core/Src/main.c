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

//test data
float aiInDataShirt[AI_NETWORK_IN_1_SIZE] = {
		0,   0,   0,   2,   0,   1,   1,   0,   0,   0,   0,  57,  67,
		73,  76,  76,  83,  62,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   1,   1,   1,   0,   0,  13,  79, 128,
		201, 162, 161, 173, 192, 172, 181, 184, 108,  30,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0, 102, 139,
		142, 103, 115, 162, 154, 165, 153, 139, 129, 150, 138, 171, 161,
		26,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0, 106,
		124, 108, 103, 106,  93, 100, 180, 156, 147, 138,  85, 157, 114,
		124, 154, 157,   0,   0,   0,   0,   0,   0,   0,   0,   2,   0,
		29, 134, 101, 113, 108,  97, 116,  81, 146, 183, 164, 111, 146,
		131, 122, 132, 145, 169,  93,   0,   1,   0,   0,   0,   0,   0,
		0,   0,  65, 131, 105, 101, 108, 100, 104,  97,  74, 206, 174,
		115, 150, 108, 119, 146, 152, 162, 141,   0,   0,   0,   0,   0,
		0,   0,   0,   0, 108, 123, 112, 106,  98, 100, 101, 111,  72,
		136, 132, 112, 115, 109, 142, 150, 160, 162, 195,   0,   0,   0,
		0,   0,   0,   0,   0,   0, 135, 122, 119, 112,  83,  93,  97,
		106, 115,  91, 109,  83, 109, 125, 165, 140, 193, 160, 176,   6,
		0,   0,   0,   0,   0,   0,   0,  23, 135, 132, 149, 104,  78,
		96,  97, 103, 108, 108, 115,  84, 114, 149, 158, 147, 209, 160,
		178,  52,   0,   0,   0,   0,   0,   0,   0,  57, 124, 131, 160,
		103,  96, 101, 109, 109, 111, 108, 114, 106, 113, 156, 163, 156,
		196, 167, 174,  85,   0,   0,   0,   0,   0,   0,   0,  86, 116,
		126, 160, 132, 102,  96, 104, 107,  98,  93, 123, 116, 112, 149,
		160, 181, 186, 162, 162, 123,   0,   0,   0,   0,   0,   0,   0,
		112, 114, 112, 167, 146, 100, 100, 101, 107,  96, 100, 126, 103,
		120, 141, 158, 167, 187, 147, 148, 170,   0,   0,   0,   0,   0,
		0,   0, 124, 118, 101, 197,  89, 101, 100,  96, 108, 103, 108,
		122, 107, 127, 139, 150, 119, 196, 145, 142, 179,   0,   0,   0,
		0,   0,   0,   0, 131, 115,  97, 198,  47, 108,  96,  96, 106,
		119, 102, 120, 103, 123, 140, 150,  81, 206, 146, 135, 194,   0,
		0,   0,   0,   0,   0,   4, 136, 118,  98, 193,  21, 109,  96,
		106, 102, 129, 100, 119, 102, 118, 141, 153,  45, 216, 148, 139,
		205,  12,   0,   0,   0,   0,   0,  24, 137, 117, 101, 187,  25,
		113,  92, 112,  94, 120, 105, 127,  97, 115, 142, 150,  19, 213,
		148, 131, 204,  36,   0,   0,   0,   0,   0,  40, 141, 109, 117,
		158,  12, 124,  90, 116,  96, 117, 113, 136,  94, 111, 147, 163,
		31, 191, 146, 134, 206,  58,   0,   0,   0,   0,   0,  39, 129,
		102, 147, 119,   0, 120,  90, 119, 101, 116, 106, 127, 102, 114,
		146, 180,  20, 146, 159, 129, 204,  70,   0,   0,   0,   0,   0,
		58, 126, 111, 162, 101,  21, 132,  89, 123, 108, 106, 102, 126,
		111, 116, 141, 178,  50, 112, 169, 138, 164,  84,   0,   0,   0,
		0,   0, 108, 134, 134, 185,  84,  73, 123,  87, 122, 111, 102,
		106, 128, 114, 109, 134, 174,  97,  98, 160, 147, 175, 135,   0,
		0,   0,   0,   0,  97, 142, 169, 198,  37,  84, 107,  97, 122,
		112, 109, 112, 126, 102,  96, 131, 172, 128,  51, 254, 168, 164,
		111,   0,   0,   0,   0,   0,   0,   0,  12,  46,   2, 119, 102,
		109, 123,  96, 116, 122, 132, 106, 106, 129, 151, 184,  26,  20,
		8,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  13,
		137, 101, 114, 100, 106, 134, 135, 129, 104, 111, 123, 151, 194,
		74,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   3,
		0,  73, 132, 101, 104, 102, 140, 108, 108, 131, 106, 119, 113,
		142, 167, 135,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0, 112, 118, 107, 104, 139, 109,  97, 123, 138, 107,
		127, 120, 136, 161, 159,   0,   0,   1,   0,   0,   0,   0,   0,
		0,   0,   0,   3,   0, 142, 148, 112, 105, 101,  83, 125, 123,
		143, 104, 115, 100, 126, 168, 178,   7,   0,   2,   0,   0,   0,
		0,   0,   0,   0,   0,   2,   0,   9, 126, 184, 200, 167, 163,
		171, 150, 167, 156, 174, 197, 182, 162,  61,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  30,
		72,  95, 109, 111, 111, 106, 101,  71,  12,   0,   0,   0,   0,
		0,   0,   0,   0
};
float aiInDataPullover[AI_NETWORK_IN_1_SIZE] = {
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  13,  67,   0,
		0,   0,   0,  50,  38,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   8, 120, 209, 226,
		247, 237, 255, 255, 255, 247, 238, 235, 172,  72,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 137, 239, 252,
		243, 234, 229, 238, 244, 246, 240, 230, 232, 239, 248, 251, 194,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 102, 255,
		231, 228, 227, 228, 233, 230, 230, 229, 228, 232, 232, 231, 227,
		224, 252, 179,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		233, 241, 229, 231, 255, 255, 238, 231, 227, 238, 246, 228, 230,
		227, 234, 235, 229, 241,  20,   0,   0,   0,   0,   0,   0,   0,
		0,   0, 248, 241, 231, 255, 149,  47, 252, 228, 255, 242, 216,
		238, 232, 255, 228, 220, 234, 250,  54,   0,   0,   0,   0,   0,
		0,   0,   0,   0, 255, 240, 232, 255,  15,   0, 255, 237, 191,
		0,   0, 214, 255,  13, 123, 255, 234, 252, 114,   0,   0,   0,
		0,   0,   0,   0,   0,   6, 255, 238, 239, 255, 177,   0, 255,
		255,   0, 130, 116,  47,  65,  43,  37, 255, 236, 249, 162,   0,
		0,   0,   0,   0,   0,   0,   0,  32, 255, 236, 245, 255, 204,
		0, 255,  84,   0,  37,  28,  31,   0,  25,  13, 255, 236, 249,
		199,   0,   0,   0,   0,   0,   0,   0,   0,  53, 255, 236, 250,
		250, 231,   2, 255,  21,   0, 221, 255, 236,  54, 245, 198, 243,
		238, 245, 223,   0,   0,   0,   0,   0,   0,   0,   0,  80, 255,
		237, 250, 240, 255,   0,   0,  39, 157,   0,   0, 215,  94,  20,
		126, 255, 237, 239, 250,   0,   0,   0,   0,   0,   0,   0,   0,
		101, 255, 235, 253, 244, 243, 133, 138, 208, 255, 201, 214, 255,
		230,   7, 174, 255, 240, 238, 255,   0,   0,   0,   0,   0,   0,
		0,   0, 126, 255, 233, 255, 248, 233, 255, 255, 240, 232, 243,
		243, 231, 251, 255, 255, 254, 243, 238, 255,   3,   0,   0,   0,
		0,   0,   0,   0, 147, 255, 233, 249, 181, 243, 227, 224, 230,
		234, 230, 230, 235, 228, 235, 222, 207, 255, 236, 255,  35,   0,
		0,   0,   0,   0,   0,   0, 163, 255, 245, 221,  86, 255, 233,
		233, 235, 236, 234, 234, 234, 232, 242, 231, 125, 255, 236, 255,
		55,   0,   0,   0,   0,   0,   0,   0, 181, 254, 255, 200,  69,
		255, 228, 232, 234, 235, 234, 234, 233, 235, 241, 237,  70, 255,
		235, 246,  57,   0,   0,   0,   0,   0,   0,   0, 197, 247, 255,
		188, 110, 255, 224, 233, 234, 234, 234, 234, 234, 234, 240, 253,
		69, 255, 236, 248,  77,   0,   0,   0,   0,   0,   0,   0, 200,
		246, 255, 149, 145, 255, 223, 235, 234, 235, 235, 235, 234, 237,
		233, 255,  47, 255, 239, 249,  98,   0,   0,   0,   0,   0,   0,
		0, 204, 243, 255, 111, 173, 255, 227, 235, 235, 236, 235, 235,
		235, 239, 229, 255,  19, 227, 246, 249, 110,   0,   0,   0,   0,
		0,   0,   0, 196, 240, 255, 109, 213, 250, 229, 235, 235, 236,
		235, 237, 236, 237, 226, 255,  55, 203, 251, 245, 120,   0,   0,
		0,   0,   0,   0,   0, 192, 243, 255, 114, 232, 240, 232, 235,
		235, 236, 234, 237, 236, 235, 229, 255, 134, 171, 252, 244, 137,
		0,   0,   0,   0,   0,   0,   0, 189, 251, 255, 154, 238, 233,
		236, 234, 235, 236, 235, 238, 236, 235, 232, 255, 166, 125, 255,
		243, 142,   0,   0,   0,   0,   0,   0,   0, 183, 252, 255, 171,
		247, 232, 234, 234, 233, 233, 232, 234, 233, 234, 233, 240, 223,
		128, 255, 242, 151,   0,   0,   0,   0,   0,   0,   0, 178, 243,
		255,  57, 238, 241, 238, 238, 238, 237, 236, 237, 237, 240, 237,
		254, 176,  52, 255, 239, 157,   0,   0,   0,   0,   0,   0,   0,
		188, 240, 250,  62, 218, 255, 220, 222, 222, 222, 223, 223, 224,
		222, 218, 255, 154,  32, 255, 236, 188,   0,   0,   0,   0,   0,
		0,   0, 130, 245, 242,  24,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,  34, 242, 244, 135,   0,   0,   0,
		0,   0,   0,   0,  76, 255, 249,  22,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,  39, 249, 255, 123,   0,
		0,   0,   0,   0,   0,   0,  49, 205, 197,  11,   0,   4,   1,
		2,   2,   2,   2,   2,   2,   2,   2,   3,   0,   3, 174, 189,
		67,   0,   0,   0
};
float aiInDataTrouser[AI_NETWORK_IN_1_SIZE] = {
		0,   0,   0,   0,   0,   0,   0,   0,   1,   0,  67, 177, 129,
		153, 117, 129, 146, 141, 175,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   0, 196,
		255, 255, 255, 241, 251, 255, 245, 255,  76,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0, 243, 237, 217, 228, 231, 222, 218, 219, 255, 116,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0, 255, 235, 231, 233, 226, 225, 229, 222, 255, 145,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,  23, 255, 230, 229, 233, 229, 225, 227, 221,
		241, 167,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,  67, 255, 225, 234, 231, 226, 227,
		228, 224, 234, 187,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0, 114, 249, 217, 235, 238,
		245, 227, 227, 225, 241, 176,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 167, 247, 227,
		231, 250, 200, 248, 231, 224, 251, 147,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 208,
		242, 225, 243, 225,   0, 255, 233, 226, 255, 129,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0, 223, 238, 223, 255, 161,   0, 255, 236, 223, 255, 135,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0, 245, 235, 222, 255,  72,   0, 248, 254, 217, 255,
		145,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0, 255, 233, 226, 255,   7,   0, 191, 248,
		220, 255, 126,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0, 255, 233, 231, 251,   0,   0,
		159, 251, 221, 255, 111,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 232, 236, 216,
		0,   0, 131, 253, 220, 255, 111,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 228,
		243, 172,   0,   0,  57, 249, 222, 255, 111,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		255, 230, 244, 139,   0,   0,  10, 255, 227, 255, 100,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0, 227, 237, 242, 113,   0,   0,   6, 255, 230, 255,  89,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0, 204, 239, 245, 151,   0,   0,   0, 255, 227,
		255,  99,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0, 151, 245, 238, 198,   0,   0,   0,
		255, 234, 255,  92,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,  89, 248, 233, 248,   0,
		0,   0, 252, 237, 255,  90,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  31, 240, 229,
		226,   0,   0,   0, 239, 238, 255,  92,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		226, 233, 237,  34,   0,   0, 234, 238, 255,  95,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0, 233, 236, 244,  68,   0,   0, 209, 241, 237,  98,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   1,   0, 152, 242, 245, 128,   0,   0, 198, 241, 238,
		81,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   2,   0,  73, 246, 241, 211,   0,   0, 202,
		240, 237,  74,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   4,   0,   0, 229, 236, 209,   0,
		0, 158, 247, 238,  99,   0,   0,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0, 199, 255,
		247,  58,   0, 161, 255, 252, 119,   0,   0,   0,   0,   0,   0,
		0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		98, 159,  71,   0,   0,  68, 176, 164,  58,   0,   0,   0,   0,
		0,   0,   0,   0
};

float aiOutData[3][AI_NETWORK_OUT_1_SIZE];
uint8_t activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];
const char* labels[AI_NETWORK_OUT_1_SIZE] = {
		"top", "trouser", "pullover", "dress", "coat", "sandal", "shirt", "sneaker", "bag", "ankle boot"
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
	uint32_t timestamp;

	//  normalise data to range [0,1]
	for(int i = 0; i < AI_NETWORK_IN_1_SIZE; i++)
	{
		aiInDataShirt[i] = aiInDataShirt[i] / 255.0;
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
  MX_USART3_UART_Init();
  MX_CRC_Init();
  MX_TIM16_Init();
  /* USER CODE BEGIN 2 */
  AI_Init(ai_network_data_weights_get(), activations);

  //  Start timer/counter
  HAL_TIM_Base_Start(&htim16);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  buf_len = sprintf(buf, "Cortex-M7 Running inference \n");
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);

	  timestamp = htim16.Instance->CNT;

	  //	  shirt
	  AI_Run(aiInDataShirt, aiOutData[0]);

	  //	  pullover
	  AI_Run(aiInDataPullover, aiOutData[1]);

	  //	  trouser
	  AI_Run(aiInDataTrouser, aiOutData[2]);


	  uint32_t predicted_class_1 = argmax(aiOutData[0], AI_NETWORK_OUT_1_SIZE);
	  uint32_t predicted_class_2 = argmax(aiOutData[1], AI_NETWORK_OUT_1_SIZE);
	  uint32_t predicted_class_3 = argmax(aiOutData[2], AI_NETWORK_OUT_1_SIZE);

	  buf_len = sprintf(buf, "Iference duration: %lu \n", (htim16.Instance->CNT - timestamp));
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);

	  buf_len = sprintf(buf, "1 predicted class: %d - %s \n", (int) predicted_class_1, labels[predicted_class_1]);
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
	  buf_len = sprintf(buf, "2 predicted class: %d - %s \n", (int) predicted_class_2, labels[predicted_class_2]);
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
	  buf_len = sprintf(buf, "3 predicted class: %d - %s \n", (int) predicted_class_3, labels[predicted_class_3]);
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
