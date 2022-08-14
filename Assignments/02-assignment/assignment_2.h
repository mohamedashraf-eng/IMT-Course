/**
 * @File: assignment2.h
 * @Author: Mohamed Wx
 * @Date: 12/8/2022
 * @brief: header for assignment 2 task.
 *
 */

#ifndef ASSIGNMENT_2_H_
#define ASSIGNMENT_2_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include "LIB/bit_math.h"
#include "LIB/std_types.h"
#include "LIB/std_libs.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	 GLOBAL
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define DELAY_IN_BETWEEN ((cu8) 50)

typedef enum LEDS
{
	LED1,
	LED2,
	LED3,
	LED4,
	LED5,
	LED6,
	LED7,
	LED8
}LEDS_et;

typedef enum LED_STATE
{
	OFF,
	ON
}LED_STATE_et;

typedef enum SWITCH
{
	SW1,
	SW2,
	SW3,
	SW4,
	SW5,
	SW6,
	SW7,
	SW8
}SWITCH_et;

typedef enum SWITCH_STATE
{
	CLOSED,
	OPENED
}SW_STATE_et;

typedef enum MODES
{
	MODE1,
	MODE2,
	MODE3,
	MODE4,
	MODE5,
	MODE6,
	MODE7,
	MODE8
}MODES_et;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -														 	 FUNCTIONS PROTOTYPE															-
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
void SYS_INIT(void);
void MODE_CTRL(void);
void LED_CTRL(cu8 , cu8);

/** @defgroup sub functions */
static void LED_1(cu8);
static void LED_2(cu8);
static void LED_3(cu8);
static void LED_4(cu8);
static void LED_5(cu8);
static void LED_6(cu8);
static void LED_7(cu8);
static void LED_8(cu8);
cu8 SW_READ(cu8);

void MODE(cu8);
static void MODE_1(void);
static void MODE_2(void);
static void MODE_3(void);
static void MODE_4(void);
static void MODE_5(void);
static void MODE_6(void);
static void MODE_7(void);
static void MODE_8(void);

#endif /* ASSIGNMENT_2_H_ */
