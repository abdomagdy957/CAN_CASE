/*
 * NTI_ADC_Program.c
 *
 *  Created on: Oct 23, 2023
 *      Author: AHMED
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"


#include "NTI_ADC_Register.h"
#include "NTI_ADC_Config.h"
#include "NTI_ADC_Interface.h"
#include "NTI_ADC_Private.h"

f32 Vref = 5, REF = 0;


void (*ADC_pvFunc)(void);


void ADC_voidInit()
{

#if 	VOLTAGE_REFERENCE == AVCC
	/* REFS1 -> 0, REFS0 -> 1 */
	Set_Bit(ADMUX, ADMUX_REFS0);
	Clear_Bit(ADMUX, ADMUX_REFS1);
	Vref = 5;

#elif	VOLTAGE_REFERENCE == AREF
	/* REFS1 -> 0, REFS0 -> 0 */
	Clear_Bit(ADMUX, ADMUX_REFS0);
	Clear_Bit(ADMUX, ADMUX_REFS1);
	Vref = REF;

#elif	VOLTAGE_REFERENCE == ADC_INTERNAL
	/* REFS1 -> 1, REFS0 -> 1 */
	Set_Bit(ADMUX, ADMUX_REFS0);
	Set_Bit(ADMUX, ADMUX_REFS1);
	Vref(f32*) = 2.6

#else
#error "WRONG INPUT"
#endif


#if ADC_PRESCALER_SELECTION == DIVIDE_BY_2
	/* ADPS2 -> 0,  ADPS1 -> 0, ADPS0 -> 1 */
	Set_Bit(ADCSRA, ADCSRA_ADPS0);
	Clear_Bit(ADCSRA, ADCSRA_ADPS1);
	Clear_Bit(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALER_SELECTION == DIVIDE_BY_4
	/* ADPS2 -> 0,  ADPS1 -> 1, ADPS0 -> 0 */
	Set_Bit(ADCSRA, ADCSRA_ADPS1);
	Clear_Bit(ADCSRA, ADCSRA_ADPS0);
	Clear_Bit(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALER_SELECTION == DIVIDE_BY_8
	/* ADPS2 -> 0,  ADPS1 -> 1, ADPS0 -> 1 */
	Clear_Bit(ADCSRA, ADCSRA_ADPS0);
	Set_Bit(ADCSRA, ADCSRA_ADPS1);
	Set_Bit(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALER_SELECTION == DIVIDE_BY_16
	/* ADPS2 -> 1,  ADPS1 -> 0, ADPS0 -> 0 */
	clear_Bit(ADCSRA, ADCSRA_ADPS0);
	Clear_Bit(ADCSRA, ADCSRA_ADPS1);
	Set_Bit(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALER_SELECTION == DIVIDE_BY_32
	/* ADPS2 -> 1,  ADPS1 -> 0, ADPS0 -> 1 */
	Set_Bit(ADCSRA, ADCSRA_ADPS0);
	Clear_Bit(ADCSRA, ADCSRA_ADPS1);
	Set_Bit(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALER_SELECTION == DIVIDE_BY_64
	/* ADPS2 -> 1,  ADPS1 -> 1, ADPS0 -> 0 */
	Clear_Bit(ADCSRA, ADCSRA_ADPS0);
	Set_Bit(ADCSRA, ADCSRA_ADPS1);
	Set_Bit(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALER_SELECTION == DIVIDE_BY_128
	/* ADPS2 -> 1,  ADPS1 -> 1, ADPS0 -> 1 */
	Set_Bit(ADCSRA, ADCSRA_ADPS0);
	Set_Bit(ADCSRA, ADCSRA_ADPS1);
	Set_Bit(ADCSRA, ADCSRA_ADPS2);

#else
#error "WRONG INPUT"
#endif

#if		ADJUSTMENT == LEFT_ADJUSTMENT
	Set_Bit(ADMUX, ADMUX_ADLAR);
#elif   ADJUSTMENT == RIGHT_ADJUSTMENT
	Clear_Bit(ADMUX, ADMUX_ADLAR);
#else
#error
#endif


#if		ADC_AUTO_TRIGGER_MODE == FREE_RUNNING_MODE
	// ADC Control Status Register
	Set_Bit(ADCSRA ,ADCSRA_ADATE);
	// Selecting free frunning mode
	Clear_Bit(SFIOR, SFIOR_ADTS0);
	Clear_Bit(SFIOR, SFIOR_ADTS1);
	Clear_Bit(SFIOR, SFIOR_ADTS2);
#elif ADC_AUTO_TRIGGER_MODE == NORMAL_MODE

#else
#error
#endif

}


void ADC_voidEnable()
{
	Set_Bit(ADCSRA, ADCSRA_ADEN);
}

void ADC_voidInterrputEnable()
{
	Set_Bit(ADCSRA, ADCSRA_ADIE);
}

void ADC_voidDisable()
{
	Clear_Bit(ADCSRA, ADCSRA_ADEN);
}

u16 ADC_u16ReadADC()
{
	u16 ADC_Result=0;

	ADC_Result = ( ADC_10Bit * Vref) / 1024;

	return ADC_Result;
}

void ADC_voidStartConversion(u8 Copy_u8Channel)
{
	ADMUX &= 0b11100000;

	ADMUX |= Copy_u8Channel;

	// Start Conversion
	Set_Bit(ADCSRA, ADCSRA_ADSC);

	// Polling { Busy Waiting } until conversion complete
	while( Get_Bit(ADCSRA, ADCSRA_ADIF) == 0 );

	// Clear Conversion Flag
	Set_Bit(ADCSRA, ADCSRA_ADIF);

}

void ADC_voidStartInterruptConversion(u8 Copy_u8Channel)
{
	ADMUX &= 0b11100000;

	ADMUX |= Copy_u8Channel;

	// Start Conversion
	Set_Bit(ADCSRA, ADCSRA_ADSC);

}


u16 ADC_u16ReadADCInMV()
{
	u16 ADC_Result= 0;

	ADC_Result = (ADC_10Bit * 1000UL * (u8)Vref) / 1024UL;

	return (u16)ADC_Result;

}

void ADC_voidDisableInt()
{
	Clear_Bit(ADCSRA, ADCSRA_ADIE);
}

void ADC_voidSetCallback( void (*ptr) (void) )
{
	if( ptr != NULL )
	{
		ADC_pvFunc = ptr;
	}
}


void __vector_16(void)__attribute__((signal,used, externally_visible));
void __vector_16(void)
{
	if( ADC_pvFunc != NULL )
	{
		ADC_pvFunc();
	}
}

