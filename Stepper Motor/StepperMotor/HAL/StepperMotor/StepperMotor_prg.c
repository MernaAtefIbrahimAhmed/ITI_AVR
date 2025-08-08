/*
 * StepperMotor_prg.c
 *
 *  Created on: Aug 8, 2025
 *      Author: Merna Atef
 */


/*
 * StepperMotor_PRG.c
 *
 *  Created on: Aug 8, 2025
 *      Author: Merna Atef
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_INT.h"
#include <util/delay.h>

#include "StepperMotor_cfg.h"
#include "StepperMotor_prv.h"
#include "StepperMotor_int.h"

void HStepperMotor_vInit(void) {
    MDIO_voidSetPinDir(STEPPER_PORT, STEPPER_IN1, MDIO_OUTPUT);
    MDIO_voidSetPinDir(STEPPER_PORT, STEPPER_IN2, MDIO_OUTPUT);
    MDIO_voidSetPinDir(STEPPER_PORT, STEPPER_IN3, MDIO_OUTPUT);
    MDIO_voidSetPinDir(STEPPER_PORT, STEPPER_IN4, MDIO_OUTPUT);
}

void HStepperMotor_vStep(u8 stepIndex) {
    MDIO_voidSetPinVal(STEPPER_PORT, STEPPER_IN1, Stepper_Sequence[stepIndex][0]);
    MDIO_voidSetPinVal(STEPPER_PORT, STEPPER_IN2, Stepper_Sequence[stepIndex][1]);
    MDIO_voidSetPinVal(STEPPER_PORT, STEPPER_IN3, Stepper_Sequence[stepIndex][2]);
    MDIO_voidSetPinVal(STEPPER_PORT, STEPPER_IN4, Stepper_Sequence[stepIndex][3]);
}

void HStepperMotor_vRotateDegrees(s16 degrees) {
    u16 totalSteps = ( (u32)degrees * STEPPER_STEPS_PER_REV ) / 360;
    for (u16 i = 0; i < totalSteps; i++) {
        HStepperMotor_vStep(i % 4);
        _delay_ms(STEPPER_STEP_DELAY_MS);
    }
}

void HStepperMotor_vRotate180(void) {
    HStepperMotor_vRotateDegrees(180);
}
