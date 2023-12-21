/*
 * APP_Interface.h
 *
 *  Created on: Nov 28, 2023
 *      Author: AHMED
 */

#ifndef APP_APP_INTERFACE_H_
#define APP_APP_INTERFACE_H_

#include "LIB/STD_Types.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "MCAL/RCC/RCC_Interface.h"
#include "MCAL/NVIC/NVIC_Interface.h"
#include "MCAL/STK/STK_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/CAN/CAN_Interface.h"
#include "RTOS/Source/include/FreeRTOS.h"
#include "RTOS/Source/include/task.h"
#include "HAL/LCD/LCD_Interface.h"
#include "RTOS/Config/FreeRTOSConfig.h"



#define READ 			1
#define WRITE 			0

#define L1				0
#define L2				1

#define ID				0
#define R_W				1

#define STATUS			1
#define RECEIEVED 		0




void Main_voidAppClockInit(void);
void USART_RXCallback(void);
void CAN_TX(void);
void CAN_RX(void);
u16 Std_id_High(u16 local_u16Std_Id);
void CAN_FilterConfig(void);




#endif /* APP_APP_INTERFACE_H_ */
