/*
 * TIMER0_Program.c
 *
 *  Created on: Dec 9, 2023
 *      Author: AHMED
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"

#include "TIMER1_Register.h"
#include "TIMER1_Private.h"
#include "TIMER1_Config.h"
#include "TIMER1_Interface.h"


static void (*Global_pvTimerICUCallBack)(void)= NULL;
static void (*Global_pvTimerCTCCallBack)(void)= NULL;

void TIMER1_voidInit()
{
	//Configure TIMER1
	TCCR1A = 0;
	TCCR1B = 0;
#if       TIMER1_Mode == TIMER1_NORMAL
	/*Choose Normal Mode*/
	Clear_Bit(TCCR1A, TCCR1A_WGM10);
	Clear_Bit(TCCR1A, TCCR1A_WGM11);
	Clear_Bit(TCCR1B, TCCR1B_WGM12);
	Clear_Bit(TCCR1B, TCCR1B_WGM13);


	/*Timer Over flow flag Enable*/
	SET_BIT(TIMSK, TIMSK_TOIE);

#elif     TIMER1_Mode == TIMER1_CTC
	/*Choose CTC Mode*/
	Clear_Bit(TCCR1A, TCCR1A_WGM10);
	Clear_Bit(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	Clear_Bit(TCCR1B, TCCR1B_WGM13);

	/*OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
	SET_BIT(TIMSK, TIMSK_OCIE1A);

	/*Set compare match value to 25000*/
	OCR1A = 24999;
	/*Set PRESCALAR 64*/
	SET_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	Clear_Bit(TCCR1B, TCCR1B_CS12);

#elif TIMER1_Mode == TIMER1_PWM

#if PWM_MODE	== TIMER1_FPWM

#if INVERTING_MODE == TIMER1_Noninverting
	//NON Inverted PWM
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	Clear_Bit(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);
	Clear_Bit(TCCR1A,TCCR1A_COM1B0);

	//MODE 14(FAST PWM)
	Clear_Bit(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

#endif
#endif

#elif TIMER1_Mode == TIMER1_ICU
#if TIMER1_DefaultEdge == TIMER1_RISING
	SET_BIT(TCCR1B,TCCR1B_ICES);
#elif TIMER1_DefaultEdge == TIMER1_FALLING
	Clear_Bit(TCCR1B,TCCR1B_ICES);
#endif

#if TIMER1_NoiseOption == TIMER1_ACTIVENOISECANCELLER
	SET_BIT(TCCR1B,TCCR1B_ICNC1);
#elif TIMER1_NoiseOption == TIMER1_NONOISECANCELLER
	Clear_Bit(TCCR1B,TCCR1B_ICNC1);
#endif

	TCNT1 = 0; /*init TIMER1 counter 0*/
	ICR1 = 0;  /*init Input Capture register counter 0*/

	/* Enable ICU Interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
#endif

	Clear_Bit(TCCR1B,TCCR1B_CS10);
	Set_Bit(TCCR1B,TCCR1B_CS11);
	Clear_Bit(TCCR1B,TCCR1B_CS12);

}

void TIMER1_voidSetICR(u16 value)
{
	ICR1 = value;
}

void TIMER1_voidSetTimerValue(u16 value)
{
	TCNT1 = value;
}
u16 TIMER1_u16ReadTimerValue()
{
	return TCNT1;
}

void TIMER1_voidSetDutyCycle(u16 duty)
{
	OCR1A = duty;
}

void TIMER1_voidStop()
{
	Clear_Bit(TCCR1B,TCCR1B_CS10);
	Clear_Bit(TCCR1B,TCCR1B_CS11);
	Clear_Bit(TCCR1B,TCCR1B_CS12);

	TCNT1 = 0;
}

void TIMER1_ICUsetEdgeDetectionMode(u8 edge)
{
	if(edge == TIMER1_RISING){
		SET_BIT(TCCR1B,TCCR1B_ICES);
	}
	else if(edge == TIMER1_FALLING){
		Clear_Bit(TCCR1B,TCCR1B_ICES);
	}
}

u16 TIMER1_ICUgetInputCaptureValue()
{
	return ICR1;
}

void TIMER1_ICUclearTimerValue()
{
	TCNT1 = 0;
}

void TIMER1_ICUDeInit()
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;
	ICR1   = 0;

	/* Disable the interrupt */
	Clear_Bit(TIMSK,TIMSK_TICIE1);
}

void TIMER1_voidTIMER1ICUSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	Global_pvTimerICUCallBack = Copy_pvCallBackFunc;
}

void TIMER1_voidTIMER1CTCSetCallBack(void (*Copy_pvCallBackFunc)(void)){
	Global_pvTimerCTCCallBack = Copy_pvCallBackFunc;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if(Global_pvTimerICUCallBack != NULL){
		Global_pvTimerICUCallBack();
	}
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	if(Global_pvTimerCTCCallBack != NULL){
		Global_pvTimerCTCCallBack();
	}
}


