/*
 * RCC_interface.h
 *
 *  Created on: Nov 8, 2023
 *      Author: Ahmed
 */


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "RCC_Private.h"

///***************   AHB BITS definition    ******************/
//#define AHB_DMA1_EN         	0
//#define AHB_DMA2_EN         	1
//#define AHB_SRAM_EN         	2
//#define AHB_FLITF_EN        	4
//#define AHB_CRC_EN         	6
//#define AHB_FSMC_EN         	8
//#define AHB_SDIO_EN         	10
///***************   APB2 BITS definition    ******************/
//#define APB2_AFIO_EN        	0
//#define APB2_GPIOA_EN       	2
//#define APB2_GPIOB_EN       	3
//#define APB2_GPIOC_EN       	4
//#define APB2_GPIOD_EN       	5
//#define APB2_ADC1_EN        	9
//#define APB2_ADC2_EN        	10
//#define APB2_TIM1_EN        	11
//#define APB2_SPI1_EN        	12
//#define APB2_USART1_EN      	14
//#define APB2_ADC3_EN        	15
///***************   APB1 BITS definition    ******************/
//#define APB1_TIM2_EN			0
//#define APB1_TIM3_EN			1
//#define APB1_TIM4_EN			2
//#define APB1_SPI2_EN			14
//#define APB1_USART2_EN 		17
//#define APB1_USART3_EN 		18
//#define APB1_I2C1_EN			21
//#define APB1_I2C2_EN			22
//#define APB1_USB_EN			23
//#define APB1_CAN_EN			25
//
//
//
///*******************   PLL MUL factor Options   ****************************/
//
//#define NO_CLOCK_FACTOR                                0b0000
//#define PLL_CLOCK_MULTIPLE_BY_2                        0b0000
//#define PLL_CLOCK_MULTIPLE_BY_3				 		   0b0001
//#define PLL_CLOCK_MULTIPLE_BY_4                        0b0010
//#define PLL_CLOCK_MULTIPLE_BY_5                        0b0011
//#define PLL_CLOCK_MULTIPLE_BY_6                        0b0100
//#define PLL_CLOCK_MULTIPLE_BY_7                        0b0101
//#define PLL_CLOCK_MULTIPLE_BY_8                        0b0110
//#define PLL_CLOCK_MULTIPLE_BY_9                        0b0111
//#define PLL_CLOCK_MULTIPLE_BY_10                       0b1000
//#define PLL_CLOCK_MULTIPLE_BY_11                       0b1001
//#define PLL_CLOCK_MULTIPLE_BY_12                       0b1010
//#define PLL_CLOCK_MULTIPLE_BY_13                       0b1011
//#define PLL_CLOCK_MULTIPLE_BY_14                       0b1100
//#define PLL_CLOCK_MULTIPLE_BY_15                       0b1101
//#define PLL_CLOCK_MULTIPLE_BY_16                       0b1110


/***************   Function definition    ******************/

void RCC_voidInitSystemClock(void);
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PerId);


// APB1 Peripherals
#define RCC_CAN_EN		RCC_APB1, 25

// APB2 Peripherals
#define RCC_GPIOA_EN	RCC_APB2, 2
#define RCC_GPIOB_EN	RCC_APB2, 3
#define RCC_GPIOC_EN	RCC_APB2, 4
#define RCC_UART_EN		RCC_APB2, 14

// AHB Peripherals
#define RCC_DMA1_EN		RCC_AHB,  0
#define RCC_DMA2_EN		RCC_AHB,  1



#endif // RCC_INTERFACE_H
