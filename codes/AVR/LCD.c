/*
 * LCD.c
 *
 *  Created on: Jul 10, 2020
 *      Author: Helmy
 */
/* Description ! 16x2 Character LCD for chip LMB161A
 *
 */
/********************************** Header Files INCLUSIONS ****************************/
#include <avr/delay.h>
#include "dio.h"
#include "LCDCONFIG.h"
#include"std_types.h"
union
{
	struct
	{
		unsigned char b0:1;
		unsigned char b1:1;
		unsigned char b2:1;
		unsigned char b3:1;
		unsigned char b4:1;
		unsigned char b5:1;
		unsigned char b6:1;
		unsigned char b7:1;
	}BITs;
	unsigned char LCD_BYTE;
}LCD_INFO;
/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7(4bit)  |
 |        PD6|---------------->|D6(4bit)  |
 |        PD5|---------------->|D5(4bit)  |
 |        PD4|---------------->|D4(4bit)  |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PC2|---------------->|E         |
 |        PC1|---------------->|RW        |
 |        PC0|---------------->|RS        |
 -----------                   ----------
 */
void LCD_Vid_SendCommand(unsigned char command)
{
DIO_SetPinValue(PORTCONTROL,RS,LOW);
DIO_SetPinValue(PORTCONTROL,RW,LOW);
DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPortValue(PORTDATA,command);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);
}

void LCD_Vid_SendChar(unsigned char Data)
{
	DIO_SetPinValue(PORTCONTROL,RS,HIGH);
	DIO_SetPinValue(PORTCONTROL,RW,LOW);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);
	DIO_SetPortValue(PORTDATA,Data);
	DIO_SetPinValue(PORTCONTROL,E,LOW);
	_delay_ms(2);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);


}
void LCD_Vid_8BitInit(void)
{DIO_SetBinDirection(PORTCONTROL,RS,output);
DIO_SetBinDirection(PORTCONTROL,RW,output);
DIO_SetBinDirection(PORTCONTROL,E,output);
DIO_SetPortdirection(PORTDATA,output);
_delay_ms(30);
LCD_Vid_SendCommand(FunctionSet_8Bit);
_delay_ms(2);
LCD_Vid_SendCommand(DisplayON);
_delay_ms(2);
LCD_Vid_SendCommand(DisplayClear);
_delay_ms(2);
LCD_Vid_SendCommand(EntryModeSet);
}
void LCD_Vid_SendCommand4Bit_test(unsigned char command)
{int x;
DIO_SetPinValue(PORTCONTROL,RS,LOW);
DIO_SetPinValue(PORTCONTROL,RW,LOW);
//x=command>>4;
//x=x&0x0f;
x=command;
x=x&0xf0;
LCD_INFO.LCD_BYTE=x;
DIO_SetPinValue(PORTDATA,0,LCD_INFO.BITs.b4);
DIO_SetPinValue(PORTDATA,1,LCD_INFO.BITs.b5);
DIO_SetPinValue(PORTDATA,2,LCD_INFO.BITs.b6);
DIO_SetPinValue(PORTDATA,3,LCD_INFO.BITs.b7);


DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);

LCD_INFO.LCD_BYTE=x;
DIO_SetPinValue(PORTDATA,0,LCD_INFO.BITs.b4);
DIO_SetPinValue(PORTDATA,1,LCD_INFO.BITs.b5);
DIO_SetPinValue(PORTDATA,2,LCD_INFO.BITs.b6);
DIO_SetPinValue(PORTDATA,3,LCD_INFO.BITs.b7);

DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);


//*****************************************
x=command<<4;
x=x&0xf0;
LCD_INFO.LCD_BYTE=x;
DIO_SetPinValue(PORTDATA,0,LCD_INFO.BITs.b4);
DIO_SetPinValue(PORTDATA,1,LCD_INFO.BITs.b5);
DIO_SetPinValue(PORTDATA,2,LCD_INFO.BITs.b6);
DIO_SetPinValue(PORTDATA,3,LCD_INFO.BITs.b7);


DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);
}

void LCD_Vid_SendCommand4Bit(unsigned char command)
{
	unsigned int  x;
	DIO_SetPinValue(PORTCONTROL,RS,LOW);
	DIO_SetPinValue(PORTCONTROL,RW,LOW);

x=command;
x=x&0xf0;
LCD_INFO.LCD_BYTE=x;
DIO_SetPinValue(PORTDATA,0,LCD_INFO.BITs.b4);
DIO_SetPinValue(PORTDATA,1,LCD_INFO.BITs.b5);
DIO_SetPinValue(PORTDATA,2,LCD_INFO.BITs.b6);
DIO_SetPinValue(PORTDATA,3,LCD_INFO.BITs.b7);

DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);
//*****************************************
x=command<<4;
x=x&0xf0;
LCD_INFO.LCD_BYTE=x;
DIO_SetPinValue(PORTDATA,0,LCD_INFO.BITs.b4);
DIO_SetPinValue(PORTDATA,1,LCD_INFO.BITs.b5);
DIO_SetPinValue(PORTDATA,2,LCD_INFO.BITs.b6);
DIO_SetPinValue(PORTDATA,3,LCD_INFO.BITs.b7);

DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);
}

void LCD_Vid_SendChar4Bit(unsigned char Data)
{int x;
	DIO_SetPinValue(PORTCONTROL,RS,HIGH);
	DIO_SetPinValue(PORTCONTROL,RW,LOW);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);

	x=Data;
	x=x&0xf0;
	LCD_INFO.LCD_BYTE=x;
	DIO_SetPinValue(PORTDATA,0,LCD_INFO.BITs.b4);
	DIO_SetPinValue(PORTDATA,1,LCD_INFO.BITs.b5);
	DIO_SetPinValue(PORTDATA,2,LCD_INFO.BITs.b6);
	DIO_SetPinValue(PORTDATA,3,LCD_INFO.BITs.b7);
	DIO_SetPinValue(PORTCONTROL,E,LOW);
	_delay_ms(2);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);

	//*****************************************
	x=Data<<4;
	x=x&0xf0;
	LCD_INFO.LCD_BYTE=x;
	DIO_SetPinValue(PORTDATA,0,LCD_INFO.BITs.b4);
	DIO_SetPinValue(PORTDATA,1,LCD_INFO.BITs.b5);
	DIO_SetPinValue(PORTDATA,2,LCD_INFO.BITs.b6);
	DIO_SetPinValue(PORTDATA,3,LCD_INFO.BITs.b7);
	DIO_SetPinValue(PORTCONTROL,E,LOW);
	_delay_ms(2);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);

}

void LCD_Vid_4BitInit(void)
{
DIO_SetBinDirection(PORTCONTROL,RS,output);
DIO_SetBinDirection(PORTCONTROL,RW,output);
DIO_SetBinDirection(PORTCONTROL,E,output);
DIO_SetBinDirection(PORTDATA,0,output);
DIO_SetBinDirection(PORTDATA,1,output);
DIO_SetBinDirection(PORTDATA,2,output);
DIO_SetBinDirection(PORTDATA,3,output);
_delay_ms(30);
LCD_Vid_SendCommand4Bit_test(FunctionSet_4bit);
_delay_ms(2);
LCD_Vid_SendCommand4Bit(DisplayON);
_delay_ms(2);
LCD_Vid_SendCommand4Bit(DisplayClear);
_delay_ms(2);
LCD_Vid_SendCommand4Bit(EntryModeSet);

}
void LCD_displayString_4bit(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_Vid_SendChar4Bit(Str[i]);
		i++;
	}

}


void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_Vid_SendChar(Str[i]);
		i++;
	}

}

void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 Address;

	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}
	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_Vid_SendCommand(Address | SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
   LCD_displayString(buff);
}

void LCD_clearScreen(void)
{
	LCD_Vid_SendCommand(DisplayClear); //clear display
}
void LCD_clearScreen_4bit(void)
{
	LCD_Vid_SendCommand4Bit(DisplayClear); //clear display
}

void LCD_intgerToString_4bit(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
   LCD_displayString_4bit(buff);
}
void LCD_goToRowColumn_4bit(uint8 row,uint8 col)
{
	uint8 Address;

	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}
	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_Vid_SendCommand4Bit(Address | SET_CURSOR_LOCATION);
}
void LCD_voidGoto(u8 y,u8 x)
{
	u8 arr[2]={0x80,0xc0};
	LCD_Vid_SendCommand4Bit(arr[y] + x);
}

