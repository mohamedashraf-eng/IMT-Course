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

#include "../HAL/LED/LED_Interface.h"
#include "../HAL/BUTTON/BUTTON_Interface.h"
#include "../HAL/SSD/SSD_Interface.h"

#include "../MCAL/DIO/DIO_Interface.h"

#include <avr/delay.h>

#define time 35
int  main(void)
{

	SSD_voidSsdInitalization(SSD_1);
	SSD_voidSsdTurnOn(SSD_1);

	SSD_voidSsdSetPin(SSD_1, PIN_E);


	while(True)
	{
		SSD_voidSsdTurnOn(SSD_1);

		SSD_voidSsdSetPin(SSD_1, PIN_A);
		_delay_ms(time);
		SSD_voidSsdSetPin(SSD_1, PIN_B);
		_delay_ms(time);
		SSD_voidSsdSetPin(SSD_1, PIN_C);
		_delay_ms(time);
		SSD_voidSsdSetPin(SSD_1, PIN_D);
		_delay_ms(time);
		SSD_voidSsdSetPin(SSD_1, PIN_E);
		_delay_ms(time);
		SSD_voidSsdSetPin(SSD_1, PIN_F);
		_delay_ms(time);

		SSD_voidSsdTurnOff(SSD_1);
		_delay_ms(500);
	}

	return 0;
}
