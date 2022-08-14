/**
 * @File: assignment2.c
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

#include "assignment_2.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


/** @defgroup main functions */

/**
 * @brief function to initialize the system.
 *
 */
void SYS_INIT(void)
{
	/* Setting the mode for used ports */
	REG_SET(DDRA);
	REG_CLR(PORTA);  /* Init as low */

	BIT_CLR(DDRB, PB0);
	BIT_CLR(DDRB, PB1);
	BIT_CLR(DDRB, PB2);
	BIT_SET(PORTB, PB0);
	BIT_SET(PORTB, PB1);
	BIT_SET(PORTB, PB2);

}/** @end SYS_INIT*/

/**
 * @brief functino to control leds.
 *
 */
void LED_CTRL(cu8 LED, cu8 LED_STATE)
{
	switch(LED)
	{
		case LED1: LED_1(LED_STATE);
			break;

		case LED2: LED_2(LED_STATE);
			break;

		case LED3: LED_3(LED_STATE);
			break;

		case LED4: LED_4(LED_STATE);
			break;

		case LED5: LED_5(LED_STATE);
			break;

		case LED6: LED_6(LED_STATE);
			break;

		case LED7: LED_7(LED_STATE);
			break;

		case LED8: LED_8(LED_STATE);
			break;

		default: return;
	}//end switch.
}/** @end LED_CTRL */

/**
 * @brief function to switch between modes
 */
void MODE_CTRL(void)
{
	if( (SW_READ(SW1) == OPENED) && (SW_READ(SW2) == OPENED) && (SW_READ(SW3) == OPENED) )
	{
		/* Flashing every 500ms */
		MODE(MODE1);
	}
	else if( (SW_READ(SW1) == OPENED) && (SW_READ(SW2) == OPENED) && (SW_READ(SW3) == CLOSED) )
	{
		/* Shifting left every 250ms */
		MODE(MODE2);
	}
	else if( (SW_READ(SW1) == OPENED) && (SW_READ(SW2) == CLOSED) && (SW_READ(SW3) == OPENED) )
	{
		/* Shifting right every 250ms */
		MODE(MODE3);
	}
	else if( (SW_READ(SW1) == OPENED) && (SW_READ(SW2) == CLOSED) && (SW_READ(SW3) == CLOSED) )
	{
		/* 2-Leds Converging every 300ms */
		MODE(MODE4);
	}
	else if( (SW_READ(SW1) == CLOSED) && (SW_READ(SW2) == OPENED) && (SW_READ(SW3) == OPENED) )
	{
		/* 2-Leds Diverging every 300ms */
		MODE(MODE5);
	}
	else if( (SW_READ(SW1) == CLOSED) && (SW_READ(SW2) == OPENED) && (SW_READ(SW3) == CLOSED) )
	{
		/* Ping Pong effect every 250ms */
		MODE(MODE6);
	}
	else if( (SW_READ(SW1) == CLOSED) && (SW_READ(SW2) == CLOSED) && (SW_READ(SW3) == OPENED) )
	{
		/* Snake effect every 300ms */
		MODE(MODE7);
	}
	else if( (SW_READ(SW1) == CLOSED) && (SW_READ(SW2) == CLOSED) && (SW_READ(SW3) == CLOSED) )
	{
		/* 2-Leds Converging/Diverging every 300ms */
		MODE(MODE8);
	}
	else;
}/** @end MODE_CTRL */

/**
 * @brief function to read switches
 *
 */
cu8 SW_READ(cu8 SW)
{
	switch(SW)
	{
		case SW1: 	return BIT_GET(PINB, PB0);
			break;
		case SW2: 	return BIT_GET(PINB, PB1);
			break;
		case SW3: 	return BIT_GET(PINB, PB2);
			break;
		case SW4:	return BIT_GET(PINB, PB3);
			break;
		case SW5: 	return BIT_GET(PINB, PB4);
			break;
		case SW6: 	return BIT_GET(PINB, PB5);
			break;
		case SW7: 	return BIT_GET(PINB, PB6);
			break;
		case SW8: 	return BIT_GET(PINB, PB7);
			break;

		default: 	return -1;
	}//end switch.

	return -1;
}/** @end LED_CTRL */


/** @defgroup sub functions */
/**
 * @brief function to control led 1
 */
static void LED_1(cu8 STATE)
{
	switch(STATE)
	{
		case ON: BIT_SET(PORTA, PA0);
			break;

		case OFF: BIT_CLR(PORTA, PA0);
			break;

		default: return;
	}//end switch.
}/** @end LED1 */

/**
 * @brief function to control led 2
 */
static void LED_2(cu8 STATE)
{
	switch(STATE)
	{
		case ON: BIT_SET(PORTA, PA1);
			break;

		case OFF: BIT_CLR(PORTA, PA1);
			break;

		default: return;
	}//end switch.
}/** @end LED2 */

/**
 * @brief function to control led 3
 */
static void LED_3(cu8 STATE)
{
	switch(STATE)
	{
		case ON: BIT_SET(PORTA, PA2);
			break;

		case OFF: BIT_CLR(PORTA, PA2);
			break;

		default: return;
	}//end switch.
}/** @end LED3 */

/**
 * @brief function to control led 4
 */
static void LED_4(cu8 STATE)
{
	switch(STATE)
	{
		case ON: BIT_SET(PORTA, PA3);
			break;

		case OFF: BIT_CLR(PORTA, PA3);
			break;

		default: return;
	}//end switch.
}/** @end LED4 */
/**
 * @brief function to control led 5
 */
static void LED_5(cu8 STATE)
{
	switch(STATE)
	{
		case ON: BIT_SET(PORTA, PA4);
			break;

		case OFF: BIT_CLR(PORTA, PA4);
			break;

		default: return;
	}//end switch.
}/** @end LED5 */
/**
 * @brief function to control led 6
 */
static void LED_6(cu8 STATE)
{
	switch(STATE)
	{
		case ON: BIT_SET(PORTA, PA5);
			break;

		case OFF: BIT_CLR(PORTA, PA5);
			break;

		default: return;
	}//end switch.
}/** @end LED6 */
/**
 * @brief function to control led 7
 */
static void LED_7(cu8 STATE)
{
	switch(STATE)
	{
		case ON: BIT_SET(PORTA, PA6);
			break;

		case OFF: BIT_CLR(PORTA, PA6);
			break;

		default: return;
	}//end switch.
}/** @end LED7 */
/**
 * @brief function to control led 8
 */
static void LED_8(cu8 STATE)
{
	switch(STATE)
	{
		case ON: BIT_SET(PORTA, PA7);
			break;

		case OFF: BIT_CLR(PORTA, PA7);
			break;

		default: return;
	}//end switch.
}/** @end LED8 */

/**
 * @brief function to implement mode 1
 */
static void MODE_1(void)
{
	REG_SET(PORTA);
	_delay_ms(DELAY_IN_BETWEEN);
	REG_CLR(PORTA);
	_delay_ms(500);
}/** @end MODE_1 */
/**
 * @brief function to implement mode 2
 */
static void MODE_2(void)
{
	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED8, OFF);
	LED_CTRL(LED1, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED1, OFF);
	LED_CTRL(LED2, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED2, OFF);
	LED_CTRL(LED3, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED3, OFF);
	LED_CTRL(LED4, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED4, OFF);
	LED_CTRL(LED5, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED5, OFF);
	LED_CTRL(LED6, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED6, OFF);
	LED_CTRL(LED7, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED7, OFF);
	LED_CTRL(LED8, ON);

	_delay_ms(250);
}/** @end MODE_2 */
/**
 * @brief function to implement mode 3
 */
static void MODE_3(void)
{
	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED1, OFF);
	LED_CTRL(LED8, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED8, OFF);
	LED_CTRL(LED7, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED7, OFF);
	LED_CTRL(LED6, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED6, OFF);
	LED_CTRL(LED5, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED5, OFF);
	LED_CTRL(LED4, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED4, OFF);
	LED_CTRL(LED3, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED3, OFF);
	LED_CTRL(LED2, ON);

	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED2, OFF);
	LED_CTRL(LED1, ON);

	_delay_ms(250);
}/** @end MODE_3 */
/**
 * @brief function to implement mode 4
 */
static void MODE_4(void)
{
	LED_CTRL(LED1, ON);
	LED_CTRL(LED8, ON);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED1, OFF);
	LED_CTRL(LED8, OFF);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED2, ON);
	LED_CTRL(LED7, ON);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED2, OFF);
	LED_CTRL(LED7, OFF);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED3, ON);
	LED_CTRL(LED6, ON);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED3, OFF);
	LED_CTRL(LED6, OFF);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED4, ON);
	LED_CTRL(LED5, ON);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED4, OFF);
	LED_CTRL(LED5, OFF);

	_delay_ms(300);
}/** @end MODE_4 */
/**
 * @brief function to implement mode 5
 */
static void MODE_5(void)
{
	LED_CTRL(LED4, ON);
	LED_CTRL(LED5, ON);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED4, OFF);
	LED_CTRL(LED5, OFF);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED3, ON);
	LED_CTRL(LED6, ON);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED3, OFF);
	LED_CTRL(LED6, OFF);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED2, ON);
	LED_CTRL(LED7, ON);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED2, OFF);
	LED_CTRL(LED7, OFF);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED1, ON);
	LED_CTRL(LED8, ON);

	_delay_ms(DELAY_IN_BETWEEN);

	LED_CTRL(LED1, OFF);
	LED_CTRL(LED8, OFF);

	_delay_ms(300);
}/** @end MODE_5 */
/**
 * @brief function to implement mode 6
 */
static void MODE_6(void)
{
	MODE_2();
	_delay_ms(DELAY_IN_BETWEEN);
	MODE_3();

	_delay_ms(250);

}/** @end MODE_6 */
/**
 * @brief function to implement mode 7
 */
static void MODE_7(void)
{
	LED_CTRL(LED1, ON);
	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED2, ON);
	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED3, ON);
	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED4, ON);
	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED5, ON);
	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED6, ON);
	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED7, ON);
	_delay_ms(DELAY_IN_BETWEEN);
	LED_CTRL(LED8, ON);
	_delay_ms(DELAY_IN_BETWEEN);

	REG_CLR(PORTA);

	_delay_ms(300);
}/** @end MODE_7 */
/**
 * @brief function to implement mode 8
 */
static void MODE_8(void)
{
	MODE_4();
	_delay_ms(DELAY_IN_BETWEEN);
	MODE_5();

	_delay_ms(300);
}/** @end MODE_8 */

/**
 * @brief functino to select between modes
 */
void MODE(cu8 MODE_SELECT)
{
	switch(MODE_SELECT)
	{
		case MODE1: MODE_1();
			break;
		case MODE2: MODE_2();
			break;
		case MODE3: MODE_3();
			break;
		case MODE4: MODE_4();
			break;
		case MODE5: MODE_5();
			break;
		case MODE6: MODE_6();
			break;
		case MODE7: MODE_7();
			break;
		case MODE8: MODE_8();
			break;
		default: return;
	}
}/** @end MODE */




