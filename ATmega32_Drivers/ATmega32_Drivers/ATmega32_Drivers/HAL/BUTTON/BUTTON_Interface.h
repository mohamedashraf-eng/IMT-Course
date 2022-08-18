/*
 * BUTTON_Interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Wx
 */
/** @def Header Guards */
#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum BUTTONS_ID
{
	BUTTON_1,
	BUTTON_2,
	BUTTON_3,
	BUTTON_4,
	BUTTON_5,
	BUTTON_6,
	BUTTON_7,
	BUTTON_8,
};

enum BUTTONS_STATE
{
	BUTTON_OFF,
	BUTTON_ON
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
void BUTTON_voidButtonsInitalaization(void);
void BUTTON_voidButtonInitalaization(u8 Copy_u8ButtonID);
u8 BUTTON_u8ButtonGetValue(u8 Copy_u8ButtonID);

#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
