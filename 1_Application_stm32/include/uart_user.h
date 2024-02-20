/*
 * uart_user.h
 *
 *  Created on: Feb 8, 2024
 *      Author: BaoThuan
 */

#ifndef INCLUDE_UART_USER_H_
#define INCLUDE_UART_USER_H_

#include "stm32f1xx_hal.h"
#include "string.h"
#include "stdbool.h"

#include <handler_keyIN.h>

typedef enum
{
	UART_HANDLER_OKE,
	UART_HANDLER_ERROR
} STATE_TX_PIN;


//==============================================================================================================================================================
/* <function summary decription>
  +) NOTE:
    -INIT UART fot this lib
  +) PARAM:
    -UART_HandleTypeDef *huart						: value rx uart is set up
  +) RETURN:
*/
void UART_Init_UART(UART_HandleTypeDef *huart);



//==============================================================================================================================================================
/* <function summary decription>
  +) NOTE:
    -RX value frome everythings
    -Change the input password value param with a pointer with letter number param
  +) PARAM:
    -uint8_t * rxBuffer								: value frome EXTI uart
  +) RETURN:
    -STATE_TX_PIN									: UART_HANDLER_OKE
    												  UART_HANDLER_ERROR
*/
STATE_TX_PIN UART_handler(uint8_t * rxBuffer, char* NUM, char* PIN);



#endif /* INCLUDE_UART_USER_H_ */