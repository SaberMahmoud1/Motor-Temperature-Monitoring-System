/*
 * leds.c
 *
 *  Created on: Aug 31, 2023
 *      Author: saber
 */

#include "leds.h"
#include "gpio.h"

void LEDS_INIT()
{
	GPIO_setupPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(YELLOW_LED_PORT, YELLOW_LED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(RED_LED_PORT, RED_LED_PIN, PIN_OUTPUT);
}

void LEDS_LIGHTEN(uint8 colour)
{
	switch(colour){
	case LIGHTEN_GREEN_LED  :
		GPIO_writePin(GREEN_LED_PORT,GREEN_LED_PIN, ON);
		GPIO_writePin(YELLOW_LED_PORT,YELLOW_LED_PIN, OFF);
		GPIO_writePin(RED_LED_PORT,RED_LED_PIN, OFF);
		break;
	case LIGHTEN_YELLOW_LED :
		GPIO_writePin(GREEN_LED_PORT,GREEN_LED_PIN, OFF);
		GPIO_writePin(YELLOW_LED_PORT,YELLOW_LED_PIN, ON);
		GPIO_writePin(RED_LED_PORT,RED_LED_PIN, OFF);
		break;
	case LIGHTEN_RED_LED    :
		GPIO_writePin(GREEN_LED_PORT,GREEN_LED_PIN, OFF);
		GPIO_writePin(YELLOW_LED_PORT,YELLOW_LED_PIN, OFF);
		GPIO_writePin(RED_LED_PORT,RED_LED_PIN, ON);
		break;
	}
}
