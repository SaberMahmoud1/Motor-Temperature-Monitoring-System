 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56F
#define ADC_CHANNEL_ID 2
typedef enum{AREF,AVCC=0x40,internal2_56=0xC0}ADC_REFRANCE_VOLTAGE;
typedef enum{Preclk_2=0x00,Preclck_4=0x02,preclck_8=0x03,preclck_16=0x04,preclck_32=0x05,preclck_64=0x06,preclck_128=0x07}ADC_PRESCALER;
typedef struct {ADC_REFRANCE_VOLTAGE ref_volt; ADC_PRESCALER pre;}ADC_config;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_config *ADC_config_ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
