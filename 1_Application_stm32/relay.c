/*
 * relay.c
 *
 *  Created on: 26 Jan 2024
 *      Author: BaoThuan
 */
#include<relay.h>
/* example: blink
	  RELAY_Set_same(GPIOA, R7_Pin|R2_Pin);
	  HAL_Delay(1000);
	  RELAY_Reset_same(GPIOA);
	  HAL_Delay(1000);
*/
//==============================================================================================================================================================
/* <function summary decription>
  +) NOTE:
    - Cài đặt co mức logic của các pin có cùng port lên mức 1
  +) PARAM:
    - GPIO_TypeDef* GPIOx_same           : GPIOx
    - uint16_t state_relay               : PIN1->PIN7
  +) RETURN:
	- void
*/
void RELAY_Set_same(GPIO_TypeDef* GPIOx_same, uint16_t state_relay)
{
	HAL_GPIO_WritePin(GPIOx_same, state_relay, GPIO_PIN_SET);
}
//==============================================================================================================================================================
/* <function summary decription>
  +) NOTE:
    - Reset tất cả các PIN trong PORT về 0
  +) PARAM:
    -GPIO_TypeDef* GPIOx_same           : PORTx
  +) RETURN:
	-void
*/
void RELAY_Reset_same(GPIO_TypeDef* GPIOx_same)
{
	HAL_GPIO_WritePin(GPIOx_same, 0xFF, GPIO_PIN_RESET);
}