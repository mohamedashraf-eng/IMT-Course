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

int  main(void)
{
	Printing_voidSystemInitialization();

	while(True)
	{
		//Printing_voidSystemUpdate1();
		Printing_voidSystemUpdate2();
	}

	return 0;
}




