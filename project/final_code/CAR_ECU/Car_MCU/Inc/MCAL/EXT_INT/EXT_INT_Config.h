/*
 * EXT_INT_Config.h
 *
 *  Created on: Oct 22, 2023
 *      Author: AHMED
 */

#ifndef MCAL_EXT_INT_EXT_INT_CONFIG_H_
#define MCAL_EXT_INT_EXT_INT_CONFIG_H_

#define SELECT_INT_ID				INT_0

/*
 * Please Copy Past one of the following for INT0
 * FALLING_EADGE
 * RISING_EADGE
 * LOW_LEVEL
 * HIGH_LEVEL
*/
#define SELECT_INT0_SENSE_CONTROL 	FALLING_EADGE

/*
 * Please Copy Past one of the following for INT1
 * FALLING_EADGE
 * RISING_EADGE
 * LOW_LEVEL
 * HIGH_LEVEL
*/
#define SELECT_INT1_SENSE_CONTROL 	FALLING_EADGE

/*
 * Please Copy Past one of the following
 * FALLING_EADGE
 * RISING_EADGE
 * LOW_LEVEL
 * HIGH_LEVEL
*/
#define SELECT_INT2_SENSE_CONTROL 	FALLING_EADGE

#endif /* MCAL_EXT_INT_EXT_INT_CONFIG_H_ */
