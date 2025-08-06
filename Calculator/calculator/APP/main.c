/*
1 * main.c
 *
 *  Created on: Jul 26, 2025
 *      Author: Merna Atef
 */

#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../MCAL/DIO/DIO_INT.h"
#define F_CPU 8000000UL

int main(void)
{
	// Init LCD and Keypad
	HLCD_vInit();
	MKPD_V_VInit();

	u8 key = 0;
	s32 num1 = 0, num2 = 0, result = 0;
	u8 operator = 0;
	u8 isSecondOperand = 0;

	HLCD_vSendString("Calculator");
	_delay_ms(1000);
	HLCD_vClearDisplay();
	HLCD_vSetCursor(0, 0);

	while (1)
	{
		key = MKPD_V_VPressed();
		if (key != 0xFF) // Valid key pressed
		{
			if (key >= '0' && key <= '9') // Number
			{
				HLCD_vSendData(key);
				if (!isSecondOperand)
				{
					num1 = num1 * 10 + (key - '0');
				}
				else
				{
					num2 = num2 * 10 + (key - '0');
				}
			}
			else if (key == '+' || key == '-' || key == '*' || key == '/')
			{
				operator = key;
				isSecondOperand = 1;
				HLCD_vSendData(key);
			}
			else if (key == '=')
			{
				HLCD_vSendData('=');
				switch (operator)
				{
					case '+': result = num1 + num2; break;
					case '-': result = num1 - num2; break;
					case '*': result = num1 * num2; break;
					case '/':
						if (num2 != 0)
							result = num1 / num2;
						else
						{
							HLCD_vClearDisplay();
							HLCD_vSendString("Math Error");
							_delay_ms(1000);
							goto reset;
						}
						break;
					default: break;
				}

				HLCD_vSendNumber(result);
				_delay_ms(1500);

			reset:
				num1 = 0;
				num2 = 0;
				result = 0;
				operator = 0;
				isSecondOperand = 0;
				HLCD_vClearDisplay();
				HLCD_vSetCursor(0, 0);
			}
			else if (key == 'C') // Clear button
			{
				num1 = 0;
				num2 = 0;
				result = 0;
				operator = 0;
				isSecondOperand = 0;
				HLCD_vClearDisplay();
				HLCD_vSetCursor(0, 0);
			}
		}
	}
}
