/*
 * SWITCH_prg.c
 *
 *  Created on: Jul 26, 2025
 *      Author: Merna Atef
 */
# include "../../LIB/STD_TYPES.h"
# include "../../LIB/BIT_MATH.h"
# include "../../MCAL/DIO/DIO_INT.h"

# include "SWITCH_int.h"
#include "SWITCH_prv.h"
# include "SWITCH_cfg.h"

void HSWITCH_V_u8Init(u8 PORT_SWITCH,u8 PIN_SWITCH){
	MDIO_voidSetPinDir(PORT_SWITCH,PIN_SWITCH,MDIO_INPUT);
	if(SWITCH_STATE == PULL_UP){
	    MDIO_voidSetPinVal(PORT_SWITCH, PIN_SWITCH, MDIO_HIGH);
	}

}

u8 HSWITCH_u8_u8GetPressed(u8 PORT_SWITCH, u8 PIN_SWITCH){
    u8 local_u8Val = 0;
    local_u8Val = MDIO_S8GetPinVal(PORT_SWITCH, PIN_SWITCH);

    #if SWITCH_STATE == PULL_UP
        return (local_u8Val == 0); // Pressed
    #elif SWITCH_STATE == PULL_DOWN
        return (local_u8Val == 1); // Pressed
    #endif

    return 0; // Default return to avoid warning
}



