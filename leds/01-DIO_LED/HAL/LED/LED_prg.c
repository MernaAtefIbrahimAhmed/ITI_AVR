/*
 * LED_PRG.C
 *
 *  Created on: Jul 26, 2025
 *      Author: Merna Atef
 */
# include "../../LIB/STD_TYPES.h"
# include "../../LIB/BIT_MATH.h"
# include "../../MCAL/DIO/DIO_INT.h"

# include "LED_int.h"
# include "LED_Prv.h"
# include "LED_cfg.h"


void HLED_u8Init(u8 PORT_LED,u8 PIN_LED){

	MDIO_voidSetPinDir(PORT_LED,PIN_LED,MDIO_OUTPUT);
}
//Turn of
void HLED_V_u8TurnON(u8 PORT_LED,u8 PIN_LED){
	if(LED_STATE == ACTIVE_HIGH){
		MDIO_voidSetPinVal(PORT_LED,PIN_LED,MDIO_HIGH);
		}
	else{
		MDIO_voidSetPinVal(PORT_LED,PIN_LED,MDIO_LOW);
	}

}
//Turn of
void HLED_V_u8TurnOff(u8 PORT_LED,u8 PIN_LED){
	if(LED_STATE == ACTIVE_HIGH){
			MDIO_voidSetPinVal(PORT_LED,PIN_LED,MDIO_LOW);
			}
		else{
			MDIO_voidSetPinVal(PORT_LED,PIN_LED,MDIO_HIGH);
		}
}
//Toggle
void HLED_V_u8Toggle(u8 PORT_LED, u8 PIN_LED){
	    u8 currentVal = MDIO_S8GetPinVal(PORT_LED, PIN_LED);
	    if (currentVal == MDIO_HIGH) {
	        MDIO_voidSetPinVal(PORT_LED, PIN_LED, MDIO_LOW);
	    } else {
	        MDIO_voidSetPinVal(PORT_LED, PIN_LED, MDIO_HIGH);
	    }
	}



