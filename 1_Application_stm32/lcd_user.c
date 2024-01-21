/*
 * lcd_user.c
 *
 *  Created on: Jan 16, 2024
 *      Author: BaoThuan
 */

#include<lcd_user.h>

static uint8_t delete = 0;
volatile uint8_t Mode = 0;

volatile STATUS_CONFIG_TYPEDEF Config = CONFIG_ROW1;

volatile uint8_t Enter = 0;
volatile uint8_t flag_button = 0;
static INDEX_MODE_TYPEDEF Index_mode = 0;
static uint8_t Status_Display = 0;
static LANGUAGE_TYPEDEF language = VIETNAMESE;

static void lcd_user_display(CLCD_I2C_Name* LCD_user, STATUS_DISPLAY_TYPEDEF status_display)
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

		CLCD_I2C_SetCursor(LCD_user, 0, 3);
		CLCD_I2C_WriteString(LCD_user,"Exit");
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
	else if(status_display == STATUS_6)
	{
		// dislay Main ! Status_Display = 4
		CLCD_I2C_SetCursor(LCD_user, 3, 0);
		CLCD_I2C_WriteString(LCD_user,"Language");

	  CLCD_I2C_SetCursor(LCD_user, 0, 1);
	  CLCD_I2C_WriteString(LCD_user,"-VietNamese");

	  CLCD_I2C_SetCursor(LCD_user, 0, 2);
	  CLCD_I2C_WriteString(LCD_user,"-English");

	  CLCD_I2C_SetCursor(LCD_user, 0, 3);
	  CLCD_I2C_WriteString(LCD_user,"-EXIT");
	}
	else if(status_display == STATUS_7)
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

void lcd_system_handler(CLCD_I2C_Name* LCD_user)
{
	if(delete)
	{
		CLCD_I2C_Clear(LCD_user);
		delete = 0;
	}
	if(Mode == 0)
	{
		Config = CONFIG_NONE;
		Enter = 0;
		Status_Display = STATUS_1;
		lcd_user_display(LCD_user, Status_Display);
		Index_mode = INDEX_MODE_NONE;
	}
	else if(Mode == 1)
	{
		if(Index_mode == INDEX_MODE_NONE)
		{
//			Config = CONFIG_ROW1;
			if (flag_button)
			{
				CLCD_I2C_Clear(LCD_user);
				flag_button = 0;
			}
			Status_Display = STATUS_2;
			if(Config != CONFIG_NONE)
			{
				CLCD_I2C_SetCursor(LCD_user, 15, Config);
				CLCD_I2C_WriteString(LCD_user, "<");
				if(Enter)
				{
					Enter = 0;
					if(Config == CONFIG_ROW1)
                    {
                        Index_mode = INDEX_MODE1;
                        Config = CONFIG_ROW1;
                        delete = 1;
                    }
					if(Config == CONFIG_ROW2)
                    {
                        Index_mode = INDEX_MODE2;
                        Config = CONFIG_ROW1;
                        delete = 1;
                    }
					if(Config == CONFIG_ROW3)
                    {
                        Index_mode = INDEX_MODE1;
                        Mode = 0;
                        Config = CONFIG_NONE;
                        Status_Display = STATUS_1;
                        delete = 1;
                    }
				} /*END if(Enter)*/
			}
			else
			{
				Config = CONFIG_ROW1;
				Enter = 0;
			}
			lcd_user_display(LCD_user, Status_Display);
		} /*END if(Index_mode == INDEX_MODE_NONE)*/
		else if(INDEX_MODE1 == Index_mode)	// Languge
		{
			Status_Display = STATUS_6;
			lcd_user_display(LCD_user, Status_Display);
			if (flag_button)
			{
				CLCD_I2C_Clear(LCD_user);
				flag_button = 0;
			}
			if(Config != CONFIG_NONE)
			{
				CLCD_I2C_SetCursor(LCD_user, 15, Config);
				CLCD_I2C_WriteString(LCD_user, "<");
				if(Enter)
				{
					Enter = 0;
					if(Config == CONFIG_ROW1)
                    {
						language = VIETNAMESE;
						Config = CONFIG_ROW3;
                    }
					if(Config == CONFIG_ROW2)
                    {
						language = ENGLISH;
						Config = CONFIG_ROW3;
                    }
					if(Config == CONFIG_ROW3)
                    {
                        Index_mode = INDEX_MODE_NONE;
//                        Mode = 0;
                        Config = CONFIG_NONE;
                        Status_Display = STATUS_2;
                        delete = 1;
                    }
				} /*END if(Enter)*/
			}
			else
			{
				Config = CONFIG_ROW1;
				Enter = 0;
			}
			lcd_user_display(LCD_user, Status_Display);
		} /*END if(Index_mode == INDEX_MODE1)*/
		else if(INDEX_MODE2 == Index_mode)	// Enter Password
		{
			Status_Display = STATUS_3;
			lcd_user_display(LCD_user, Status_Display);
			if (flag_button)
			{
				CLCD_I2C_Clear(LCD_user);
				flag_button = 0;
			}
			if(Config != CONFIG_NONE)
			{
				CLCD_I2C_SetCursor(LCD_user, 15, Config);
				CLCD_I2C_WriteString(LCD_user, "<");
				if(Enter)
				{
					Enter = 0;
					if(Config == CONFIG_ROW1)
                    {


                    }
					if(Config == CONFIG_ROW2)
                    {


                    }
					if(Config == CONFIG_ROW3)
                    {
                        Index_mode = INDEX_MODE_NONE;
//                        Mode = 0;
                        Config = CONFIG_NONE;
                        Status_Display = STATUS_2;
                        delete = 1;
                    }
				} /*END if(Enter)*/
			}
			else
			{
				Config = CONFIG_ROW1;
				Enter = 0;
			}
			lcd_user_display(LCD_user, Status_Display);
		} /*END if(Index_mode == INDEX_MODE2)*/
	}/*END if(Mode == 1)*/
}

void lcd_reset_display()
{

}
void lcd_display_EnterCheck_password()
{

}
void lcd_display_EnterCheck_number()
{

}
