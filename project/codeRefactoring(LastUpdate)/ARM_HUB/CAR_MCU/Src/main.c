#include "APP/APP_Interface.h"
#include "APP/APP_Config.h"





int main()
{

	/* CAN Start */
	CAN_voidStart();

	while(1)
	{
		CAN_RX();
		UART_TX();
	}
	return 0;
}

