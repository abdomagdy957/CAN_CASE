/*
 * ADC_NTI_Interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: AHMED
 */

#ifndef MCAL_ADC_NTI_ADC_INTERFACE_H_
#define MCAL_ADC_NTI_ADC_INTERFACE_H_


#define ADC_0		0
#define ADC_1		1
#define ADC_2		2
#define ADC_3		3
#define ADC_4		4
#define ADC_5		5
#define ADC_6		6
#define ADC_7		7


void ADC_voidInit();
void ADC_voidEnable();
void ADC_voidInterrputEnable();
void ADC_voidDisable();
u16 ADC_u16ReadADC();
void ADC_voidStartConversion(u8 Copy_u8Channel);
void ADC_voidStartInterruptConversion(u8 Copy_u8Channel);
u16 ADC_u16ReadADCInMV();
void ADC_voidDisableInt();

// CALL BACK FUNC
void ADC_voidSetCallback( void (*ptr) (void) );


#endif /* MCAL_ADC_NTI_ADC_INTERFACE_H_ */
