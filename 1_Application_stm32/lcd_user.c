/*
 * lcd_user.c
 *
 *  Created on: Jan 16, 2024
 *      Author: BaoThuan
 */

#include<lcd_user.h>

void lcd_user_init(CLCD_I2C_Name* LCD_user, I2C_HandleTypeDef* hi2c_CLCD_user, uint8_t Address_user, uint8_t Colums_user, uint8_t Rows_user)
{
	CLCD_I2C_Init(LCD_user, hi2c_CLCD_user, Address_user, Colums_user, Rows_user);
}
