/*
 * 		main.c
 *
 * 		Created on: Nov 28, 2023
 *      Author: AHMED
 */


#include "APP/APP_Interface.h"
#include "APP/APP_Config.h"
//#include "MCAL/UART/UART_Interface.h"
#include "HAL/LCD/LCD_Interface.h"


#define TX_LED_CHECK	GPIO_A, PIN2, GPIO_HIGH
#define RX_LED_CHECK	GPIO_A, PIN1, GPIO_HIGH

#define terminationChar '/'
#define nullChar '\0'
#define resetChar '.'
volatile u8 counter = 0;
volatile u8 ch1=terminationChar;

TaskHandle_t	xTask_1	;
TaskHandle_t	xTask_2	;
TaskHandle_t	xTask_3	;

void vTask_CAN_TX( void* params );
void vTask_CAN_RX( void* params );
void vTask_IDLE( void* params );

//volatile u8 TX_Flag = 0;
//volatile u8 RX_Flag = 0;

static u8 Device_IDs[][6] = {"FRONT", "BACK", "BELT", "MOTOR"};
static u8 Device_Status[][4] = {"OFF", "ON"};

volatile u8 Globaleu8Data[3];

//
//extern u8 TX_Flag;
//extern TaskHandle_t	xTask_1;

void Main_voidAppClockInit(void)
{
	/* Rcc init */
	RCC_voidInitSystemClock();

	/* Enable Peripherals Clock */
	RCC_voidEnablePeripheralClock(RCC_GPIOA_EN);		// Enable GPIO_A Clock
	RCC_voidEnablePeripheralClock(RCC_UART_EN);			// Enable USART Clock
	RCC_voidEnablePeripheralClock(RCC_CAN_EN);			// Enable CAN Clock
	RCC_voidEnablePeripheralClock(RCC_GPIOB_EN);
	GPIO_voidSetPinMode(GPIO_B,PIN0,GPIO_OUTPUT_2MHz_PP);
	GPIO_voidSetPinMode(GPIO_B,PIN1,GPIO_OUTPUT_2MHz_PP);
	GPIO_voidSetPinMode(GPIO_B,PIN3,GPIO_OUTPUT_2MHz_PP);
	/* Setting GPIO_Pins Mode/Direction */
	GPIO_voidSetPinMode(UART_RX_PIN);					// RX -> Input Floating
	GPIO_voidSetPinMode(UART_TX_PIN);					// TX -> Output AF PP

	GPIO_voidSetPinMode(CAN_RX_PIN);					// RX -> Input Floating
	GPIO_voidSetPinMode(CAN_TX_PIN);					// TX -> Output AF PP

	/* Enable Interrupt */
	NVIC_voidEnableInterrupt(USART1_IRQn);				// Enable USART Interrupt

	/* Peripherals Initialization */

	//	STK_voidInit();										// Init	Systick

	USART1_void_SetCallBack(USART_RXCallback);
	USART_RX_InterruptEnable(USART_ONE);
	USART_voidInit(USART_ONE);							// Init USART 1 	9600

	CAN_voidInit();										// CAN Init

	CAN_FilterConfig();									//

	CAN_voidStart();									// Start Conversion


}

void CAN_TX(void)			// CAN Transmit Fun
{
	CAN_TxHeaderTypeDef tx_header;

	tx_header.StdId = 0x65d;
	tx_header.IDE = CAN_ID_STD;
	tx_header.RTR = CAN_RTR_DATA;
	tx_header.DLC = 3;				// Data Length is 3 for ID, Command, Data.

	CAN_voidAddTxMsg(&tx_header,Globaleu8Data);

}

void CAN_RX(void)			// CAN Receive Fun
{
	CAN_RxHeaderTypeDef Rx_header;

	while(CAN_voidRXPending(CAN_RX_FIFO0) == 0);

	CAN_voidGetRxMsg(CAN_RX_FIFO0,&Rx_header,Globaleu8Data);
//	USART_voidTransmitSynch(USART_ONE, Device_IDs[Globaleu8Data[ID]]);
//
//	USART_voidTransmitCharSynch(USART_ONE, ' ');
	if(Globaleu8Data[ID] < 2){
		USART_voidTransmitSynch(USART_ONE, Device_Status[Globaleu8Data[STATUS]]);
	}
	else{
		if(Globaleu8Data[STATUS] > 0){
			u8 str[20];
			u8 *intSTR = IntToString(Globaleu8Data[STATUS],str);
			USART_voidTransmitSynch(USART_ONE, intSTR);
		}
		else{
			USART_voidTransmitCharSynch(USART_ONE, '0');
		}
	}

//	USART_voidTransmitCharSynch(USART_ONE, '\n');
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


void USART_RXCallback(void)
{
	//	static u8 Local_u8counter = 0;
	//
	//	Local_u8counter++;
	//
	//	if( Local_u8counter == 1)
	//	{
	//		// Task ID
	//		Globaleu8Data[ID] =  ( USART_ReceiveNoBlock(USART_ONE) - '0' );
	//		GPIO_voidSetPinValue(GPIO_B, PIN0, GPIO_HIGH);
	//		//		USART_voidTransmitCharSynch(USART_ONE, Globaleu8Data[ID] + '0');
	//
	//	}
	//	else if( Local_u8counter == 2)
	//	{
	//		// READ/WRITE  Data
	//		Globaleu8Data[R_W] = (USART_ReceiveNoBlock(USART_ONE) - '0');
	//		GPIO_voidSetPinValue(GPIO_B, PIN1, GPIO_HIGH);
	//		//		USART_voidTransmitCharSynch(USART_ONE, Globaleu8Data[R_W] + '0');
	//
	//	}
	//	else if( Local_u8counter == 3)
	//	{
	//		// Data
	//		Globaleu8Data[2] = (USART_ReceiveNoBlock(USART_ONE) - '0');
	//		GPIO_voidSetPinValue(GPIO_B, PIN3, GPIO_HIGH);
	//		//		USART_voidTransmitCharSynch(USART_ONE, Globaleu8Data[2] + '0');
	//
	//		Local_u8counter = 0;
	//		USART_voidTransmitCharSynch(USART_ONE, ' ');
	//		//		TX_Flag = 1;
	//		vTaskResume(xTask_1);
	//	}

	if(ch1 == terminationChar)
		counter++;

	//read identifier, DLC, ID, Command, Data
	ch1 = USART_ReceiveNoBlock(USART_ONE);
	if(ch1 != nullChar && ch1 != terminationChar && ch1 != resetChar){
		//		LCD_WriteChar(ch1);
	}
	else if(ch1 == resetChar){
		//		LCD_SetCursor(0, 0);
		ch1 = terminationChar;
		counter = 0;
	}
	if(ch1 >= '0' && ch1 <= '9'){
		ch1 -= '0';
		if(counter == 3){//check ID
			GPIO_voidSetPinValue(GPIO_B, PIN0, GPIO_HIGH);
			Globaleu8Data[ID] = ch1;
		}
		else if(counter == 4) {//check command
			Globaleu8Data[R_W] = ch1;
			GPIO_voidSetPinValue(GPIO_B, PIN1, GPIO_HIGH);
			if(Globaleu8Data[R_W] == READ){
				GPIO_voidSetPinValue(GPIO_B, PIN3, GPIO_HIGH);
				Globaleu8Data[2] = 0;
				counter = 2;
				vTaskResume(xTask_1);
			}
		}
		else if(counter == 5){//check data
			GPIO_voidSetPinValue(GPIO_B, PIN3, GPIO_HIGH);
			Globaleu8Data[2] = ch1;
			counter = 2;
			vTaskResume(xTask_1);
		}
	}

}

int main()
{
	Main_voidAppClockInit();

	GPIO_voidSetPinMode(GPIO_A, PIN2,GPIO_OUTPUT_2MHz_PP);
	GPIO_voidSetPinMode(GPIO_A, PIN1,GPIO_OUTPUT_2MHz_PP);

	xTaskCreate(vTask_CAN_TX, "CAN_TX", configMINIMAL_STACK_SIZE, NULL, 2,&xTask_1);
	xTaskCreate(vTask_CAN_RX, "CAN_RX", configMINIMAL_STACK_SIZE, NULL, 2,&xTask_2);
	vTaskSuspend(xTask_1);
	vTaskSuspend(xTask_2);
	vTaskStartScheduler();

	while(1);
	return 0;
}

void vTask_CAN_TX( void* params )
{
	while(1)
	{
		// Check test GPIO_A_PIN_2

		//		if(TX_Flag == 1)
		//		{
//		USART_RX_InterruptDisable(USART_ONE);
		GPIO_voidSetPinValue(TX_LED_CHECK);
		CAN_TX();			// Start Transmit

		//		TX_Flag = 0;		// Busy
		//
		//		RX_Flag = 1;		// Start
		vTaskResume(xTask_2);
		vTaskSuspend(xTask_1);
		//		}

		//		vTaskDelay(100);
	}
}

void vTask_CAN_RX( void* params )
{
	while(1)
	{
		// Check test GPIO_A_PIN_1

		//		if(RX_Flag == 1)
		//		{
		GPIO_voidSetPinValue(RX_LED_CHECK);
		CAN_RX();			// Start Receive

		//		RX_Flag = 0;
		GPIO_voidSetPinValue(GPIO_A, PIN1, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_A, PIN2, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_B, PIN0, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_B, PIN1, GPIO_LOW);
		GPIO_voidSetPinValue(GPIO_B, PIN3, GPIO_LOW);
//		USART_RX_InterruptEnable(USART_ONE);
		vTaskSuspend(xTask_2);

		//		}
		//
		//		vTaskDelay(100);
	}
}
