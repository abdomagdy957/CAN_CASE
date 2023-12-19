#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

#define KPD_PORT    	DIO_u8PORTC

#define KPD_COLM_PIN0	DIO_u8PIN_7
#define KPD_COLM_PIN1	DIO_u8PIN_6
#define KPD_COLM_PIN2	DIO_u8PIN_5
#define KPD_COLM_PIN3	DIO_u8PIN_4

#define KPD_ROW_PIN0 	DIO_u8PIN_3
#define KPD_ROW_PIN1 	DIO_u8PIN_2
#define KPD_ROW_PIN2 	DIO_u8PIN_1
#define KPD_ROW_PIN3 	DIO_u8PIN_0

#define KPD_NO_PRESSED_KEY  0xFF

#define KPD_ARR_VAL    { { 7 , 8 , 9, '/' },{ 4 , 5 , 6, '*' },{ 1 , 2 , 3, '-' },{ 'C' , 0 , '=', '+' }}


#endif
