/**
 * @file Printing_Program.c
 * 
 * @author: Mohamed Wx
 * @date Aug 23, 2022
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
#include <avr/delay.h>

#include "../../HAL/BUTTON/BUTTON_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"

#include "Printing_Private.h"
#include "Printing_Interface.h"


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION -- PUBLIC
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void Printing_voidSystemInitialization(void)
{
	/** @def initalize system */
	LCD_voidSystemInitalaization(LCD_EightBitMode);
}/** @end Printing_voidSystemInitialization */

void Printing_voidSystemUpdate1(void)
{
	u8 delay = 10;

	u8 L_u8MyNameArr[] = "MOHAMEDASHRAFFATHY";
	u8 L_u8ArrSize = sizeof(L_u8MyNameArr) / sizeof(L_u8MyNameArr[0]);

	u8 row = 0;

	for(u8 i = 0; i < L_u8ArrSize; ++i)
	{
		LCD_voidGoToRowColumn(row, i);
		LCD_voidDisplayCharacter(L_u8MyNameArr[i]);

		row ^= 1;

		_delay_ms(delay);
	}

	LCD_voidClearScreen();
}/** @end Printing_voidSystemUpdate */

void Printing_voidSystemUpdate2(void)
{
	u8 delay = 50;

	u8 L_u8MyNameArr[] = "MOHAMED";

	u8 row = 0;

	for(u8 i = 0; i < 15; ++i)
	{
		LCD_voidGoToRowColumn(row, i);
		LCD_voidDisplayString(L_u8MyNameArr);

		row ^= 1;

		_delay_ms(delay);

		LCD_voidClearScreen();
	}
}/** @end Printing_voidSystemUpdate2 */


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION -- PRIVATE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void Printing_voidSwapCharacters(u8 *Address_u8Character1, u8 *Address_u8Character2)
{
	u8 temp = *Address_u8Character1;
	*Address_u8Character1 = *Address_u8Character2;
	*Address_u8Character2 = temp;
}/** @end Printing_voidSwapCharacters */

