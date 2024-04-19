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
#define L_RS_Pin GPIO_PIN_5
#define L_RS_GPIO_Port GPIOA
#define L_UR_Pin GPIO_PIN_6
#define L_UR_GPIO_Port GPIOA
#define BT_RX_Pin GPIO_PIN_15
#define BT_RX_GPIO_Port GPIOA
#define BT_RX_EXTI_IRQn EXTI15_10_IRQn

/* USER CODE BEGIN Private defines */
#define L_RS_Pin GPIO_PIN_5
#define L_RS_GPIO_Port GPIOA

#define L_UR_Pin GPIO_PIN_6
#define L_UR_GPIO_Port GPIOA

#define BT_RX_Pin GPIO_PIN_15
#define BT_RX_GPIO_Port GPIOA
#define BT_RX_EXTI_IRQn EXTI15_10_IRQn
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
