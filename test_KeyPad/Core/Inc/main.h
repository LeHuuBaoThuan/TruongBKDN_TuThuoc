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

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
