/*
 * SWITCH_int.h
 *
 *  Created on: Jul 26, 2025
 *      Author: Merna Atef
 */

#ifndef HAL_SWITCH_SWITCH_INT_H_
#define HAL_SWITCH_SWITCH_INT_H_
# include "../../LIB/STD_TYPES.h"

void HSWITCH_V_u8Init(u8 PORT_SWITCH,u8 PIN_SWITCH);
u8 HSWITCH_u8_u8GetPressed(u8 PORT_SWITCH,u8 PIN_SWITCH);

#endif /* HAL_SWITCH_SWITCH_INT_H_ */
