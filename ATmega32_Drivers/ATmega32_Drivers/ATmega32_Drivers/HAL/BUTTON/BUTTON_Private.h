/*
 * BUTTON_Private.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Wx
 */
/** @def Header Guards */
#ifndef HAL_BUTTON_BUTTON_PRIVATE_H_
#define HAL_BUTTON_BUTTON_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum ATmega32_INPUT_CONFIG
{
	INTERNAL_TRI_STATE,
	INTERNAL_PULLUP_RESISTOR
};

#define EXTERNAL_PULLUP_RESISTOR	( 3 )
#define EXTERNAL_PULLDOWN_RESISTOR	( 4 )
#define NOTHING						( 5 )

#define NUM_OF_BUTTONS ( (cu8) (8) )

typedef struct
{
	cu8 PORT_ID;
	cu8 PIN_ID;
	cu8 BUTTON_STATE;
}ST_ButtonConfig_t;


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS PROTOYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void BUTTON_voidSetButtonPinDirection(u8 Copy_u8ButtonID);
static void BUTTON_voidSetButtonPinValue(u8 Copy_u8ButtonID);
static u8 BUTTON_u8GetButtonValue(u8 Copy_u8ButtonID);

#endif /* HAL_BUTTON_BUTTON_PRIVATE_H_ */
