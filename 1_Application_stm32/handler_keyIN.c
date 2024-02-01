/*
 * handler.c
 *
 *  Created on: 31 Jan 2024
 *      Author: BaoThuan
 */

#include <handler_keyIN.h>

uint8_t row_key_num = 1;
uint8_t row_key_password = 9;

STATE_KEY handler_keyIN_enterKey_DisplayLCD(CLCD_I2C_Name* LCD_user, STATE_SELECT_BUTTON_HANDLER_TYPEDEF state_button, char* key, char* password)
{
	  if(*key != KEYPAD_NOT_PRESSED)	//when state_button = KEYPAD
	  {
		  if(enter_num_pass.signal_enter_pass == PROCESSING)	// Được thay đổi trong lcd_user.c
		  {
			  CLCD_I2C_SetCursor(LCD_user, row_key_password, 2);
			  CLCD_I2C_WriteChar(LCD_user, *key);

			  password[row_key_password - 9] = *key;
			  row_key_password++;
			  *key = KEYPAD_NOT_PRESSED;

			  if(row_key_password > SIZE_ROW_PASS)
			  {
//				  enter_num_pass.signal_enter_pass = NOT_DONE;

				  state_button = BUTTON;
				  /*Neu Mang hinh nhap du 5 so*/
				  /*reset mang hinh*/
				  CLCD_I2C_Clear(LCD_user);

				  state_star_pass = STAR;
				  row_key_password = 9;
				  return KEY_OK;
			  }
			  else
			  {
				  return KEY_NOT;
			  }
		  }/*END if(enter_num_pass.signal_enter_pass == PROCESSING)*/
		  else if(enter_num_pass.signal_enter_num == PROCESSING)
		  {
			  CLCD_I2C_SetCursor(LCD_user, row_key_num, 1);
			  CLCD_I2C_WriteChar(LCD_user, *key);

			  password[row_key_num - 1] = *key;
			  row_key_num++;
			  *key = KEYPAD_NOT_PRESSED;

			  if(row_key_num > SIZE_ROW_NUM)
			  {
//				  enter_num_pass.signal_enter_num = NOT_DONE;

				  state_button = BUTTON;
				  /*Neu Mang hinh nhap du 5 so*/
				  /*reset mang hinh*/
				  CLCD_I2C_Clear(LCD_user);

				  state_star_pass = STAR;
				  row_key_num = 1;
				  return KEY_OK;
			  }
			  else
			  {
				  return KEY_NOT;
			  }
		  }/*END if(enter_num_pass.signal_enter_num == PROCESSING)*/
		  else
		  {
			  return KEY_NOT;
		  }
	  }/*END if(*key != KEYPAD_NOT_PRESSED)*/
	  else
	  {
		  return KEY_NOT;
	  }
}
void handler_keyIN_CheckPIN_NUM()
{

}