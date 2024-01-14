#include "KeyPad.h"

#define _KEYPAD_DELAY(x)      		HAL_Delay(x)

GPIO_COLUMN_TYPEDEF 	COL_KEY_PAD; //INPUT
GPIO_ROW_TYPEDEF 		ROW_KEY_PAD; //OUTPUT

KeyPad_t	KeyPad;

/* Keypad Button Values*/
const char Keypad_Button_Values[4][4] =  {    {'1', '2', '3', 'A'},
											  {'4', '5', '6', 'B'},
											  {'7', '8', '9', 'C'},
											  {'*', '0', '#', 'D'},
                                         };
static uint32_t TimeBegin = 0;
static uint32_t TimeNow = 0;

void KeyPad_Init(	uint8_t sizeColumn, uint8_t sizeRow,\
					GPIO_TypeDef* C_port0, GPIO_TypeDef* C_port1, GPIO_TypeDef* C_port2, GPIO_TypeDef* C_port3,\
					uint16_t C_pin0, uint16_t C_pin1, uint16_t C_pin2, uint16_t C_pin3,\
					GPIO_TypeDef* R_port0, GPIO_TypeDef* R_port1, GPIO_TypeDef* R_port2, GPIO_TypeDef* R_port3,\
					uint16_t R_pin0, uint16_t R_pin1, uint16_t R_pin2, uint16_t R_pin3)
{
  KeyPad.ColumnSize = sizeColumn / 2;
  KeyPad.RowSize = sizeRow / 2;

  COL_KEY_PAD.PORT.GPIO0 = C_port0;
  COL_KEY_PAD.PORT.GPIO1 = C_port1;
  COL_KEY_PAD.PORT.GPIO2 = C_port2;
  COL_KEY_PAD.PORT.GPIO3 = C_port3;

  COL_KEY_PAD.PIN.GPIO_PIN_A = C_pin0;
  COL_KEY_PAD.PIN.GPIO_PIN_B = C_pin1;
  COL_KEY_PAD.PIN.GPIO_PIN_C = C_pin2;
  COL_KEY_PAD.PIN.GPIO_PIN_D = C_pin3;

  ROW_KEY_PAD.PORT.GPIO0 = R_port0;
  ROW_KEY_PAD.PORT.GPIO1 = R_port1;
  ROW_KEY_PAD.PORT.GPIO2 = R_port2;
  ROW_KEY_PAD.PORT.GPIO3 = R_port3;

  ROW_KEY_PAD.PIN.GPIO_PIN_A = R_pin0;
  ROW_KEY_PAD.PIN.GPIO_PIN_B = R_pin1;
  ROW_KEY_PAD.PIN.GPIO_PIN_C = R_pin2;
  ROW_KEY_PAD.PIN.GPIO_PIN_D = R_pin3;
}
/*For specific row value sent , check all the cloumns*/
static char Check_Keypad_Column(uint8_t Row)
{
	if(!HAL_GPIO_ReadPin(COL_KEY_PAD.PORT.GPIO0, COL_KEY_PAD.PIN.GPIO_PIN_A)) //If COLUMN_1 is LOW
	{
		return Keypad_Button_Values[Row-1][0];
	}

	if(!HAL_GPIO_ReadPin(COL_KEY_PAD.PORT.GPIO1, COL_KEY_PAD.PIN.GPIO_PIN_B)) //If COLUMN_2 is LOW
	{
		return Keypad_Button_Values[Row-1][1];
	}

    if(!HAL_GPIO_ReadPin(COL_KEY_PAD.PORT.GPIO2, COL_KEY_PAD.PIN.GPIO_PIN_C)) //If COLUMN_3 is LOW
	{
		return Keypad_Button_Values[Row-1][2];
	}

	if(!HAL_GPIO_ReadPin(COL_KEY_PAD.PORT.GPIO3, COL_KEY_PAD.PIN.GPIO_PIN_D)) //If COLUMN_4 is LOW
	{
		return Keypad_Button_Values[Row-1][3];
	}
	HAL_Delay(70);
	TimeBegin = HAL_GetTick();
	while((!HAL_GPIO_ReadPin(COL_KEY_PAD.PORT.GPIO0, COL_KEY_PAD.PIN.GPIO_PIN_A)) | (!HAL_GPIO_ReadPin(COL_KEY_PAD.PORT.GPIO1, COL_KEY_PAD.PIN.GPIO_PIN_B)) |	\
		  (!HAL_GPIO_ReadPin(COL_KEY_PAD.PORT.GPIO2, COL_KEY_PAD.PIN.GPIO_PIN_C)) | (!HAL_GPIO_ReadPin(COL_KEY_PAD.PORT.GPIO3, COL_KEY_PAD.PIN.GPIO_PIN_D)))
	{
		TimeNow = HAL_GetTick();
		if(TimeNow - TimeBegin >= 3000)
		{
//			ButtonError = 1;
			break;
		}
	}
	HAL_Delay(70);
	return KEYPAD_NOT_PRESSED;                   //If NO Key is pressed
}
/* Read the keypad */
char KEYPAD_Read(void)
{
    char check = 0;
    /*Set ROW_1 LOW and scan all the columns*/
    HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO0, ROW_KEY_PAD.PIN.GPIO_PIN_A, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO1, ROW_KEY_PAD.PIN.GPIO_PIN_B, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO2, ROW_KEY_PAD.PIN.GPIO_PIN_C, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO3, ROW_KEY_PAD.PIN.GPIO_PIN_D, GPIO_PIN_SET);
    check = Check_Keypad_Column(1);
    if(check)
    	return check;

    /*Set ROW_2 LOW and scan all the columns*/
    HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO0, ROW_KEY_PAD.PIN.GPIO_PIN_A, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO1, ROW_KEY_PAD.PIN.GPIO_PIN_B, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO2, ROW_KEY_PAD.PIN.GPIO_PIN_C, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO3, ROW_KEY_PAD.PIN.GPIO_PIN_D, GPIO_PIN_SET);
    check = Check_Keypad_Column(2);
    if(check)
    	return check;
    /*Set ROW_3 LOW and scan all the columns*/
    HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO0, ROW_KEY_PAD.PIN.GPIO_PIN_A, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO1, ROW_KEY_PAD.PIN.GPIO_PIN_B, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO2, ROW_KEY_PAD.PIN.GPIO_PIN_C, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO3, ROW_KEY_PAD.PIN.GPIO_PIN_D, GPIO_PIN_SET);
    check = Check_Keypad_Column(3);
    if(check)
    	return check;
    /*Set ROW_4 LOW and scan all the columns*/
    HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO0, ROW_KEY_PAD.PIN.GPIO_PIN_A, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO1, ROW_KEY_PAD.PIN.GPIO_PIN_B, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO2, ROW_KEY_PAD.PIN.GPIO_PIN_C, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW_KEY_PAD.PORT.GPIO3, ROW_KEY_PAD.PIN.GPIO_PIN_D, GPIO_PIN_RESET);
    check = Check_Keypad_Column(4);
    if(check)
    	return check;
    /*Key not pressed */
    return KEYPAD_NOT_PRESSED;
}
