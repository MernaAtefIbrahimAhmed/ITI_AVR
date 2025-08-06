/*
 * LCD_int.h
 *
 *  Created on: Jul 21, 2025
 *      Author: Merna Atef
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_


void HLCD_vInit(void);
void HLCD_vSendCommand(char A_u8Command);

void HLCD_vSendData(char A_u8Data);

void HLCD_vSetCursor(char A_u8Row, char A_u8Col);

#endif /* HAL_LCD_LCD_INT_H_ */
