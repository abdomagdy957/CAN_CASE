#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Register.h"

// Set "Pin" Direction 
/*u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    u8 ERROR_FLAG = 0;

    switch (Copy_u8Port)
    {
    case DIO_u8PORTA:
        if (Copy_u8Direction == DIO_u8PIN_OUTPUT)
        {
            Set_Bit(DDRA, Copy_u8Pin);
        }
        else if (Copy_u8Direction == DIO_u8PIN_INPUT)
        {
            Clear_Bit(DDRA, Copy_u8Pin);
        }
        else
        {
            ERROR_FLAG = 1;
        }
        break;
    case DIO_u8PORTB:
        if (Copy_u8Direction == DIO_u8PIN_OUTPUT)
        {
            Set_Bit(DDRB, Copy_u8Pin);
        }
        else if (Copy_u8Direction == DIO_u8PIN_INPUT)
        {
            Clear_Bit(DDRB, Copy_u8Pin);
        }
        else
        {
            ERROR_FLAG = 1;
        }
        break;
    case DIO_u8PORTC:
        if (Copy_u8Direction == DIO_u8PIN_OUTPUT)
        {
            Set_Bit(DDRC, Copy_u8Pin);
        }
        else if (Copy_u8Direction == DIO_u8PIN_INPUT)
        {
            Clear_Bit(DDRC, Copy_u8Pin);
        }
        else
        {
            ERROR_FLAG = 1;
        }
        break;
    case DIO_u8PORTD:
        if (Copy_u8Direction == DIO_u8PIN_OUTPUT)
        {
            Set_Bit(DDRD, Copy_u8Pin);
        }
        else if (Copy_u8Direction == DIO_u8PIN_INPUT)
        {
            Clear_Bit(DDRD, Copy_u8Pin);
        }
        else
        {
            ERROR_FLAG = 1;
        }
        break;

    default:
        break;
    }

    return ERROR_FLAG;
}
*/

// Set "Pin" Value
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    u8 ERROR_FLAG = 0;

    switch (Copy_u8Port)
    {
    case DIO_u8PORTA:
        if (Copy_u8Value == DIO_u8PIN_HIGH)
            Set_Bit(PORTA, Copy_u8Pin);
        else if (Copy_u8Value == DIO_u8PIN_LOW)
            Clear_Bit(PORTA, Copy_u8Pin);
        else
            ERROR_FLAG = 1;
        break;

    case DIO_u8PORTB:
        if (Copy_u8Value == DIO_u8PIN_HIGH)
            Set_Bit(PORTB, Copy_u8Pin);
        else if (Copy_u8Value == DIO_u8PIN_LOW)
            Clear_Bit(PORTB, Copy_u8Pin);
        else
            ERROR_FLAG = 1;
        break;

    case DIO_u8PORTC:
        if (Copy_u8Value == DIO_u8PIN_HIGH)
            Set_Bit(PORTC, Copy_u8Pin);
        else if (Copy_u8Value == DIO_u8PIN_LOW)
            Clear_Bit(PORTC, Copy_u8Pin);
        else
            ERROR_FLAG = 1;
        break;

    case DIO_u8PORTD:
        if (Copy_u8Value == DIO_u8PIN_HIGH)
            Set_Bit(PORTD, Copy_u8Pin);
        else if (Copy_u8Value == DIO_u8PIN_LOW)
            Clear_Bit(PORTD, Copy_u8Pin);
        else
            ERROR_FLAG = 1;
        break;

    default:
        break;
    }

    return ERROR_FLAG;
}

// Set "Port" Direction
/*u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
    u8 Local_u8Error = 0;
    if (Copy_u8Port < 4)
    {
        switch (Copy_u8Port)
        {
        case DIO_u8PORTA:
            DDRA = Copy_u8Direction;
            break;
        case DIO_u8PORTB:
            DDRB = Copy_u8Direction;
            break;
        case DIO_u8PORTC:
            DDRC = Copy_u8Direction;
            break;
        case DIO_u8PORTD:
            DDRD = Copy_u8Direction;
            break;

        default:
            break;
        }
    }
    else
    {
        Local_u8Error = 1;
    }

    return Local_u8Error;
}*/

// Set "Port" Value
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
    u8 Local_u8Error = 0;
    if (Copy_u8Port < 4)
    {
        switch (Copy_u8Port)
        {
        case DIO_u8PORTA:
            PORTA = Copy_u8Value;
            break;
        case DIO_u8PORTB:
            PORTB = Copy_u8Value;
            break;
        case DIO_u8PORTC:
            PORTC = Copy_u8Value;
            break;
        case DIO_u8PORTD:
            PORTD = Copy_u8Value;
            break;

        default:
            break;
        }
    }
    else
    {
        Local_u8Error = 1;
    }

    return Local_u8Error;
}

// Get/Read "Pin" value
u8 DIO_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_u8Value)
{

    switch (Copy_u8Port)
    {
    case DIO_u8PORTA:
        *Copy_u8Value = Get_Bit(PINA, Copy_u8Pin);
        break;
    case DIO_u8PORTB:
        *Copy_u8Value = Get_Bit(PINB, Copy_u8Pin);
        break;
    case DIO_u8PORTC:
        *Copy_u8Value = Get_Bit(PINC, Copy_u8Pin);
        break;
    case DIO_u8PORTD:
        *Copy_u8Value = Get_Bit(PIND, Copy_u8Pin);
        break;

    default:
    	return NOK;
        break;
    }

    return OK;
}


u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8Value = 0;

	 switch (Copy_u8Port)
	    {
	    case DIO_u8PORTA:
	        Local_u8Value = Get_Bit(PINA, Copy_u8Pin);
	        break;
	    case DIO_u8PORTB:
	    	Local_u8Value = Get_Bit(PINB, Copy_u8Pin);
	        break;
	    case DIO_u8PORTC:
	    	Local_u8Value = Get_Bit(PINC, Copy_u8Pin);
	        break;
	    case DIO_u8PORTD:
	    	Local_u8Value = Get_Bit(PIND, Copy_u8Pin);
	        break;
	    default:
	        break;
	    }

	 return Local_u8Value;
}

void DIO_voidSetPortValue( u8 PORT_OUTPUT_VAL )
{

#if SELECTED_PORT == PORT_u8_A
    PORTA = PORT_OUTPUT_VAL;
#elif SELECTED_PORT == PORT_u8_B
    PORTB = PORT_OUTPUT_VAL;
#elif SELECTED_PORT == PORT_u8_C
    PORTC = PORT_OUTPUT_VAL;
#elif SELECTED_PORT == PORT_u8_D
    PORTD = PORT_OUTPUT_VAL;
#else

#endif

}
