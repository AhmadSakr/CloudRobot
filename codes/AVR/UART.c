/*
 * UART.c
 *
 *  Created on: Oct 19, 2020
 *      Author: Helmy
 */
#include "bit_math.h"
#include <avr/io.h>
void USART_vidinit(void)
{	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,RXCIE);

	UCSRC=0b10000110;
	UBRRH=0;
	UBRRL=51;//Baud rate 9600 at 8MHZ

}
void USR_vidSend(unsigned char Data){
	UDR=Data;
	while(GET_BIT(UCSRA,5)==0);
}
void USR_vidSend_Num(unsigned char Data){
	UDR=Data+48;
	while(GET_BIT(UCSRA,5)==0);
}
unsigned char USR_u8Recive(void){
		while(GET_BIT(UCSRA,7)==0);
		return UDR;
}

void USR_send_string_Uart(const char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0')
	{
		USR_vidSend(Str[i]);
		i++;
	}

}
