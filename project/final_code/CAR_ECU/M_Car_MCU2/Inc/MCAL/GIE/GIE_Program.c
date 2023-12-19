/*
 * GIE_Program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: AHMED
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"


#include "GIE_Register.h"
#include "GIE_Interface.h"

void GIE_voidEnable(void)
{
	/* Enable Global Interrupt  */
	Set_Bit(SREG, SREG_I);
}
void GIE_voidDisable(void)
{
	/* Disable Global Interrupt  */
	Clear_Bit(SREG, SREG_I);
}

