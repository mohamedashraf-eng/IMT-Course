/*
 * Counter_Program.c
 *
 *  Created on: Aug 18, 2022
 *      Author: Wx
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include <avr/delay.h>

#include "../../HAL/SSD/SSD_Interface.h"
#include "Counter_Private.h"
#include "Counter_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


cu8 delay_between = 30;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION -- PUBLIC
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void Counter_voidSystemInitalaization(void)
{
	SSD_voidSsdInitalization(SSD_1);
	SSD_voidSsdInitalization(SSD_2);

}/** @end Counter_voidSystemInitalaization */

void Counter_voidUpdate(u8 Copy_u8Counter, u8 Copy_u8LimitNumber)
{
	u8 L_u8Digit1 = 0,
	   L_u8Digit2 = 0;

	L_u8Digit1 = (Copy_u8Counter % 10);
	L_u8Digit2 = (Copy_u8Counter / 10);

	SSD_voidSsdTurnOff(SSD_2);
	SSD_voidSsdTurnOn(SSD_1);

	SSD_voidSsdSetNumber(SSD_1, L_u8Digit2);
	_delay_ms(delay_between);

	SSD_voidSsdTurnOff(SSD_1);
	SSD_voidSsdTurnOn(SSD_2);

	SSD_voidSsdSetNumber(SSD_2, L_u8Digit1);
	_delay_ms(delay_between);

}/** @end Counter_voidUpdate */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION -- Private
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
