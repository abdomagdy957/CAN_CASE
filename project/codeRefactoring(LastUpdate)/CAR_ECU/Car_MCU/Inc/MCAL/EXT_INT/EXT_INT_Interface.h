/*
 * EXT_INT_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: AHMED
 */

#ifndef MCAL_EXT_INT_EXT_INT_INTERFACE_H_
#define MCAL_EXT_INT_EXT_INT_INTERFACE_H_

// Interrupt ID
#define INT_0	1
#define INT_1	2
#define INT_2	3


//init the INT with sensing mood in preprocessing stage
void EXTI0_voidInit(void);

//enable EXTI
void EXTI0_voidEnable(void);

//disable EXTI
void EXTI0_voidDisable(void);

//change the INT with sensing mood in runtime
void EXT0_voidSetSignalch(u8 SenseCpy);


// INTERRUPT 1
void EXTI1_voidInit(void);

//enable EXTI
void EXTI1_voidEnable(void);

//disable EXTI
void EXTI1_voidDisable(void);

//change the INT with sensing mood in runtime
void EXT1_voidSetSignalch(u8 SenseCpy);


// INTERRUPT 1
void EXTI2_voidInit(void);

//enable EXTI
void EXTI2_voidEnable(void);

//disable EXTI
void EXTI2_voidDisable(void);

//change the INT with sensing mood in runtime
void EXT2_voidSetSignalch(u8 SenseCpy);


//callback function
void EXT0_VID_SET_CALL_BACK(void (*PTR)(void));
void EXT1_VID_SET_CALL_BACK(void (*PTR)(void));
void EXT2_VID_SET_CALL_BACK(void (*PTR)(void));



#endif /* MCAL_EXT_INT_EXT_INT_INTERFACE_H_ */
