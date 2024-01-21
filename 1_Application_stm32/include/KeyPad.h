#ifndef	_KEYPAD_H
#define	_KEYPAD_H

#include "stm32f1xx_hal.h"
#include <stdint.h>
//#include <stdbool.h>

//#define           _KEYPAD_USE_FREERTOS            0
#define 			KEYPAD_NOT_PRESSED			'\0'

//typedef enum
//{
//	C0_OUT_SET,
//	C1_OUT_SET,
//	C2_OUT_SET,
//	C3_OUT_SET,
//
//	C0_OUT_RESET,
//	C1_OUT_RESET,
//	C2_OUT_RESET,
//	C3_OUT_RESET,
//
//	R0_READ,
//	R1_READ,
//	R2_READ,
//	R3_READ,
//} STATE_PIN_TYPEDEF;

typedef struct
{
	struct
	{
		GPIO_TypeDef* GPIO0;
		GPIO_TypeDef* GPIO1;
		GPIO_TypeDef* GPIO2;
		GPIO_TypeDef* GPIO3;
	} PORT;
	struct
	{
		uint16_t GPIO_PIN_A;
		uint16_t GPIO_PIN_B;
		uint16_t GPIO_PIN_C;
		uint16_t GPIO_PIN_D;
	} PIN;
} GPIO_COLUMN_TYPEDEF;

typedef struct
{
	struct
	{
		GPIO_TypeDef* GPIO0;
		GPIO_TypeDef* GPIO1;
		GPIO_TypeDef* GPIO2;
		GPIO_TypeDef* GPIO3;
	} PORT;
	struct
	{
		uint16_t GPIO_PIN_A;
		uint16_t GPIO_PIN_B;
		uint16_t GPIO_PIN_C;
		uint16_t GPIO_PIN_D;
	} PIN;
} GPIO_ROW_TYPEDEF;

void KeyPad_Init(	GPIO_COLUMN_TYPEDEF* COL_KEY_PAD, GPIO_ROW_TYPEDEF* ROW_KEY_PAD,
					GPIO_TypeDef* C_port0, GPIO_TypeDef* C_port1, GPIO_TypeDef* C_port2, GPIO_TypeDef* C_port3,\
					uint16_t C_pin0, uint16_t C_pin1, uint16_t C_pin2, uint16_t C_pin3,\
					GPIO_TypeDef* R_port0, GPIO_TypeDef* R_port1, GPIO_TypeDef* R_port2, GPIO_TypeDef* R_port3,\
					uint16_t R_pin0, uint16_t R_pin1, uint16_t R_pin2, uint16_t R_pin3);
char KEYPAD_Read(GPIO_COLUMN_TYPEDEF* COL_KEY_PAD, GPIO_ROW_TYPEDEF* ROW_KEY_PAD);
#endif
