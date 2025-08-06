/*
 * main.c
 *
 *  Created on: Jul 21, 2025
 *      Author: Merna Atef
 */
#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../HAL/LED/LED_int.h"
#include "../MCAL/DIO/DIO_INT.h"

int main(void) {

    for (u8 i = 0; i < 8; i++) {
        HLED_u8Init(MDIO_PORTB, i);
    }

    while (1) {
        // Animation 1: Shift Left
        for (u8 i = 0; i < 8; i++) {
            for (u8 j = 0; j < 8; j++) {
                HLED_V_u8TurnOff(MDIO_PORTB, j);
            }
            HLED_V_u8TurnON(MDIO_PORTB, i);
            _delay_ms(200);
        }

        // Animation 2: Shift Right
        for (s8 i = 6; i >= 0; i--) {
            for (u8 j = 0; j < 8; j++) {
                HLED_V_u8TurnOff(MDIO_PORTB, j);
            }
            HLED_V_u8TurnON(MDIO_PORTB, i);
            _delay_ms(200);
        }

        // Animation 3: Ping-pong
        for (u8 i = 0; i < 8; i++) {
            for (u8 j = 0; j < 8; j++) {
                HLED_V_u8TurnOff(MDIO_PORTB, j);
            }
            HLED_V_u8TurnON(MDIO_PORTB, i);
            _delay_ms(100);
        }
        for (s8 i = 6; i >= 0; i--) {
            for (u8 j = 0; j < 8; j++) {
                HLED_V_u8TurnOff(MDIO_PORTB, j);
            }
            HLED_V_u8TurnON(MDIO_PORTB, i);
            _delay_ms(100);
        }

        // Animation 4: All LEDs Blink
        for (u8 i = 0; i < 8; i++) {
            HLED_V_u8TurnON(MDIO_PORTB, i);
        }
        _delay_ms(300);
        for (u8 i = 0; i < 8; i++) {
            HLED_V_u8TurnOff(MDIO_PORTB, i);
        }
        _delay_ms(300);

        // Animation 5: Converging
        for (u8 i = 0; i < 4; i++) {
            for (u8 j = 0; j < 8; j++) {
                HLED_V_u8TurnOff(MDIO_PORTB, j);
            }
            HLED_V_u8TurnON(MDIO_PORTB, i);
            HLED_V_u8TurnON(MDIO_PORTB, 7 - i);
            _delay_ms(200);
        }

        // Animation 6: Diverging
        for (s8 i = 3; i >= 0; i--) {
            for (u8 j = 0; j < 8; j++) {
                HLED_V_u8TurnOff(MDIO_PORTB, j);
            }
            HLED_V_u8TurnON(MDIO_PORTB, i);
            HLED_V_u8TurnON(MDIO_PORTB, 7 - i);
            _delay_ms(200);
        }

        // Animation 7: Snake effect
        for (u8 i = 0; i < 8; i++) {
            HLED_V_u8TurnON(MDIO_PORTB, i);
            _delay_ms(150);
        }
        for (u8 i = 0; i < 8; i++) {
            HLED_V_u8TurnOff(MDIO_PORTB, i);
        }
    }

    return 0;
}
