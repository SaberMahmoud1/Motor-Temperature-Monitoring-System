 /******************************************************************************
 *
 * Module: WDT
 *
 * File Name: WDT.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/

#ifndef WDT_H_
#define WDT_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
//	function to enable Watchdog timer.
void WDT_ON(void);
// 	function to disable Watchdog timer.
void WDT_OFF(void);

#endif /* ADC_H_ */
