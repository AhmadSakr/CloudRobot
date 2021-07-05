/*
 * LCD.h
 *
 *  Created on: Jul 10, 2020
 *      Author: Helmy
 */

#ifndef LCD_H_
#define LCD_H_
#include"std_types.h"
void LCD_Vid_8BitInit(void);
void LCD_Vid_SendChar(unsigned char Data);
void LCD_Vid_SendCommand(unsigned char command);
void LCD_Vid_4BitInit(void);
void LCD_Vid_SendChar4Bit(unsigned char Data);
void LCD_Vid_SendCommand4Bit(unsigned char command);
void LCD_Vid_SendCommand4Bit_test(unsigned char command);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_clearScreen(void);
void LCD_clearScreen_4bit(void);
void LCD_intgerToString_4bit(int data);
void LCD_goToRowColumn_4bit(uint8 row,uint8 col);
void LCD_intgerToString(int data);
void LCD_displayString_4bit(const char *Str);

#endif /* LCD_H_ */
