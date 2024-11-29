/*
 * control_ECU.h
 *
 *  Created on: Nov 3, 2022
 *      Author: saber
 */

#ifndef MCU1_H_
#define MCU1_H_
#include "std_types.h"

#define NORMAL                0
#define EMERGENCY             1
#define ABNORMAL              2
#define STOP_MACHINE          3
#define LIGHTEN_GREEN_LED     4
#define LIGHTEN_YELLOW_LED    5
#define LIGHTEN_RED_LED       6

#define PUSH_BUTTON_PORT      PORTA_ID
#define PUSH_BUTOON_PIN       PIN6_ID

// Define the EEPROM address
uint8  storedAddress=0x00;

// Write variable for internal EEPROM
uint8 valueToWrite = 0xAA;

//read variable for internal EEPROM
uint8 readValue;

uint16 temp;
uint8 motor_state=CW;
uint8 time_in_seconds=0;

#endif /* MCU1_H_ */
