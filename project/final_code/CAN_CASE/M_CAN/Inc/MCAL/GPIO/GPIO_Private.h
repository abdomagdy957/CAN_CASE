/*
 * 		GPIO_Private.h
 *
 *  	Created on: Nov 27, 2023
 *      Author: Ahmed Mohammed
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

typedef enum{
	GPIO_A=0,
	GPIO_B,
	GPIO_C,
	GPIO_D,
}GPIO_t;

typedef enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
}PIN_t;

typedef enum{
	GPIO_LOW=0,
	GPIO_HIGH,
}GPIO_MODE;

#define GPIO_INPUT_ANALOG            	0b0000
#define GPIO_INPUT_FLOAT             	0b0100
#define GPIO_INPUT_PULL_UP_DOWN      	0b1000

#define GPIO_OUTPUT_10MHz_PP			0b0001
#define GPIO_OUTPUT_10MHz_OD			0b0101
#define GPIO_OUTPUT_10MHz_AF_PP			0b1001
#define GPIO_OUTPUT_10MHz_AF_OD			0b1101

#define GPIO_OUTPUT_2MHz_PP          	0b0010
#define GPIO_OUTPUT_2MHz_OD          	0b0110
#define GPIO_OUTPUT_2MHz_AF_PP       	0b1010
#define GPIO_OUTPUT_2MHz_AF_OD       	0b1110

#define GPIO_OUTPUT_50MHz_PP			0b0011
#define GPIO_OUTPUT_50MHz_OD			0b0111
#define GPIO_OUTPUT_50MHz_AF_PP		    0b1011
#define GPIO_OUTPUT_50MHz_AF_OD			0b1111

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
