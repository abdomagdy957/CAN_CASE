///*
// * ServoMotor_Program.c
// *
// *  Created on: Oct 28, 2023
// *      Author: AHMED
// */
//
//#include "../../LIB/STD_TYPES.h"
//#include "../../LIB/Bit_Math.h"
//
////#include "../../MCAL/Timer/Timer1/Timer1_Interface.h"
//#include "../../MCAL/DIO/DIO_Interface.h"
//
//#include "ServoMotor_Interface.h"
//#include "ServoMotor_Config.h"
//
//void Servo_voidInit()
//{
//	u16 Local_u8ICR_Value = (16000000UL) / (f32)(SERVO_FREQ * SERVO_TIMER_PRESCALER) - 1 ;
//	TIMER1_voidInit();
//	TIMER1_voidSetICR(Local_u8ICR_Value);
//}
//void Servo_voidSetAngle(u8 Copy_u8Angle)
//{
//	u8 Localu8TickTime = ( SERVO_TIMER_PRESCALER / 16 );
//	u16 Local_u16Angle = ( ( ((f32)Copy_u8Angle) / 180 + 1 ) * 1000UL) / Localu8TickTime - 1;
//	TIMER1_voidSetDutyCycle(Local_u16Angle);
//}
//
//
//
//
