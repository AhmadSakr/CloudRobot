/*
 * UART.h
 *
 *  Created on: Oct 19, 2020
 *      Author: Helmy
 */

#ifndef UART_H_
#define UART_H_
void USART_vidinit(void);
void USR_vidSend_Num(unsigned char Data);

unsigned char USR_u8Recive(void);
void USR_vidSend(unsigned char Data);
#endif /* UART_H_ */
