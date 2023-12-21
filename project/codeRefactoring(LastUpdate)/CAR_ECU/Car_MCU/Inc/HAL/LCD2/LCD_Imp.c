/*
 * LCD_Imp.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Hazim Emad
 */
#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_Math.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"

#include "avr/delay.h"


void LCD_voidInit(){
	_delay_ms(35);
#if LCD_BITS == LCD_4_BIT_MODE
	LCD_voidSendInitCommand(LCD_SpecialFunctionSet);
	_delay_ms(5);
	LCD_voidSendInitCommand(LCD_SpecialFunctionSet);
	_delay_ms(1);
	LCD_voidSendInitCommand(LCD_SpecialFunctionSet);
	_delay_ms(1);
	LCD_voidSendInitCommand(LCD_4BitMode);
	_delay_ms(1);
#endif
	LCD_voidSendCommand(LCD_FunctionSet);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_DisplayOFF);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_ClearDisplay);
	_delay_ms(5);
	LCD_voidSendCommand(LCD_DisplayON);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_EntryMode);
	_delay_ms(1);
}

void LCD_voidSendCommand(u8 command){
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS, DIO_u8PIN_LOW); //RS = 0

	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_u8PIN_HIGH); //EN = 1
#if LCD_BITS == LCD_8_BIT_MODE
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D0, Get_Bit(command, 0));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D1, Get_Bit(command, 1));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D2, Get_Bit(command, 2));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D3, Get_Bit(command, 3));
#endif
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4, Get_Bit(command, 4));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5, Get_Bit(command, 5));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6, Get_Bit(command, 6));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7, Get_Bit(command, 7));
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_u8PIN_LOW); //EN = 0

#if LCD_BITS == LCD_4_BIT_MODE
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_u8PIN_HIGH); //EN = 1
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4, Get_Bit(command, 0));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5, Get_Bit(command, 1));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6, Get_Bit(command, 2));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7, Get_Bit(command, 3));
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_u8PIN_LOW); //EN = 0
#endif
	_delay_ms(5);
}

void LCD_voidSendInitCommand(u8 command){
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS, DIO_u8PIN_LOW); //RS = 0

	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_u8PIN_HIGH); //EN = 1
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4, Get_Bit(command, 4));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5, Get_Bit(command, 5));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6, Get_Bit(command, 6));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7, Get_Bit(command, 7));
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_u8PIN_LOW); //EN = 0
	_delay_ms(5);
}

void LCD_voidWriteChar(u8 data){
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS, DIO_u8PIN_HIGH); //RS = 0

	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_u8PIN_HIGH); //EN = 1
#if LCD_BITS == LCD_8_BIT_MODE
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D0, Get_Bit(data, 0));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D1, Get_Bit(data, 1));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D2, Get_Bit(data, 2));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D3, Get_Bit(data, 3));
#endif
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4, Get_Bit(data, 4));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5, Get_Bit(data, 5));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6, Get_Bit(data, 6));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7, Get_Bit(data, 7));
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_u8PIN_LOW); //EN = 0

#if LCD_BITS == LCD_4_BIT_MODE
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_u8PIN_HIGH); //EN = 1
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4, Get_Bit(data, 0));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5, Get_Bit(data, 1));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6, Get_Bit(data, 2));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7, Get_Bit(data, 3));
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_u8PIN_LOW); //EN = 0
#endif
	_delay_ms(5);
}

void LCD_voidWriteString(u8* Local_Data){
	u8 index = 0;
	while(Local_Data[index] != '\0'){
		LCD_voidWriteChar(Local_Data[index]);
		index++;
	}
}

u8* IntToString(s32 anInteger,u8 *str){
	u32 flag = 0;
	u32 i = INT_TO_STRING_ARR_SIZE - 1;
	str[i--] = '\0';
	if (anInteger < 0) {
		flag = 1;
		anInteger = -anInteger;
	}
	while (anInteger != 0) {
		str[i--] = (anInteger % 10) + '0';
		anInteger /= 10;
	}
	if (flag){
		str[i--] = '-';
	}
	i++;
	return str + i;

}

void LCD_voidWriteIntData(s32 Data){
	if(Data){
		u8 arr[INT_TO_STRING_ARR_SIZE];
		u8 *str = IntToString(Data,arr);
		LCD_voidWriteString(str);
	}
	else{
		LCD_voidWriteChar('0');
	}
}

void LCD_voidWriteFloatData(f32 Data){
	u8 arr[INT_TO_STRING_ARR_SIZE];
	s32 number = (s32) (Data * 100);
	u8 *str = IntToString(number,arr);
	u32 counter=0;
	u32 counter2=0;
	while(str[counter] != '\0'){
		counter++;
	}
	counter -= 2;
	if(!counter){
		LCD_voidWriteChar('0');
	}
	while(str[counter2] != '\0'){
		if(counter2 == counter){
			LCD_voidWriteChar('.');
		}
		LCD_voidWriteChar(str[counter2]);
		counter2++;
	}
}

void LCD_voidGoToPosition(u8 X_Position, u8 Y_Position){
	u8 Local_Address = FIRST_LINE_ADDRESS;

	if(X_Position == 0){
		Local_Address = FIRST_LINE_ADDRESS + Y_Position;
	}
	else if(X_Position == 1){
		Local_Address = SECOND_LINE_ADDRESS + Y_Position;
	}
	else if(X_Position == 2){
		Local_Address = THIRD_LINE_ADDRESS + Y_Position;
	}
	else if(X_Position == 3){
		Local_Address = FOURTH_LINE_ADDRESS + Y_Position;
	}

	Set_Bit(Local_Address,7); /*You can also just OR / add with 0x80 (128) to set the the MSB*/
	LCD_voidSendCommand(Local_Address);
}

void LCD_voidClear(u8 X_Position, u8 Y_Position)
{
	LCD_voidGoToPosition(X_Position,Y_Position);
	LCD_voidWriteChar(' ');
}
void LCD_voidClearLine(u8 X_Position, u8 Y_Position)
{
	for(u8 num = 0; num <= Y_Position; num++)
	{
		LCD_voidGoToPosition(X_Position,num);
		LCD_voidWriteChar(' ');
	}
}

void LCD_voidDisplaySpecialChar(u8 *char_ptr,u8 CGRam_index,u8 row,u8 column){

	LCD_voidGoToPosition(row,column);
	LCD_voidWriteChar(CGRam_index);
	u8 address = 0;
	u8 index = 0;
	if(CGRam_index < 8){
		address = CGRam_index * 8;
		Set_Bit(address,6);
		Clear_Bit(address,7);
		LCD_voidSendCommand(address);
		for(index = 0; index < 8; index++){
			LCD_voidWriteChar(char_ptr[index]);
		}
	}
	LCD_voidSendCommand(LCD_ReturnHome);
}
