/*
 * lcd_user.c
 *
 *  Created on: Jan 16, 2024
 *      Author: BaoThuan
 */

#include<lcd_user.h>

void lcd_user_init(CLCD_I2C_Name* LCD_user, I2C_HandleTypeDef* hi2c_CLCD_user, uint8_t Data_user, uint8_t Mode_user)
{
	CLCD_I2C_Init(LCD_user, hi2c_CLCD_user, (0x27 << 1), Colums, Rows), hi2c_CLCD, Address, Colums, Rows)
}
