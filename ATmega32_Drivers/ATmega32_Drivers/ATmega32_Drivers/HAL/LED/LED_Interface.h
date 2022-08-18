/*
 * LED_Interface.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Wx
 */
/** @def Header Guards */
#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum LEDS_ID
{
	LED_1,
	LED_2,
	LED_3,
	LED_4,
	LED_5,
	LED_6,
	LED_7,
	LED_8,
};

enum LEDS_STATE
{
	LED_OFF,
	LED_ON
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
void LED_voidLedsInitalaization(void);

void LED_voidLedInitalaization(cu8 Copy_cu8LedID);

void LED_voidLedSetValue(cu8 Copy_cu8LedID, cu8 Copy_cu8LedValue);

#endif /* HAL_LED_LED_INTERFACE_H_ */
