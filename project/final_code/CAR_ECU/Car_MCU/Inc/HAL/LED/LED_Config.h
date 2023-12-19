/*
 * LED_Config.h
 *
 *  Created on: Dec 9, 2023
 *      Author: AHMED
 */

#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_

#define SECOND				1000

#define LED_ON				1
#define LED_OFF				0


#define LED_FRONT			DIO_u8PORTA, DIO_u8PIN_4

#define LED_BACK			DIO_u8PORTA, DIO_u8PIN_5

#define LED_RIGHT			DIO_u8PORTA, DIO_u8PIN_6

#define LED_LEFT			DIO_u8PORTA, DIO_u8PIN_7


#define LED_CONTROL_PORT				DIO_u8PORTA



#endif /* HAL_LED_LED_CONFIG_H_ */
