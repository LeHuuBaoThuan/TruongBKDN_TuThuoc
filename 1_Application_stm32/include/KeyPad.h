#ifndef	_KEYPAD_H
#define	_KEYPAD_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

typedef enum
{
	KEYPAD = 0,
	BUTTON = 1
} STATE_SELECT_BUTTON_HANDLER_TYPEDEF;

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


#define 			KEYPAD_NOT_PRESSED			'\0'

extern volatile uint8_t flag_keypad;


//==============================================================================================================================================================
/* <function summary decription>
  +) NOTE:
    -Khai báo port, pin
  +) PARAM:
    -***
  +) RETURN:
    -void
*/
void KeyPad_Init(	GPIO_COLUMN_TYPEDEF* COL_KEY_PAD, GPIO_ROW_TYPEDEF* ROW_KEY_PAD,
					GPIO_TypeDef* C_port0, GPIO_TypeDef* C_port1, GPIO_TypeDef* C_port2, GPIO_TypeDef* C_port3,\
					uint16_t C_pin0, uint16_t C_pin1, uint16_t C_pin2, uint16_t C_pin3,\
					GPIO_TypeDef* R_port0, GPIO_TypeDef* R_port1, GPIO_TypeDef* R_port2, GPIO_TypeDef* R_port3,\
					uint16_t R_pin0, uint16_t R_pin1, uint16_t R_pin2, uint16_t R_pin3);



//==============================================================================================================================================================
/* <function summary decription>
  +) NOTE:
    -Read the keypad
  +) PARAM:
    -GPIO_COLUMN_TYPEDEF* COL_KEY_PAD				: GPIO0 -> GPIO3, GPIO_PIN_A -> GPIO_PIN_D
    -GPIO_ROW_TYPEDEF* ROW_KEY_PAD, uint8_t* row	: GPIO0 -> GPIO3, GPIO_PIN_A -> GPIO_PIN_D
  +) RETURN:
    -Keypad_Button_Values[Row-x][x+1]   			: Keypad_Button_Values
    -KEYPAD_NOT_PRESSED                 			: "\0" (Không ấn nút)
*/
char KEYPAD_Handler(GPIO_COLUMN_TYPEDEF* COL_KEY_PAD, GPIO_ROW_TYPEDEF* ROW_KEY_PAD_main);

#endif
