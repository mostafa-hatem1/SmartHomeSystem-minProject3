/*
 * Flame.c
 *
 *  Created on: Mar 10, 2025
 *      Author: Hatem
 */
#include"std_types.h"
#include "Flame.h"
#include "gpio.h"
#include "common_macros.h"
#include "std_types.h"

void FlameSensor_init(void){
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID,FLAME_SENSOR_PIN_ID,PIN_OUTPUT);

}

uint8 FlameSensor_getValue(void){
    return BIT_IS_SET(FLAME_SENSOR_PIN_REGISTER, FLAME_SENSOR_PIN_ID) ? LOGIC_HIGH : LOGIC_LOW;
}
