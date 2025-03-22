/*
 * LED.c
 *
 *  Created on: Mar 10, 2025
 *      Author: Hatem
 */
#include "LED.h"
#include "gpio.h"
#include "std_types.h"

 static inline void LED_onGeneric(uint8 port, uint8 pin, uint8 logic) {
    GPIO_writePin(port, pin, (logic == POSITIVE_LOGIC) ? LOGIC_HIGH : LOGIC_LOW);
}

 static inline void LED_offGeneric(uint8 port, uint8 pin, uint8 logic) {
    GPIO_writePin(port, pin, (logic == POSITIVE_LOGIC) ? LOGIC_LOW : LOGIC_HIGH);
}

void LEDS_init(void){
	GPIO_setupPinDirection(RED_LED_PORT_ID, RED_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, PIN_OUTPUT);

	/* Turn off all LEDs initially */
	LED_off(RED_LED);
	LED_off(GREEN_LED);
	LED_off(BLUE_LED);
}

void LED_on(LED_ID id){
	switch (id){
		case RED_LED: LED_onGeneric(RED_LED_PORT_ID, RED_LED_PIN_ID, RED_LED_LOGIC); break;
		case GREEN_LED: LED_onGeneric(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, GREEN_LED_LOGIC); break;
		case BLUE_LED: LED_onGeneric(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, BLUE_LED_LOGIC); break;
	}
}

void LED_off(LED_ID id){
	switch (id){
	case RED_LED: LED_offGeneric(RED_LED_PORT_ID, RED_LED_PIN_ID, RED_LED_LOGIC); break;
	case GREEN_LED: LED_offGeneric(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, GREEN_LED_LOGIC); break;
	case BLUE_LED: LED_offGeneric(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, BLUE_LED_LOGIC); break;
	}
}
