/*
 * LED_int.h
 *
 *  Created on: Jul 26, 2025
 *      Author: Merna Atef
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_


void HLED_u8Init(u8 PORT_LED,u8 PIN_LED);
//Turn of
void HLED_V_u8TurnON(u8 PORT_LED,u8 PIN_LED);
//Turn of
void HLED_V_u8TurnOff(u8 PORT_LED,u8 PIN_LED);
void HLED_V_u8Toggle(u8 PORT_LED,u8 PIN_LED);

#endif /* HAL_LED_LED_INT_H_ */
