/*
 * main.c
 *
 *  Created on: Jul 21, 2025
 *      Author: Merna Atef
 */
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD/LCD_int.h"
#include <util/delay.h>

int main(void)
{
	 // Initialize LCD
	    HLCD_vInit();

	   HLCD_vSendData('M');
	   HLCD_vSendData('E');
	   HLCD_vSendData('R');
	   HLCD_vSendData('N');
	   HLCD_vSendData('A');
	   HLCD_vSendData('&');
	   HLCD_vSendData('H');
	   HLCD_vSendData('A');
	   HLCD_vSendData('N');
	   HLCD_vSendData('A');
	   HLCD_vSetCursor(1,4);

	while(1)
	{

	}
	return 0;
}
