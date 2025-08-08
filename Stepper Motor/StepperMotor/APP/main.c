/*
 * main.c
 *
 *  Created on: Jul 26, 2025
 *      Author: Merna Atef
 */
#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_INT.h"
#include "../HAL/StepperMotor/StepperMotor_int.h"

int main(void) {
    HStepperMotor_vInit();
    while (1) {
        HStepperMotor_vRotate180(); // Rotate 180 degrees
        _delay_ms(1000);            // Wait 1 second
    }
}
