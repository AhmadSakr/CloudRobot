
#ifndef DIO_DIO_H_
#define DIO_DIO_H_
#include "DIO_Types.h"

void DIO_SetPortdirection(DIO_PORT_ID Port_Id,DIO_Direction Direction);

void DIO_SetPortValue(DIO_PORT_ID Port_Id,unsigned char value);

void DIO_SetBinDirection(DIO_PORT_ID Port_Id,DIO_PORT_ID pin_id,DIO_Direction Direction);

void DIO_SetPinValue(DIO_PORT_ID Port_Id,DIO_PORT_ID pin_id,DIO_Value value);

DIO_Value DIO_GetPinValue(DIO_PORT_ID Port_Id,DIO_PORT_ID pin_id);




#endif /* DIO_DIO_H_ */
