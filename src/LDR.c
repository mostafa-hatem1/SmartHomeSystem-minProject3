/*
 * LDR.c
 *
 *  Created on: Mar 10, 2025
 *      Author: Hatem
 */
#include "std_types.h"
#include "ADC.h"
#include "LDR.h"

uint16 LDR_getLightIntensity(void) {
	uint16 light_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the LDR is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the light intensity from the ADC value*/
	light_value = (uint16)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

	return light_value;
}


