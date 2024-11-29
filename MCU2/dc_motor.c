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
#include"dc_motor.h"
#include"gpio.h"
#include"timer2_fast_PWM.h"
/*
 *Description
➢ The Function responsible for setup the direction for the two
motor pins through the GPIO driver.
➢ Stop at the DC-Motor at the beginning through the GPIO driver.
 *
 */
void DcMotor_Init(void)
{
	/* configure pin PC0 and PC1 as output pins */
	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN1,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN2,PIN_OUTPUT);
	/* Motor is stop at the beginning */
	GPIO_writePort(PORTB_ID, STOP_MOTOR);
}
/*
 * • Description:
➢ The function responsible for rotate the DC Motor CW/ or A-CW or
stop the motor based on the state input state value.
➢ Send the required duty cycle to the PWM driver based on the
required speed value.
 */
void DcMotor_Rotate(uint8 state,uint8 speed)
{
	Timer2_PWM_Init(speed);
	switch(state)
	{
	case CW:
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN2, LOGIC_LOW);break;
	case A_CW:
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN2, LOGIC_HIGH);break;
	case STOP_MOTOR:
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN2, LOGIC_LOW);break;
	}
}
