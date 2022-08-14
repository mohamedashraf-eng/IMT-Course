/**
 * @File: main.c
 * @Author: Mohamed Wx
 * @Date: 12/8/2022
 * @brief: the main entry point.
 *
 */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	HEADERS INCLUDED															-
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

//#include "assignment_2.h"

#include <avr/io.h>
#include "LIB/BIT_MATH.h"

/**
 * @brief main entry point.
 * @return int.
 */
int main(void)
{
	//SYS_INIT();

	REG_SET(DDRA);
	REG_CLR(PORTA);

	BIT_SET(PORTB, PB0);
	BIT_SET(PORTB, PB1);
	BIT_SET(PORTB, PB2);

	while(1)
	{
		//MODE_CTRL();
		if( (BIT_GET(PINB, PB1) == 0) )
		{
			BIT_SET(PORTA, PA0);
			BIT_SET(PORTA, PA1);
		}
		else;

	}

	return 0;
}
