

/******************** 			CAN 		   ***********************************/

#include "../Inc/APP/app.h"
#include "MCAL/UART/UART_interface.h"

#define ID				0
#define R_W				1
#define DATA_BYTE		2

#define UART1_RX_PIN		PINA10, INPUT_PULL_UP_DOWN
#define UART1_TX_PIN		PINA9, OUTPUT_SPEED_2MHZ_AFPP
#define RCC_UART1_EN		RCC_APB2, 14

#define UART2_RX_PIN		PINA3, INPUT_PULL_UP_DOWN
#define UART2_TX_PIN		PINA2, OUTPUT_SPEED_2MHZ_AFPP
#define RCC_UART2_EN		RCC_APB1, 17

u8 Device_IDs[][6] = {"FRONT", "BACK", "BELT", "MOTOR", "TEMP", "LIGHT"};
u8 Device_CMD[][6] ={"Write", "Read"};
u8 Device_Value[][5] ={"Low", "High"};
u8 Data_TX[2];
u8 Data_RX[3];
volatile u8 state = 0;
volatile u8 readSPI = 0;
volatile u8 counter = 0;
volatile u8 UART_NUM	= USART_ONE;
volatile u8 SPI_NUM	= 0;

void CAN_TX()
{
	CAN_TxHeaderTypeDef tx_header;
	tx_header.StdId = 0x65d;
	tx_header.IDE = CAN_ID_STD;
	tx_header.RTR = CAN_RTR_DATA;
	tx_header.DLC = 2;
	//	tx_header.TransmitGlobalTime=DISABLE;

	CAN_voidAddTxMsg(&tx_header,Data_TX);
}

void CAN_RX(void)
{

	CAN_RxHeaderTypeDef Rx_header;
	while(CAN_voidRXPending(CAN_RX_FIFO0) == 0);
	CAN_voidGetRxMsg(CAN_RX_FIFO0,&Rx_header,Data_RX);
	//	GPIO_voidSetPinValue(PINA1, HIGH);
	LCD_Clear();
	LCD_SetCursor(0, 0);
	//	CAN_Data(Data);
	if(Data_RX[ID] > 3){
		Data_RX[R_W] = 1;
	}
	LCD_WriteString(Device_CMD[Data_RX[R_W]]);
	LCD_WriteChar(' ');
	LCD_WriteString(Device_IDs[Data_RX[ID]]);
	LCD_WriteChar(' ');
	if(Data_RX[R_W] == 0 && Data_RX[ID] < 2)
		LCD_WriteString(Device_Value[Data_RX[DATA_BYTE]]);
}

u16 Std_id_High(u16 local_u16Std_Id)
{
	return (local_u16Std_Id << 5);
}

void CAN_FilterConfig(void)
{
	CAN_FilterTypeDef CAN_FilterInit;
	CAN_FilterInit.FilterActivation = ENABLE;
	CAN_FilterInit.FilterBank = 0;
	CAN_FilterInit.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	CAN_FilterInit.FilterIdHigh = Std_id_High(0x65d);
	CAN_FilterInit.FilterIdLow = 0x0000;
	CAN_FilterInit.FilterMaskIdHigh = 0x0000;
	CAN_FilterInit.FilterMaskIdLow = 0x0000;
	CAN_FilterInit.FilterMode = CAN_FILTERMODE_IDMASK;
	CAN_FilterInit.FilterScale = CAN_FILTERSCALE_32BIT;

	CAN_voidConfigFilter(&CAN_FilterInit);
}

void UART_TX(void)
{
	counter = 0;

	while(counter < 5)
	{
		STK_voidSetBusyWait(50);

		if(counter == 0)
		{
			LCD_SetCursor(1, counter);
			LCD_WriteNumber(Data_RX[ID]);
			USART_voidTransmitCharSynch(UART_NUM, Data_RX[ID]);
			//			USART_voidTransmitCharSynch(USART_ONE, 'H');
			counter++;
		}
		else if(counter == 1){
			LCD_SetCursor(1, counter + 1);
			LCD_WriteNumber(Data_RX[R_W]);
			USART_voidTransmitCharSynch(UART_NUM, Data_RX[R_W]);
			//			USART_voidTransmitCharSynch(USART_ONE, 'A');
			counter++;
		}
		else
		{
			if(Data_RX[R_W] == 0){
				USART_voidTransmitCharSynch(UART_NUM, Data_RX[DATA_BYTE]);
				Data_TX[R_W] = Data_RX[DATA_BYTE];
				LCD_SetCursor(1, counter + 2);
				LCD_WriteNumber(Data_TX[R_W]);
				break;
			}
			else if(readSPI == 1){
				readSPI = 0;
				//				GPIO_voidSetPinValue(PINA1, HIGH);
				MSPI_voidSendRecieveSynch(SPI_NUM, 0, &state);
				Data_TX[R_W] = state;
				LCD_SetCursor(1, counter + 2);
				LCD_WriteNumber(counter);
				counter++;
				if(counter < 5)
					USART_voidTransmitCharSynch(UART_NUM, state);
			}
		}
	}

	readSPI = 0;
	Data_TX[ID] = Data_RX[ID];
	CAN_TX();
}

void USART_RXCallback()
{
	u8 temp;
	readSPI = 1;
	temp = USART_ReceiveNoBlock(UART_NUM);
}
int main()
{

	/* RCC Init */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);		// GPIO_A
	RCC_voidEnableClock(RCC_APB2, 3);		// GPIO_B
	RCC_voidEnableClock(RCC_APB2, 12);		// SPI1
	RCC_voidEnableClock(RCC_APB1, 14);		// SPI2

	GPIO_voidSetPinDirection(PINA1, OUTPUT_SPEED_10MHZ_PP);
	//	/* SPI MASTER PIN Init */
	GPIO_voidSetPinDirection(PINA0, OUTPUT_SPEED_10MHZ_PP);//Slave 1 Control
	GPIO_voidSetPinDirection(PINA4, INPUT_PULL_UP_DOWN);
	GPIO_voidSetPinDirection(PINA5, OUTPUT_SPEED_10MHZ_AFPP);
	GPIO_voidSetPinDirection(PINA6, INPUT_FLOATING);
	GPIO_voidSetPinDirection(PINA7, OUTPUT_SPEED_10MHZ_AFPP);
	GPIO_voidSetPinPull(PINA4, PULL_UP);

	GPIO_voidSetPinDirection(PINA1, OUTPUT_SPEED_10MHZ_PP);//Slave 2 Control
	GPIO_voidSetPinDirection(PINB12, INPUT_PULL_UP_DOWN);
	GPIO_voidSetPinDirection(PINB13, OUTPUT_SPEED_10MHZ_AFPP);
	GPIO_voidSetPinDirection(PINB14, INPUT_FLOATING);
	GPIO_voidSetPinDirection(PINB15, OUTPUT_SPEED_10MHZ_AFPP);
	GPIO_voidSetPinPull(PINB12, PULL_UP);
	//Initialize SPI
	MSPI_voidInit(0);
	MSPI_voidInit(1);

	RCC_voidEnableClock(RCC_UART1_EN);			// Enable USART Clock
	/* Setting GPIO_Pins Mode/Direction */
	GPIO_voidSetPinDirection(UART1_RX_PIN);					// RX -> Input PUSH-PULL
	GPIO_voidSetPinPull(PINA10, PULL_DOWN);
	GPIO_voidSetPinDirection(UART1_TX_PIN);					// TX -> Output AF PP

	RCC_voidEnableClock(RCC_UART2_EN);			// Enable USART Clock
	/* Setting GPIO_Pins Mode/Direction */
	GPIO_voidSetPinDirection(UART2_RX_PIN);					// RX -> Input PUSH-PULL
	GPIO_voidSetPinPull(PINA3, PULL_DOWN);
	GPIO_voidSetPinDirection(UART2_TX_PIN);					// TX -> Output AF PP

	/* Enable Interrupt */
	NVIC_voidEnableInterrupt(USART1_IRQn);				// Enable USART1 Interrupt
	NVIC_voidEnableInterrupt(USART2_IRQn);				// Enable USART2 Interrupt

	USART1_void_SetCallBack(USART_RXCallback);
	USART_RX_InterruptEnable(USART_ONE);
	USART_voidInit(USART_ONE);

	USART2_void_SetCallBack(USART_RXCallback);
	USART_RX_InterruptEnable(USART_TWO);
	USART_voidInit(USART_TWO);
	STK_voidInit();
	/* LCD Init */
	LCD_PinsInit();
	LCD_Init();

	/* CAN init */
	CAN_voidInit();

	/* CAN Filter set */
	CAN_FilterConfig();

	/* CAN Start */
	CAN_voidStart();
//	LCD_WriteChar('H');
	while(1)
	{
		CAN_RX();
		if(Data_RX[ID] < 4){
			UART_NUM = USART_ONE;
			SPI_NUM = 0;
		}
		else{
			UART_NUM = USART_TWO;
			SPI_NUM = 1;
		}
		UART_TX();
		//		SPI_SendRecv();
	}
	return 0;
}

