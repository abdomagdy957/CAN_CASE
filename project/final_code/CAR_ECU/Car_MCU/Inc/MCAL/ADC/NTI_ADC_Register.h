/*
 * NTI_ADC_Register.h
 *
 *  Created on: Oct 23, 2023
 *      Author: AHMED
 */

#ifndef MCAL_ADC_NTI_ADC_REGISTER_H_
#define MCAL_ADC_NTI_ADC_REGISTER_H_

// ADC Multiplexer Selection Register Address
#define ADMUX		 	 *( (volatile u8 *) 0x27)

// ADC Multiplexer Selection Register BITS
#define ADMUX_REFS1    		7			// Reference Selection 1
#define ADMUX_REFS0     	6			// Reference Selection 0
#define ADMUX_ADLAR     	5
#define ADMUX_MUX4      	4			//
#define ADMUX_MUX3      	3			//
#define ADMUX_MUX2      	2			//
#define ADMUX_MUX1      	1			//
#define ADMUX_MUX0      	0			//


// ADC Control and Status Register Address
#define ADCSRA			 *( (volatile u8 *) 0x26)

// ADC Control and Status Register BITS
#define ADCSRA_ADEN 		7		// Enable Bit
#define ADCSRA_ADSC 		6		// Start Conversion bit
#define ADCSRA_ADATE 		5		// ADC Auto trigger
#define ADCSRA_ADIF 		4		// ADC Interrupt Flag
#define ADCSRA_ADIE 		3		// ADC Interrupt Enable
#define ADCSRA_ADPS2 		2		// ADC Prescaler bit 2
#define ADCSRA_ADPS1 		1		// ADC Prescaler bit 1
#define ADCSRA_ADPS0		0		// ADC Prescaler bit 0



// Special Function Register Address
#define SFIOR			 *( (volatile u8 *) 0x50)

// Special Function Register BITS
#define SFIOR_ADTS2 		7
#define SFIOR_ADTS1			6
#define SFIOR_ADTS0			5


#define ADCH			 *( (volatile u8 *) 0x25)

#define ADCL 		 	 *( (volatile u8 *) 0x24)

#define ADC_10Bit  	 	 *( (volatile u16 *) 0x24)

#endif /* MCAL_ADC_NTI_ADC_REGISTER_H_ */
