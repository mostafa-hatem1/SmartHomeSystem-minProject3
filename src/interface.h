/*
 * interface.h
 *
 *  Created on: Mar 22, 2025
 *      Author: Hatem
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "std_types.h"

void init(void);
void setLEDS(uint8 lightValue);
void detectCriticalCondition(uint8 tempValue, uint8 lightValue);
void displayConstants(void);
void displayTemp(uint8 tempValue);
void displayLight(uint8 lightValue);
void setMotorSpeed(uint8 tempValue);

#endif /* INTERFACE_H_ */
