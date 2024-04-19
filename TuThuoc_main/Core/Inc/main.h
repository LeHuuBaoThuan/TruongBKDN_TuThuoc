/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#define UP_EXTI_3_Pin GPIO_PIN_3
#define UP_EXTI_3_GPIO_Port GPIOB
#define UP_EXTI_3_EXTI_IRQn EXTI3_IRQn
#define DOWN_EXTI_4_Pin GPIO_PIN_4
#define DOWN_EXTI_4_GPIO_Port GPIOB
#define DOWN_EXTI_4_EXTI_IRQn EXTI4_IRQn
#define ENTER_EXTI_5_Pin GPIO_PIN_5
#define ENTER_EXTI_5_GPIO_Port GPIOB
#define ENTER_EXTI_5_EXTI_IRQn EXTI9_5_IRQn

#define BUZZER_Pin GPIO_PIN_8
#define BUZZER_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
/*LED define pin*/
#define LED_BUTTON_Pin GPIO_PIN_13
#define LED_BUTTON_GPIO_Port GPIOC

#define LED_STATE_Pin GPIO_PIN_3
#define LED_STATE_GPIO_Port GPIOA

#define LED_KEY_Pin GPIO_PIN_4
#define LED_KEY_GPIO_Port GPIOA

#define LED_RESULT_Pin GPIO_PIN_5
#define LED_RESULT_GPIO_Port GPIOA

#define LED_USER_Pin GPIO_PIN_6
#define LED_USER_GPIO_Port GPIOA

/*Relay 74HC595 Pin*/
#define DATA_595_Pin GPIO_PIN_7
#define DATA_595_GPIO_Port GPIOA

#define CLK_595_Pin GPIO_PIN_0
#define CLK_595_GPIO_Port GPIOB

#define LAT_595_Pin GPIO_PIN_1
#define LAT_595_GPIO_Port GPIOB

/*KeyPad Pin*/
#define R4_IN_Pin GPIO_PIN_12
#define R4_IN_GPIO_Port GPIOB
#define R4_IN_EXTI_IRQn EXTI15_10_IRQn

#define R3_IN_Pin GPIO_PIN_13
#define R3_IN_GPIO_Port GPIOB
#define R3_IN_EXTI_IRQn EXTI15_10_IRQn

#define R2_IN_Pin GPIO_PIN_14
#define R2_IN_GPIO_Port GPIOB
#define R2_IN_EXTI_IRQn EXTI15_10_IRQn

#define R1_IN_Pin GPIO_PIN_15
#define R1_IN_GPIO_Port GPIOB
#define R1_IN_EXTI_IRQn EXTI15_10_IRQn

#define C4_OUT_Pin GPIO_PIN_8
#define C4_OUT_GPIO_Port GPIOA

#define C3_OUT_Pin GPIO_PIN_9
#define C3_OUT_GPIO_Port GPIOA

#define C2_OUT_Pin GPIO_PIN_10
#define C2_OUT_GPIO_Port GPIOA

#define C1_OUT_Pin GPIO_PIN_11
#define C1_OUT_GPIO_Port GPIOA
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
