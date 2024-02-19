/*
 * uart_user.c
 *
 *  Created on: Feb 8, 2024
 *      Author: BaoThuan
 */

#include<uart_user.h>

static UART_HandleTypeDef Lib_uart;
static const char * confirm_NUM_PIN = "*NUM-PIN:";
static uint8_t num = 0;
static uint8_t pin[5] = {0};

//************************** LOW Level Function ****************************************************************//

/* <function summary decription>
  +) NOTE:
    -Truyen vao voi param:
    	*NUM:x, PIN:abcde\n\r
  +) PARAM:
    -uint8_t * rxBuffer								: value frome EXTI uart
  +) RETURN:
    -bool											: true
    												  false
*/
static bool UART_Check_string(uint8_t * rxBuffer)
{
	if(strstr((char*)rxBuffer, confirm_NUM_PIN) != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}



/* <function summary decription>
  +) NOTE:
    -Tac PIN va num tu chuoi da nhan:
    	*NUM-PIN:x,abcde\n\r
  +) PARAM:
    -uint8_t * rxBuffer								: value frome EXTI uart
  +) RETURN:
    -void
*/
static void UART_SetNUM_PIN(uint8_t * rxBuffer)
{
   /* Kiểm tra độ dài của command "*NUM-PIN:x,abcde\n\r"*/
   if(strlen((char*)rxBuffer) == 17)
   {
      /*Tách NUM thiết bị */
      char *token = NULL;
      token = strtok((char*)rxBuffer, ":"); //*NUM-PIN:
      token = strtok(NULL, ","); //x
      num = *token - 48; //num = x


      /*Tách PIN thiết bị */
      token = strtok(NULL, "\n"); //abcde
      memcpy(pin, token, 5); //pin = abcde;

      token = NULL;

//      response("\r\n+OK\r\n ");
   }
   else
   {
//      response("\r\n+ERROR:error command\r\n");
   }
}



/* <function summary decription>
  +) NOTE:
    -Gan vao Array extern ben handler_keyIN.h
    	*NUM-PIN:x,abcde\n\r
  +) PARAM:
    -uint8_t * rxBuffer								: value frome EXTI uart
  +) RETURN:
    -void
*/
static void UART_Assign_password()
{
	for(uint8_t i = 0; i <= sizeof(jagged_pass[num - 48]); i++)
	{
		*(jagged_pass[num - 48] + i) = pin[0];
	}
}



//************************** High Level Function ****************************************************************//
void UART_Init_UART(UART_HandleTypeDef *huart)
{
	Lib_uart = *huart;
}



STATE_TX_PIN UART_handler(uint8_t * rxBuffer, char* NUM, char* PIN)
{
	if(UART_Check_string(rxBuffer) == true)	// Kiem tra chuoi
	{
		UART_SetNUM_PIN(rxBuffer);			// Gan vao val "pin" voi num tuong ung

		UART_Assign_password();				// Gan vao Array extern ben handler_keyIN.h

		//Lay lai gia tri num va pin
		*NUM = num;
		for(uint8_t i = 0; i <= sizeof(PIN); i++)
		{
			PIN[i] = pin[i];
		}

		return UART_HANDLER_OKE;
	}
	else
	{
		return UART_HANDLER_ERROR;
	}
}
