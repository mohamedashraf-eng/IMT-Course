/**
 * @file SREG_Interface.h
 * 
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_SREG_SREG_INTERFACE_H_
#define MCAL_SREG_SREG_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum BIT_STATE
{
	SREG_Disable,
	SREG_Enable
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void SREG_voidGlobalInterruptInitalization(void);
void SREG_voidGlobalInterruptControl(u8 Copy_u8State);

#endif /* MCAL_SREG_SREG_INTERFACE_H_ */
