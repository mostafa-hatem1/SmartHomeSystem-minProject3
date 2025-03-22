/*
 * LM35.h
 *
 *  Created on: Mar 10, 2025
 *      Author: Hatem
 */

#ifndef LM35_H_
#define LM35_H_
#include "std_types.h"


#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150


uint8 LM35_getTemperature(void);


#endif /* LM35_H_ */
