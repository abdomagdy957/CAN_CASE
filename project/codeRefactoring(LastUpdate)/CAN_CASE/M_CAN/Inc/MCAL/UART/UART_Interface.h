
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/***************   Function definition    ******************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/


typedef enum
{
	USART_ONE=0,
	USART_TwO,
	USART_THREE,
	UART_FOUR,
	UART_FIVE


}UART_Channel;


void USART_voidInit(UART_Channel UART_Num);
void USART_voidTransmitSynch(UART_Channel UART_Num , u8 Copy_u8DataArr[]  );
void USART_voidTransmitCharSynch(UART_Channel UART_Num  ,u8 Copy_u8DataArr);
u8   USART_u8ReceiveSynch(UART_Channel UART_Num );
void USART_ReceiveString(UART_Channel UART_Num,u8*pu8str);
u8 USART_ReceivePerodic(UART_Channel UART_Num,u8 *pu8data);
u8 USART_ReceiveNoBlock(UART_Channel UART_Num);
void USART_RX_InterruptDisable(UART_Channel UART_Num );
void USART_RX_InterruptEnable(UART_Channel UART_Num );

void USART1_void_SetCallBack();

#endif // UART_INTERFACE_H
