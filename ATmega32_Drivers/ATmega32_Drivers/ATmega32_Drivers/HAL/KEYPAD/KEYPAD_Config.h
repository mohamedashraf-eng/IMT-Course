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
	{PORT_B, PIN_1, INPUT, HIGH},	/** @note Row 1		*/
	{PORT_B, PIN_2, INPUT, HIGH},	/** @note Row 2		*/
	{PORT_B, PIN_3, INPUT, HIGH},	/** @note Row 3		*/
	{PORT_B, PIN_4, INPUT, HIGH},	/** @note Row 4		*/

	{PORT_B, PIN_5, OUTPUT, HIGH},	/** @note Column 1	*/
	{PORT_B, PIN_6, OUTPUT, HIGH},	/** @note Column 2	*/
	{PORT_B, PIN_7, OUTPUT, HIGH},	/** @note Column 3	*/
	{PORT_B, PIN_8, OUTPUT, HIGH},	/** @note Column 4	*/
};


/** @def keys equivalent value */
static const u8 G_Keys_LookUpTable[NUM_OF_ROWS][NUM_OF_COLS] =
{
/**  C:0         C:1        C:2      C:3 */
	{KP_ONE,   KP_TWO, 	  KP_THREE, KP_MUL},	/** R:0 */
	{KP_FOUR,  KP_FIVE,   KP_SIX,   KP_DIV},	/** R:1 */
	{KP_SEVEN, KP_EIGHT,  KP_NINE,  KP_SUM},	/** R:2 */
	{KP_ZERO,  KP_ENTER,  KP_CLR,   KP_SUB}		/** R:3 */
	/** @note E: Enter, C: Clear & Reset */
};

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
