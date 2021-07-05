/*
 * LCDCONFIG.h
 *
 *  Created on: Jul 10, 2020
 *      Author: Helmy
 */

#ifndef LCDCONFIG_H_
#define LCDCONFIG_H_

#define RS 5
#define RW 6
#define E 7
#define FunctionSet_8Bit 	0b00111000
#define FunctionSet_8Bit_F10 	0b00111100

#define FunctionSet_4bit    0b00101100
#define DisplayON 			0b00001110
#define DisplayOFF 			0b00001010
#define DisplayClear 		0b00000001
#define EntryModeSet	 	0b00000110
#define EntryModeSetARC 	0b00000101
#define SET_CURSOR_LOCATION 0x80
#define PORTCONTROL 		PORTCC
#define PORTDATA 			PORTCC



#endif /* LCDCONFIG_H_ */
