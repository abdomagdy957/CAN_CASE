
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

// Pin Output
//#define DIO_u8PIN_OUTPUT    1
//#define DIO_u8PIN_INPUT     0

// Pin Values
#define DIO_u8PIN_LOW       0
#define DIO_u8PIN_HIGH      1

// Port Names
#define DIO_u8PORTA         0
#define DIO_u8PORTB         1
#define DIO_u8PORTC         2
#define DIO_u8PORTD         3

// Port Output
//#define DIO_u8PORT_OUTPUT   0xFF
//#define DIO_u8PORT_INPUT    0

// Pin Num
#define DIO_u8PIN_0         0
#define DIO_u8PIN_1         1
#define DIO_u8PIN_2         2
#define DIO_u8PIN_3         3
#define DIO_u8PIN_4         4
#define DIO_u8PIN_5         5
#define DIO_u8PIN_6         6
#define DIO_u8PIN_7         7


// Set "Pin" Direction 
//u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

// Set "Pin" Value
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

// Set "Port" Direction
//u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

// Set "Port" Value
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
void DIO_voidSetPortValue(u8 PORT_OUTPUT_VAL);

// Get/Read "Pin" value
u8 DIO_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif
