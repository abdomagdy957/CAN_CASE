/*
 * TIMER1_Register.h
 *
 *  Created on: Dec 9, 2023
 *      Author: AHMED
 */

#ifndef MCAL_TIMER1_TIMER1_REGISTER_H_
#define MCAL_TIMER1_TIMER1_REGISTER_H_


#define OCR1A 		*((volatile u16*) 0x4A)
#define OCR1B 		*((volatile u16*) 0x48)

#define TCCR1A 		*((volatile u8*) 0x4F)

#define TCCR1A_COM1A1 		7
#define TCCR1A_COM1A0 		6
#define TCCR1A_WGM11 		1
#define TCCR1A_WGM10 		0
#define TCCR1A_COM1B1 		5
#define TCCR1A_COM1B0 		4
#define TCCR1A_FOC1A 		3
#define TCCR1A_FOC1B 		2

#define TCCR1B 		*((volatile u8*)0x4E)

#define TCCR1B_WGM13 		4
#define TCCR1B_WGM12 		3
#define TCCR1B_CS12 		2
#define TCCR1B_CS11 		1
#define TCCR1B_CS10 		0
#define TCCR1B_ICNC1 		7
#define TCCR1B_ICES 		6

#define ICR1 		*((volatile u16*) 0x46)

#define TCNT1       *((volatile u16*) 0x4C)

#define TIMSK       *((volatile u8*) 0x59)          /*Timer mask*/
#define TIMSK_TICIE1	   5
#define TIMSK_OCIE1A       4                        /*Output Compare 0 interrupt enable*/
#define TIMSK_OCIE1B       3                      /*Output Compare 0 interrupt enable*/
#define TIMSK_TOIE1        2



#endif /* MCAL_TIMER1_TIMER1_REGISTER_H_ */
