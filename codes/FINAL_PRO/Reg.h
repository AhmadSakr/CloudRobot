/*
 * dio_reg.h
 *
 *  Created on: Feb 25, 2020
 *      Author: helmy_
 */

#ifndef DIO_DIO_REG_H_
#define DIO_DIO_REG_H_

#define PORTA_Reg   *((volatile unsigned char* )0x3B)
#define DDRA_Reg    *((volatile unsigned char* )0x3A)
#define PINA_Reg    *((volatile unsigned char* )0x39)

#define PORTB_Reg   *((volatile unsigned char* )0x38)
#define DDRB_Reg    *((volatile unsigned char* )0x37)
#define PINB_Reg    *((volatile unsigned char* )0x36)

#define PORTC_Reg   *((volatile unsigned char* )0x35)
#define DDRC_Reg    *((volatile unsigned char* )0x34)
#define PINC_Reg    *((volatile unsigned char* )0x33)

#define PORTD_Reg   *((volatile unsigned char* )0x32)
#define DDRD_Reg    *((volatile unsigned char* )0x31)
#define PIND_Reg    *((volatile unsigned char* )0x30)

#define MCUCR_Reg   *((volatile unsigned char *)0x55)
#define SREG_Reg    *((volatile unsigned char *)0x5F)
#define GICR_Reg   *((volatile unsigned char *)0x5B)

#endif /* DIO_DIO_REG_H_ */
