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

//#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/KEYPAD_Interface.h"
#include "../HAL/LED/LED_Interface.h"

#include "SimpleCalculator/Interface.h"

#include <avr/delay.h>

int  main(void)
{
	voidSystemInitilization();

	while(True)
	{
		voidSystemUpdate();
	}

	return 0;
}




