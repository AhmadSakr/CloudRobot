

#ifndef DIO_DIO_TYPES_H_
#define DIO_DIO_TYPES_H_
typedef enum
{
input,
output
}DIO_Direction;
typedef enum
{
	PORTAA,
	PORTBB,
	PORTCC,
	PORTDD,
}DIO_PORT_ID;
typedef enum
{
	LOW,
	HIGH
}DIO_Value;
typedef enum
{ pin0,
  pin1,
  pin2,
  pin3,
 pin4,
 pin5,
 pin6,
 pin7}DIO_Pin_ID;

#endif /* DIO_DIO_TYPES_H_ */
