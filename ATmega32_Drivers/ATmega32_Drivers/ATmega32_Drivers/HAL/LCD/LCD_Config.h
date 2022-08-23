/**
 * @file LCD_Config.h
 * 
 * @author: Mohamed Wx
 * @date Aug 22, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

ST_LCD_ConfigParameters_t myLCD_Configs =
{
	PORT_A,			/** @note Data	*/
	PORT_D, PIN_1,	/** @note EN	*/
	PORT_D, PIN_2,	/** @note RW	*/
	PORT_D, PIN_3	/** @note RS	*/
};

/**
 * Options:
 * 1. FOUR_BIT_MODE
 * 2. EIGHT_BIT_MODE
 */
#define DATA_BIT_MODE EIGHT_BIT_MODE


#endif /* HAL_LCD_LCD_CONFIG_H_ */
