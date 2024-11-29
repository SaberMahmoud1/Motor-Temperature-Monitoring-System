/******************************************************************************
 *
 * Module: TWI(I2C)
 *
 * File Name: twi.h
 *
 * Description: Header file for the TWI(I2C) AVR driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/

#ifndef TIMER1_FAST_PWM_H_
#define TIMER1_FAST_PWM_H_
#include"std_types.h"
/***********************************************************************
 * type definitions
 ***********************************************************************/
typedef enum{deg_0=187,deg_90=250}servo_angel;
/***********************************************************************
 * functions prototype
 ***********************************************************************/
void Timer1_Fast_PWM_Init(unsigned short duty_cycle);
/*
● Description
⮚ Function to initialize the Timer driver
● Inputs: The duty.
● Return: None
*/
#endif /* TIMER1_COMPARE_NORMAL_H_ */
