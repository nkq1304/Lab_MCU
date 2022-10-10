/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
int time1=0;
int time2=0;
int time3=0;
int time4=0;
int time5=0;
int time6=0;
  int timered=5;
  int timegreen=3;
  int timeyellow=2;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int counter=0;
unsigned char segmentNumber[10]={
		0x40,
		0x79,
		0x24,
		0x30,
		0x19,
		0x12,
		0x02,
		0x78,
		0x00,
		0x10
};

void display7SEG_1(int counter){
	unsigned char num = segmentNumber[counter];
	HAL_GPIO_WritePin(SEG7_6_GPIO_Port, SEG7_6_Pin, ((num>>6)&0x01));
	HAL_GPIO_WritePin(SEG7_5_GPIO_Port, SEG7_5_Pin, ((num>>5)&0x01));
	HAL_GPIO_WritePin(SEG7_4_GPIO_Port, SEG7_4_Pin, ((num>>4)&0x01));
	HAL_GPIO_WritePin(SEG7_3_GPIO_Port, SEG7_3_Pin, ((num>>3)&0x01));
	HAL_GPIO_WritePin(SEG7_2_GPIO_Port, SEG7_2_Pin, ((num>>2)&0x01));
	HAL_GPIO_WritePin(SEG7_1_GPIO_Port, SEG7_1_Pin, ((num>>1)&0x01));
	HAL_GPIO_WritePin(SEG7_0_GPIO_Port, SEG7_0_Pin, ((num>>0)&0x01));
}
void display7SEG_2(int counter){
	unsigned char num = segmentNumber[counter];
	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, ((num>>6)&0x01));
	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, ((num>>5)&0x01));
	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, ((num>>4)&0x01));
	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, ((num>>3)&0x01));
	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, ((num>>2)&0x01));
	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, ((num>>1)&0x01));
	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, ((num>>0)&0x01));
}
void timecotden1();
void timecotden2();
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		/*COT DEN 1: xanh vang do 3 2 5*/
			  	  if (time3==0)
			  	  {
			  		 HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin,1); /* muc 1 den xanh mo 3s */
			  	  }
			  	  if (time3==3)
			  	  {
			  	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin,0);/*  muc 0 den xanh tat */
			  	  }
			  	  if (time3==10)
			  	  {
			  	    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin,1);
			  		  time3=0;
			  	  }
		/*den vang */
			  	  if (time2==0)
			  	  {
			  		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin,0);/*  den vang tat */
			  	  }
			  	  if (time2==3)
			  	  {
			  		  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin,1);/*  den vang sang */
			  	  }
			  	  if (time2==5)
			  	  {
			  		  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin,0);/* den vang tat */
			  	  }
			  	  if (time2==13) /* set den vang ban dau */
			  	  {
			  		  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin,1);
			  		  time2=3;
			  	  }

			  	  /*den do*/
			  	  if (time1==0)
			  	  {
			  		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin,0); /* den do tat*/
			  	  }
			  	  if (time1==5)
			  	  {
			  		  HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin,1); /* muc 1 den do sang*/

			  	  }
			  	  if (time1==10)
			  	  {
			  		  HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin,0); /* muc 0 den do tat*/

			  	  }
			  	  if (time1==15) /*set den do */
			  	  {
			  		 HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin,1);

			  		  time1=5;
			  	  }
			  	/*COT DEN 2: do vang xanh 5s 3s 2s */
			  		  	  if (time4==0)
			  		  	  {
			  		  		 HAL_GPIO_WritePin(LED_RED1_GPIO_Port,LED_RED1_Pin,1); /* muc 1 den do mo 5s */
			  		  	  }
			  		  	  if (time4==5)
			  		  	  {
			  		  	  HAL_GPIO_WritePin(LED_RED1_GPIO_Port,LED_RED1_Pin,0);/*  muc 0 den do tat */
			  		  	  }
			  		  	  if (time4==10)
			  		  	  {
			  		  	    HAL_GPIO_WritePin(LED_RED1_GPIO_Port,LED_RED1_Pin,1);
			  		  		  time4=0;
			  		  	  }
			  		  	  /* den xanh*/
			  		  	  if (time6==0)
			  		  	  {
			  		  		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port,LED_GREEN1_Pin,0); /*  den xanh tat*/
			  		  	  }
			  		  	  if (time6==5)
			  		  	  {
			  		  		  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port,LED_GREEN1_Pin,1); /* muc 1 den xanh mo 3s*/

			  		  	  }
			  		  	  if (time6==8)
			  		  	  {
			  		  		  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port,LED_GREEN1_Pin,0);

			  		  	  }
			  		  	  if (time6==15) /* set den xanh */
			  		  	  {
			  		  		 HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port,LED_GREEN1_Pin,1);

			  		  		  time6=5;
			  		  	  }

			  	/*den vang */
			  		  	  if (time5==0)
			  		  	  {
			  		  		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port,LED_YELLOW1_Pin,0);
			  		  	  }
			  		  	  if (time5==8)
			  		  	  {
			  		  		  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port,LED_YELLOW1_Pin,1);
			  		  	  }
			  		  	  if (time5==10)
			  		  	  {
			  		  		  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port,LED_YELLOW1_Pin,0);
			  		  	  }
			  		  	  if (time5==18)
			  		  	  {
			  		  		  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port,LED_YELLOW1_Pin,1);
			  		  		  time5=8;
			  		  	  }
			  		  	  /******/
			  		  	timecotden1();
			  		  timecotden2();
HAL_Delay(1000);
	  	  time3++;
	  	  time2++;
	  	  time1++;
	  	  time4++;
		  time5++;
		  time6++;
  }
  /* USER CODE END 3 */
}

void timecotden1(){
	if(HAL_GPIO_ReadPin(LED_GREEN_GPIO_Port, LED_GREEN_Pin) == GPIO_PIN_SET){
		  		display7SEG_1(timegreen);
		  		timegreen--;
		  		if(timegreen==0){
		  			timegreen=3;
		  		}
		  	  }
		if( HAL_GPIO_ReadPin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin)== GPIO_PIN_SET ){
		  		display7SEG_1(timeyellow);
		  		timeyellow--;
		  		if(timeyellow==0){
		  			timeyellow=2;
		  		}
		}
		 if( HAL_GPIO_ReadPin(LED_RED_GPIO_Port, LED_RED_Pin)== GPIO_PIN_SET ){
		  		display7SEG_1(timered);
		  		timered--;
		  		if(timered==0){
		  			timered=5;
		  		}
		}
}
void timecotden2(){
	if( HAL_GPIO_ReadPin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin) == GPIO_PIN_SET){
			  		display7SEG_2(timegreen);
			  		timegreen--;
			  		if(timegreen==0){
			  			timegreen=3;
			  		}
	}
	if( HAL_GPIO_ReadPin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin)== GPIO_PIN_SET){
			  		display7SEG_2(timeyellow);
			  		timeyellow--;
			  		if(timeyellow==0){
			  			timeyellow=2;
			  				  		}
	}
	if( HAL_GPIO_ReadPin(LED_RED1_GPIO_Port, LED_RED1_Pin)== GPIO_PIN_SET ){
			  		display7SEG_2(timered);
			  		timered--;
			  		if(timered==0){
			  			timered=5;
			  		}
	}
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin|LED_YELLOW_Pin|LED_RED_Pin|LED_GREEN1_Pin
                          |LED_YELLOW1_Pin|LED_RED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG7_0_Pin|SEG7_1_Pin|SEG7_2_Pin|SEG_3_Pin
                          |SEG_4_Pin|SEG_5_Pin|SEG_6_Pin|SEG7_3_Pin
                          |SEG7_4_Pin|SEG7_5_Pin|SEG7_6_Pin|SEG_0_Pin
                          |SEG_1_Pin|SEG_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_GREEN_Pin LED_YELLOW_Pin LED_RED_Pin LED_GREEN1_Pin
                           LED_YELLOW1_Pin LED_RED1_Pin */
  GPIO_InitStruct.Pin = LED_GREEN_Pin|LED_YELLOW_Pin|LED_RED_Pin|LED_GREEN1_Pin
                          |LED_YELLOW1_Pin|LED_RED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG7_0_Pin SEG7_1_Pin SEG7_2_Pin SEG_3_Pin
                           SEG_4_Pin SEG_5_Pin SEG_6_Pin SEG7_3_Pin
                           SEG7_4_Pin SEG7_5_Pin SEG7_6_Pin SEG_0_Pin
                           SEG_1_Pin SEG_2_Pin */
  GPIO_InitStruct.Pin = SEG7_0_Pin|SEG7_1_Pin|SEG7_2_Pin|SEG_3_Pin
                          |SEG_4_Pin|SEG_5_Pin|SEG_6_Pin|SEG7_3_Pin
                          |SEG7_4_Pin|SEG7_5_Pin|SEG7_6_Pin|SEG_0_Pin
                          |SEG_1_Pin|SEG_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
