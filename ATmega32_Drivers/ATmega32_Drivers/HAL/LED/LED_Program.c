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

void LED_voidLedsInitalaization(void)
{
	u8 Led_ID;
	for(Led_ID = 0; (Led_ID < NUM_OF_LEDS); ++Led_ID)
	{
		DIO_voidSetPinDirection(myLedsConfig[Led_ID].PORT_ID,
								myLedsConfig[Led_ID].PIN_ID,
								OUTPUT);
	}
}

void LED_voidLedInitalaization(cu8 Copy_cu8LedID)
{
	DIO_voidSetPinDirection(myLedsConfig[Copy_cu8LedID].PORT_ID,
							myLedsConfig[Copy_cu8LedID].PIN_ID,
							OUTPUT);

	DIO_voidSetPinValue(myLedsConfig[Copy_cu8LedID].PORT_ID,
						myLedsConfig[Copy_cu8LedID].PIN_ID,
						myLedsConfig[Copy_cu8LedID].INITAL_STATE);
}/** @end LED_voidLedInitalaization */

void LED_voidLedSetValue(cu8 Copy_cu8LedID, cu8 Copy_cu8LedValue)
{
	DIO_voidSetPinValue(myLedsConfig[Copy_cu8LedID].PORT_ID,
						myLedsConfig[Copy_cu8LedID].PIN_ID,
						Copy_cu8LedValue);
}/** @end LED_voidLedSetValue */
