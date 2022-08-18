/*
 * BUTTON_Config.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Wx
 */
/** @def Header Guards */
#ifndef HAL_BUTTON_BUTTON_CONFIG_H_
#define HAL_BUTTON_BUTTON_CONFIG_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define NUM_OF_BUTTONS ( (cu8) (8) )

typedef struct
{
	cu8 PORT_ID;
	cu8 PIN_ID;
	cu8 BUTTON_STATE;
}ST_ButtonConfig_t;

/**
 * Available internal options for the state:
 *  1. INTERNAL_TRI_STATE
 *  2. INTERNAL_PULLUP_RESISTOR
 *
 * */
/** @note only add the internal options */
ST_ButtonConfig_t myButtonConfig[NUM_OF_BUTTONS] =
{
		{PORT_A, PIN_3, INTERNAL_PULLUP_RESISTOR},  /** @def button 1 */
		{PORT_A, PIN_4, INTERNAL_PULLUP_RESISTOR},  /** @def button 2 */
		{PORT_D, PIN_3, INTERNAL_PULLUP_RESISTOR},  /** @def button 3 */
		{PORT_D, PIN_4, INTERNAL_PULLUP_RESISTOR},  /** @def button 4 */
		{PORT_D, PIN_5, INTERNAL_PULLUP_RESISTOR},  /** @def button 5 */
		{PORT_D, PIN_6, INTERNAL_PULLUP_RESISTOR},  /** @def button 6 */
		{PORT_D, PIN_7, INTERNAL_PULLUP_RESISTOR},  /** @def button 7 */
		{PORT_D, PIN_8, INTERNAL_PULLUP_RESISTOR}   /** @def button 8 */
};

/**
 * Available external options for the state:
 *  1. EXTERNAL_PULLUP_RESISTOR
 *  2. EXTERNAL_PULLDOWN_RESISTOR
 *	3. NOTHING
 * */

#define INPUT_TYPE  ( NOTHING )

#endif /* HAL_BUTTON_BUTTON_CONFIG_H_ */
