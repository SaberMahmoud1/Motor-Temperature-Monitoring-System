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
#ifndef BUZZER_H_
#define BUZZER_H_
/***********************************************************************
 * type definitions
 ***********************************************************************/
#define BUZZER_PORT_ID 		PORTA_ID
#define BUZZER_BIN_ID 		PIN4_ID
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void Buzzer_init();
/*● Description
⮚ Setup the direction for the buzzer pin as output pin through the
GPIO driver.
⮚ Turn off the buzzer through the GPIO.
● Inputs: None
● Return: None
*/
void Buzzer_on(void);
/*● Description
⮚ Function to enable the Buzzer through the GPIO.
● Inputs: None
● Return: None
*/
void Buzzer_off(void);
/*● Description
⮚ Function to disable the Buzzer through the GPIO.
● Inputs: None
● Return: No
*/


#endif /* BUZZER_H_ */
