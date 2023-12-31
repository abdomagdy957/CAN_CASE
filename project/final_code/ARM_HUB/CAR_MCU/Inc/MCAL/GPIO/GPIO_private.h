/*
 * GPIO_private.h
 *
 *  Created on: Nov 1, 2023
 *      Author: atef
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_




typedef struct {

	volatile u32 CRL  ;
	volatile u32 CRH  ;
	volatile u32 IDR  ;
	volatile u32 ODR  ;
	volatile u32 BSRR ;
	volatile u32 BRR  ;
	volatile u32 LCKR ;

}GPIO_t;

/*******************   BASE Address Definition    *********************/

#define GPIOA_Base_Address      0x40010800      //define the boundary address of GPIOA
#define GPIOB_Base_Address      0x40010C00      //define the boundary address of GPIOB
#define GPIOC_Base_Address      0x40011000      //define the boundary address of GPIOC

/***********   REGISTER ADDRESSES FOR GPIOx     ***********************/
#define GPIO_A						( ( volatile GPIO_t* ) GPIOA_Base_Address )
#define GPIO_B						( ( volatile GPIO_t* ) GPIOB_Base_Address )
#define GPIO_C						( ( volatile GPIO_t* ) GPIOC_Base_Address )


/***********   REGISTER ADDRESSES FOR GPIOA     ***********************/

#define GPIOA_CRL               *((volatile u32 *)(GPIOA_Base_Address + 0X00))
#define GPIOA_CRH               *((volatile u32 *)(GPIOA_Base_Address + 0X04))
#define GPIOA_IDR               *((volatile u32 *)(GPIOA_Base_Address + 0X08))
#define GPIOA_ODR               *((volatile u32 *)(GPIOA_Base_Address + 0X0C))
#define GPIOA_BSRR              *((volatile u32 *)(GPIOA_Base_Address + 0X10))
#define GPIOA_BRR               *((volatile u32 *)(GPIOA_Base_Address + 0X14))
#define GPIOA_LCKR              *((volatile u32 *)(GPIOA_Base_Address + 0X18))

/***********   REGISTER ADDRESSES FOR GPIOB     ***********************/

#define GPIOB_CRL               *((volatile u32 *)(GPIOB_Base_Address + 0X00))
#define GPIOB_CRH               *((volatile u32 *)(GPIOB_Base_Address + 0X04))
#define GPIOB_IDR               *((volatile u32 *)(GPIOB_Base_Address + 0X08))
#define GPIOB_ODR               *((volatile u32 *)(GPIOB_Base_Address + 0X0C))
#define GPIOB_BSRR              *((volatile u32 *)(GPIOB_Base_Address + 0X10))
#define GPIOB_BRR               *((volatile u32 *)(GPIOB_Base_Address + 0X14))
#define GPIOB_LCKR              *((volatile u32 *)(GPIOB_Base_Address + 0X18))

/***********   REGISTER ADDRESSES FOR GPIOC     ***********************/

#define GPIOC_CRL               *((volatile u32 *)(GPIOC_Base_Address + 0X00))
#define GPIOC_CRH               *((volatile u32 *)(GPIOC_Base_Address + 0X04))
#define GPIOC_IDR               *((volatile u32 *)(GPIOC_Base_Address + 0X08))
#define GPIOC_ODR               *((volatile u32 *)(GPIOC_Base_Address + 0X0C))
#define GPIOC_BSRR              *((volatile u32 *)(GPIOC_Base_Address + 0X10))
#define GPIOC_BRR               *((volatile u32 *)(GPIOC_Base_Address + 0X14))
#define GPIOC_LCKR              *((volatile u32 *)(GPIOC_Base_Address + 0X18))

#endif /* GPIO_PRIVATE_H_ */
