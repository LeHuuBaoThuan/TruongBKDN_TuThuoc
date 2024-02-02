/*
 * lcd_user.h
 *
 *  Created on: Jan 16, 2024
 *      Author: BaoThuan
 */

#ifndef _LCD_USER_H_
#define _LCD_USER_H_

#include "i2c-lcd.h"

#define ROW_BEGIN_KEPAD_NUM		9
#define ROW_BEGIN_KEPAD_PASS 	9
typedef enum
{
	STATUS_1 = 1,
	STATUS_2 = 2,
	STATUS_3 = 3,
	STATUS_4 = 4,
	STATUS_5 = 5,
	STATUS_6 = 6,
	STATUS_7 = 7
} STATUS_DISPLAY_TYPEDEF;

typedef enum
{
	CONFIG_ROW0 = 0,
	CONFIG_ROW1 = 1,
	CONFIG_ROW2 = 2,
	CONFIG_ROW3 = 3,
	CONFIG_ERROR = -1
} STATUS_CONFIG_TYPEDEF;

typedef enum
{
	INDEX_MODE_NONE = 0,
	INDEX_MODE1 = 1,
	INDEX_MODE2 = 2,
	INDEX_MODE3 = 3,
	INDEX_MODE_OKE_PASS = 4,
	INDEX_MODE_NO_OKE_PASS
} INDEX_MODE_TYPEDEF;

typedef enum
{
	VIETNAMESE = 0,
	ENGLISH = 1
} LANGUAGE_TYPEDEF;

enum
{
	PROCESSING = 0,
	NOT_DONE = 1
};

typedef enum
{
	STAR = 0,
	NONE_STAR = 1
} STATE_SCREEN_STAR_PASS_TYPEDEF;

typedef struct
{
	uint8_t signal_enter_pass;
	uint8_t signal_enter_num;
} enter_num_pass_typedef;


extern volatile STATUS_CONFIG_TYPEDEF Config;							// Điểu chỉnh "<" lên xuống để chọn chế độ thao tác
extern volatile uint8_t Enter;											// Chọn chế độ
extern volatile uint8_t flag_button;									// Biết nút có được nhấn hay chưa?
extern volatile uint8_t Mode;											// giao diện chính mode = 0

extern STATE_SCREEN_STAR_PASS_TYPEDEF state_star_pass;					// Dấu sao ko được hiển thị chòng khi đang nhập mk
extern enter_num_pass_typedef enter_num_pass;							// Cờ được bật khi chọn 1 trong 2 lựa chọn nhập mk, num

extern INDEX_MODE_TYPEDEF Index_mode;									// Lựa chọn khung màng hình hiển thị và thao tác trên đó

void lcd_user_display(CLCD_I2C_Name* LCD_user, STATUS_DISPLAY_TYPEDEF status_display);
void lcd_system_handler(CLCD_I2C_Name* LCD_user);

#endif /* _LCD_USER_H_ */
