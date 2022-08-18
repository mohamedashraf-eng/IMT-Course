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
 * -	GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

cu8 G_cu8LedsArray[NUM_OF_LEDS] = {LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION -- PUBLIC
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void LED_voidLedsInitalaization(void)
{
	u8 L_u8LedID;
	for(L_u8LedID = 0; (L_u8LedID < NUM_OF_LEDS); ++L_u8LedID)
	{
		LED_SetLedPinDirection(L_u8LedID);
	}
}/** @end LED_voidLedsInitalaization */

void LED_voidLedInitalaization(cu8 Copy_cu8LedID)
{
	LED_SetLedPinDirection(Copy_cu8LedID);
	LED_SetLedPinValue(Copy_cu8LedID);
}/** @end LED_voidLedInitalaization */

void LED_voidLedSetValue(cu8 Copy_cu8LedID, cu8 Copy_cu8LedValue)
{
	LED_SetLedPinValue(Copy_cu8LedID);
}/** @end LED_voidLedSetValue */


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION -- PRIVATE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
static void LED_SetLedPinDirection(u8 Copy_u8LedPinID)
{
	DIO_voidSetPinDirection(myLedsConfig[Copy_u8LedPinID].PORT_ID,
							myLedsConfig[Copy_u8LedPinID].PIN_ID,
							OUTPUT);
}/** @end LED_SetLedPinDirection */

static void LED_SetLedPinValue(u8 Copy_u8LedPinID)
{
	DIO_voidSetPinValue(myLedsConfig[Copy_u8LedPinID].PORT_ID,
						myLedsConfig[Copy_u8LedPinID].PIN_ID,
						myLedsConfig[Copy_u8LedPinID].INITAL_STATE);
}/** @end LED_SetLedPinValue */





