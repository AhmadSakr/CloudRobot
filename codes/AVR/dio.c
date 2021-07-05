
#include "dio_reg.h"
#include "DIO_Types.h"
#include "bit_math.h"
#include "dio.h"

void DIO_SetPortdirection(DIO_PORT_ID Port_Id ,DIO_Direction Direction)
{
	if (output == Direction)
	{
		switch(Port_Id)
		{
		case PORTAA: DDRA_Reg= 0xff;break;
		case PORTBB: DDRB_Reg= 0xff;break;
		case PORTCC: DDRC_Reg= 0xff;break;
		case PORTDD: DDRD_Reg= 0xff;break;

		}

	}
	else if(input == Direction)
	{
			switch(Port_Id)
			{
			case PORTAA:DDRA_Reg = 0x00;break;
			case PORTBB:DDRB_Reg = 0x00;break;
			case PORTCC:DDRC_Reg = 0x00;break;
			case PORTDD:DDRD_Reg = 0x00;break;
			}
	}
}

void DIO_SetPortValue(DIO_PORT_ID Port_Id,unsigned char value)
{
	switch(Port_Id)
			{
			case PORTAA: PORTA_Reg= value;break;
			case PORTBB: PORTB_Reg= value;break;
			case PORTCC: PORTC_Reg= value;break;
			case PORTDD: PORTD_Reg= value;break;
			}

};
void DIO_SetBinDirection(DIO_PORT_ID Port_Id,DIO_PORT_ID pin_id,DIO_Direction Direction)
{
	if(Port_Id <= PORTDD && pin_id<=pin7)
{	if ( output == Direction )
{
	switch(Port_Id)
				{
				case PORTAA: SET_BIT(DDRA_Reg,pin_id);break;
				case PORTBB: SET_BIT(DDRB_Reg,pin_id);break;
				case PORTCC: SET_BIT(DDRC_Reg,pin_id);break;
				case PORTDD: SET_BIT(DDRD_Reg,pin_id);break;
				}
}
       else if(input == Direction )
	{
	switch(Port_Id)
			{
			case PORTAA : CLEAR_BIT(DDRA_Reg,pin_id) ; break;
			case PORTBB : CLEAR_BIT(DDRB_Reg,pin_id) ; break;
			case PORTCC : CLEAR_BIT(DDRC_Reg,pin_id) ; break;
			case PORTDD : CLEAR_BIT(DDRD_Reg,pin_id) ; break;
			}

}

}
}
void DIO_SetPinValue(DIO_PORT_ID Port_Id,DIO_PORT_ID pin_id,DIO_Value value)
{
	if(Port_Id <= PORTDD && pin_id<=pin7)
	{
if(value == HIGH)
{switch(Port_Id)
{
case PORTAA: SET_BIT(PORTA_Reg,pin_id);break;
case PORTBB: SET_BIT(PORTB_Reg,pin_id);break;
case PORTCC: SET_BIT(PORTC_Reg,pin_id);break;
case PORTDD: SET_BIT(PORTD_Reg,pin_id);break;
}}
else if(value == LOW)
{
	switch(Port_Id)
{
case PORTAA: CLEAR_BIT(PORTA_Reg,pin_id);break;
case PORTBB: CLEAR_BIT(PORTB_Reg,pin_id);break;
case PORTCC: CLEAR_BIT(PORTC_Reg,pin_id);break;
case PORTDD: CLEAR_BIT(PORTD_Reg,pin_id);break;
}
}
}};
DIO_Value DIO_GetPinValue(DIO_PORT_ID Port_Id,DIO_PORT_ID pin_id)
	{DIO_Value val;

		if(Port_Id <= PORTDD && pin_id<=pin7)
		{		switch (Port_Id)
			{   case PORTAA : val = GET_BIT(PINA_Reg,pin_id);break;
				case PORTBB : val = GET_BIT(PINB_Reg,pin_id);break;
				case PORTCC : val = GET_BIT(PINC_Reg,pin_id);break;
				case PORTDD : val = GET_BIT(PIND_Reg,pin_id);break;
			}
		}
		return val;
	}







