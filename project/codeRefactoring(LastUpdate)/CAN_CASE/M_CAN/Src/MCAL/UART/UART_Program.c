
#include "LIB/BIT_MATH.h"
#include "LIB/std_types.h"

#include "MCAL/GPIO/GPIO_Interface.h"


#include "MCAL/UART/UART_interface.h"
#include "MCAL/UART/UART_config.h"
#include "MCAL/UART/UART_private.h"


#define THRESHOLD_VALUE  9000000UL

void (*USART1_RXCallBack)(void);

void USART_voidInit(UART_Channel UART_Num )
{

	//9600 BAUDE RATE
	USARTNumbers[UART_Num]->USART_BRR =  BAUDE_RATE;

#if (WORD_LENGTH == _8BIT_DATA)
	CLR_BIT(USARTNumbers[UART_Num]->USART_CR1 , M);

#elif (WORD_LENGTH == _9BIT_DATA)
	SET_BIT(USARTNumbers[UART_Num]->USART_CR1 , M);
#endif


#if (STOP_BIT == _1STOP_BIT)
	USARTNumbers[UART_Num]->USART_CR2 |= (0<<STOP1)|(0<<STOP0);

#elif (STOP_BIT == _0_5_STOP_BIT)
	USARTNumbers[UART_Num]->USART_CR2 |= (0<<STOP1)|(1<<STOP0);

#elif (STOP_BIT == _2STOP_BIT)
	USARTNumbers[UART_Num]->USART_CR2 |= (1<<STOP1)|(0<<STOP0);

#elif (STOP_BIT == _1_5_STOP_BIT)
	USARTNumbers[UART_Num]->USART_CR2 |= (1<<STOP1)|(1<<STOP0);
#endif




	/*
		put baud rates
		enable TX
		enable RX
		enable UART
	 */
	//USARTNumbers[UART_Num]->USART_BRR = 0x341;
	USARTNumbers[UART_Num]->USART_CR1 |=(1<<UE)|(1<<TE)|(1<<RE);

	/*cleare status register*/
	USARTNumbers[UART_Num]->USART_SR= CLR_REGISTER;

	//SET_BIT(USARTNumbers[USART_ONE]->USART_CR1 ,RXNEIE);
}


void USART_RX_InterruptEnable(UART_Channel UART_Num )
{
	SET_BIT(USARTNumbers[UART_Num]->USART_CR1 ,RXNEIE);
}

void USART_RX_InterruptDisable(UART_Channel UART_Num )
{
	CLR_BIT(USARTNumbers[UART_Num]->USART_CR1 ,RXNEIE);
}

void USART_TX_InterruptEnable(UART_Channel UART_Num )
{
	SET_BIT(USARTNumbers[UART_Num]->USART_CR1 ,TXEIE);
}

void USART_TX_InterruptDisable(UART_Channel UART_Num )
{
	CLR_BIT(USARTNumbers[UART_Num]->USART_CR1 ,TXEIE);
}

void USART_voidTransmitSynch(UART_Channel UART_Num  ,u8 Copy_u8DataArr[])
{
	u8 LOC_u8Counter=0;

	while(Copy_u8DataArr[LOC_u8Counter] !='\0' )
	{
		USARTNumbers[UART_Num]->USART_DR = Copy_u8DataArr[LOC_u8Counter];
		/*wait till transmition  complete */
		while( GET_BIT(USARTNumbers[UART_Num]->USART_SR ,TC) ==0 );
		LOC_u8Counter++;
	}
}

void USART_voidTransmitCharSynch(UART_Channel UART_Num  ,u8 Copy_u8DataArr)
{
	USARTNumbers[UART_Num]->USART_DR = Copy_u8DataArr;
	/*wait till transmition  complete */
	while( GET_BIT(USARTNumbers[UART_Num]->USART_SR ,TC) ==0 );
}

u8 USART_u8ReceiveSynch(UART_Channel UART_Num )
{
	u8 LOC_u8DataRecieve=0;

	u16 TimeOut=0;
	/*wait till Receive complete */
	while( GET_BIT(USARTNumbers[UART_Num]->USART_SR ,RXNE) ==0 && TimeOut ==THRESHOLD_VALUE)
	{
		TimeOut++;
	}
	if(TimeOut ==THRESHOLD_VALUE)
	{
		LOC_u8DataRecieve=255;
	}
	else
	{
		LOC_u8DataRecieve= (USARTNumbers[UART_Num]->USART_DR);
	}

	return (LOC_u8DataRecieve);

}

void USART1_void_SetCallBack(void(*Ptr)(void))
{
	USART1_RXCallBack = Ptr;
}

/*Interrupt Service Routines*/
void USART1_IRQHandler(void)
{

	if(GET_BIT(USARTNumbers[USART_ONE]->USART_SR,RXNE))
	{
		USART1_RXCallBack();

	}



}


/********************************************************/
void USART_ReceiveString(UART_Channel UART_Num,u8*pu8str)
{
	u8 i=0;

	//	pu8str[i]=MUART_u8ReceiveSynch(UART_Num);
	//LCD_WriteChar(pu8str[i]);
	for(;pu8str[i]!=13;)
	{
		i++;
		//	pu8str[i]=MUART_u8ReceiveSynch(UART_Num);
		//	LCD_WriteChar(pu8str[i]);
	}
	pu8str[i]=0;

}

u8 USART_ReceivePerodic(UART_Channel UART_Num,u8 *pu8data)
{
	u8 status =0;

	if (GET_BIT(USARTNumbers[UART_Num]->USART_SR,RXNE))
	{
		*pu8data=(USARTNumbers[UART_Num]->USART_DR);
		status = 1 ;
	}
	else
	{
		status= 0;
	}
	return status;
}

u8 USART_ReceiveNoBlock(UART_Channel UART_Num)
{
	return (USARTNumbers[UART_Num]->USART_DR);
}

u8 USART_TransmitNoBlock(UART_Channel UART_Num,u8 *pu8data)
{
	USARTNumbers[UART_Num]->USART_DR = *pu8data;
}
