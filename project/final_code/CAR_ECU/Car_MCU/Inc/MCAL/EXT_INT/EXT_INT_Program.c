/*
 * EXT_INT_Program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: AHMED
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"

#include "EXT_INT_Register.h"
#include "EXT_INT_Private.h"
#include "EXT_INT_Interface.h"
#include "EXT_INT_Config.h"


void (*EXTI_pvINT0Func)(void) = NULL;
void (*EXTI_pvINT1Func)(void) = NULL;
void (*EXTI_pvINT2Func)(void) = NULL;


void EXTI0_voidInit(void)
{
#if		SELECT_INT0_SENSE_CONTROL == FALLING_EADGE
	/* ISC01 -> 1, ISC00 -> 0  */
	Set_Bit(MCUCR, MCUCR_ISC01);
	Clear_Bit(MCUCR, MCUCR_ISC00);

#elif 	SELECT_INT0_SENSE_CONTROL == RISING_EADGE
	/* ISC01 -> 1, ISC00 -> 1  */
	Set_Bit(MCUCR, MCUCR_ISC01);
	Set_Bit(MCUCR, MCUCR_ISC00);


#elif	SELECT_INT0_SENSE_CONTROL == LOW_LEVEL
	/* ISC01 -> 0, ISC00 -> 0  */
	Clear_Bit(MCUCR, MCUCR_ISC01);
	Clear_Bit(MCUCR, MCUCR_ISC00);

#elif	SELECT_INT0_SENSE_CONTROL == ON_CHANGE
	/* ISC01 -> 0, ISC00 -> 1  */
	Set_Bit(MCUCR, MCUCR_ISC00);
	Clear_Bit(MCUCR, MCUCR_ISC01);
#else
#error "WRONG SENCE CONTROL"
#endif
}

void EXTI0_voidEnable(void)
{
	Set_Bit(GICR, GICR_INT0);
}

void EXTI0_voidDisable(void)
{
	Clear_Bit(GICR, GICR_INT0);
}

void EXT0_voidSetSignalch(u8 SenseCpy)
{
	switch( SenseCpy )
	{
	case FALLING_EADGE:
		/* ISC01 -> 1, ISC00 -> 0  */
		Set_Bit(MCUCR, MCUCR_ISC01);
		Clear_Bit(MCUCR, MCUCR_ISC00);
		break;
	case RISING_EADGE:
		/* ISC01 -> 1, ISC00 -> 1  */
		Set_Bit(MCUCR, MCUCR_ISC01);
		Set_Bit(MCUCR, MCUCR_ISC00);
		break;
	case LOW_LEVEL:
		/* ISC01 -> 0, ISC00 -> 0  */
		Clear_Bit(MCUCR, MCUCR_ISC01);
		Clear_Bit(MCUCR, MCUCR_ISC00);

		break;
	case ON_CHANGE:
		/* ISC01 -> 0, ISC00 -> 1  */
		Set_Bit(MCUCR, MCUCR_ISC00);
		Clear_Bit(MCUCR, MCUCR_ISC01);
		break;
	default:
		break;
	}
}

void EXTI1_voidInit(void)
{
#if		SELECT_INT1_SENSE_CONTROL == FALLING_EADGE
	/* ISC11 -> 1, ISC10 -> 0  */
	Clear_Bit(MCUCR, MCUCR_ISC10);
	Set_Bit(MCUCR, MCUCR_ISC11);

#elif 	SELECT_INT1_SENSE_CONTROL == RISING_EADGE
	/* ISC11 -> 1, ISC10 -> 1  */
	Set_Bit(MCUCR, MCUCR_ISC10);
	Set_Bit(MCUCR, MCUCR_ISC11);


#elif	SELECT_INT1_SENSE_CONTROL == LOW_LEVEL
	/* ISC11 -> 0, ISC10 -> 0  */
	Clear_Bit(MCUCR, MCUCR_ISC10);
	Clear_Bit(MCUCR, MCUCR_ISC11);

#elif	SELECT_INT1_SENSE_CONTROL == ON_CHANGE
	/* ISC11 -> 1, ISC10 -> 1  */
	Clear_Bit(MCUCR, MCUCR_ISC11);
	Set_Bit(MCUCR, MCUCR_ISC10);

#error "WRONG SENCE CONTROL"
#endif
}

void EXTI1_voidEnable(void)
{
	Set_Bit(GICR, GICR_INT1);
}

void EXTI1_voidDisable(void)
{
	Clear_Bit(GICR, GICR_INT1);
}

void EXT1_voidSetSignalch(u8 SenseCpy)
{

	switch (SenseCpy)
	{
	case FALLING_EADGE:
		/* ISC11 -> 1, ISC10 -> 0  */
		Clear_Bit(MCUCR, MCUCR_ISC10);
		Set_Bit(MCUCR, MCUCR_ISC11);
		break;
	case RISING_EADGE:
		/* ISC11 -> 1, ISC10 -> 1  */
		Set_Bit(MCUCR, MCUCR_ISC10);
		Set_Bit(MCUCR, MCUCR_ISC11);
		break;
	case LOW_LEVEL:
		/* ISC11 -> 0, ISC10 -> 0  */
		Clear_Bit(MCUCR, MCUCR_ISC10);
		Clear_Bit(MCUCR, MCUCR_ISC11);
		break;
	case ON_CHANGE:
		/* ISC11 -> 1, ISC10 -> 1  */
		Clear_Bit(MCUCR, MCUCR_ISC11);
		Set_Bit(MCUCR, MCUCR_ISC10);
		break;
	default:
		break;
	}

}


// INTERRUPT 1
void EXTI2_voidInit(void)
{

#if 	SELECT_INT2_SENSE_CONTROL == FALLING_EADGE
	Clear_Bit(MCUCR, MCUCSR_ISC2);
#elif 	SELECT_INT2_SENSE_CONTROL == RISING_EADGE
	Set_Bit(MCUCR, MCUCSR_ISC2);
#else
#endif

}

//enable EXTI
void EXTI2_voidEnable(void)
{
	Set_Bit(GICR, GICR_INT2);
}

//disable EXTI
void EXTI2_voidDisable(void)
{
	Clear_Bit(GICR, GICR_INT2);
}

//change the INT with sensing mood in runtime
void EXT2_voidSetSignalch(u8 SenseCpy)
{
	switch(SenseCpy)
	{
	case FALLING_EADGE:
		Clear_Bit(MCUCR, MCUCSR_ISC2);
		break;
	case RISING_EADGE:
		Set_Bit(MCUCR, MCUCSR_ISC2);
		break;

	}
}



//callback function
void EXT0_VID_SET_CALL_BACK(void (*PTR)(void))
{
	if(PTR != NULL)
	{
		EXTI_pvINT0Func = PTR;
	}
	else
	{

	}
}
void EXT1_VID_SET_CALL_BACK(void (*PTR)(void))
{
	if(PTR != NULL)
	{
		EXTI_pvINT1Func = PTR;
	}
	else
	{

	}
}
void EXT2_VID_SET_CALL_BACK(void (*PTR)(void))
{
	if(PTR != NULL)
	{
		EXTI_pvINT2Func = PTR;
	}
	else
	{

	}
}





void __vector_1(void)__attribute__((signal,used, externally_visible));
void __vector_1(void)
{
	if(EXTI_pvINT0Func != NULL)
	{
		EXTI_pvINT0Func();
	}
}

void __vector_2(void)__attribute__((signal,used, externally_visible));
void __vector_2(void)
{
	if(EXTI_pvINT1Func != NULL)
	{
		EXTI_pvINT1Func();
	}
}

void __vector_3(void)__attribute__((signal,used, externally_visible));
void __vector_3(void)
{
	if(EXTI_pvINT2Func != NULL)
	{
		EXTI_pvINT2Func();
	}
}
