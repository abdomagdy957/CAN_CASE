/*************************************************************/
/* Description: SPI_program.c implement SPI APIs			 */
/* Author     : Zaki Ahmed Hamed                             */
/* Date       : 21 Sep 2020                                  */
/* Version    : V03                      				     */
/* LOG		  : v01 -> initial creation 					 */
/*			  : v02 -> add [MSPI_voidRecieveASynch] function */
/*            : v03 -> make driver handle SPI1,SPI2,SPI3     */
/*************************************************************/


#include"Lib/std_types.h"
#include"Lib/utils.h"

#include "MCAL/GPIO/GPIO_interface.h"
#include"MCAL/STK/STK_interface.h"
#include"MCAL/SPI/SPI_init.h"
#include"MCAL/SPI/SPI_private.h"
#include"MCAL/SPI/SPI_config.h"

/* Global Callback variables */
void (*CallBack_Func)();

void MSPI_voidInit( u8 Copy_u8SPINumbers)
{
	/* CPOL =1 / CPHA = 1 / Prescaller = Clk/2 / SPI Enable / MSB First */
	//SPI1->SPI_CR1 = 0x0347;
#if (CLOCK_PHASE == CPHA_HIGH)
	SET_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , CPHA);
#elif (CLOCK_PHASE == CPHA_LOW)
	CLR_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , CPHA);
#endif

#if (CLOCK_POLARITY == IDLE_HIGH)
	SET_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , CPOL);
#elif (CLOCK_POLARITY == IDLE_LOW)
	CLR_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , CPOL);
#endif


#if (MASTER_SLAVE_SELECT == MASTER)
	SET_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , MSTR);
#elif (MASTER_SLAVE_SELECT == SLAVE)
	CLR_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , MSTR);
#endif

#if (BAUD_ERATE	== FPCLK_DIV_2)
	SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 |= (0<<BR2)|(0<<BR1)|(0<<BR0);

#elif (BAUD_ERATE	== FPCLK_DIV_4)
	SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 |= (0<<BR2)|(0<<BR1)|(1<<BR0);

#elif (BAUD_ERATE	== FPCLK_DIV_8)
	SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 |= (0<<BR2)|(1<<BR1)|(0<<BR0);

#elif (BAUD_ERATE	== FPCLK_DIV_16)
	SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 |= (0<<BR2)|(1<<BR1)|(1<<BR0);

#elif (BAUD_ERATE	== FPCLK_DIV_32)
	SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 |= (1<<BR2)|(0<<BR1)|(0<<BR0);

#elif (BAUD_ERATE	== FPCLK_DIV_64)
	SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 |= (1<<BR2)|(0<<BR1)|(1<<BR0);

#elif (BAUD_ERATE	== FPCLK_DIV_128)
	SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 |= (0<<BR2)|(1<<BR1)|(0<<BR0);

#elif (BAUD_ERATE	== FPCLK_DIV_256)
	SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 |= (1<<BR2)|(1<<BR1)|(1<<BR0);

#endif

#if (DATA_ORDER	== MSB_FIRST)
	CLR_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , LSBFIRST);
#elif (DATA_ORDER	== LSB_FIRST)
	SET_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , LSBFIRST);
#endif

#if (SW_SLAVE_MANAGE == SW_MANAGE_ENABLE)
	SET_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , SSM);
#elif (SW_SLAVE_MANAGE == SW_MANAGE_DISABLE)
	CLR_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , SSM);
#endif

#if (DATA_FORMAT == _8BIT)
	CLR_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , DFF);
#elif (DATA_FORMAT == _16BIT)
	SET_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 , SSM);
#endif

//	SET_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_CR2 , 7);
	/* enable SPI , SSI*/
	SPI_NUM[Copy_u8SPINumbers]->SPI_CR1 |= (1<<SPE) ;
//	STK_voidInit();

}

void MSPI_voidSendRecieveSynch(u8 Copy_u8SPINumbers ,u8 Copy_u8DataToTransmit ,u8 *Copy_u8DataToReceive)
{
	/*1- Clear for slave select pin*/
	if(Copy_u8SPINumbers == 0)
		GPIO_voidSetPinValue(MSPI_SLAVE1_PIN, LOW);
	else
		GPIO_voidSetPinValue(MSPI_SLAVE2_PIN, LOW);
//	STK_voidSetBusyWait(200);
	/*2- Put data transmit to SPI data register*/
	SPI_NUM[Copy_u8SPINumbers] -> SPI_DR =Copy_u8DataToTransmit;

//	timeoutFlag = 0;
//	STK_voidSetIntervalSingle(timeoutTimeMicroSec, timeoutFunc);
	/*3- wait Busy flag finish*/
	while(GET_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_SR , BSY) == 1 && GET_BIT(SPI_NUM[Copy_u8SPINumbers]->SPI_SR , RXNE) == 1 );
//	STK_voidStopInterval();
	/*4- return received data*/
	if(	Copy_u8DataToReceive != NULL )
	{
		*Copy_u8DataToReceive = SPI_NUM[Copy_u8SPINumbers] -> SPI_DR;
	}

	/*5-set for slave select pin*/	
	if(Copy_u8SPINumbers == 0)
		GPIO_voidSetPinValue(MSPI_SLAVE1_PIN, HIGH);
	else
		GPIO_voidSetPinValue(MSPI_SLAVE2_PIN, HIGH);

}

void MSPI_voidSendRecieveASynch(u8 Copy_u8SPINumbers , u8 Copy_u8DataToTransmit , void(*Copy_Func)())
{
	/*Clear for slave select pin*/
	if(Copy_u8SPINumbers == 0)
		GPIO_voidSetPinValue(MSPI_SLAVE1_PIN, LOW);
	else
		GPIO_voidSetPinValue(MSPI_SLAVE2_PIN, LOW);

	// Assign call back function
	CallBack_Func = Copy_Func;
	//send data
	SPI_NUM[Copy_u8SPINumbers] -> SPI_DR =  Copy_u8DataToTransmit;

	/*set for slave select pin*/
	if(Copy_u8SPINumbers == 0)
			GPIO_voidSetPinValue(MSPI_SLAVE1_PIN, HIGH);
		else
			GPIO_voidSetPinValue(MSPI_SLAVE2_PIN, HIGH);

}

void SPI1_IRQHandler(void)
{
	CallBack_Func();
}

u8 MSPI_u8ReadDataISR(u8 Copy_u8SPINumbers){
	return (SPI_NUM[Copy_u8SPINumbers] -> SPI_DR);
}


