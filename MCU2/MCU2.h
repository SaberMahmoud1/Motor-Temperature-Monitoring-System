/*
 * HMI_ECU.h
 *
 *  Created on: Nov 3, 2022
 *      Author: saber
 */

#ifndef MCU2_H_
#define MCU2_H_

#include "std_types.h"

#define EMERGENCY             1
#define ABNORMAL              2
#define STOP_MACHINE          3
#define LIGHTEN_GREEN_LED     4
#define LIGHTEN_YELLOW_LED    5
#define LIGHTEN_RED_LED       6

extern uint8 g_operation;

#endif /* MCU2_H_ */
