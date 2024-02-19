/*
 * handler.c
 *
 *  Created on: 31 Jan 2024
 *      Author: BaoThuan
 */

#include <handler_keyIN.h>

static uint8_t row_key_num 			= ROW_BEGIN_KEPAD_NUM;
static uint8_t row_key_password 	= ROW_BEGIN_KEPAD_PASS;

static uint8_t num_ok = 0;
/*test pass*/
//char num1[5] = "111";
//char num2[5] = "111";
//char num3[5] = "111";
//char num4[5] = "111";
//char num5[5] = "111";
//char num6[5] = "111";
//char num7[5] = "111";

//char* jagged_num[7] = { num1, num2, num3, num4, num5, num6, num7 };

char stt1 = '1';
char stt2 = '1';
char stt3 = '1';
char stt4 = '1';
char stt5 = '1';
char stt6 = '1';
char stt7 = '1';


char* jagged_num[7] = { &stt1, &stt2, &stt3, &stt4, &stt5, &stt6, &stt7 };



char pass1[5] = "54321";
char pass2[5] = "54321";
char pass3[5] = "54321";
char pass4[5] = "54321";
char pass5[5] = "54321";
char pass6[5] = "54321";
char pass7[5] = "54321";


char* jagged_pass[7] = { pass1, pass2, pass3, pass4, pass5, pass6, pass7 };




STATE_KEY handler_keyIN_enterKey_DisplayLCD(CLCD_I2C_Name* LCD_user, STATE_SELECT_BUTTON_HANDLER_TYPEDEF state_button, char* key, char* password)
{
	  if(*key != KEYPAD_NOT_PRESSED)	//when state_button = KEYPAD
	  {
		  if(enter_num_pass.signal_enter_pass == PROCESSING)	// Được thay đổi trong lcd_user.c
		  {
			  CLCD_I2C_SetCursor(LCD_user, row_key_password, 2);
			  CLCD_I2C_WriteChar(LCD_user, *key);

			  password[row_key_password - ROW_BEGIN_KEPAD_PASS] = *key;
			  row_key_password++;
			  *key = KEYPAD_NOT_PRESSED;

			  if(row_key_password > SIZE_ROW_PASS)
			  {
				  state_button = BUTTON;
				  /*Neu Mang hinh nhap du 5 so*/
				  /*reset mang hinh*/
				  CLCD_I2C_Clear(LCD_user);

				  state_star_pass = STAR;
				  row_key_password = ROW_BEGIN_KEPAD_PASS;
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

			  password[row_key_num - ROW_BEGIN_KEPAD_NUM] = *key;
			  row_key_num++;
			  *key = KEYPAD_NOT_PRESSED;

			  if(row_key_num > SIZE_ROW_NUM)
			  {
				  state_button = BUTTON;
				  /*Neu Mang hinh nhap du 5 so*/
				  /*reset mang hinh*/
				  CLCD_I2C_Clear(LCD_user);

				  state_star_pass = STAR;
				  row_key_num = ROW_BEGIN_KEPAD_NUM;
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



void handler_keyIN_CheckPIN_NUM(char * num_pin_buffer)
{
	static uint8_t counter = 0;
	if(enter_num_pass.signal_enter_num == PROCESSING)
	{
		counter = 0;
		num_ok = 0;
		enter_num_pass.signal_enter_num = NOT_DONE;
		for(uint8_t j = 0; j < 7; j++)
		{
			if(strstr(num_pin_buffer, jagged_num[j]) != NULL)
			{
				num_ok = j;
				counter++;
			}
		}
		if(counter == 0)
		{
			num_ok = 0;
		}
	}
	else if(enter_num_pass.signal_enter_pass == PROCESSING && counter != 0)
	{
		enter_num_pass.signal_enter_pass = NOT_DONE;
		if(strstr(num_pin_buffer, jagged_pass[num_ok]) != NULL)
		{
			Index_mode = INDEX_MODE_OKE_PASS;
		}
		else
		{
			Index_mode = INDEX_MODE_NO_OKE_PASS;
		}
	}
	else
	{
		enter_num_pass.signal_enter_num = NOT_DONE;
		enter_num_pass.signal_enter_pass = NOT_DONE;
		Index_mode = INDEX_MODE_NO_OKE_PASS;
	}
	/*Reset*/
	for(uint8_t i = 0; i < sizeof(num_pin_buffer); i++)
	{
		num_pin_buffer[i] = 0;
	}
}
