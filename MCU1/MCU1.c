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
#include"timer_pwm.h"
#include"timer1_compare_normal.h"
#include"uart.h"
#include"common_macros.h"
#include"std_types.h"
#include<avr/io.h>
#include"internal_eeprome.h"
#include "gpio.h"
#include "MCU1.h"
#include "lm35_sensor.h"
#include "watch_dog.h"
#include<util/delay.h>

void seconds_counter(void);
int main(void)
{
	Timer1_setCallBack(seconds_counter);
	/*choose a pin for the push button*/
	GPIO_setupPinDirection(PUSH_BUTTON_PORT,PUSH_BUTOON_PIN, PIN_INPUT);
	/*config the uart to send info between the MCUs*/
	UART_ConfigType UART_config={BITS_8,Disabled,One_bit,BaudRate9600};
	/*config the timer to Compare mode*/
	Timer1_ConfigType TIMER1_config={0,7812,clk_1024,CTC};
	/*initialize the motor*/
	DcMotor_Init();
	/*initialize the uart*/
	UART_init(&UART_config);
	/*initialize the temperature sensor*/
	LM35_INIT();
	/*enable the global interrupts*/
	SET_BIT(SREG,7);

	/*initialize the state of MCU1 to normal*/
	INTERNAL_EEPROM_writeByte(storedAddress, NORMAL);
	_delay_ms(1);
	readValue=INTERNAL_EEPROM_readByte(storedAddress);
	while(1)
	{
		while(readValue==NORMAL)
		{
			/*read the temperature */
			temp=LM35_getTemperature();
			if(temp<20)
			{
				/*rotate the motor*/
				DcMotor_Rotate(STOP_MOTOR,ZeroSpeed);
				/*send the  the temperature message to MCU2*/
				UART_sendByte(LIGHTEN_GREEN_LED);
			}
			else if(temp>=20 && temp<40)
			{
				/*in case temp = 20 the equation =0 and if the duty =0 the speed will be max*/
				if(temp==20)
				{
					DcMotor_Rotate(STOP_MOTOR, ZeroSpeed);
				}
				/*rotate the motor*/
				else
				DcMotor_Rotate(CW,(temp-20)*5);
				/*send the  the temperature message to MCU2*/
				UART_sendByte(LIGHTEN_YELLOW_LED);
			}
			else if(temp>=40 && temp <= 50)
			{
				/*rotate the motor*/
				DcMotor_Rotate(CW,MAX_SPEED);
				/*send the  the temperature message to MCU2*/
				UART_sendByte(LIGHTEN_RED_LED);
				while(GPIO_readPin(PUSH_BUTTON_PORT,PUSH_BUTOON_PIN)&&(temp>=40 && temp <= 50))
				{

					UART_sendByte(STOP_MACHINE);
					temp=LM35_getTemperature();
				}

			}
			else
			{
				INTERNAL_EEPROM_writeByte(storedAddress, EMERGENCY);
				_delay_ms(1);
				//read the state from the internal EEPROM
				readValue=INTERNAL_EEPROM_readByte(storedAddress);

			}

		}
		while(readValue==EMERGENCY)
		{
			/*count time*/
			/*rotate the motor*/
			DcMotor_Rotate(CW,MAX_SPEED);
			UART_sendByte(EMERGENCY);
			time_in_seconds=0;
			Timer1_init(&TIMER1_config);
			while(temp>50 && readValue==EMERGENCY)
			{
				temp=LM35_getTemperature();
				if(time_in_seconds==7)
				{
					INTERNAL_EEPROM_writeByte(storedAddress, ABNORMAL);
					_delay_ms(1);
					readValue=INTERNAL_EEPROM_readByte(storedAddress);
					break;
				}
			}
			if(temp <= 50)
			{
				INTERNAL_EEPROM_writeByte(storedAddress, NORMAL);
				_delay_ms(1);
				readValue=INTERNAL_EEPROM_readByte(storedAddress);
			}
		}
		while(readValue==ABNORMAL)
		{
			//read the state from the internal EEPROM
			readValue=INTERNAL_EEPROM_readByte(storedAddress);
			/*rotate the motor*/
			DcMotor_Rotate(CW,MAX_SPEED);
			UART_sendByte(ABNORMAL);
			WDT_ON();
		}


	}
}

void seconds_counter()
{
	time_in_seconds++;
}
