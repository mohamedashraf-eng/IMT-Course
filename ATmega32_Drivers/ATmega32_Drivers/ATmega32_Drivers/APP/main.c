/**
 * @file main.c
 * @brief the main application entry point.
 * @author Mohamed Wx
 * @date 15/08/2022
 *
 */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"

#include "../MCAL/DIO/DIO_Interface.h"

#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/KEYPAD_Interface.h"

#include <avr/delay.h>

int  main(void)
{
	LCD_voidSystemInitalaization(LCD_EightBitMode);
	KEYPAD_voidSystemInitialization();

	u8 Value = 0;

	while(True)
	{
		KEYPAD_voidGetPressedKey(&Value);

		if( (Value != NO_KEY_PRESSED) )
		{
			LCD_voidDisplayCharacter('W');
		}
		else
		{
			;
		}
	}

	return 0;
}




