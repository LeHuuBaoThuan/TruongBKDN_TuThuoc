#ifndef	_KEYPAD_H
#define	_KEYPAD_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

#define 			KEYPAD_NOT_PRESSED			'\0'

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

typedef struct
{
	uint8_t flag_input_4r;
	uint8_t flag_input_r1;
	uint8_t flag_input_r2;
	uint8_t flag_input_r3;
	uint8_t flag_input_r4;
} PIN_Rx_INPUT_TYPEDEF;

void KeyPad_Init(	GPIO_COLUMN_TYPEDEF* COL_KEY_PAD, GPIO_ROW_TYPEDEF* ROW_KEY_PAD,
					GPIO_TypeDef* C_port0, GPIO_TypeDef* C_port1, GPIO_TypeDef* C_port2, GPIO_TypeDef* C_port3,\
					uint16_t C_pin0, uint16_t C_pin1, uint16_t C_pin2, uint16_t C_pin3,\
					GPIO_TypeDef* R_port0, GPIO_TypeDef* R_port1, GPIO_TypeDef* R_port2, GPIO_TypeDef* R_port3,\
					uint16_t R_pin0, uint16_t R_pin1, uint16_t R_pin2, uint16_t R_pin3);
//char KEYPAD_Read(GPIO_COLUMN_TYPEDEF* COL_KEY_PAD, GPIO_ROW_TYPEDEF* ROW_KEY_PAD_main, uint8_t* row);
char KEYPAD_Handler(GPIO_COLUMN_TYPEDEF* COL_KEY_PAD, GPIO_ROW_TYPEDEF* ROW_KEY_PAD_main, uint8_t* row);
#endif
