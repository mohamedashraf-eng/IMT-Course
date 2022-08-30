/**
 * @file ESW_Config.h
 * 
 * @author: Mohamed Wx
 * @date Aug 28, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef HAL_ESW_ESW_CONFIG_H_
#define HAL_ESW_ESW_CONFIG_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

ST_MyESWConfig_t MyESWConfigs =
{
		/** @note Relay Config */
		{		/** @note Coil */
				{PORT_D, PIN_2},	 /* Relay 1 Config */
				{PORT_D, PIN_2} 	 /* Relay 2 Config */
		},
		/** @note Opto Coupler Config */
		{	    /** @note ANODE */
				{PORT_A, PIN_1},	/* OptoCoupler 1 Config */
				{PORT_A, PIN_2}		/* OptoCoupler 2 Config */
		},
		/** @note Transistor Config */
		{	    /** @note Base */
				{PORT_A, PIN_3},	/* Transistor 1 Config */
				{PORT_A, PIN_4},	/* Transistor 2 Config */
				{PORT_A, PIN_5},	/* Transistor 3 Config */
				{PORT_A, PIN_6}		/* Transistor 4 Config */
		}
};


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	STRUCTS & GLOBALS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#endif /* HAL_ESW_ESW_CONFIG_H_ */
