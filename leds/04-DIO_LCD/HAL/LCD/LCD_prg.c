/*
 * LCD_prg.c
 *
 *  Created on: Jul 21, 2025
 *      Author: Merna Atef
 */


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_INT.h"
#include "LCD_int.h"
#include "LCD_cfg.h"
#include <util/delay.h>

void HLCD_vInit(void)
{
	MDIO_voidSetPortDir(LCD_DATA_PORT,0xFF);
	MDIO_voidSetPinDir(LCD_CTR_PORT,LCD_RS_PIN,MDIO_OUTPUT);
	MDIO_voidSetPinDir(LCD_CTR_PORT,LCD_RW_PIN,MDIO_OUTPUT);
	MDIO_voidSetPinDir(LCD_CTR_PORT,LCD_EN_PIN,MDIO_OUTPUT);

	_delay_ms(50); // Wait for LCD to power up

	HLCD_vSendCommand(0b00111000); // Function Set
	_delay_ms(1);

	HLCD_vSendCommand(0b00001100); // Display ON, Cursor OFF
	_delay_ms(1);

	HLCD_vSendCommand(0b00000001); // Clear Display
	_delay_ms(2);

	HLCD_vSendCommand(0b00000110); // Entry Mode Set (increment cursor)
	_delay_ms(1);
}
void HLCD_vSendCommand(char A_u8Command)
{
	MDIO_voidSetPinVal(LCD_CTR_PORT,LCD_RS_PIN,MDIO_LOW);
	MDIO_voidSetPinVal(LCD_CTR_PORT,LCD_RW_PIN,MDIO_LOW);
	MDIO_voidSetPortVal(LCD_DATA_PORT,A_u8Command);

	MDIO_voidSetPinVal(LCD_CTR_PORT,LCD_EN_PIN,MDIO_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinVal(LCD_CTR_PORT,LCD_EN_PIN,MDIO_LOW);
	_delay_ms(1);

}

void HLCD_vSendData(char A_u8Data)
{
	MDIO_voidSetPinVal(LCD_CTR_PORT,LCD_RS_PIN,MDIO_HIGH);
	MDIO_voidSetPinVal(LCD_CTR_PORT,LCD_RW_PIN,MDIO_LOW);
	MDIO_voidSetPortVal(LCD_DATA_PORT,A_u8Data);

	MDIO_voidSetPinVal(LCD_CTR_PORT,LCD_EN_PIN,MDIO_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinVal(LCD_CTR_PORT,LCD_EN_PIN,MDIO_LOW);
	_delay_ms(1);
}

void HLCD_vSetCursor(char A_u8Row, char A_u8Col)
{
	if(A_u8Col<=15)
	{
		switch(A_u8Row)
		{
		case 0 :  HLCD_vSendCommand(0x80+A_u8Col);
			break;
		case 1 : HLCD_vSendCommand(0x80+0x40+A_u8Col);
			break;
		}
	}
}
