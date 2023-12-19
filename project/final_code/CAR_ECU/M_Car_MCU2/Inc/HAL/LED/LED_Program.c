/*
 * LED_Program.c
 *
 *  Created on: Dec 9, 2023
 *      Author: AHMED
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LED_Config.h"
#include "LED_Interface.h"

void LED_voidInit()
{
	LED_voidRIGHT(LED_OFF);
	LED_voidLEFT(LED_OFF);
	LED_voidFRONT(LED_OFF);
	LED_voidBACK(LED_OFF);
}

void LED_voidRIGHT(u8 Copy_u8State)
{
	if(Copy_u8State == LED_ON)
	{
		DIO_u8SetPinValue(LED_RIGHT,DIO_u8PIN_HIGH);

	}
	else if(Copy_u8State == LED_OFF)
	{
		DIO_u8SetPinValue(LED_RIGHT,DIO_u8PIN_LOW);
	}
}
void LED_voidLEFT(u8 Copy_u8State)
{
	if(Copy_u8State == LED_ON)
	{
		DIO_u8SetPinValue(LED_LEFT,DIO_u8PIN_HIGH);
	}
	else if(Copy_u8State == LED_OFF)
	{
		DIO_u8SetPinValue(LED_LEFT,DIO_u8PIN_LOW);
	}
}
void LED_voidCloseTraffic(void)
{
	DIO_u8SetPinValue(LED_RIGHT, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(LED_LEFT, DIO_u8PIN_LOW);
}
void LED_voidFRONT(u8 Copy_u8State)
{
	if(Copy_u8State == LED_ON)
	{
		DIO_u8SetPinValue(LED_FRONT, DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_u8SetPinValue(LED_FRONT, DIO_u8PIN_LOW);
	}
}
void LED_voidBACK(u8 Copy_u8State)
{
	if(Copy_u8State == LED_ON)
	{
		DIO_u8SetPinValue(LED_BACK, DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_u8SetPinValue(LED_BACK, DIO_u8PIN_LOW);
	}
}
