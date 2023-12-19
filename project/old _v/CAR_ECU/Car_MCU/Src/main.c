/*
 * main.c
 *
 *  Created on: Dec 9, 2023
 *      Author: AHMED
 */

#include "../Inc/APP/APP_Interface.h"
#include "../Inc/MCAL/USART/USART_Interface.h"

#define STATE_ON	1
#define STATE_OFF	0

volatile u8 SPI_RX_Flag = 0;
volatile u8 USART_RX_Flag = 0;
volatile u8 Data_Count = 0;

volatile u8 Global_ID = 0;
volatile u8 R_W = 3;

// IDs
#define FRONT_LED_ID		0
#define BACK_LED_ID			1
#define SEAT_ID				2
#define MOTOR_ID			3

//
#define READ				1
#define WRITE				0


volatile u8 FRONT_LED_STATE = 1;
volatile u8 BACK_LED_STATE =	0;

volatile u8 SeatState = 0;

volatile u8 MotorSpeed = 50;

volatile u8 state = 0;

#define GET_SEAT_STATE			DIO_u8PORTA, DIO_u8PIN_0
#define SEAT_LED				DIO_u8PORTA, DIO_u8PIN_1
#define BUZZER_PIN				DIO_u8PORTA, DIO_u8PIN_2

//
//void SPI_RX()
//{
//
//	if( Data_Count == 0 )
//	{
//		Global_ID = SPI_u8ReadDataISR();
//		LCD_voidGoToPosition(0,0);
//		LCD_voidWriteIntData(Global_ID);
//		Data_Count++;
//	}
//	else if(Data_Count == 1)
//	{
//		R_W = SPI_u8ReadDataISR();
//		LCD_voidGoToPosition(1,0);
//		LCD_voidWriteIntData(R_W);
//		Data_Count++;
//		SPI_RX_Flag = 1;
//	}
//	else
//	{
//		state = SPI_u8ReadDataISR();
//		LCD_voidGoToPosition(0,4);
//		LCD_voidWriteIntData(state);
//		Data_Count=0;
//	}
//}


void USART_RXCallback(){
	if( Data_Count == 0 )
	{
		Global_ID = USART_u8ReceiveInterruptByte();
		LCD_voidGoToPosition(0,0);
		LCD_voidWriteIntData(Global_ID);
		Data_Count++;
	}
	else if(Data_Count == 1)
	{
		R_W = USART_u8ReceiveInterruptByte();
		LCD_voidGoToPosition(1,0);
		LCD_voidWriteIntData(R_W);
		Data_Count++;
		USART_RX_Flag = 1;
	}
	else
	{
		state = USART_u8ReceiveInterruptByte();
		if(R_W == 0){
			Data_Count = 0;
		}
		else{
			USART_RX_Flag = 1;
			Data_Count++;
		}
	}
}
void APP_voidInit(void)
{
	// Pin IN/OUT Init
	PORT_voidInit();

	// Gobale Interrupt Enable
	GIE_voidEnable();

	// SPI Init
	//	SPI_voidSetCallBack(SPI_RX);
	_delay_ms(20);
	SPI_voidSlaveInit();
	USART_voidRXCSetCallBack(USART_RXCallback);
	USART_voidEnableRXCInterrupt();
	USART_voidInit();
	// LCD
	LCD_voidInit();

	// Motor Init
	Motor_voidInit();
//	Motor_voidSetSpeed(MotorSpeed);

	// LED Init
	LED_voidInit();
	LED_voidFRONT(FRONT_LED_STATE);		// Front LED ON
	LED_voidBACK(BACK_LED_STATE);		// Back LED OFF
}

void APP_voidStart(void)
{
	/****************************************************************************/
	// Seat Check
	//		SeatState = DIO_u8GetPinValue(GET_SEAT_STATE);
	//
	//		if(SeatState)
	//		{
	//			DIO_u8SetPinValue(SEAT_LED, DIO_u8PIN_LOW);
	//			DIO_u8SetPinValue(BUZZER_PIN, DIO_u8PIN_LOW);
	//		}
	//		else
	//		{
	//			if( MotorSpeed > 0 )
	//			{
	//				DIO_u8SetPinValue(SEAT_LED, DIO_u8PIN_HIGH);
	//				//DIO_u8SetPinValue(BUZZER_PIN, DIO_u8PIN_HIGH);
	//				//_delay_ms(300);
	//				//DIO_u8SetPinValue(BUZZER_PIN, DIO_u8PIN_LOW);
	//			}
	//			else
	//			{
	//				DIO_u8SetPinValue(SEAT_LED, DIO_u8PIN_HIGH);
	//			}
	//		}



	/****************************************************************************/
	// SPI Communication
	if( SPI_RX_Flag == 1 && ((R_W == READ && Data_Count > 1) || (R_W == WRITE && Data_Count == 0)))
	{
		SPI_RX_Flag = 0;
		if(Data_Count == 4){
			Data_Count = 0;
		}
		switch (Global_ID)
		{

		case FRONT_LED_ID:

			if( R_W == READ )
			{
				SPI_voidSendDataISR(FRONT_LED_STATE);
			}
			else if( R_W == WRITE )
			{
				FRONT_LED_STATE = state;
				LED_voidFRONT(FRONT_LED_STATE);
			}
			else
			{

			}
			LCD_voidGoToPosition(1,1);
			LCD_voidWriteIntData(FRONT_LED_STATE);
			break;

		case BACK_LED_ID:

			if( R_W == READ )
			{
				SPI_voidSendDataISR(BACK_LED_STATE);
			}
			else if( R_W == WRITE )
			{
				BACK_LED_STATE = state;
				LED_voidBACK(BACK_LED_STATE);
			}
			else
			{

			}
			LCD_voidGoToPosition(1,2);
			LCD_voidWriteIntData(BACK_LED_STATE);
			break;

		case SEAT_ID:

			if( R_W == READ )
			{
				SPI_voidSendDataISR(SeatState);
			}
			else
			{

			}
			LCD_voidGoToPosition(1,3);
			LCD_voidWriteIntData(SeatState);
			break;

		case MOTOR_ID:

			if( R_W == READ )
			{
				SPI_voidSendDataISR(MotorSpeed);
			}
			else if( R_W == WRITE )
			{
				MotorSpeed = state;
				Motor_voidSetSpeed(MotorSpeed);

			}
			else
			{

			}
			LCD_voidGoToPosition(1,4);
			LCD_voidWriteIntData(MotorSpeed);
			break;

		default:
			break;
		}
	}

}

int main(void)
{

	APP_voidInit();

	while(1)
	{
		/****************************************************************************/
		// USART Communication
		if( USART_RX_Flag == 1 && ((R_W == READ && Data_Count > 1) || (R_W == WRITE && Data_Count == 0)))
		{
			u8 temp = SPI_u8ReadDataISR();
			USART_RX_Flag = 0;
			if(Data_Count == 4){
				Data_Count = 0;
			}
			switch (Global_ID)
			{

			case FRONT_LED_ID:

				if( R_W == READ )
				{
					SPI_voidSendDataISR(FRONT_LED_STATE);
					USART_voidSendInterruptByte(FRONT_LED_STATE);
				}
				else if( R_W == WRITE )
				{
					FRONT_LED_STATE = state;
					LED_voidFRONT(FRONT_LED_STATE);
				}
				else
				{

				}
				LCD_voidGoToPosition(1,1);
				LCD_voidWriteIntData(FRONT_LED_STATE);
				break;

			case BACK_LED_ID:

				if( R_W == READ )
				{
					SPI_voidSendDataISR(BACK_LED_STATE);
					USART_voidSendInterruptByte(BACK_LED_STATE);
				}
				else if( R_W == WRITE )
				{
					BACK_LED_STATE = state;
					LED_voidBACK(BACK_LED_STATE);
				}
				else
				{

				}
				LCD_voidGoToPosition(1,2);
				LCD_voidWriteIntData(BACK_LED_STATE);
				break;

			case SEAT_ID:

				if( R_W == READ )
				{
					SPI_voidSendDataISR(SeatState);
					USART_voidSendInterruptByte(SeatState);
				}
				else
				{

				}
				LCD_voidGoToPosition(1,3);
				LCD_voidWriteIntData(SeatState);
				break;

			case MOTOR_ID:

				if( R_W == READ )
				{
					SPI_voidSendDataISR(MotorSpeed);
					USART_voidSendInterruptByte(MotorSpeed);
				}
				else if( R_W == WRITE )
				{
					MotorSpeed = state * 50;
					Motor_voidSetSpeed(MotorSpeed);

				}
				else
				{

				}
				LCD_voidGoToPosition(1,4);
				LCD_voidWriteIntData(MotorSpeed);
				break;

			default:
				break;
			}
		}
		//		APP_voidStart();
	}

	return 0;
}
