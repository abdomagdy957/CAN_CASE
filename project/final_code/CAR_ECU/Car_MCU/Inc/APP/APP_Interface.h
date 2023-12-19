/*
 * APP_Interface.h
 *
 *  Created on: Dec 9, 2023
 *      Author: AHMED
 */

#ifndef APP_APP_INTERFACE_H_
#define APP_APP_INTERFACE_H_

#include "../LIB/STD_TYPES.h"
#include "../LIB/Bit_Math.h"

#include "../HAL/Motor/Motor_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/LCD2/LCD_Interface.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/Port/Port_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/TIMER1/TIMER1_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "util/delay.h"


void APP_voidInit(void);

void APP_voidStart(void);

#endif /* APP_APP_INTERFACE_H_ */
