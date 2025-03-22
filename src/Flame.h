/*
 * Flame.h
 *
 *  Created on: Mar 10, 2025
 *      Author: Hatem
 */

#ifndef FLAME_H_
#define FLAME_H_
#include <avr/io.h>
#include "std_types.h"
#include "gpio.h"

#define FLAME_SENSOR_PORT_ID PORTD_ID
#define FLAME_SENSOR_PIN_ID PIN2_ID
#define FLAME_SENSOR_PIN_REGISTER PIND

void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);
#endif /* FLAME_H_ */
