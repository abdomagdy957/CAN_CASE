/*
 * app.h
 *
 *  Created on: Nov 1, 2023
 *      Author: atef
 */


#ifndef APP_APP_INTERFACE_H_
#define APP_APP_INTERFACE_H_

#include "lib/std_types.h"
#include "lib/utils.h"

#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/NVIC/NVIC_interface.h"
#include "../MCAL/STK/STK_interface.h"
#include "../MCAL/SPI/SPI_init.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/CAN/CAN_interface.h"

void main_init();
void NVIC_test ();
void STK_TEST();
void USART_init();

#endif /* APP_APP_INTERFACE_H_ */
