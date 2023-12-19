/*
 * TIMER1_Interface.h
 *
 *  Created on: Dec 9, 2023
 *      Author: AHMED
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_


void TIMER1_voidInit();
void TIMER1_voidSetICR(u16 value);
void TIMER1_voidSetDutyCycle(u16 duty);
void TIMER1_voidStop();

void TIMER1_ICUsetEdgeDetectionMode(u8 edge);
u16 TIMER1_ICUgetInputCaptureValue();
void TIMER1_ICUclearTimerValue();
void TIMER1_voidSetTimerValue(u16 value);
u16 TIMER1_u16ReadTimerValue();
void TIMER1_ICUDeInit();
void TIMER1_voidTIMER1ICUSetCallBack(void (*Copy_pvCallBackFunc)(void));
void TIMER1_voidTIMER1CTCSetCallBack(void (*Copy_pvCallBackFunc)(void));


#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
