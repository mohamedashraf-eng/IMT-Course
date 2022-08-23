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
	BUTTON_voidButtonInitalaization(BUTTON_1);
	BUTTON_voidButtonInitalaization(BUTTON_2);
}/** @end Printing_voidSystemInitialization */

void Printing_voidSystemUpdate(void)
{
	u8 delay = 20;

	u8 i = 0;

	u8 L_u8MyNameArr[] = "MOHAMEDASHRAFFAT";
	//u8 Lu8ArrSize = sizeof(L_u8MyNameArr) / sizeof(L_u8MyNameArr[0]);

	u8 x = 0, y = 1;

	for(i = 0; i < 15; i++)
	{
		LCD_voidGoToRowColumn(Row0_ID, x);
		LCD_voidDisplayCharacter(L_u8MyNameArr[i]);

		_delay_ms(delay);

		LCD_voidGoToRowColumn(Row1_ID, y);
		LCD_voidDisplayCharacter(L_u8MyNameArr[i+1]);

		_delay_ms(delay);

		LCD_voidClearScreen();

		x += 1;
		y += 1;

		//Printing_voidSwapCharacters(&L_u8MyNameArr[i], &L_u8MyNameArr[i+1]);
	}
}/** @end Printing_voidSystemUpdate */

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

