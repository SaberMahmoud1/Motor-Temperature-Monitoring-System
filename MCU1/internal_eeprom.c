/*
 * internal_eeprom.c
 *
 *  Created on: Aug 30, 2023
 *      Author: Saber Mahmoud
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "common_macros.h"
#include "std_types.h"
#include "internal_eeprome.h"

void INTERNAL_EEPROM_writeByte(uint16 Address, uint8 Data) {

	/*Wait for completion of previous write*/
	while(EECR & (1<<EEWE));
	while(SPMCR & (1<<SPMEN));
	/*Put address in address register*/
	EEARH = Address>>8;
	EEARL = Address;
	/*Put data in data register*/
	EEDR = Data;
	/*
	 * Those two statements must be within 4clock cycles apart, thus
	 * must use assembly.
	 */
	asm("SBI 0x1C,2");
	asm("SBI 0x1C,1");

}

uint8 INTERNAL_EEPROM_readByte(uint16 Address) {
	/*Wait for completion of previous write*/
	while(EECR & (1<<EEWE));
	while(SPMCR & (1<<SPMEN));

	/*Put address of data to be read in register*/
	EEARH = Address>>8;
	EEARL = Address;
	/*Start EEPROM read by writing EEMWE*/
	SET_BIT(EECR,EERE);

	/*Return data from  data register*/
	return EEDR;
}
