/******************************************************************************
 *
 * Module: timer0
 *
 * File Name: timer_pwm.h
 *
 * Description: Source file for the TIMER0 driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/
#ifndef TIMER_PWM_H_
#define TIMER_PWM_H_
/************************************************************
 * functions prototypes
 ***********************************************************
 */
#include"std_types.h"
/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */
void Timer0_PWM_Init(uint8 set_duty_cycle);
#endif /* TIMER_PWM_H_ */
