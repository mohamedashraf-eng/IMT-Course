/*
 * Frame_Interface.h
 *
 *  Created on: Aug 18, 2022
 *      Author: Wx
 */
/** @def Header Guards */
#ifndef APP_SSD_FRAME_FRAME_INTERFACE_H_
#define APP_SSD_FRAME_FRAME_INTERFACE_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum Frame_Directions
{
	Clockwise,
	AntiClockwise
};


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void Frame_voidSystemInitalaization(void);
void Frame_voidSetFrameDirection(u8 Copy_u8FrameDirection);
void Frame_voidUpdate(void);


#endif /* APP_SSD_FRAME_FRAME_INTERFACE_H_ */
