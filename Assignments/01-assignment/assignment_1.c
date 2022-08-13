/**
 * @File: assignment_1.c
 * @Author: Mohamed Wx
 * @Date: 12/8/2022
 * @brief: assignment 1 functions prototype.
 *
 */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "assignment_1.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @def global look-up table that contain all the binary code for SSD digits */
cu8 SSD_DIGIT_CODE[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																FUNCTION IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
/**
 * @brief function to initialize all the requirements.
 *
 */
void SYS_INIT(void)
{
	/** @defgroup setting SSD PORTx */
	/** @def could be changed to any port */
	REG_SET(DDRA); /* Set All PORTA pins to be output */
	REG_CLR(PORTA); /* Set all PORTA pins to be low */

	BIT_CLR(DDRA, PA7);
	BIT_SET(PORTA, PA7);

	/** @defgroup setting TL PORTx */
	/** @def set pins as output and low */
	REG_SET(DDRD); /* Set All PORTD pins to be output */
	REG_CLR(PORTD); /* Set all PORTD pins to be low */

	BIT_CLR(DDRD, PD7);
	BIT_SET(PORTD, PD7);
}/** @end SYS_INIT */

/**
 * @brief function implementation for seven segment display system.
 *
 */
void SYS_SSD(cu8 select, cu8 last, cu8 delay)
{
	switch(select)
	{
		case SSD1:
					BIT_CLR(PORTD, PD4);
					BIT_SET(PORTD, PD3);
					SSD_1(last, delay*SECOND, DECREASING);
			break;

		case SSD2:
					BIT_CLR(PORTD, PD3);
					BIT_SET(PORTD, PD4);
					SSD_2(last, delay*SECOND, DECREASING);
			break;

		default: return;
	}//end switch.
}/** @end SYS_SSD */

/**
 * @brief function to generic control available leds.
 */
void LED_CTRL(cu8 LED, cu8 LED_STATE)
{
	switch(LED)
	{
		case RED: LED_RED(LED_STATE);
			break;

		case YELLOW: LED_YELLOW(LED_STATE);
			break;

		case GREEN: LED_GREEN(LED_STATE);
			break;

		default: return;
	}//end switch.
}/** @end LED_CTRL */

/** @defgroup sub functions */

/**
 * @brief function to turn on the green led.
 */
static void LED_GREEN(cu8 mode)
{
	switch(mode)
	{
		case OFF: BIT_CLR(PORTD, PD2);
			break;
		case ON: BIT_SET(PORTD, PD2);
			break;
		default: return;
	}//end switch.
}/**@end LED_GREEN */


/**
 * @brief function to turn on the yellow led.
 */
static void LED_YELLOW(cu8 mode)
{
	switch(mode)
	{
		case OFF: BIT_CLR(PORTD, PD1);
			break;
		case ON: BIT_SET(PORTD, PD1);
			break;
		default: return;
	}//end switch.
}/**@end LED_YELLOW */

/**
 * @brief function to turn on the red led.
 */
static void LED_RED(cu8 mode)
{
	switch(mode)
	{
		case OFF: BIT_CLR(PORTD, PD0);
			break;
		case ON: BIT_SET(PORTD, PD0);
			break;
		default: return;
	}//end switch.
}/**@end LED_RED */


/**
 * @brief function to control seven segment 1
 */
static void SSD_1(cu8 last, cu16 delay, cu8 mode)
{
	u8 i;

	switch(mode)
	{
		case INCREASING:
			for(i = 1; (i <= last); i++)
			{
				REG_WRT(PORTA, ~SSD_DIGIT_CODE[i]);
				_delay_ms(delay);
			}//end for.
			break;
		case DECREASING:
			for(i = last; (i >= 1); i--)
			{
				REG_WRT(PORTA, ~SSD_DIGIT_CODE[i]);
				_delay_ms(delay);
			}//end for.
			break;
		default: return;
	}//end switch.
}/** @end SSD_1 */

/**
 * @brief function to control seven segment 2
 */
static void SSD_2(cu8 last, cu16 delay, cu8 mode)
{

	u8 i;
	switch(mode)
	{
		case INCREASING:
			for(i = 1; (i <= last); i++)
			{
				REG_WRT(PORTA, ~SSD_DIGIT_CODE[i]);
				_delay_ms(delay);
			}//end for.
			break;
		case DECREASING:
			for(i = last; (i >= 1); i--)
			{
				REG_WRT(PORTA, ~SSD_DIGIT_CODE[i]);
				_delay_ms(delay);
			}//end for.
			break;
		default: return;
	}//end switch.
}/** @end SSD_1 */





