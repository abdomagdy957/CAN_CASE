#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "Port_Config.h"
#include "Port_Private.h"
#include "Port_Interface.h"
#include "Port_Register.h"


void PORT_voidInit(void)
{
    DDRA = PORTA_DIR ;
    DDRB = PORTB_DIR ;
    DDRC = PORTC_DIR ;
    DDRD = PORTD_DIR ;

    PORTA = PORTA_INIT_VALUE;
    PORTB = PORTB_INIT_VALUE;
    PORTC = PORTC_INIT_VALUE;
    PORTD = PORTD_INIT_VALUE;


}
