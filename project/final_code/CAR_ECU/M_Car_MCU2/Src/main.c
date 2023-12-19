/*
 * main.c
 *
 *  Created on: Dec 9, 2023
 *      Author: AHMED
 */

#include "../Inc/APP/APP_Interface.h"
#include "../Inc/MCAL/USART/USART_Interface.h"
#include "../Inc/MCAL/ADC/NTI_ADC_Interface.h"

// IDs
#define TEMP_ID				4
#define LIGHT_ID			5
//Commands
#define READ				1
#define WRITE				0

volatile u8 SPI_RX_Flag = 0;
volatile u8 USART_RX_Flag = 0;
volatile u8 Data_Count = 0;

volatile u8 Global_ID = 0;
volatile u8 R_W = 3;

volatile f32 readings[2];
volatile u8 current_ADC = 0;
volatile u8 state = 0;

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
		ADC_voidStartConversion(Global_ID - TEMP_ID);
		readings[Global_ID - TEMP_ID] = ADC_u16ReadADCInMV();
	}
	else
	{
		state = USART_u8ReceiveInterruptByte();
		if(R_W == 0){
			Data_Count = 0;
		}
		else if(Data_Count < 4){
			USART_RX_Flag = 1;
			Data_Count++;
		}
		else{
			Data_Count = 0;
		}
	}
}

//void ADC_Chain(){
//	ADC_voidDisable();
//	readings[current_ADC] = ADC_u16ReadADCInMV();
//	current_ADC++;
//	if(current_ADC > 1){
//		current_ADC = 0;
//	}
//}

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
//	ADC_voidSetCallback(ADC_Chain);
	ADC_voidInit();
	ADC_voidEnable();
//	ADC_voidInterrputEnable();
//	ADC_voidStartInterruptConversion(current_ADC);
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

			case TEMP_ID:
				SPI_voidSendDataISR((u32)(readings[0]/10));
				USART_voidSendInterruptByte((u32)(readings[0]/10));
				LCD_voidGoToPosition(1,1);
				LCD_voidWriteIntData((u32)(readings[0]/10));
				break;

			case LIGHT_ID:
				SPI_voidSendDataISR((u32)(readings[1]/10));
				USART_voidSendInterruptByte((u32)(readings[1]/10));
				LCD_voidGoToPosition(1,5);
				LCD_voidWriteIntData((u32)(readings[1]/10));
				break;

			default:
				break;
			}
		}
//		ADC_voidEnable();
//		ADC_voidStartInterruptConversion(current_ADC);
	}

	return 0;
}
