/*
 * LED_Program.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Wx
 */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LED_Private.h"
#include "LED_Config.h"
#include "LED_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


cu8 G_cu8LedsArray[NUM_OF_LEDS] = {LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8};

void
LED_voidLedsInitalaization(void)
{
	u8 L_u8LedID;
	for(L_u8LedID = 0; (L_u8LedID < NUM_OF_LEDS); ++L_u8LedID)
	{
		DIO_voidSetPinDirection(myLedsConfig[L_u8LedID].PORT_ID,
								myLedsConfig[L_u8LedID].PIN_ID,
								OUTPUT);
	}
}/** @end LED_voidLedsInitalaization */

void
LED_voidLedInitalaization(cu8 Copy_cu8LedID)
{
	DIO_voidSetPinDirection(myLedsConfig[Copy_cu8LedID].PORT_ID,
							myLedsConfig[Copy_cu8LedID].PIN_ID,
							OUTPUT);

	DIO_voidSetPinValue(myLedsConfig[Copy_cu8LedID].PORT_ID,
						myLedsConfig[Copy_cu8LedID].PIN_ID,
						myLedsConfig[Copy_cu8LedID].INITAL_STATE);
}/** @end LED_voidLedInitalaization */

void
LED_voidLedSetValue(cu8 Copy_cu8LedID, cu8 Copy_cu8LedValue)
{
	DIO_voidSetPinValue(myLedsConfig[Copy_cu8LedID].PORT_ID,
						myLedsConfig[Copy_cu8LedID].PIN_ID,
						Copy_cu8LedValue);
}/** @end LED_voidLedSetValue */
