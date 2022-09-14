/**
 * @file SREG_Program.c
 * 
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup Horizontal Layer*/
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

#include "SREG_Private.h"
#include "SREG_Config.h"
#include "SREG_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void SREG_voidGlobalInterruptInitalization(void)
{
	/** @note Disable the GIE */
	BIT_CLR(SREG, I);
}/** @end SREG_voidGlobalInterruptControl */

void SREG_voidGlobalInterruptControl(u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
		case SREG_Disable:	BIT_CLR(SREG, I);	break;
		case SREG_Enable: 	BIT_SET(SREG, I);	break;
		default: break; /* Error handler */
	}
}/** @end SREG_voidGlobalInterruptControl */
