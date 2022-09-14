/**
 * @file EXTI_Config.h
 * 
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	 STRUCTS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

ST_EXTIConfig_t MyEXTIConfigs =
{
	/** @defgroup Pins */
	PORT_D,	/** @note INT0 */
	PIN_3,	/** @note INT0 */

	PORT_D,	/** @note INT1  */
	PIN_4,	/** @note INT1 */

	PORT_B,	/** @note INT2 */
	PIN_3,	/** @note INT2 */

	/** @defgroup Modes */
	EXTI_FALLING_EDGE,	/** @note INT0 */
	EXTI_FALLING_EDGE,	/** @note INT1 */
	EXTI_FALLING_EDGE	/** @note INT2 */
};

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
