/*
 * main.c
 *
 *  Created on: Jun 20, 2020
 *      Author: Helmy
 */
#include <avr/delay.h>
#include <avr/interrupt.h>
#include"UART.h"
#include"Reg.h"
#include"dio.h"
#include "adc.h"
#include "LCD.h"
#include "bit_math.h"
#define SREG_Reg    *((volatile unsigned char *)0x5F)
int x,y;
int t, r,g;
char arr[4]={'\n','\n','\n','\n'};
char Rec_UDR;
char Temp_UDR;
//proto type
/* Include BIT_MATH file */
int main(void)
{
	SREG_Reg=0b10000000;//global interrput enable

int GAS=0;
uint32 temp;
LCD_Vid_4BitInit(); /* initialize LCD driver */
	USART_vidinit();
	ADC_init(); /* initialize ADC driver */
DIO_SetPortdirection(PORTBB,output);
LCD_displayString_4bit("Direction= ");


while(1){



	LCD_goToRowColumn_4bit(0,10);/* display the number every time at this position */
//****MOTOR Driver HW_95 and DC motor and linear follower *****//
/* display the number every time at this position */
	if(Temp_UDR=='w')
				{
						DIO_SetPinValue(PORTBB,pin3,LOW);
						DIO_SetPinValue(PORTBB,pin4,HIGH);
						DIO_SetPinValue(PORTBB,pin5,LOW);
						DIO_SetPinValue(PORTBB,pin6,HIGH);
						LCD_displayString_4bit("Forward");
						Temp_UDR=0;
				}
		else if(Temp_UDR=='a')
				{


				DIO_SetPinValue(PORTBB,pin3,LOW);
				DIO_SetPinValue(PORTBB,pin4,LOW);
				DIO_SetPinValue(PORTBB,pin5,LOW);
				DIO_SetPinValue(PORTBB,pin6,HIGH);
	  			LCD_displayString_4bit("Left  ");
				Temp_UDR=0;

				}
			else if(Temp_UDR=='s')
				{

				DIO_SetPinValue(PORTBB,pin3,LOW);
				DIO_SetPinValue(PORTBB,pin4,LOW);
				DIO_SetPinValue(PORTBB,pin5,LOW);
				DIO_SetPinValue(PORTBB,pin6,LOW);
				LCD_displayString_4bit("Stop  ");
				Temp_UDR=0;
				}
			else if(Temp_UDR=='d')
				{

				DIO_SetPinValue(PORTBB,pin3,LOW);
				DIO_SetPinValue(PORTBB,pin4,HIGH);
				DIO_SetPinValue(PORTBB,pin5,LOW);
				DIO_SetPinValue(PORTBB,pin6,LOW);
				LCD_displayString_4bit("Right  ");
				Temp_UDR=0;

				}
LCD_goToRowColumn_4bit(1,0);
/* display this string "Temp =" only once at LCD */
LCD_displayString_4bit("Temp=");
temp = ADC_readChannel(2); /* read channel two where the temp sensor is connect */
temp = (temp*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/
LCD_intgerToString_4bit(temp); /* display the temp on LCD screen */
/* display character 'C' on the screen "Temp =   C" */
 LCD_Vid_SendChar4Bit('C');
 LCD_goToRowColumn_4bit(1,9);
/* display this string "gas=" only once at LCD */
 LCD_displayString_4bit("Gas=");
 LCD_goToRowColumn_4bit(1,13);
GAS = ADC_readChannel(1);
///*** this condition is for gas read is 2 or 3 digit to ignore the digit  between them we do this ******//
 if(GAS<100){
LCD_intgerToString_4bit(0);}
/* read channel one where the temp sensor is connect */
LCD_intgerToString_4bit(GAS); /* display the GAS on LCD screen */

//	USR_u8Recive();


	if(Temp_UDR=='t')
			{	t=temp;
				for(x=0;x<=3;x++)
				{	r=t%10;
					arr[x]=r;
				t=t/10;}
				for(x=3;x>=0;x--)
					{
					if(arr[x]!=0){
					y=x;
					break;
					}}
				USR_send_string_Uart("temperature=");
					for(x=y;x>=0;x--)
				{
										USR_vidSend_Num(arr[x]);

							}

					USR_send_string_Uart("\n");
				Temp_UDR='z';
			}
			if(Temp_UDR=='T')
			{	t=temp;
				for(x=0;x<=3;x++)
				{	r=t%10;
					arr[x]=r;
				t=t/10;}
				for(x=3;x>=0;x--)
					{
					if(arr[x]!=0){
					y=x;
					break;
					}}
				USR_send_string_Uart("temperature=");
					for(x=y;x>=0;x--)
				{
										USR_vidSend_Num(arr[x]);

							}
//
					USR_send_string_Uart("\r");

				Temp_UDR='z';
			}



	if(Temp_UDR=='g')
			{
		 g=GAS;
						for(x=0;x<=3;x++)
						{	r=g%10;
							arr[x]=r;
						g=g/10;}
						for(x=3;x>=0;x--)
										{
										if(arr[x]!=0){
										y=x;
										break;
										}}
						USR_send_string_Uart("Gas=");

						for(x=y;x>=0;x--)
							{
							USR_vidSend_Num(arr[x]);

							}
						USR_send_string_Uart("\n");
						Temp_UDR='z';

			}



	if(Temp_UDR=='G')
				{
			 g=GAS;
							for(x=0;x<=3;x++)
							{	r=g%10;
								arr[x]=r;
							g=g/10;}
							for(x=3;x>=0;x--)
											{
											if(arr[x]!=0){
											y=x;
											break;
											}}
							USR_send_string_Uart("Gas=");

							for(x=y;x>=0;x--)
								{
								USR_vidSend_Num(arr[x]);

								}
							USR_send_string_Uart("\r");

							Temp_UDR='z';

				}


}
	return 0;
}

ISR( USART_RXC_vect){
	Rec_UDR=UDR;
	if((Rec_UDR!='\r\n')&&(Rec_UDR!='\n')&&(Rec_UDR!='\r')){
		Temp_UDR=Rec_UDR;


}

}


