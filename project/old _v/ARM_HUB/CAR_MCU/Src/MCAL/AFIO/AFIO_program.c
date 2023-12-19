

#include "../../../Inc/MCAL/AFIO/AFIO_interface.h"
#include "../../../Inc/MCAL/AFIO/AFIO_config.h"
#include "../../../Inc/MCAL/AFIO/AFIO_private.h"



/*************	 Function OF Set EXTI Configuration  **************************/

void AFIO_voidSetEXTIConfiguration (u8 Copy_u8Line, u8 Copy_u8PortMap)
{
	u8 Local_u8RegIndex = 0;
	/* Assign to EXTICRx register */
	Local_u8RegIndex = Copy_u8Line / 4;
	Copy_u8Line = Copy_u8Line % 4 ;

	AFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111) 		 << (Copy_u8Line * 4));
	AFIO->EXTICR[Local_u8RegIndex] |=  ((Copy_u8PortMap) << (Copy_u8Line * 4));
}

/*************	 Function OF remapping pins   **************************/

void AFIO_voidRemapPeripheralPins (u8 Copy_u8Port)
{

	switch(Copy_u8Port){
		 case UART1_REMAP:
			SET_BIT(AFIO->MAPR, UART1_REMAP);
			break;
		case CAN_REMAP:
			/* CAN remap, use PB8, PB9 >> BITS 13,14   = 10*/
			CLR_BIT(AFIO->MAPR, CAN_REMAP); 	/* bit 13 */
			SET_BIT(AFIO->MAPR, (CAN_REMAP+1) ); /* bit 14 */
			break;
		case I2C1_REMAP:
			SET_BIT(AFIO->MAPR, I2C1_REMAP);
			break;
		case SPI1_REMAP:
			SET_BIT(AFIO->MAPR, SPI1_REMAP);
			break;
	}

}

