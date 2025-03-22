/*
 * Motor.h
 *
 *  Created on: Mar 10, 2025
 *      Author: Hatem
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"
#include "gpio.h"

/* Enum for DC Motor states */
typedef enum {
    MOTOR_CW,
    MOTOR_ACW,
    MOTOR_STOP
} DcMotor_State;

/* Motor Configuration */
#define MOTOR_IN1_PORT_ID  PORTB_ID
#define MOTOR_IN1_PIN_ID   PIN0_ID
#define MOTOR_IN2_PORT_ID  PORTB_ID
#define MOTOR_IN2_PIN_ID   PIN1_ID

/* Function Declarations */
void Motor_init(void);
void Motor_rotate(DcMotor_State state, uint8 speed);

#endif /* MOTOR_H_ */
