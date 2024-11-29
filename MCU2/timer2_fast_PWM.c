 /******************************************************************************
 *
 * Module: timer0
 *
 * File Name: timer_pwm.c
 *
 * Description: Source file for the TIMER0 driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/
/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */
#include"timer2_fast_PWM.h"
#include<avr/io.h>
#include<util/delay.h>
#include"gPio.h"
#include"common_macros.h"

void Timer2_PWM_Init(uint8 set_duty_cycle)
{
	if(set_duty_cycle==0)
	{
		TCCR2=0;
		OCR2=0;
		return;
	}
	SET_VALUE_IN_REG(TCNT2,0); // Set Timer Initial Value to 0
	SET_VALUE_IN_REG(OCR2,set_duty_cycle); //Set Compare value

	GPIO_setupPinDirection(PORTD_ID, PIN7_ID, PIN_OUTPUT); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC2=0
	 * 2. Fast PWM Mode WGM21=1 & WGM20=1
	 * 3. Clear OC2 when match occurs (non inverted mode) COM20=0 & COM21=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR2 = (1<<WGM20) | (1<<WGM21) | (1<<COM21) | (1<<CS21);
}
