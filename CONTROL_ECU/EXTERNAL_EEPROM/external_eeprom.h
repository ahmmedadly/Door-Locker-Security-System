  /******************************************************************************
 *
 * File Name: external_eeprom.h
 *
 * Description: header file for External EEPROM driver
 *
 * Author: AHMED ADLY
 *
 *******************************************************************************/

#ifndef EEPROM_24C16_H_
#define EEPROM_24C16_H_

#include "../std_types.h"

#define EEPROM_SUCCESS 1
#define EEPROM_ERROR   0
/*
 * write one byte into specific address to External EEPROM using TWI
 * single meesage
 */
uint8 EEPROM_writeByte(uint16 address, uint8* data);

/*
 * read one byte from specific address at External EEPROM using TWI
 * combined message
 */
uint8 EEPROM_readByte(uint16 address, uint8* data);

#endif /* EEPROM_24C16_H_ */
