/*
 * KEYPAD_prg.c
 *
 *  Created on: Jul 26, 2025
 *      Author: Merna Atef
 */
# include "../../LIB/STD_TYPES.h"
# include "../../LIB/BIT_MATH.h"
# include "../../MCAL/DIO/DIO_INT.h"
#include <util/delay.h>

#include "../KEYPAD/KEYPAD_cfg.h"
#include "../KEYPAD/KEYPAD_int.h"
#include "../KEYPAD/KEYPAD_prv.h"

void MKPD_V_VInit(void){
	//ROW->PULL UP
	//OUTPUT
	MDIO_voidSetPinDir(KPD_PORT,KPD_R0,MDIO_INPUT);
	MDIO_voidSetPinDir(KPD_PORT,KPD_R1,MDIO_INPUT);
	MDIO_voidSetPinDir(KPD_PORT,KPD_R2,MDIO_INPUT);
	MDIO_voidSetPinDir(KPD_PORT,KPD_R3,MDIO_INPUT);

    //HIGH
	MDIO_voidSetPinVal(KPD_PORT,KPD_R0,MDIO_HIGH);
	MDIO_voidSetPinVal(KPD_PORT,KPD_R1,MDIO_HIGH);
	MDIO_voidSetPinVal(KPD_PORT,KPD_R2,MDIO_HIGH);
	MDIO_voidSetPinVal(KPD_PORT,KPD_R3,MDIO_HIGH);

	//COL
	//INPUT
	MDIO_voidSetPinDir(KPD_PORT,KPD_C0,MDIO_OUTPUT);
	MDIO_voidSetPinDir(KPD_PORT,KPD_C1,MDIO_OUTPUT);
	MDIO_voidSetPinDir(KPD_PORT,KPD_C2,MDIO_OUTPUT);
	MDIO_voidSetPinDir(KPD_PORT,KPD_C3,MDIO_OUTPUT);

    //HIGH
	MDIO_voidSetPinVal(KPD_PORT,KPD_C0,MDIO_HIGH);
	MDIO_voidSetPinVal(KPD_PORT,KPD_C1,MDIO_HIGH);
	MDIO_voidSetPinVal(KPD_PORT,KPD_C2,MDIO_HIGH);
	MDIO_voidSetPinVal(KPD_PORT,KPD_C3,MDIO_HIGH);
}
u8 MKPD_V_VPressed(void) {
	u8 Local_u8PressedKey = 255; // Default value if no key is pressed

	u8 Col_Arr[4] = {KPD_C0, KPD_C1, KPD_C2, KPD_C3}; // Columns
	u8 Row_Arr[4] = {KPD_R0, KPD_R1, KPD_R2, KPD_R3}; // Rows

	for (u8 col = 0; col < 4; col++) {
		MDIO_voidSetPinVal(KPD_PORT, Col_Arr[col], MDIO_LOW);

		for (u8 row = 0; row < 4; row++) {
			s8 value = MDIO_S8GetPinVal(KPD_PORT, Row_Arr[row]);
			if (value == 0) {
				_delay_ms(20);
				value = MDIO_S8GetPinVal(KPD_PORT, Row_Arr[row]);
				if (value == 0) {
					Local_u8PressedKey = KEYPAD[row][col];

					while (MDIO_S8GetPinVal(KPD_PORT, Row_Arr[row]) == 0);

					MDIO_voidSetPinVal(KPD_PORT, Col_Arr[col], MDIO_HIGH);

					return Local_u8PressedKey;
				}
			}
		}
		MDIO_voidSetPinVal(KPD_PORT, Col_Arr[col], MDIO_HIGH);
	}

	return Local_u8PressedKey; // Return 255 if no key was pressed
}

