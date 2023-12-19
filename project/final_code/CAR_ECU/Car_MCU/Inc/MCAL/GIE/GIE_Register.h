/*
 * GIE_Register.h
 *
 *  Created on: Oct 22, 2023
 *      Author: AHMED
 */

#ifndef MCAL_GIE_GIE_REGISTER_H_
#define MCAL_GIE_GIE_REGISTER_H_

#define SREG *( (volatile u8 *) 0x5F )

// Global Interrupt Enable
#define SREG_I		7

// Other
#define SREG_T		6
#define SREG_H		5
#define SREG_S		4
#define SREG_V		3
#define SREG_N		2
#define SREG_Z		1
#define SREG_C		0


#endif /* MCAL_GIE_GIE_REGISTER_H_ */
