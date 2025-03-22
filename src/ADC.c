/*
 * ADC.c
 *
 *  Created on: Mar 8, 2025
 *      Author: Hatem
 */

#include <avr/io.h>
#include "std_types.h"
#include "ADC.h"
#include "common_macros.h"

void ADC_init(void){
	ADMUX = (1<<REFS1) | (1<<REFS0);/*setting Vref to internal voltage,
	assuming channel 0 and setting ADLAR bit to 0*/
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	/*enable ADC and choose prescalar 128*/
	/*disable interrupts*/
}

uint16 ADC_readChannel(uint8 ch_num){
	ADMUX = (ADMUX & 0xE0) | ch_num;/*choosing the channel*/
	SET_BIT(ADCSRA, ADSC);/*start conversion*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));/*Polling until flag = 1*/
	SET_BIT(ADCSRA, ADIF);/*clearing the flag*/
	return ADC;/*returning the data register*/
}
