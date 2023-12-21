/*
 * 		main.c
 *
 * 		Created on: Nov 28, 2023
 *      Author: AHMED
 */


#include "APP/APP_Interface.h"
#include "APP/APP_Config.h"



int main()
{


	xTaskCreate(vTask_CAN_TX, "CAN_TX", configMINIMAL_STACK_SIZE, NULL, 2,&xTask_1);
	xTaskCreate(vTask_CAN_RX, "CAN_RX", configMINIMAL_STACK_SIZE, NULL, 2,&xTask_2);

	vTaskSuspend(xTask_1);
	vTaskSuspend(xTask_2);
	vTaskStartScheduler();

	while(1);
	return 0;
}

