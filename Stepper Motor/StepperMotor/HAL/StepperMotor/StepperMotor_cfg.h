/*
 * StepperMotor_cfg.h
 *
 *  Created on: Aug 8, 2025
 *      Author: Merna Atef
 */


#ifndef HAL_STEPPERMOTOR_CFG_H_
#define HAL_STEPPERMOTOR_CFG_H_

#include "../../MCAL/DIO/DIO_INT.h"

// Define Stepper Motor Port
#define STEPPER_PORT MDIO_PORTA

// Define Stepper Motor Pins
#define STEPPER_IN1  MDIO_PIN0
#define STEPPER_IN2  MDIO_PIN1
#define STEPPER_IN3  MDIO_PIN2
#define STEPPER_IN4  MDIO_PIN3

// Steps per Revolution for your stepper
#define STEPPER_STEPS_PER_REV  2048  // For 28BYJ-48

// Delay between steps in milliseconds (controls speed)
#define STEPPER_STEP_DELAY_MS  5

#endif /* HAL_STEPPERMOTOR_CFG_H_ */
