/*
 * EXT_INT_Register.h
 *
 *  Created on: Oct 22, 2023
 *      Author: AHMED
 */

#ifndef MCAL_EXT_INT_EXT_INT_REGISTER_H_
#define MCAL_EXT_INT_EXT_INT_REGISTER_H_

// MCU Control Register Address
#define MCUCR 	*( (volatile u8 *) 0x55)

// MCU Control Registers PINs
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3


// MCU Control and Status Register Address
#define MCUCSR	*( (volatile u8 *) 0x54)

// MCU Control and Status Register PIN
#define MCUCSR_ISC2 	6


// General Interrupt Control Register Address
#define GICR	*( (volatile u8 *) 0x5B)

// General Interrupt Control Register PINs
#define GICR_INT0		6
#define GICR_INT1		7
#define GICR_INT2		5


// General Interrupt Flag Register Address
#define GIFR	*( (volatile u8 *) 0x5A)

// General Interrupt Flag Register PINs
#define GIFR_INTF0		6
#define GIFR_INTF1		7
#define GIFR_INTF2		5


#endif /* MCAL_EXT_INT_EXT_INT_REGISTER_H_ */
