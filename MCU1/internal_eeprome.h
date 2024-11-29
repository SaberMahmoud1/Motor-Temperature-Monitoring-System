/*
 * internal_eeprom.h
 *
 *  Created on: Aug 30, 2023
 *      Author: Saber Mahmoud
 */

#ifndef INTERNAL_EEPROM_H_
#define INTERNAL_EEPROM_H_

#include "std_types.h"


void INTERNAL_EEPROM_writeByte(uint16 Address, uint8 Data);
uint8 INTERNAL_EEPROM_readByte(uint16 Address);

#endif /* INTERNAL_EEPROM_H_ */
