 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "std_types.h"
/***********************************************************************
 * type definitions
 ***********************************************************************/
typedef enum{BITS_5,BITS_6=2,BITS_7=4,BITS_8=6,BITS_9=6}UART_BitData;
typedef enum{Disabled,EvenParity=0x20,OddParity=0x30}UART_Parity;
typedef enum{One_bit,Two_bits=0x08}UART_StopBit;
typedef enum{BaudRate2400=2400,BaudRate4800=4800,BaudRate9600=9600,BaudRate14k=14400,BaudRate19k=19200,BaudRate28k=29800,BaudRate38k=38400,BaudRate57k=57600,BaudRate76k=76800,BaudRate115k=115200,BaudRate230k=230400,BaudRate250k=250000,BaudRatehalfM=500000,BaudRateM=1000000}UART_BaudRate;
typedef struct{
 UART_BitData bit_data;
 UART_Parity parity;
 UART_StopBit stop_bit;
 UART_BaudRate baud_rate;
}UART_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(const UART_ConfigType * Config_Ptr);
/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
