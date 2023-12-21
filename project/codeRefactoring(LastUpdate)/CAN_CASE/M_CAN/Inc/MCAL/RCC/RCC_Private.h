/*
 * RCC_private.h
 *
 *  Created on: Nov 8, 2023
 *      Author: atef
 */

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/*******************   Register Definition     ***********************/
typedef struct {

	volatile u32 CR       ;
	volatile u32 CFGR     ;
	volatile u32 CIR      ;
	volatile u32 APB2RSTR ;
	volatile u32 APB1RSTR ;
	volatile u32 AHBENR   ;
	volatile u32 APB2ENR  ;
	volatile u32 APB1ENR  ;
	volatile u32 BDCR     ;
	volatile u32 CSR      ;
}RCC_t;

/*******************   BASE Address Definition    *********************/

#define RCC_BASE_ADDRESS	0x40021000		//define the boundary address of RCC

#define RCC ( ( volatile RCC_t* ) RCC_BASE_ADDRESS)

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2

/*******************     Clock Types      *****************************/
#define RCC_HSE_CRYSTAL       0
#define RCC_HSE_RC            1
#define RCC_HSI               2
#define RCC_PLL               3

/*******************   PLL INPUT Options   ****************************/
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2


#endif // RCC_PRIVATE_H
