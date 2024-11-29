/*
 * Timer1_Fast_PWM_Init.c
 *
 *  Created on: Aug 31, 2023
 *      Author: saber
 */
#include<avr/io.h>
#include"gpio.h"
void Timer1_Fast_PWM_Init(unsigned short duty_cycle)
{
	GPIO_setupPinDirection(PORTD_ID, PIN5_ID, PIN_OUTPUT);
	TCNT1 = 0;		/* Set timer1 initial count to zero */
	ICR1 = 2499;	/* Set TOP count for timer1 in ICR1 register */

	OCR1A = duty_cycle; /* Set the compare value */

	/* Configure timer control register TCCR1A
     * 1. Clear OC1A on compare match (non inverting mode) COM1A1=1 COM1A0=0
     * 2. Disconnect OC1B  COM1B0=0 COM1B1=0
     * 3. FOC1A=0 FOC1B=0 because these bits are only active in case non-pwm mode
     * 4. Fast Pwm Mode with the TOP in ICR1 WGM10=0 WGM11=1 (Mode Number 14)
	 */
	TCCR1A = (1<<WGM11) | (1<<COM1A1);

	/* Configure timer control register TCCR1B
	 * 1. Fast Pwm Mode with the TOP in ICR1 WGM12=1 WGM13=1 (Mode Number 14)
	 * 2. Prescaler = F_CPU/64
     */
	TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS10) | (1<<CS11);
}
