/*
 * lcd_user.h
 *
 *  Created on: Jan 16, 2024
 *      Author: BaoThuan
 */

#ifndef _LCD_USER_H_
#define _LCD_USER_H_

#include "i2c-lcd.h"

void lcd_user_init(CLCD_I2C_Name* LCD_user, I2C_HandleTypeDef* hi2c_CLCD_user, uint8_t Address_user, uint8_t Colums_user, uint8_t Rows_user);

#endif /* _LCD_USER_H_ */
