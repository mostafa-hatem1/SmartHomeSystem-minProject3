/*
 * LED.h
 *
 *  Created on: Mar 10, 2025
 *      Author: Hatem
 */

#ifndef LED_H_
#define LED_H_
#include "gpio.h"

#define POSITIVE_LOGIC 1
#define NEGATIVE_LOGIC 0

/* Define LED Ports and Pins */
#define RED_LED_PORT_ID    PORTB_ID
#define RED_LED_PIN_ID     PIN5_ID
#define RED_LED_LOGIC   POSITIVE_LOGIC

#define GREEN_LED_PORT_ID  PORTB_ID
#define GREEN_LED_PIN_ID   PIN6_ID
#define GREEN_LED_LOGIC POSITIVE_LOGIC

#define BLUE_LED_PORT_ID   PORTB_ID
#define BLUE_LED_PIN_ID    PIN7_ID
#define BLUE_LED_LOGIC  POSITIVE_LOGIC

/* Enum for LED IDs */
typedef enum {
    RED_LED,
    GREEN_LED,
    BLUE_LED
} LED_ID;

void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);


#endif /* LED_H_ */
