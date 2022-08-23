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

#include "LCD_PrintingName/Printing_Interface.h"

#include "../HAL/LCD/LCD_Interface.h"

#include <avr/delay.h>

int  main(void)
{
	Printing_voidSystemInitialization();

	u8 L_MyNameArr[] = "MOHAMED";
	u8 ArrSize = sizeof(L_MyNameArr) / sizeof(L_MyNameArr[0]);

	while(True)
	{
		Printing_voidSystemUpdate();
	}

	return 0;
}




