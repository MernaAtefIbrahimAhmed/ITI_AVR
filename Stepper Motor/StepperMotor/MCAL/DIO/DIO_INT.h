/*
M * DIO_INT.h
 *
 *  Created on: Jul 21, 2025
 *      Author: Merna Atef
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

# include "../../LIB/STD_TYPES.h"

#define MDIO_PORTA 'A'
#define MDIO_PORTB 'B'
#define MDIO_PORTC 'C'
#define MDIO_PORTD 'D'

#define MDIO_PIN0    0
#define MDIO_PIN1    1
#define MDIO_PIN2    2
#define MDIO_PIN3    3
#define MDIO_PIN4    4
#define MDIO_PIN5    5
#define MDIO_PIN6    6
#define MDIO_PIN7    7

#define MDIO_INPUT   0
#define MDIO_OUTPUT  1

#define MDIO_LOW     0
#define MDIO_HIGH    1



//DDR
//INPUT OR OUTPUT
void MDIO_voidSetPinDir(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinDir);
//HIGH OR LOW
void MDIO_voidSetPinVal(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinVal);

//INPUT

s8 MDIO_S8GetPinVal(u8 A_u8PortNum,u8 A_u8PinVal);

//PORT
void MDIO_voidSetPortDir(u8 A_u8PortNum,u8 A_u8PortDir);
void MDIO_voidSetPortVal(u8 A_u8PortNum,u8 A_u8PortVal);
s8 MDIO_S8GetPortVal(u8 A_u8PortVal);


#endif /* MCAL_DIO_DIO_INT_H_ */
