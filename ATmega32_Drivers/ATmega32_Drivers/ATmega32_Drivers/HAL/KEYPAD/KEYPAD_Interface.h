/**
 * @file KEYPAD_Interface.h
 * 
 * @author: Mohamed Wx
 * @date Aug 24, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define NO_KEY_PRESSED	 255

enum KEY_STATE
{
	Pressed,
	NotPressed
};

enum KEYPAD_PINS
{
	KP_Row0_ID,
	KP_Row1_ID,
	KP_Row2_ID,
	KP_Row3_ID,
	KP_Column0_ID,
	KP_Column1_ID,
	KP_Column2_ID,
	KP_Column3_ID,

	KP_LastRow_ID	 = KP_Row3_ID,
	KP_LastColumn_ID = KP_Column3_ID
};

enum KEYPAD_AVAILABILE_KEYS
{
	/** @defgroup numbers */
	KP_ZERO,
	KP_ONE,
	KP_TWO,
	KP_THREE,
	KP_FOUR,
	KP_FIVE,
	KP_SIX,
	KP_SEVEN,
	KP_EIGHT,
	KP_NINE,

	/** @defgroup operations */
	KP_MUL,
	KP_DIV,
	KP_SUM,
	KP_SUB,
	KP_CLR,
	KP_ENTER
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void KEYPAD_voidSystemInitialization(void);
void KEYPAD_voidGetPressedKey(u8 *Address_u8PressedValue);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
