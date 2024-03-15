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

typedef enum
{
	KEY_OK = 1,
	KEY_NOT = 0
} STATE_KEY;

typedef enum
{
	NUM_OKE,
	NUM_NONE,
	PASS_OKE,
	PASS_NONE,
	NUM_PASS_NONE
} STATE_HANDLER;

#define SIZE_ROW_NUM 	ROW_BEGIN_KEPAD_NUM + 1 - 1				// Cột đầu tiên nhập num: ROW_BEGIN_KEPAD_NUM + so luong NUM duoc dien vao
#define SIZE_ROW_PASS 	ROW_BEGIN_KEPAD_PASS + 5 - 1			// Cột đâu tiên nhập pass: ROW_BEGIN_KEPAD_PASS + so luong PASS duoc dien vao


extern char* jagged_pass[7];
extern STATE_HANDLER state_hand;
extern uint8_t num_set_fet;

//==============================================================================================================================================================
/* <function summary decription>
  +) NOTE:
    - Hàm để nhận pass/ num và xuất ra màng hình LCD
    - lưu pass được nhập vào 5 phần tử của mảng password, 3 phần tử của num được lưu vào password.
    - Trả về trạng thái đã nhập đủ ký tự hay chưa?
  +) PARAM:
    - CLCD_I2C_Name* LCD_user                      		: Thông số LCD
    - STATE_SELECT_BUTTON_HANDLER_TYPEDEF state_button  : BUTTON/KEYPAD
    - char* password									:
  +) RETURN:
    - KEY_NOT	                                : Ký tự chưa nhập đủ, nhập thêm
    - KEY_OK                               		: Ký tự nhập vào đã đủ 3 cho num, 5 cho pin
*/
STATE_KEY handler_keyIN_enterKey_DisplayLCD(CLCD_I2C_Name* LCD_user, STATE_SELECT_BUTTON_HANDLER_TYPEDEF state_button, char *key, char* password);




//==============================================================================================================================================================
/* <function summary decription>
  +) NOTE:
    - Kiểm tra num/pass và trả về khung hình OKE, Fail
  +) PARAM:
    -char * password                       : key được nhập từ bàn phiếm khi được báo nhập đủ
    -num								   : con trỏ trỏ đến vị trí của num_set_fet để điều khiển fet khi nhập đúng mã
  +) RETURN:
	-NUM_OKE,                              : none
	-NUM_NONE,                             : none
	-PASS_OKE,                             : Chạy thuốc
	-PASS_NONE,                            : none
	-NUM_PASS_NONE                         : none
*/
STATE_HANDLER handler_keyIN_CheckPIN_NUM(char * password, uint8_t* num);
#endif /* _HANDLER_KEYIN_H_ */
