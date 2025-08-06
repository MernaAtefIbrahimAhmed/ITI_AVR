/*
 * main.c
 *
 *  Created on: Jul 26, 2025
 *      Author: Merna Atef
 */
#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../HAL/SSD/SSD_int.h"
#include "../HAL/SWITCH/SWITCH_int.h"
#include "../MCAL/DIO/DIO_INT.h"

int main(){
	HSSD_VInit();
	HSWITCH_V_u8Init(MDIO_PORTD, MDIO_PIN0);
	while(1){
		for (u8 i = 0; i < 10; i++) {
			if(HSWITCH_u8_u8GetPressed(MDIO_PORTD, MDIO_PIN0))
			  {
				HSSD_VDisplayNum(i);
				_delay_ms(500);
			  }


	}
	}
}
