/*
 * StepperMotor_int.h
 *
 *  Created on: Aug 8, 2025
 *      Author: Merna Atef
 */

#ifndef HAL_STEPPERMOTOR_STEPPERMOTOR_INT_H_
#define HAL_STEPPERMOTOR_STEPPERMOTOR_INT_H_

void HStepperMotor_vInit(void);
void HStepperMotor_vStep(u8 stepIndex);
void HStepperMotor_vRotateDegrees(s16 degrees);
void HStepperMotor_vRotate180(void);


#endif /* HAL_STEPPERMOTOR_STEPPERMOTOR_INT_H_ */
