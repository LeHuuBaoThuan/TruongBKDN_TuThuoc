/*
 * handler.h
 *
 *  Created on: 31 Jan 2024
 *      Author: BaoThuan
 */

#ifndef _HANDLER_KEYIN_H_
#define _HANDLER_KEYIN_H_

#include "stm32f1xx_hal.h"
#include <KeyPad.h>
#include<lcd_user.h>

#define SIZE_ROW_NUM 1+3-1
#define SIZE_ROW_PASS 9+5-1

typedef enum
{
	KEY_OK = 1,
	KEY_NOT = 0
} STATE_KEY;
STATE_KEY handler_keyIN_enterKey_DisplayLCD(CLCD_I2C_Name* LCD_user, STATE_SELECT_BUTTON_HANDLER_TYPEDEF state_button, char *key, char* password);

#endif /* _HANDLER_KEYIN_H_ */