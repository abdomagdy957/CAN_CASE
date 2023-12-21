/*
 * LCD_Private.h
 *
 *  Created on: Nov 5, 2023
 *      Author: AHMED
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_


#define LCD_SpecialFunctionSet		0x30
#define LCD_FunctionSet				0x28
#define LCD_DisplayOFF				0x08
#define LCD_DisplayON				0x0C
#define LCD_EntryMode				0x06
#define LCD_ClearDisplay			0x01
#define LCD_ReturnHome				0x02
#define LCD_4BitMode				0x20
#define LCD_ShiftDisplayRight	 	0x1C
#define LCD_ShiftDisplayLeft  		0x18

#define FIRST_LINE_ADDRESS  		0x80
#define SECOND_LINE_ADDRESS 		0xC0
#define THIRD_LINE_ADDRESS  		0x94
#define FOURTH_LINE_ADDRESS 		0xD4

#define INT_TO_STRING_ARR_SIZE  20


#endif /* HAL_LCD_LCD_PRIVATE_H_ */
