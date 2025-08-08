/*
 * StepperMotor_prv.h
 *
 *  Created on: Aug 8, 2025
 *      Author: Merna Atef
 */

#ifndef HAL_STEPPERMOTOR_STEPPERMOTOR_PRV_H_
#define HAL_STEPPERMOTOR_STEPPERMOTOR_PRV_H_

static u8 Stepper_Sequence[4][4] = {
    {1,0,0,1},
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0}
};

#endif /* HAL_STEPPERMOTOR_STEPPERMOTOR_PRV_H_ */
