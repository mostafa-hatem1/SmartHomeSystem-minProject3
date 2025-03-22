/*
 * interface.c
 *
 *  Created on: Mar 22, 2025
 *      Author: Hatem
 */
#include "std_types.h"
#include "LED.h"
#include "Motor.h"
#include "Buzzer.h"
#include "Flame.h"
#include "LCD.h"
#include "ADC.h"

/* Initializes all required modules */
void init(void){
    LCD_init();       /* Initialize LCD display */
    ADC_init();       /* Initialize ADC for sensor readings */
    LEDS_init();      /* Initialize LEDs */
    Motor_init();     /* Initialize motor control */
    Buzzer_init();    /* Initialize buzzer */
    FlameSensor_init(); /* Initialize flame sensor */
}

void setLEDS(uint8 lightValue) {
    if (lightValue < 15) {
        LED_on(RED_LED);    /* Turn on red LED */
        LED_on(GREEN_LED);  /* Turn on green LED */
        LED_on(BLUE_LED);   /* Turn on blue LED */
    }
    else if (lightValue <= 50) {
        LED_on(RED_LED);
        LED_on(GREEN_LED);
        LED_off(BLUE_LED);  /* Turn off blue LED */
    }
    else if (lightValue <= 70) {
        LED_on(RED_LED);
        LED_off(GREEN_LED); /* Turn off green LED */
        LED_off(BLUE_LED);
    }
    else {
        LED_off(RED_LED);
        LED_off(GREEN_LED);
        LED_off(BLUE_LED);  /* Turn off all LEDs */
    }
}

/* Checks for fire and triggers alarm if detected */
void detectCriticalCondition(uint8 tempValue, uint8 lightValue){
    if(FlameSensor_getValue()){ /* If flame is detected */
        LCD_clearScreen();
        LCD_sendString("Critical alert!"); /* Display warning message */
        Buzzer_on(); /* Activate buzzer */

        while(FlameSensor_getValue()); /* Wait until fire is gone */

        LCD_clearScreen();
        Buzzer_off();
        displayConstants(); /* Restore LCD display */
        displayTemp(tempValue);
        displayLight(lightValue);
    }
}

/* Displays static labels on LCD */
void displayConstants(void){
    LCD_sendString("   FAN is");
    LCD_moveCursor(1,0);
    LCD_sendString("Temp=");
    LCD_moveCursor(1,8);
    LCD_sendString("LDR=");
}

/* Updates LCD with temperature value */
void displayTemp(uint8 tempValue){
    LCD_moveCursor(1,5);
    LCD_sendString("   "); /* Clear previous value */
    LCD_moveCursor(1,5);
    LCD_integerToString(tempValue); /* Display new temp */
    LCD_moveCursor(0,10);
    LCD_sendString((tempValue >= 25) ? "ON " : "OFF"); /* Indicate fan status */
}

/* Updates LCD with light intensity value */
void displayLight(uint8 lightValue){
    LCD_moveCursor(1,12);
    LCD_sendString("   "); /* Clear previous value */
    LCD_moveCursor(1,12);
    LCD_integerToString(lightValue); /* Display new value */

    /* Adjust cursor based on number of digits */
    if (lightValue < 10) {
        LCD_moveCursor(1,13);
    } else if (lightValue < 100) {
        LCD_moveCursor(1,14);
    } else {
        LCD_moveCursor(1,15);
    }

    LCD_sendString("% "); /* Display percentage sign */
}

/* Adjusts motor speed based on temperature */
void setMotorSpeed(uint8 tempValue) {
    uint8 speed = 0;
    if(tempValue >= 25){
        if(tempValue < 30) speed = 64;  /* Low speed */
        else if(tempValue < 35) speed = 128; /* Medium speed */
        else if(tempValue < 40) speed = 192; /* High speed */
        else speed = 255; /* Max speed */
    }
    Motor_rotate(speed > 0 ? MOTOR_CW : MOTOR_STOP, speed); /* Control motor */
}
