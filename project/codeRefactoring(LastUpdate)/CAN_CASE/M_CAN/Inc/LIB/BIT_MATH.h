/*
 * utils.h
 *
 *  Created on: Nov 27, 2023
 *      Author: Ahmed
 */


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define  READ_BIT(reg,bit)       ((reg>>bit)&1)     //(reg &(1<<bit))
#define  SET_BIT(reg,bit)        (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit)        (reg=reg&~(1<<bit))
#define  TOGGLE_BIT(reg,bit)     (reg=reg^(1<<bit))
#define  GET_BIT(reg,bit)       ((reg>>bit)&1)

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))

#define _PORT_MODE   1
#define _PIN_MODE    0


#define Set_Bit(Reg,Bit)     		(Reg |= (1 << Bit))
#define Clear_Bit(Reg,Bit)   		(Reg &= ~(1 << Bit))
#define Toggle_Bit(Reg,Bit)  		(Reg ^= (1 << Bit))
#define Get_Bit(Reg,Bit)     		((Reg >> Bit) & (0x01))


#define CONC(B7,B6,B5,B4,B3,B2,B1,B0)			    CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)		0b##B7##B6##B5##B4##B3##B2##B1##B0


/* _4_BIT OR _8_BIT*/

#define  GPIO_MODE   _PINT_MODE

#endif /* UTILS_H_ */
