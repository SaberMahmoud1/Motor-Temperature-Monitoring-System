/******************************************************************************
 *
 * Module: timer1
 *
 * File Name: timer_pwm.c
 *
 * Description: Source file for the TIMER0 driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/
#include"timer1_compare_normal.h"
#include"common_macros.h"
#include<avr/io.h>
#include<avr/interrupt.h>
/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;
/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtr != NULL_PTR)
		{
			/* Call the Call Back function in the application*/
			(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
		}
}
ISR(TIMER1_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
		{
			/* Call the Call Back function in the application*/
			(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
		}
}
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void Timer1_init(const Timer1_ConfigType * Config_Ptr)
{
	SET_VALUE_IN_REG(TCNT1,Config_Ptr->initial_value);	/* Set timer1 initial value */
	SET_VALUE_IN_REG(TCCR1B,0);
	if(Config_Ptr->mode==CTC)
	{

		SET_VALUE_IN_REG(OCR1A,Config_Ptr->compare_value);	/* Set the Compare value *) */

		SET_BIT(TIMSK,OCIE1A);	/* Enable Timer1 Compare A Interrupt */
			/* Configure timer control register TCCR1B
			 * 1. CTC Mode WGM12=1 WGM13=0 (Mode Number 4)
			 */
			SET_BIT(TCCR1B,WGM12);
	}
	else if(Config_Ptr->mode==NORMAL)
	{
		SET_BIT(TIMSK,TOIE1);		/*enable overflow interrupt*/
	}
	/* Configure timer control register TCCR1A
				 * 1. Disconnect OC1A and OC1B  COM1A1=0 COM1A0=0 COM1B0=0 COM1B1=0
				 * 2. FOC1A=1 FOC1B=0 non PWM mode
				 * 3. CTC Mode WGM10=0 WGM11=0 (Mode Number 4)
				 */
				TCCR1A = (1<<FOC1A);
	TCCR1B|=Config_Ptr->prescaler;
}
void Timer1_deInit(void)
{
	SET_VALUE_IN_REG(TCCR1A,0);
	SET_VALUE_IN_REG(TCCR1B,0);
}
void Timer1_setCallBack(void(*a_ptr)(void))
{

	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}
