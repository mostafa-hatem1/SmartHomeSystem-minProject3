/*
 * App.c
 *
 *  Created on: Mar 10, 2025
 *      Author: Hatem
 */
#include "std_types.h"
#include "interface.h"
#include "LDR.h"
#include "LM35.h"

/*Global Variables*/
uint8 tempValue;       /* Stores temperature reading */
uint8 lightValue;      /* Stores light intensity reading */
uint8 prevTemp = 0xFF; /* Holds previous temperature value */
uint8 prevLight = 0xFF;/* Holds previous light value */
/* Main program loop */
int main(void){
    init(); /* Initialize system */
    displayConstants(); /* Display static labels */
    while(1){
        tempValue = LM35_getTemperature(); /* Read temperature sensor */
        lightValue = LDR_getLightIntensity(); /* Read light sensor */

        /* Update LCD only if value changes (to prevent flicker) */
        if(prevTemp != tempValue){
            displayTemp(tempValue);
            prevTemp = tempValue;
        } else if( prevLight != lightValue){
            displayLight(lightValue);
            prevLight = lightValue;
        }

        setLEDS(lightValue);  /* Update LED state based on light intensity */
        setMotorSpeed(tempValue); /* Control motor speed based on temp */
        detectCriticalCondition(tempValue, lightValue); /* Check for fire */
    }
}



