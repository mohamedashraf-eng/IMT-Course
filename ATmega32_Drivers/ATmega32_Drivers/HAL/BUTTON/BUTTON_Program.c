/*
 * BUTTON_Program.c
 *
 *  Created on: Aug 17, 2022
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

#include "BUTTON_Private.h"
#include "BUTTON_Config.h"
#include "BUTTON_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void
BUTTON_voidButtonsInitalaization(void)
{
	int L_u8Counter;
	for(L_u8Counter = 0; (L_u8Counter < NUM_OF_BUTTONS); ++L_u8Counter)
	{
		DIO_voidSetPinDirection(myButtonConfig[L_u8Counter].PORT_ID,
								myButtonConfig[L_u8Counter].PIN_ID,
								INPUT);

		DIO_voidSetPinValue(myButtonConfig[L_u8Counter].PORT_ID,
							myButtonConfig[L_u8Counter].PIN_ID,
							myButtonConfig[L_u8Counter].BUTTON_STATE);
	}
}/** @end BUTTON_voidButtonsInitalaization */

void
BUTTON_voidButtonInitalaization(u8 Copy_cu8ButtonID)
{
	DIO_voidSetPinDirection(myButtonConfig[Copy_cu8ButtonID].PORT_ID,
							myButtonConfig[Copy_cu8ButtonID].PIN_ID,
							INPUT);

	DIO_voidSetPinValue(myButtonConfig[Copy_cu8ButtonID].PORT_ID,
						myButtonConfig[Copy_cu8ButtonID].PIN_ID,
						myButtonConfig[Copy_cu8ButtonID].BUTTON_STATE);
}/** @end BUTTON_voidButtonInitalaization */


u8
BUTTON_u8ButtonGetValue(u8 Copy_u8ButtonID)
{
	u8 L_u8ButtonValue = DIO_u8GetPinValue(myButtonConfig[Copy_u8ButtonID].PORT_ID,
									 	    myButtonConfig[Copy_u8ButtonID].PIN_ID);

#if   (INPUT_TYPE == EXTERNAL_PULLUP_RESISTOR)

	if( (L_u8ButtonValue == 0) )
	{
		L_u8ButtonValue = BUTTON_ON;
	}
	else
	{
		L_u8ButtonValue = BUTTON_OFF;
	}

#elif (INPUT_TYPE == EXTERNAL_PULLDOWN_RESISTOR)

	if( (L_u8ButtonValue == 1) )
	{
		L_u8ButtonValue = BUTTON_ON;
	}
	else
	{
		L_u8ButtonValue = BUTTON_OFF;
	}

#elif (INPUT_TYPE == NOTHING)

	if( (myButtonConfig[Copy_u8ButtonID].BUTTON_STATE == INTERNAL_PULLUP_RESISTOR) )
	{
		if( (L_u8ButtonValue == 0) )
		{
			L_u8ButtonValue = BUTTON_ON;
		}
		else
		{
			L_u8ButtonValue = BUTTON_OFF;
		}
	}
	else if( (myButtonConfig[Copy_u8ButtonID].BUTTON_STATE == INTERNAL_TRI_STATE) )
	{
		if( (L_u8ButtonValue == 1) )
		{
			L_u8ButtonValue = BUTTON_ON;
		}
		else
		{
			L_u8ButtonValue = BUTTON_OFF;
		}
	}
	else
	{
		/* return error code */
		return -1;
	}

#else
	#warning ("No Input type selected.")
#endif

	return L_u8ButtonValue;
}/** @end BUTTON_voidButtonGetValue */
