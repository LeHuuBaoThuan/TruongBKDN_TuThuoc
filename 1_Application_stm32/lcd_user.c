/*
 * lcd_user.c
 *
 *  Created on: Jan 16, 2024
 *      Author: BaoThuan
 */

#include<lcd_user.h>

void lcd_user_display(CLCD_I2C_Name* LCD_user, STATUS_DISPLAY_TYPEDEF status_display)
{
	if(status_display == STATUS_1)
	{
		// dislay hello ! Status_Display=0
		CLCD_I2C_SetCursor(LCD_user, 0, 0);
		CLCD_I2C_WriteString(LCD_user,"TRUONG DHBK-DHDN");

		CLCD_I2C_SetCursor(LCD_user, 3, 1);
		CLCD_I2C_WriteString(LCD_user,"KHOA CO KHI");

		CLCD_I2C_SetCursor(LCD_user, 4, 2);
		CLCD_I2C_WriteString(LCD_user,"TU THUOC");

		CLCD_I2C_SetCursor(LCD_user, 0, 3);
		CLCD_I2C_WriteString(LCD_user,"Please Set Mode!");
	}
	else if(status_display == STATUS_2)
	{
		// dislay Select Mode ! Status_Display=1
		CLCD_I2C_SetCursor(LCD_user, 3, 0);
		CLCD_I2C_WriteString(LCD_user,"SELECT MODE");

		CLCD_I2C_SetCursor(LCD_user, 0, 1);
		CLCD_I2C_WriteString(LCD_user,"-Language");

		CLCD_I2C_SetCursor(LCD_user, 0, 2);
		CLCD_I2C_WriteString(LCD_user,"-Enter password");

		CLCD_I2C_SetCursor(LCD_user, 0, 3);
		CLCD_I2C_WriteString(LCD_user,"-Exit");
	}
	else if(status_display == STATUS_3)
	{
		// dislay Select cycle ! Status_Display =2
		CLCD_I2C_SetCursor(LCD_user, 0, 0);
		CLCD_I2C_WriteString(LCD_user,"Enter ur number:");

		CLCD_I2C_SetCursor(LCD_user, 0, 2);
		CLCD_I2C_WriteString(LCD_user,"Password: ");

//		CLCD_I2C_SetCursor(LCD_user, 0, 1);
//		CLCD_I2C_WriteString(LCD_user,"Cycle : ");
//
//		CLCD_I2C_SetCursor(LCD_user, 0, 3);
//		CLCD_I2C_WriteString(LCD_user,"Start");
	}
	else if(status_display == STATUS_4)
	{
		// dislay Until Cut ! Status_Display = 3
		CLCD_I2C_SetCursor(LCD_user, 0, 0);
		CLCD_I2C_WriteString(LCD_user,"Password OKE!");

		CLCD_I2C_SetCursor(LCD_user, 0, 1);
		CLCD_I2C_WriteString(LCD_user,"Wait few ");

		CLCD_I2C_SetCursor(LCD_user, 3, 2);
		CLCD_I2C_WriteString(LCD_user,"minutes...");
	}
	else if(status_display == STATUS_5)
	{
		// dislay Main ! Status_Display = 4
	  CLCD_I2C_SetCursor(LCD_user, 0, 0);
	  CLCD_I2C_WriteString(LCD_user,"Password FAIL!");

	  CLCD_I2C_SetCursor(LCD_user, 0, 1);
	  CLCD_I2C_WriteString(LCD_user,"\"Enter\" to enter");

	  CLCD_I2C_SetCursor(LCD_user, 4, 2);
	  CLCD_I2C_WriteString(LCD_user,"new password :<");
	}
}


