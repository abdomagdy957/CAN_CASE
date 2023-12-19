#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*
 *	0 for INPUT
 * 	1 for OUTPUT
 */

/*
    - For PORTA Select DIO_u8PORTA
    - For PORTB Select DIO_u8PORTB
    - For PORTC Select DIO_u8PORTC
    - For PORTD Select DIO_u8PORTD

 */

// Select PORT
#define SELECTED_PORT   DIO_u8PORTA

/*
    - For PIN0 Select 	DIO_u8PIN_0
    - For PIN1 Select 	DIO_u8PIN_1
    - For PIN2 Select 	DIO_u8PIN_2

 */


// Select PIN
#define SELECTED_PIN    DIO_u8PIN_1

// Set PIN_Value
#define PIN_OUTPUT_VAL     PIN_HIGH

#define STATE_INPUT		0
#define STATE_OUTPUT	1


// PORT A Direction
#define PORTA_PIN0_DIR          STATE_INPUT
#define PORTA_PIN1_DIR          STATE_OUTPUT
#define PORTA_PIN2_DIR          STATE_OUTPUT
#define PORTA_PIN3_DIR          STATE_OUTPUT
#define PORTA_PIN4_DIR          STATE_OUTPUT
#define PORTA_PIN5_DIR          STATE_OUTPUT
#define PORTA_PIN6_DIR          STATE_OUTPUT
#define PORTA_PIN7_DIR          STATE_OUTPUT

// PORT B Direction
#define PORTB_PIN0_DIR         	STATE_OUTPUT
#define PORTB_PIN1_DIR         	STATE_OUTPUT
#define PORTB_PIN2_DIR         	STATE_OUTPUT
#define PORTB_PIN3_DIR         	STATE_OUTPUT
#define PORTB_PIN4_DIR         	STATE_INPUT
#define PORTB_PIN5_DIR         	STATE_INPUT
#define PORTB_PIN6_DIR          STATE_OUTPUT
#define PORTB_PIN7_DIR          STATE_INPUT

// PORT C Direction
#define PORTC_PIN0_DIR          STATE_OUTPUT
#define PORTC_PIN1_DIR          STATE_OUTPUT
#define PORTC_PIN2_DIR          STATE_OUTPUT
#define PORTC_PIN3_DIR          STATE_OUTPUT
#define PORTC_PIN4_DIR          STATE_OUTPUT
#define PORTC_PIN5_DIR          STATE_OUTPUT
#define PORTC_PIN6_DIR          STATE_OUTPUT
#define PORTC_PIN7_DIR          STATE_OUTPUT

// PORT D Direction
#define PORTD_PIN0_DIR          STATE_INPUT
#define PORTD_PIN1_DIR          STATE_OUTPUT
#define PORTD_PIN2_DIR          STATE_OUTPUT
#define PORTD_PIN3_DIR          STATE_OUTPUT
#define PORTD_PIN4_DIR          STATE_OUTPUT
#define PORTD_PIN5_DIR          STATE_OUTPUT
#define PORTD_PIN6_DIR          STATE_OUTPUT
#define PORTD_PIN7_DIR          STATE_OUTPUT


/*
    0 For floating if input, Low if output
    1 For pulledup if input, High if output 
 */

// PORT A PINS Initial Values
#define PORTA_PIN0_INTIAL_VALUE     0
#define PORTA_PIN1_INTIAL_VALUE     0
#define PORTA_PIN2_INTIAL_VALUE     0
#define PORTA_PIN3_INTIAL_VALUE     0
#define PORTA_PIN4_INTIAL_VALUE     0
#define PORTA_PIN5_INTIAL_VALUE     0
#define PORTA_PIN6_INTIAL_VALUE     0
#define PORTA_PIN7_INTIAL_VALUE     0

// PORT B PINS Initial Values
#define PORTB_PIN0_INTIAL_VALUE     0
#define PORTB_PIN1_INTIAL_VALUE     0
#define PORTB_PIN2_INTIAL_VALUE     0
#define PORTB_PIN3_INTIAL_VALUE     0
#define PORTB_PIN4_INTIAL_VALUE     0
#define PORTB_PIN5_INTIAL_VALUE     1
#define PORTB_PIN6_INTIAL_VALUE     0
#define PORTB_PIN7_INTIAL_VALUE     1

// PORT C PINS Initial Values
#define PORTC_PIN0_INTIAL_VALUE     0
#define PORTC_PIN1_INTIAL_VALUE     0
#define PORTC_PIN2_INTIAL_VALUE     0
#define PORTC_PIN3_INTIAL_VALUE     0
#define PORTC_PIN4_INTIAL_VALUE     0
#define PORTC_PIN5_INTIAL_VALUE     0
#define PORTC_PIN6_INTIAL_VALUE     0
#define PORTC_PIN7_INTIAL_VALUE     0

// PORT D PINS Initial Values
#define PORTD_PIN0_INTIAL_VALUE     0
#define PORTD_PIN1_INTIAL_VALUE     0
#define PORTD_PIN2_INTIAL_VALUE     0
#define PORTD_PIN3_INTIAL_VALUE     0
#define PORTD_PIN4_INTIAL_VALUE     0
#define PORTD_PIN5_INTIAL_VALUE     0
#define PORTD_PIN6_INTIAL_VALUE     0
#define PORTD_PIN7_INTIAL_VALUE     0




#endif
