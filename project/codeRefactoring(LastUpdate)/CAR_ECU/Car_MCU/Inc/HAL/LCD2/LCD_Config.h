/*
 * LCD_Config.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Hazim Emad
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_4_BIT_MODE	0
#define LCD_8_BIT_MODE	1

#define LCD_BITS	LCD_4_BIT_MODE

#if LCD_BITS == LCD_8_BIT_MODE
#define LCD_D0	DIO_u8PIN_0
#define LCD_D1	DIO_u8PIN_1
#define LCD_D2	DIO_u8PIN_2
#define LCD_D3	DIO_u8PIN_3
#endif

#define LCD_D4	DIO_u8PIN_0
#define LCD_D5	DIO_u8PIN_1
#define LCD_D6	DIO_u8PIN_2
#define LCD_D7	DIO_u8PIN_3

#define LCD_RS				DIO_u8PIN_3
#define LCD_EN				DIO_u8PIN_2
#define LCD_CONTROL_PORT  	DIO_u8PORTA
#define LCD_DATA_PORT  	  	DIO_u8PORTB

#endif /* HAL_LCD_HEADER_LCD_CONFIG_H_ */
