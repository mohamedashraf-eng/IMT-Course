/*
 * SSD_Interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Wx
 */
/** @def Header Guards */
#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum SSD_ID
{
	SSD_1,
	SSD_2
};

enum SSD_Display
{
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
	A,
	B,
	C,
	D,
	E,
	F
};

enum SSD_PINS
{
	PIN_A,
	PIN_B,
	PIN_C,
	PIN_D,
	PIN_E,
	PIN_F,
	PIN_G,
	PIN_DOT,
	PIN_COMM
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void SSD_voidSsdInitalization(u8 Copy_u8SsdID);
void SSD_voidSsdTurnOn(u8 Copy_u8SsdID);
void SSD_voidSsdTurnOff(u8 Copy_u8SsdID);
void SSD_voidSsdSetNumber(u8 Copy_u8SsdID, u8 Copy_u8Number);
void SSD_voidSsdSetPin(u8 Copy_u8SsdID, u8 Copy_u8SsdPin);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
