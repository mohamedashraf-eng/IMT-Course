/**
 * @File: assignment1.h
 * @Author: Mohamed Wx
 * @Date: 12/8/2022
 * @brief: header for assignment 1 task.
 *
 */

#ifndef ASSIGNMENT_1_H_
#define ASSIGNMENT_1_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	HEADERS INCLUDED															-
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include "LIB/bit_math.h"
#include "LIB/std_types.h"
#include "LIB/std_libs.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	 GLOBAL															-
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define SECOND (1000u)

typedef enum LEDS
{
	RED,
	YELLOW,
	GREEN
}LEDS_t;

typedef enum LED_STATE
{
	OFF,
	ON
}LED_STATE_t;

typedef enum SSD
{
	SSD1,
	SSD2
}SSD_t;

typedef enum SSD_MODES
{
	INCREASING,
	DECREASING
}SSD_MODES_t;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -														 	 FUNCTIONS PROTOTYPE															-
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
void SYS_INIT(void);
void SYS_SSD(cu8, cu8, cu8);
void LED_CTRL(cu8, cu8);

/** @defgroup sub functions */
static void LED_GREEN(cu8);
static void LED_YELLOW(cu8);
static void LED_RED(cu8);

static void SSD_1(cu8, cu16, cu8);
static void SSD_2(cu8, cu16, cu8);

#endif /* ASSIGNMENT_1_H_ */
