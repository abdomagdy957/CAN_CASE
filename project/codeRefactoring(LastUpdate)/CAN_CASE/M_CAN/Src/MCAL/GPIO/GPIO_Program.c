/*
 * GPIO_Program.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Ahmed Mohammed
 */

#include "LIB/STD_types.h"
#include "LIB/Bit_Math.h"

#include "MCAL/GPIO/GPIO_Register.h"
#include "MCAL/GPIO/GPIO_Config.h"
#include "MCAL/GPIO/GPIO_Interface.h"

void GPIO_voidSetPinMode(u8 Copy_u8PORT, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	if (Copy_u8Pin < 16)
	{
		switch (Copy_u8PORT)
		{
		case GPIO_A:
			if (Copy_u8Pin < 8)
			{
				GPIOA_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
				GPIOA_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
			}
			else if (Copy_u8Pin < 16)
			{
				Copy_u8Pin -= 8;
				GPIOA_CRH &= ~((0b1111) << (Copy_u8Pin * 4));
				GPIOA_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
			}
			break;

		case GPIO_B:
			if (Copy_u8Pin < 8)
			{
				GPIOB_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
				GPIOB_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
			}
			else if (Copy_u8Pin < 16)
			{
				Copy_u8Pin -= 8;
				GPIOB_CRH &= ~((0b1111) << (Copy_u8Pin * 4));
				GPIOB_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
			}
			break;

		case GPIO_C:
			if (Copy_u8Pin > 12)
			{
				Copy_u8Pin -= 8;
				GPIOC_CRH &= ~((0b1111) << (Copy_u8Pin * 4));
				GPIOC_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
			}
			break;

		default:
			break;
		}
	}
}



void GPIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if (Copy_u8Pin < 16)
	{
		if (Copy_u8Value == GPIO_HIGH)
		{
			switch (Copy_u8PORT)
			{
			case GPIO_A:
				GPIOA_BSRR = (1 << Copy_u8Pin);
				break;

			case GPIO_B:
				GPIOB_BSRR = (1 << Copy_u8Pin);
				break;

			case GPIO_C:
				GPIOC_BSRR = (1 << Copy_u8Pin);
				break;

			default:
				break;
			}
		}
		else if (Copy_u8Value == GPIO_LOW)
		{
			switch (Copy_u8PORT)
			{
			case GPIO_A:
				GPIOA_BRR = (1 << Copy_u8Pin);
				break;

			case GPIO_B:
				GPIOB_BRR = (1 << Copy_u8Pin);
				break;

			case GPIO_C:
				GPIOC_BRR = (1 << Copy_u8Pin);
				break;

			default:
				break;
			}
		}
	}
}

u8 GPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	u8 LOC_U8Value = 0;

	if (Copy_u8PIN < 16)
	{
		switch (Copy_u8PORT)
		{
		case GPIO_A:
			LOC_U8Value = Get_Bit(GPIOA_IDR, Copy_u8PIN);
			break;

		case GPIO_B:
			LOC_U8Value = Get_Bit(GPIOB_IDR, Copy_u8PIN);
			break;

		case GPIO_C:
			LOC_U8Value = Get_Bit(GPIOC_IDR, Copy_u8PIN);
			break;

		default:
			break;
		}
	}
	return LOC_U8Value;
}

void GPIO_voidSetPortValue(u8 Copy_u8PORT, u32 Copy_u8Value)
{
	switch (Copy_u8PORT)
	{
	case GPIO_A:
		GPIOA_ODR = Copy_u8Value;
		break;

	case GPIO_B:
		GPIOB_ODR = Copy_u8Value;
		break;

	case GPIO_C:
		Copy_u8Value &= 0xE0000000;
		GPIOC_ODR = Copy_u8Value;
		break;

	default:
		break;
	}
}

void GPIO_voidSetPortMode(u8 Copy_u8PORT, u32 Copy_u8ModeL, u32 Copy_u8ModeH)
{
	switch (Copy_u8PORT)
	{
	case GPIO_A:
		GPIOA_CRL = Copy_u8ModeL;
		GPIOA_CRH = Copy_u8ModeH;
		break;

	case GPIO_B:
		GPIOB_CRL = Copy_u8ModeL;
		GPIOB_CRH = Copy_u8ModeH;
		break;

	case GPIO_C:
		GPIOC_CRL = Copy_u8ModeL;
		GPIOC_CRH = Copy_u8ModeH;
		break;

	default:
		break;
	}
}


