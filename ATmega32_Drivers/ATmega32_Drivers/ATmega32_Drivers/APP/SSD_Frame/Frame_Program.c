/*
 * main.c
 *
 *  Created on: Aug 18, 2022
 *      Author: Wx
 */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include <avr/delay.h>

#include "../../HAL/BUTTON/BUTTON_Interface.h"
#include "../../HAL/SSD/SSD_Interface.h"

#include "Frame_Private.h"
#include "Frame_Interface.h"


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

cu8 delay_time = 35;
cu8 switch_delay = 25;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION -- PUBLIC
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void Frame_voidSystemInitalaization(void)
{
	SSD_voidSsdInitalization(SSD_1);
	SSD_voidSsdInitalization(SSD_2);
	BUTTON_voidButtonInitalaization(BUTTON_1);
}/** @end Frame_voidSystemInitalaization */

void Frame_voidSetFrameDirection(u8 Copy_u8FrameDirection)
{
	switch(Copy_u8FrameDirection)
	{
		case Clockwise:	Frame_voidFrameClockwise();			break;
		case AntiClockwise:	Frame_voidFrameAntiClockwise();	break;
		default: return;
	}
}/** @end Frame_voidSetFrameDirection */

void Frame_voidUpdate(void)
{
	if( (BUTTON_u8ButtonGetValue(BUTTON_1) == BUTTON_ON) )
	{
		Frame_voidSetFrameDirection(Clockwise);
	}
	else
	{
		Frame_voidSetFrameDirection(AntiClockwise);
	}
}/** @end Frame_voidUpdate */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION -- Private
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void Frame_voidFrameClockwise(void)
{
	SSD_voidSsdTurnOff(SSD_2);
	_delay_ms(switch_delay);
	SSD_voidSsdTurnOn(SSD_1);

	SSD_voidSsdSetPin(SSD_1, PIN_D);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_1, PIN_E);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_1, PIN_F);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_1, PIN_A);
	_delay_ms(delay_time);

	SSD_voidSsdTurnOff(SSD_1);
	_delay_ms(switch_delay);
	SSD_voidSsdTurnOn(SSD_2);

	SSD_voidSsdSetPin(SSD_2, PIN_A);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_2, PIN_B);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_2, PIN_C);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_2, PIN_D);
	_delay_ms(delay_time);
}/** @end Frame_voidFrameClockwise */

static void Frame_voidFrameAntiClockwise(void)
{
	SSD_voidSsdTurnOff(SSD_2);
	_delay_ms(switch_delay);
	SSD_voidSsdTurnOn(SSD_1);

	SSD_voidSsdSetPin(SSD_1, PIN_A);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_1, PIN_F);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_1, PIN_E);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_1, PIN_D);
	_delay_ms(delay_time);

	SSD_voidSsdTurnOff(SSD_1);
	_delay_ms(switch_delay);
	SSD_voidSsdTurnOn(SSD_2);

	SSD_voidSsdSetPin(SSD_2, PIN_D);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_2, PIN_C);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_2, PIN_B);
	_delay_ms(delay_time);
	SSD_voidSsdSetPin(SSD_2, PIN_A);
	_delay_ms(delay_time);
}/** @end Frame_voidFrameAntiClockwise */
