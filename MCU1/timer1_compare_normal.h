/******************************************************************************
 *
 * Module: TWI(I2C)
 *
 * File Name: twi.h
 *
 * Description: Header file for the TWI(I2C) AVR driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/

#ifndef TIMER1_COMPARE_NORMAL_H_
#define TIMER1_COMPARE_NORMAL_H_
#include"std_types.h"
/***********************************************************************
 * type definitions
 ***********************************************************************/
typedef enum{NORMAL=0x00,CTC=0x04}Timer1_Mode;
typedef enum{NO_CLK,clk_1,clk_8,clk_64,clk_256,clk_1024,External_clock_source_on_T1_pin_falling_edge,External_clock_source_on_T1_pin_rising_edge}Timer1_Prescaler;
typedef struct {
 uint16 initial_value;
 uint16 compare_value; // it will be used in compare mode only.
 Timer1_Prescaler prescaler;
 Timer1_Mode mode;
} Timer1_ConfigType;
/***********************************************************************
 * functions prototype
 ***********************************************************************/
void Timer1_init(const Timer1_ConfigType * Config_Ptr);
/*
● Description
⮚ Function to initialize the Timer driver
● Inputs: pointer to the configuration structure with type
Timer1_ConfigType.
● Return: None
*/
void Timer1_deInit(void);
/*
● Description
⮚ Function to disable Timer1.
● Inputs: None
● Return: None
*/
void Timer1_setCallBack(void(*a_ptr)(void));
/*
● Description
⮚ Function to set the Call Back function address.
● Inputs: pointer to Call Back function.
● Return: None
*/
#endif /* TIMER1_COMPARE_NORMAL_H_ */
