/**
 * @file KEYPAD_Program.c
 * 
 * @author: Mohamed Wx
 * @date Aug 24, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "KEYPAD_Private.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"

#include <avr/delay.h>

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void KEYPAD_voidSystemInitialization(void)
{
	u8 L_u8Iterator;

	u8 Lu8TotalNumbersOfPins = NUM_OF_ROWS + NUM_OF_COLS;

	for(L_u8Iterator = 0; (L_u8Iterator <  Lu8TotalNumbersOfPins); ++L_u8Iterator)
	{
		DIO_voidSetPinDirection(MyKeyPadConfig[L_u8Iterator].PORT_ID,
								MyKeyPadConfig[L_u8Iterator].PIN_ID,
								MyKeyPadConfig[L_u8Iterator].PIN_Direction);

		DIO_voidSetPinValue(MyKeyPadConfig[L_u8Iterator].PORT_ID,
							MyKeyPadConfig[L_u8Iterator].PIN_ID,
							MyKeyPadConfig[L_u8Iterator].PIN_Value);
	}
}/** @end KEYPAD_voidSystemInitialization */


/**
 * @def algorithm used
 *
 * 1. Iterate through the columns.
 * 		1. Set the current column pin as "output_low".
 * 		2. Iterate through the rows.
 * 			1. Read each row pin value.
 *			2. If one is "Pressed".
 *				1. Set the "result_variable"
 *				2. Set a while loop till the release the key.
 *				3. set the pressed_flag raised.
 *				4. break.
 *		3. Set the column pin as "output_high"
 *		4. Check the pressed_flag.
 *		5. If flag is raised.
 *			1. break the columns loop.
 *		6. Else
 *			1. Keep iterating.
 *	2. return the key value.
 */
void KEYPAD_voidGetPressedKey(u8 *Address_u8PressedValue)
{
	/** @defgroup Variables declaration */
	u8 delay_after = 50;

	u8 volatile L_u8KeyValue 	= 0,
				L_u8ReturnValue = NO_KEY_PRESSED;

	u8 L_u8RowsIterator    = 0,
	   L_u8ColumnsIterator = 0;

	u8 L_u8FlagPressed = 0;

	/** @defgroup Algorithm */
	/* Iterate through columns */
	for((L_u8ColumnsIterator  = MyKeyPadConfig[KP_Column0_ID].PIN_ID);
		(L_u8ColumnsIterator <= MyKeyPadConfig[KP_LastColumn_ID].PIN_ID);
		(++L_u8ColumnsIterator))
	{
		/* Set the current column pin as output_low */
		DIO_voidSetPinValue(MyKeyPadConfig[L_u8ColumnsIterator].PORT_ID,
							MyKeyPadConfig[L_u8ColumnsIterator].PIN_ID,
							LOW);

		/* Iterate through rows */
		for((L_u8RowsIterator  = MyKeyPadConfig[KP_Row0_ID].PIN_ID);
			(L_u8RowsIterator <= MyKeyPadConfig[KP_LastRow_ID].PIN_ID);
			(++L_u8RowsIterator))
		{
			/* Get the current row value */
			L_u8KeyValue = DIO_u8GetPinValue(MyKeyPadConfig[L_u8RowsIterator].PORT_ID,
											 MyKeyPadConfig[L_u8RowsIterator].PIN_ID);
			/* Check if key is pressed */
			if( (L_u8KeyValue == Pressed) )
			{
				/* Set the return value */
				L_u8ReturnValue = G_Keys_LookUpTable[L_u8RowsIterator-MyKeyPadConfig[KP_Row0_ID].PIN_ID] \
													[L_u8ColumnsIterator-MyKeyPadConfig[KP_Column0_ID].PIN_ID];

				/* Raise the pressed flag */
				L_u8FlagPressed = 1;

				/* Loop to make sure that only get one value for the pressed key */
				//while( (L_u8KeyValue == Pressed) ) {;} /** @todo to be modifed */

				/* Delay to solve the bouncing problem */
				_delay_ms(delay_after);

				break;
			}
			else;
		}/* end for: rows */

		/* Set the current column pin as output_high */
		DIO_voidSetPinValue(MyKeyPadConfig[L_u8ColumnsIterator].PORT_ID,
							MyKeyPadConfig[L_u8ColumnsIterator].PIN_ID,
							HIGH);
		/* Check for the pressed flag */
		if( (L_u8FlagPressed == 1) )
		{
			break;
		}
		else;
	}/* end for: columns */

	/* Return the key value */
	(*Address_u8PressedValue) = L_u8ReturnValue;
}/** @end KEYPAD_voidGetPressedKey */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

