/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_RED_1_Pin GPIO_PIN_3
#define LED_RED_1_GPIO_Port GPIOA
#define LED_GREEN_1_Pin GPIO_PIN_4
#define LED_GREEN_1_GPIO_Port GPIOA
#define LED_YELLOW_1_Pin GPIO_PIN_5
#define LED_YELLOW_1_GPIO_Port GPIOA
#define LED_RED_2_Pin GPIO_PIN_6
#define LED_RED_2_GPIO_Port GPIOA
#define LED_GREEN_2_Pin GPIO_PIN_7
#define LED_GREEN_2_GPIO_Port GPIOA
#define INPUTSEG1_1_Pin GPIO_PIN_0
#define INPUTSEG1_1_GPIO_Port GPIOB
#define INPUTSEG1_2_Pin GPIO_PIN_1
#define INPUTSEG1_2_GPIO_Port GPIOB
#define INPUTSEG1_3_Pin GPIO_PIN_2
#define INPUTSEG1_3_GPIO_Port GPIOB
#define INPUTSEG3_3_Pin GPIO_PIN_10
#define INPUTSEG3_3_GPIO_Port GPIOB
#define INPUTSEG3_4_Pin GPIO_PIN_11
#define INPUTSEG3_4_GPIO_Port GPIOB
#define MODE_1_Pin GPIO_PIN_12
#define MODE_1_GPIO_Port GPIOB
#define MODE_2_Pin GPIO_PIN_13
#define MODE_2_GPIO_Port GPIOB
#define MODE_3_Pin GPIO_PIN_14
#define MODE_3_GPIO_Port GPIOB
#define MODE_4_Pin GPIO_PIN_15
#define MODE_4_GPIO_Port GPIOB
#define LED_YELLOW_2_Pin GPIO_PIN_8
#define LED_YELLOW_2_GPIO_Port GPIOA
#define BUTTON_1_Pin GPIO_PIN_9
#define BUTTON_1_GPIO_Port GPIOA
#define BUTTON_2_Pin GPIO_PIN_10
#define BUTTON_2_GPIO_Port GPIOA
#define BUTTON_3_Pin GPIO_PIN_11
#define BUTTON_3_GPIO_Port GPIOA
#define INPUTSEG0_1_Pin GPIO_PIN_12
#define INPUTSEG0_1_GPIO_Port GPIOA
#define INPUTSEG0_2_Pin GPIO_PIN_13
#define INPUTSEG0_2_GPIO_Port GPIOA
#define INPUTSEG0_3_Pin GPIO_PIN_14
#define INPUTSEG0_3_GPIO_Port GPIOA
#define INPUTSEG0_4_Pin GPIO_PIN_15
#define INPUTSEG0_4_GPIO_Port GPIOA
#define INPUTSEG1_4_Pin GPIO_PIN_3
#define INPUTSEG1_4_GPIO_Port GPIOB
#define INPUTSEG2_1_Pin GPIO_PIN_4
#define INPUTSEG2_1_GPIO_Port GPIOB
#define INPUTSEG2_2_Pin GPIO_PIN_5
#define INPUTSEG2_2_GPIO_Port GPIOB
#define INPUTSEG2_3_Pin GPIO_PIN_6
#define INPUTSEG2_3_GPIO_Port GPIOB
#define INPUTSEG2_4_Pin GPIO_PIN_7
#define INPUTSEG2_4_GPIO_Port GPIOB
#define INPUTSEG3_1_Pin GPIO_PIN_8
#define INPUTSEG3_1_GPIO_Port GPIOB
#define INPUTSEG3_2_Pin GPIO_PIN_9
#define INPUTSEG3_2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
