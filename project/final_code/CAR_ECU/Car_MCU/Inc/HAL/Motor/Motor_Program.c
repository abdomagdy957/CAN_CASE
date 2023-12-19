/*
 * Motor_Program.c
 *
 *  Created on: Dec 9, 2023
 *      Author: AHMED
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"

#include "../../MCAL/TIMER1/TIMER1_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Motor_Interface.h"
#include "Motor_Config.h"

void Motor_voidInit()
{
	Motor_voidSetSpeed(MOTOR_INIT_SPEED);
}

void Motor_voidSetSpeed(u8 Copy_u8Speed)		// 50 - 50% duty / 100 - 100% duty
{
	u16 Local_u16SpeedMapping = ((f32)Copy_u8Speed / MAX_SPEED) * (MAX_PERIOD);		// 10 / 100 -> 0.1 * (20,000)

	if(Copy_u8Speed > 0){
		// Init Timer 1
		TIMER1_voidInit();
		// Set OCR1A
		TIMER1_voidSetDutyCycle(Local_u16SpeedMapping);
	}
	else{
		TIMER1_voidStop();
		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN_5, DIO_u8PIN_LOW);
	}


}
