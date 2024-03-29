/*
 * lcd_user.h
 *
 *  Created on: Jan 16, 2024
 *      Author: BaoThuan
 */

#ifndef _LCD_USER_H_
#define _LCD_USER_H_

#include "i2c-lcd.h"

/**
 * @brief  Hàng con trỏ trỏ đến chức năng được chọn
 */
typedef enum
{
	CONFIG_ROW0 = 0,
	CONFIG_ROW1 = 1,
	CONFIG_ROW2 = 2,
	CONFIG_ROW3 = 3,
	CONFIG_ERROR = -1
} STATUS_CONFIG_TYPEDEF;

/**
 * @brief  Các thao tác trên khung hình bao gồm hiển thị khung hình, chọn chức năng cần thao tác
 */
typedef enum
{
	INDEX_MODE_MENU = 0,
	INDEX_MODE_LANGUAGE = 1,
	INDEX_MODE_PIN = 2,
	INDEX_MODE_OKE_PASS = 3,
	INDEX_MODE_NO_OKE_PASS
} INDEX_MODE_TYPEDEF;

/**
 * @brief  Chọn hay không chọn?
 */
enum
{
	PROCESSING = 0,
	NOT_DONE = 1
};

/**
 * @brief  Khi nhập pin/num thì không hiển thị chồng các dấu "*"
 */
typedef enum
{
	STAR = 0,
	NONE_STAR = 1
} STATE_SCREEN_STAR_PASS_TYPEDEF;


/**
 * @brief  Ấn hay không ấn pass/num
 */
typedef struct
{
	uint8_t signal_enter_pass;
	uint8_t signal_enter_num;
} enter_num_pass_typedef;


#define ROW_BEGIN_KEPAD_NUM		9		// Cột bắt đầu ghi NUM
#define ROW_BEGIN_KEPAD_PASS 	9		// Cột bắt đầu ghi mã pin

/*Biến được gọi trong ngắt nút nhấn (hàm main)*/
extern volatile STATUS_CONFIG_TYPEDEF Config;							// Điểu chỉnh "<" lên xuống để chọn chế độ thao tác
extern volatile uint8_t Enter;											// Chọn chế độ
extern volatile uint8_t flag_button;									// Biết nút có được nhấn hay chưa?
extern volatile uint8_t Mode;											// giao diện chính mode = 0


extern STATE_SCREEN_STAR_PASS_TYPEDEF state_star_pass;					// Dấu sao ko được hiển thị chòng khi đang nhập mk
extern enter_num_pass_typedef enter_num_pass;							// Cờ được bật khi chọn 1 trong 2 lựa chọn nhập mk, num

extern INDEX_MODE_TYPEDEF Index_mode;									// Lựa chọn khung màng hình hiển thị và thao tác trên đó


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
void lcd_system_handler(CLCD_I2C_Name* LCD_user);

#endif /* _LCD_USER_H_ */
