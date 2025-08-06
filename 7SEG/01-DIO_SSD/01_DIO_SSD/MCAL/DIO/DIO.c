/*
 * DIO.c
 *
 *  Created on: Jul 21, 2025
 *      Author: Merna Atef
 */



# include "../../LIB/BIT_MATH.h"
# include "DIO_INT.h"
#include "DIO_prv.h"


//DDR
//INPUT OR OUTPUT
void MDIO_voidSetPinDir(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinDir){
	if(A_u8PinNum>=0 && A_u8PinNum<=7){
		switch(A_u8PortNum){
			case MDIO_PORTA:
				switch(A_u8PinDir){
				case MDIO_OUTPUT : SET_BIT(DDRA,A_u8PinNum); break;
				case MDIO_INPUT : CLR_BIT(DDRA,A_u8PinNum); break;
				}
				break;
			case MDIO_PORTB:
				switch(A_u8PinDir){
					case MDIO_OUTPUT : SET_BIT(DDRB,A_u8PinNum); break;
					case MDIO_INPUT : CLR_BIT(DDRB,A_u8PinNum); break;
				}
					break;
			case MDIO_PORTC:
				switch(A_u8PinDir){
					case MDIO_OUTPUT : SET_BIT(DDRC,A_u8PinNum); break;
					case MDIO_INPUT : CLR_BIT(DDRC,A_u8PinNum); break;
				}
			break;
			case MDIO_PORTD:
				switch(A_u8PinDir){
					case MDIO_OUTPUT : SET_BIT(DDRD,A_u8PinNum); break;
				    case MDIO_INPUT : CLR_BIT(DDRD,A_u8PinNum); break;
				}
			break;
			}
	}

}
//HIGH OR LOW
void MDIO_voidSetPinVal(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinVal)
{
	if(A_u8PinNum>=0 && A_u8PinNum<=7){
		switch(A_u8PortNum){
			case MDIO_PORTA:
				switch(A_u8PinVal){
				case MDIO_HIGH : SET_BIT(PORTA,A_u8PinNum); break;
				case MDIO_LOW : CLR_BIT(PORTA,A_u8PinNum); break;
				}
				break;
			case MDIO_PORTB:
				switch(A_u8PinVal){
					case MDIO_HIGH : SET_BIT(PORTB,A_u8PinNum); break;
					case MDIO_LOW : CLR_BIT(PORTB,A_u8PinNum); break;
				}
					break;
			case MDIO_PORTC:
				switch(A_u8PinVal){
					case MDIO_HIGH : SET_BIT(PORTC,A_u8PinNum); break;
					case MDIO_LOW : CLR_BIT(PORTC,A_u8PinNum); break;
				}
			break;
			case MDIO_PORTD:
				switch(A_u8PinVal){
					case MDIO_HIGH : SET_BIT(PORTD,A_u8PinNum); break;
				    case MDIO_LOW : CLR_BIT(PORTD,A_u8PinNum); break;
				}
			break;
			}
	}
}


s8 MDIO_S8GetPinVal(u8 A_u8PortNum,u8 A_u8PinVal){
	s8 L_s8ReturnVal = -1;
	if(A_u8PinVal>=0 && A_u8PinVal<=7){
		switch(A_u8PortNum){
	    case MDIO_PORTA : L_s8ReturnVal= GET_BIT(PINA,A_u8PinVal); break;
		case MDIO_PORTB : L_s8ReturnVal= GET_BIT(PINB,A_u8PinVal); break;
		case MDIO_PORTC : L_s8ReturnVal= GET_BIT(PINC,A_u8PinVal); break;
		case MDIO_PORTD : L_s8ReturnVal= GET_BIT(PIND,A_u8PinVal); break;
		}

	}
	return L_s8ReturnVal;


}

//PORT
void MDIO_voidSetPortDir(u8 A_u8PortNum,u8 A_u8PortDir){
	switch(A_u8PortNum){
	case MDIO_PORTA: DDRA=A_u8PortDir; break;
	case MDIO_PORTB: DDRB=A_u8PortDir; break;
	case MDIO_PORTC: DDRC=A_u8PortDir; break;
	case MDIO_PORTD: DDRD=A_u8PortDir; break;

	}

}
void MDIO_voidSetPortVal(u8 A_u8PortNum,u8 A_u8PortVal){
	switch(A_u8PortNum){
		case MDIO_PORTA: PORTA= A_u8PortVal; break;
		case MDIO_PORTB: PORTB= A_u8PortVal; break;
		case MDIO_PORTC: PORTC= A_u8PortVal; break;
	    case MDIO_PORTD: PORTD= A_u8PortVal; break;
		}


}
s8 MDIO_S8GetPortVal(u8 A_u8PortVal){
	s8 L_s8ReturnVal = -1;
		switch(A_u8PortVal){
		case MDIO_PORTA : L_s8ReturnVal=PINA;  break;
		case MDIO_PORTB : L_s8ReturnVal=PINB;  break;
		case MDIO_PORTC : L_s8ReturnVal= PINC; break;
		case MDIO_PORTD : L_s8ReturnVal= PIND;break;
		}
		return L_s8ReturnVal;

}
