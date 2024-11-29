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
#include"buzzer.h"
#include"common_macros.h"
#include"gpio.h"
void Buzzer_init()
{
	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_BIN_ID,PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_BIN_ID, LOGIC_LOW);
}
void Buzzer_on(void)
{
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_BIN_ID, LOGIC_HIGH);
}
void Buzzer_off(void)
{
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_BIN_ID, LOGIC_LOW);
}
