/*
 * BUTTON_Private.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Wx
 */
/** @def Header Guards */
#ifndef HAL_BUTTON_BUTTON_PRIVATE_H_
#define HAL_BUTTON_BUTTON_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum ATmega32_INPUT_CONFIG
{
	INTERNAL_TRI_STATE,
	INTERNAL_PULLUP_RESISTOR
};

#define EXTERNAL_PULLUP_RESISTOR	( 3 )
#define EXTERNAL_PULLDOWN_RESISTOR	( 4 )
#define NOTHING						( 5 )

#endif /* HAL_BUTTON_BUTTON_PRIVATE_H_ */
