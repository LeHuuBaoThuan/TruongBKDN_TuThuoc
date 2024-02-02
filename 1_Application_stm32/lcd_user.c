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

enter_num_pass_typedef enter_num_pass = {NOT_DONE, NOT_DONE};
STATE_SCREEN_STAR_PASS_TYPEDEF state_star_pass = STAR;
INDEX_MODE_TYPEDEF Index_mode = 0;

static uint8_t Status_Display = 0;
static LANGUAGE_TYPEDEF language = VIETNAMESE;
//==============================================================================================================================================================
/* <function summary decription>
  +) NOTE:
    -Hiển thị các khung hình hiển thị trên màn hình LCD
  +) PARAM:
    -CLCD_I2C_Name* LCD_user                       : CLCD_I2C_Name
    -STATUS_DISPLAY_TYPEDEF status_display         : STATUS_1 -> STATUS_7
  +) RETURN:
    -void
*/
void lcd_user_display(CLCD_I2C_Name* LCD_user, STATUS_DISPLAY_TYPEDEF status_display)
{
	if(language == ENGLISH)
	{
		if(status_display == STATUS_1)
			{
				// dislay hello ! Status_Display=0
				CLCD_I2C_SetCursor(LCD_user, 0, 0);
				CLCD_I2C_WriteString(LCD_user,"TRUONG DHBK-DHDN");

				CLCD_I2C_SetCursor(LCD_user, 4, 1);
				CLCD_I2C_WriteString(LCD_user,"SV-NV-KH");

				CLCD_I2C_SetCursor(LCD_user, 4, 2);
				CLCD_I2C_WriteString(LCD_user,"TU THUOC");

				CLCD_I2C_SetCursor(LCD_user, 2, 3);
				CLCD_I2C_WriteString(LCD_user,"Press \"Enter\"!");
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
			else if(status_display == STATUS_3)							// PASSWORD
			{
				CLCD_I2C_SetCursor(LCD_user, 0, 0);
				CLCD_I2C_WriteString(LCD_user,"Information:");
				// dislay Select cycle ! Status_Display =2
				CLCD_I2C_SetCursor(LCD_user, 0, 1);
				CLCD_I2C_WriteString(LCD_user,"-NUM:");
				if(state_star_pass == STAR)
				{
					CLCD_I2C_SetCursor(LCD_user, ROW_BEGIN_KEPAD_NUM - 1, 1);
					CLCD_I2C_WriteString(LCD_user,">***");
				}
				else
				{
					CLCD_I2C_SetCursor(LCD_user, ROW_BEGIN_KEPAD_NUM - 1, 1);
					CLCD_I2C_WriteString(LCD_user,">");
				}

				CLCD_I2C_SetCursor(LCD_user, 0, 2);
				CLCD_I2C_WriteString(LCD_user,"-PIN: ");
				if(state_star_pass == STAR)
				{
					CLCD_I2C_SetCursor(LCD_user, ROW_BEGIN_KEPAD_PASS - 1, 2);
					CLCD_I2C_WriteString(LCD_user,">*****");
				}
				else
				{
					CLCD_I2C_SetCursor(LCD_user, ROW_BEGIN_KEPAD_PASS - 1, 2);
					CLCD_I2C_WriteString(LCD_user,">");
				}

				CLCD_I2C_SetCursor(LCD_user, 0, 3);
				CLCD_I2C_WriteString(LCD_user,"-Exit");
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
	}/*END if(language == ENGLISH)*/
	else if(language == VIETNAMESE)
	{
		if(status_display == STATUS_1)
		{
			// dislay hello ! Status_Display=0
			CLCD_I2C_SetCursor(LCD_user, 0, 0);
			CLCD_I2C_WriteString(LCD_user,"TRUONG DHBK-DHDN");

			CLCD_I2C_SetCursor(LCD_user, 4, 1);
			CLCD_I2C_WriteString(LCD_user,"SV-NV-KH");

			CLCD_I2C_SetCursor(LCD_user, 4, 2);
			CLCD_I2C_WriteString(LCD_user,"TU THUOC");

			CLCD_I2C_SetCursor(LCD_user, 2, 3);
			CLCD_I2C_WriteString(LCD_user,"Nhan \"Enter\"!");
		}
		else if(status_display == STATUS_2)
		{
			// dislay Select Mode ! Status_Display=1
			CLCD_I2C_SetCursor(LCD_user, 0, 0);
			CLCD_I2C_WriteString(LCD_user,"Lua chon che do:");

			CLCD_I2C_SetCursor(LCD_user, 0, 1);
			CLCD_I2C_WriteString(LCD_user,"-Ngon ngu");

			CLCD_I2C_SetCursor(LCD_user, 0, 2);
			CLCD_I2C_WriteString(LCD_user,"-Nhap ma pin");

			CLCD_I2C_SetCursor(LCD_user, 0, 3);
			CLCD_I2C_WriteString(LCD_user,"-Thoat");
		}
		else if(status_display == STATUS_3)										//PASSWORD
		{
			CLCD_I2C_SetCursor(LCD_user, 0, 0);
			CLCD_I2C_WriteString(LCD_user,"TT benh nhan:");
			// dislay Select cycle ! Status_Display =2
			CLCD_I2C_SetCursor(LCD_user, 0, 1);
			CLCD_I2C_WriteString(LCD_user,"-STT:");
			if(state_star_pass == STAR)
			{
				CLCD_I2C_SetCursor(LCD_user, ROW_BEGIN_KEPAD_NUM - 1, 1);
				CLCD_I2C_WriteString(LCD_user,">***");
			}
			else
			{
				CLCD_I2C_SetCursor(LCD_user, ROW_BEGIN_KEPAD_NUM - 1, 1);
				CLCD_I2C_WriteString(LCD_user,">");
			}
			CLCD_I2C_SetCursor(LCD_user, 0, 2);
			CLCD_I2C_WriteString(LCD_user,"-PIN: ");
			if(state_star_pass == STAR)
			{
				CLCD_I2C_SetCursor(LCD_user, ROW_BEGIN_KEPAD_PASS - 1, 2);
				CLCD_I2C_WriteString(LCD_user,">*****");
			}
			else
			{
				CLCD_I2C_SetCursor(LCD_user, ROW_BEGIN_KEPAD_PASS - 1, 2);
				CLCD_I2C_WriteString(LCD_user,">");
			}

			CLCD_I2C_SetCursor(LCD_user, 0, 3);
			CLCD_I2C_WriteString(LCD_user,"-Thoat");
		}
		else if(status_display == STATUS_4)
		{
			// dislay Until Cut ! Status_Display = 3
			CLCD_I2C_SetCursor(LCD_user, 0, 0);
			CLCD_I2C_WriteString(LCD_user,"PIN OKE!");

			CLCD_I2C_SetCursor(LCD_user, 0, 1);
			CLCD_I2C_WriteString(LCD_user,"Cho");

			CLCD_I2C_SetCursor(LCD_user, 3, 2);
			CLCD_I2C_WriteString(LCD_user,"1 phut...");
		}
		else if(status_display == STATUS_5)
		{
			// dislay Main ! Status_Display = 4
		  CLCD_I2C_SetCursor(LCD_user, 0, 0);
		  CLCD_I2C_WriteString(LCD_user,"PIN sai!");

		  CLCD_I2C_SetCursor(LCD_user, 0, 1);
		  CLCD_I2C_WriteString(LCD_user,"\"Nhap\" de nhap");

		  CLCD_I2C_SetCursor(LCD_user, 4, 2);
		  CLCD_I2C_WriteString(LCD_user,"PIN moi :<");
		}
		else if(status_display == STATUS_6)
		{
			// dislay Main ! Status_Display = 4
			CLCD_I2C_SetCursor(LCD_user, 3, 0);
			CLCD_I2C_WriteString(LCD_user,"Ngon ngu");

			CLCD_I2C_SetCursor(LCD_user, 0, 1);
			CLCD_I2C_WriteString(LCD_user,"-VietNamese");

			CLCD_I2C_SetCursor(LCD_user, 0, 2);
			CLCD_I2C_WriteString(LCD_user,"-English");

			CLCD_I2C_SetCursor(LCD_user, 0, 3);
			CLCD_I2C_WriteString(LCD_user,"-EXIT");
		}
	}/*END if(language == ENGLISH)*/

}
//==============================================================================================================================================================
/* <function summary decription>
  +) NOTE:
    -Hàm xử lý chính trên màng hình LCD
    	+Chọn khung hình cần hiển thị
    	+Nhập mật khẩu
  +) PARAM:
    -CLCD_I2C_Name* LCD_user            : pointer lcd
  +) RETURN:
    -void
*/
void lcd_system_handler(CLCD_I2C_Name* LCD_user)
{
	if(delete)
	{
		CLCD_I2C_Clear(LCD_user);
		delete = 0;
	}
	if(Mode == 0)												//Begin
	{
		Config = CONFIG_ROW0;
		Enter = 0;
		Status_Display = STATUS_1;
		lcd_user_display(LCD_user, Status_Display);
		Index_mode = INDEX_MODE_NONE;
	}
	else if(Mode == 1)
	{
		if(Index_mode == INDEX_MODE_NONE)						//  Select modes
		{
//			Config = CONFIG_ROW1;
			if (flag_button)
			{
				CLCD_I2C_Clear(LCD_user);
				flag_button = 0;
			}
			Status_Display = STATUS_2;
			if(Config != CONFIG_ROW0)
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
                        Config = CONFIG_ROW0;
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
		else if(INDEX_MODE1 == Index_mode)					// Languge
		{
			Status_Display = STATUS_6;
			lcd_user_display(LCD_user, Status_Display);
			if (flag_button)
			{
				CLCD_I2C_Clear(LCD_user);
				flag_button = 0;
			}
			if(Config != CONFIG_ROW0)
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
                        Config = CONFIG_ROW0;
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
		else if(INDEX_MODE2 == Index_mode)						// Enter Password
		{
			Status_Display = STATUS_3;
			lcd_user_display(LCD_user, Status_Display);
			if (flag_button)
			{
				CLCD_I2C_Clear(LCD_user);
				flag_button = 0;
			}
			if(Config != CONFIG_ROW0)
			{
				CLCD_I2C_SetCursor(LCD_user, 15, Config);
				CLCD_I2C_WriteString(LCD_user, "<");
				if(Enter)
				{
					Enter = 0;
					if(Config == CONFIG_ROW1)	// Nhap so thu tu
					{
						enter_num_pass.signal_enter_num = PROCESSING;
					}
					if(Config == CONFIG_ROW2)	// Nhap pass
					{
						enter_num_pass.signal_enter_pass = PROCESSING;
					}
					if(Config == CONFIG_ROW3)
					{
						Index_mode = INDEX_MODE_NONE;
	//                        Mode = 0;
						Config = CONFIG_ROW0;
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
		else if(INDEX_MODE_OKE_PASS == Index_mode)					// Pass oke
		{
			Status_Display = STATUS_4;
			lcd_user_display(LCD_user, Status_Display);
			if(Enter)
            {
				Enter = 0;
                Index_mode = INDEX_MODE_NONE;
                Config = CONFIG_ROW0;
                Status_Display = STATUS_2;
                delete = 1;
            }
		}
		else if(INDEX_MODE_NO_OKE_PASS == Index_mode)				// Pass fail
		{
			Status_Display = STATUS_5;
			lcd_user_display(LCD_user, Status_Display);
			if(Enter)
            {
				Enter = 0;
                Index_mode = INDEX_MODE2;
                Config = CONFIG_ROW0;
                Status_Display = STATUS_3;
                delete = 1;
            }
		}
	}/*END if(Mode == 1)*/
}
