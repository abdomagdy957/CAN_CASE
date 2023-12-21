/*
 * LCD_Config.h
 *
 *  Created on: Nov 5, 2023
 *      Author: AHMED
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_4_BIT_MODE	0
#define LCD_8_BIT_MODE	1

#define LCD_BITS	LCD_4_BIT_MODE

#if LCD_BITS == LCD_8_BIT_MODE
#define LCD_D0	PIN0
#define LCD_D1	PIN1
#define LCD_D2	PIN2
#define LCD_D3	PIN3
#endif

#define LCD_D4	PIN0
#define LCD_D5	PIN1
#define LCD_D6	PIN2
#define LCD_D7	PIN3

#define LCD_RS				PIN4
#define LCD_EN				PIN5

#define LCD_CONTROL_PORT  	GPIO_B
#define LCD_DATA_PORT  	  	GPIO_B


#endif /* LCD_CONFIG_H_ */
