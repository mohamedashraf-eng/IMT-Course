/**
 * @file MOTORS_Config.h
 * 
 * @author: Mohamed Wx
 * @date Aug 25, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef HAL_MOTORS_MOTORS_CONFIG_H_
#define HAL_MOTORS_MOTORS_CONFIG_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	STRUCTS & GLOBALS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

ST_MotorsConfig_t MyMotorsConfig =
{
	/** @note DC Motors Config */
	{	  /* IN1,    IN2,    SPD */
			{PORT_D, PORT_C, PORT_C,
			 PIN_4,  PIN_5,  PIN_6}
	},
	/** @note Servo Motors Config */
	{		/*	Signal  */
			{PORT_D, PIN_5}
	},
	/** @note Stepper Motors Config */
	{     /* Pole1,  Pole2, Pole3,   Pole4  */
			{PORT_C, PORT_C, PORT_C, PORT_C,
			 PIN_1,  PIN_2,  PIN_3,  PIN_4}
	}
};

#endif /* HAL_MOTORS_MOTORS_CONFIG_H_ */
