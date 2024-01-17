/*
 * lcd_user.h
 *
 *  Created on: Jan 16, 2024
 *      Author: BaoThuan
 */

#ifndef _LCD_USER_H_
#define _LCD_USER_H_

#include "i2c-lcd.h"

typedef enum
{
	STATUS_1 = 1,
	STATUS_2 = 2,
	STATUS_3 = 3,
	STATUS_4 = 4,
	STATUS_5 = 5,
} STATUS_DISPLAY_TYPEDEF;

void lcd_user_display(CLCD_I2C_Name* LCD_user, STATUS_DISPLAY_TYPEDEF status_display);

#endif /* _LCD_USER_H_ */
