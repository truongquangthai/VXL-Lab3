/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE BEGIN Private defines */
#define Count500ms 			50
#define BUTTON_1_Pin 		GPIO_PIN_0
#define BUTTON_1_GPIO_Port 	GPIOB

#define BUTTON_2_Pin 		GPIO_PIN_1
#define BUTTON_2_GPIO_Port 	GPIOB

#define BUTTON_3_Pin 		GPIO_PIN_2
#define BUTTON_3_GPIO_Port 	GPIOB

#define H_RED_PIN 			GPIO_PIN_3
#define H_RED_GPIO_Port 	GPIOB
#define H_YELLOW_PIN 		GPIO_PIN_4
#define H_YELLOW_GPIO_Port 	GPIOB
#define H_GREEN_PIN 		GPIO_PIN_5
#define H_GREEN_GPIO_Port 	GPIOB

#define V_RED_PIN 			GPIO_PIN_6
#define V_RED_GPIO_Port 	GPIOB
#define V_YELLOW_PIN 		GPIO_PIN_7
#define V_YELLOW_GPIO_Port 	GPIOB
#define V_GREEN_PIN 		GPIO_PIN_8
#define V_GREEN_GPIO_Port 	GPIOB

#define first_O7SEG_1_PIN 		GPIO_PIN_9
#define first_O7SEG_1_Port		GPIOB
#define first_O7SEG_2_PIN 		GPIO_PIN_10
#define first_O7SEG_2_Port		GPIOB
#define first_O7SEG_3_PIN 		GPIO_PIN_11
#define first_O7SEG_3_Port		GPIOB
#define first_O7SEG_4_PIN 		GPIO_PIN_12
#define first_O7SEG_4_Port		GPIOB
#define first_O7SEG_5_PIN 		GPIO_PIN_13
#define first_O7SEG_5_Port		GPIOB
#define first_O7SEG_6_PIN 		GPIO_PIN_14
#define first_O7SEG_6_Port		GPIOB
#define first_O7SEG_7_PIN 		GPIO_PIN_15
#define first_O7SEG_7_Port		GPIOB
//////////////////////////////////////////
#define second_O7SEG_1_PIN 		GPIO_PIN_0
#define second_O7SEG_1_Port		GPIOA
#define second_O7SEG_2_PIN 		GPIO_PIN_1
#define second_O7SEG_2_Port		GPIOA
#define second_O7SEG_3_PIN 		GPIO_PIN_2
#define second_O7SEG_3_Port		GPIOA
#define second_O7SEG_4_PIN 		GPIO_PIN_3
#define second_O7SEG_4_Port		GPIOA
#define second_O7SEG_5_PIN 		GPIO_PIN_4
#define second_O7SEG_5_Port		GPIOA
#define second_O7SEG_6_PIN 		GPIO_PIN_5
#define second_O7SEG_6_Port		GPIOA
#define second_O7SEG_7_PIN 		GPIO_PIN_6
#define second_O7SEG_7_Port		GPIOA

#define third_O7SEG_1_PIN 		GPIO_PIN_7
#define third_O7SEG_1_Port		GPIOA
#define third_O7SEG_2_PIN 		GPIO_PIN_8
#define third_O7SEG_2_Port		GPIOA
#define third_O7SEG_3_PIN 		GPIO_PIN_9
#define third_O7SEG_3_Port		GPIOA
#define third_O7SEG_4_PIN 		GPIO_PIN_10
#define third_O7SEG_4_Port		GPIOA
#define third_O7SEG_5_PIN 		GPIO_PIN_11
#define third_O7SEG_5_Port		GPIOA
#define third_O7SEG_6_PIN 		GPIO_PIN_12
#define third_O7SEG_6_Port		GPIOA
#define third_O7SEG_7_PIN 		GPIO_PIN_13
#define third_O7SEG_7_Port		GPIOA

#define Enable_third_7SEG_PIN	GPIO_PIN_15
#define Enable_third_7SEG_Port	GPIOA





/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
