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

#include "SSD_Counter/Counter_Interface.h"

#include "../HAL/SSD/SSD_Interface.h"

#include <avr/delay.h>

int  main(void)
{
	Counter_voidSystemInitalaization();

	u8 L_u8Limit = 99;
	u8 L_u8Counter = 0;

	while(True)
	{
		Counter_voidUpdate(L_u8Counter, L_u8Limit);

		++L_u8Counter;

		if( (L_u8Counter >= L_u8Limit) )
		{
			_delay_ms(100); /** @note give the chance to see */
			L_u8Counter = 0;
		}
		else;

	}

	return 0;
}




