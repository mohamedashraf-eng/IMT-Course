/*
 * LED_Config.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Wx
 */
/** @def Header Guards */
#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define NUM_OF_LEDS ( (cu8) (8) )

typedef struct
{
	cu8 PORT_ID;
	cu8 PIN_ID;
	cu8 INITAL_STATE;
}ST_LED_LedsConfig_t;


ST_LED_LedsConfig_t myLedsConfig[NUM_OF_LEDS] =
{
		{PORT_A, PIN_1, LOW}, /** @def Led 1 */
		{PORT_A, PIN_2, LOW}, /** @def Led 2 */
		{PORT_A, PIN_3, LOW}, /** @def Led 3 */
		{PORT_A, PIN_4, LOW}, /** @def Led 4 */
		{PORT_A, PIN_5, LOW}, /** @def Led 5 */
		{PORT_A, PIN_6, LOW}, /** @def Led 6 */
		{PORT_A, PIN_7, LOW}, /** @def Led 7 */
		{PORT_A, PIN_8, LOW}, /** @def Led 8 */
};

#endif /* HAL_LED_LED_CONFIG_H_ */
