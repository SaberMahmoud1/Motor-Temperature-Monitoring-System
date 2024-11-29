/*
 * leds.h
 *
 *  Created on: Aug 31, 2023
 *      Author: saber
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "std_types.h"

#define GREEN_LED_PORT     PORTC_ID
#define YELLOW_LED_PORT	   PORTC_ID
#define RED_LED_PORT       PORTC_ID

#define GREEN_LED_PIN	   PIN0_ID
#define YELLOW_LED_PIN	   PIN1_ID
#define RED_LED_PIN		   PIN2_ID

#define LIGHTEN_GREEN_LED     4
#define LIGHTEN_YELLOW_LED    5
#define LIGHTEN_RED_LED       6

#define ON                    1
#define OFF                   0

/*initialize the leds*/
void LEDS_INIT();
/*lighten particular led*/
void LEDS_LIGHTEN(uint8 colour);

#endif /* LEDS_H_ */
