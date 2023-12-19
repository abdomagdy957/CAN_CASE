/*
 * GPIO_Interface.h
 *
 *  Created on: Nov 27, 2023
 *      Author: Ahmed Mohammed
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "GPIO_Private.h"

/* Main Functions */
void GPIO_voidSetPinMode (u8 Copy_u8PORT, u8 Copy_u8Pin, u8 Copy_u8Mode);
void GPIO_voidSetPinValue (u8 Copy_u8PORT, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 GPIO_u8GetPinValue (u8 Copy_u8PORT, u8 Copy_u8PIN);
void GPIO_voidSetPortValue(u8 Copy_u8PORT, u32 Copy_u8Value);
void GPIO_voidSetPortMode(u8 Copy_u8PORT, u32 Copy_u8ModeL, u32 Copy_u8ModeH);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
