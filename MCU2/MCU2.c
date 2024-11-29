/******************************************************************************
 *
 * Module:main
 *
 * File Name: HMI_ECU.c
 *
 * Description: Source file for the TIMER0 driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/
#include "MCU2.h"

#include"uart.h"
#include<util/delay.h>
#include<avr/io.h>
#include"common_macros.h"
#include "leds.h"
#include"buzzer.h"
#include"Timer1_Fast_PWM.h"
#include"dc_motor.h"
#include "adc.h"

void main()
{
	/*config the uart to send info between the MCUs*/
	UART_ConfigType UART_config={BITS_8,Disabled,One_bit,BaudRate9600};
	/*initialize the motor*/
	DcMotor_Init();
	/*initialize the uart*/
	UART_init(&UART_config);
	/*initialize the ADC*/
	ADC_config ADC_CONTROLLER={internal2_56,preclck_64};
	ADC_init(&ADC_CONTROLLER);
	/*initialize the leds*/
	LEDS_INIT();
	/*initialize the buzzer*/
	Buzzer_init();
	/*enable the global interrupts*/
	SET_BIT(SREG,7);
	while(1)
	{
		Timer1_Fast_PWM_Init(deg_0);
		Buzzer_off();
		while(g_operation==LIGHTEN_GREEN_LED)
		{
			LEDS_LIGHTEN(LIGHTEN_GREEN_LED);
			DcMotor_Rotate(CW, ADC_readChannel(2)/4);
			_delay_ms(1);
		}
		while(g_operation==LIGHTEN_YELLOW_LED)
		{
			LEDS_LIGHTEN(LIGHTEN_YELLOW_LED);
			DcMotor_Rotate(CW,ADC_readChannel(2)/4);
			_delay_ms(1);
		}
		while(g_operation==LIGHTEN_RED_LED)
		{
			LEDS_LIGHTEN(LIGHTEN_RED_LED);
			DcMotor_Rotate(CW,ADC_readChannel(2)/4);
			_delay_ms(1);
		}
		while(g_operation==STOP_MACHINE)
		{
			DcMotor_Rotate(STOP_MOTOR,ZeroSpeed);
			_delay_ms(1);
		}
		while(g_operation==EMERGENCY)
		{
			LEDS_LIGHTEN(LIGHTEN_RED_LED);
			Buzzer_on();
			DcMotor_Rotate(CW,ADC_readChannel(2)/4);
			_delay_ms(1);
		}
		while(g_operation==ABNORMAL)
		{
			LEDS_LIGHTEN(LIGHTEN_RED_LED);
			Buzzer_on();
			DcMotor_Rotate(STOP_MOTOR,ZeroSpeed);
			Timer1_Fast_PWM_Init(deg_90);
			_delay_ms(5000);
		}

	}
}
