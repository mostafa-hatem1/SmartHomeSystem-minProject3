/*
 * Buzzer.c
 *
 *  Created on: Mar 10, 2025
 *      Author: Hatem
 */
#include "Buzzer.h"
#include "gpio.h"
#include "common_macros.h"

/* Function to initialize the buzzer */
void Buzzer_init(void) {
    GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
    GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}

/* Function to turn on the buzzer */
void Buzzer_on(void) {
    GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}

/* Function to turn off the buzzer */
void Buzzer_off(void) {
    GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}

