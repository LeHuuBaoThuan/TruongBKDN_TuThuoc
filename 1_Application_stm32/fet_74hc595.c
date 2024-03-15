/*
 * fet_74hc595.c
 *
 *  Created on: Mar 16, 2024
 *      Author: BaoThuan
 */
#include <fet_74hc595.h>

/*74HC595 Port*/
static GPIO_TypeDef *					IC74HC595_ST_Port;
static GPIO_TypeDef * 					IC74hc595_DS_Port;
static GPIO_TypeDef * 					IC74HC595_Shift_Port;
/*74HC595 Pin*/
static uint16_t 						IC74hc595_Shift_Pin;
static uint16_t							IC74hc595_DS_Pin;
static uint16_t							IC74HC595_ST_Pin;



void FET_74HC595_Init(	GPIO_TypeDef * DS_Port, GPIO_TypeDef * Shift_Port, GPIO_TypeDef * ST_Port, 			\
						uint16_t DS_Pin, uint16_t SH_Pin, uint16_t ST_Pin)									\
{
	IC74HC595_ST_Port		=	ST_Port;
	IC74hc595_DS_Port		= 	DS_Port;
	IC74HC595_Shift_Port	=	Shift_Port;
	IC74HC595_ST_Pin		=	ST_Pin;
	IC74hc595_Shift_Pin		=	SH_Pin;
	IC74hc595_DS_Pin		=	DS_Pin;
}



void FET_74HC595_Set_Reset(uint16_t  tt)
{
	uint16_t	tam 	= 	tt;
	uint8_t		i 		= 	0;
	for(i = 0; i < 8; i++)
	{
		if(tam & (0x80 >> i))
		{
			HAL_GPIO_WritePin(IC74hc595_DS_Port, IC74hc595_DS_Pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(IC74hc595_DS_Port, IC74hc595_DS_Pin, GPIO_PIN_RESET);
		}
		HAL_GPIO_WritePin(IC74HC595_Shift_Port, IC74hc595_Shift_Pin ,GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(IC74HC595_Shift_Port, IC74hc595_Shift_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
	}
	HAL_GPIO_WritePin(IC74HC595_ST_Port, IC74HC595_ST_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(IC74HC595_ST_Port, IC74HC595_ST_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}
