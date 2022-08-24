/**
 * @file KEYPAD_Config.h
 * 
 * @author: Mohamed Wx
 * @date Aug 24, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define NUM_OF_ROWS		4
#define NUM_OF_COLS		4

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	STRUCTS & GLOBALS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @def keypad config parameters */

ST_KeyPadConfig_t MyKeyPadConfig[] =
{
	{PORT_D, PIN_1, INPUT, HIGH},	/** @note Row 1		*/
	{PORT_D, PIN_2, INPUT, HIGH},	/** @note Row 2		*/
	{PORT_D, PIN_3, INPUT, HIGH},	/** @note Row 3		*/
	{PORT_D, PIN_4, INPUT, HIGH},	/** @note Row 4		*/

	{PORT_D, PIN_5, OUTPUT, HIGH},	/** @note Column 1	*/
	{PORT_D, PIN_6, OUTPUT, HIGH},	/** @note Column 2	*/
	{PORT_D, PIN_7, OUTPUT, HIGH},	/** @note Column 3	*/
	{PORT_D, PIN_8, OUTPUT, HIGH},	/** @note Column 4	*/
};


enum KEY_CODE_EQV_FUNC
{
	/** @defgroup numbers */
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,

	/** @defgroup operations */
	MUL,
	DIV,
	SUM,
	SUB,
	CLR,
	ENTER
};

/** @def keys equivalent value */
static const u8 G_Keys_LookUpTable[NUM_OF_ROWS][NUM_OF_COLS] =
{
/**  C:0    C:1      C:2   C:3 */
	{ONE,   TWO, 	THREE, MUL},	/** R:0 */
	{FOUR,  FIVE,   SIX,   DIV},	/** R:1 */
	{SEVEN, EIGHT,  NINE,  SUM},	/** R:2 */
	{ZERO,  ENTER,  CLR,   SUB}		/** R:3 */
	/** @note E: Enter, C: Clear & Reset */
};

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
