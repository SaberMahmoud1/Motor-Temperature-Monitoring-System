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
#include"timer_pwm.h"
#include<avr/io.h>
#include<util/delay.h>
#include"gPio.h"
#include"common_macros.h"

void Timer0_PWM_Init(uint8 set_duty_cycle)
{
	if(set_duty_cycle==0)
	{
		TCCR0=0;
		OCR0=0;
		return;
	}
	SET_VALUE_IN_REG(TCNT0,0); // Set Timer Initial Value to 0
	SET_VALUE_IN_REG(OCR0,set_duty_cycle); //Set Compare value

	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
