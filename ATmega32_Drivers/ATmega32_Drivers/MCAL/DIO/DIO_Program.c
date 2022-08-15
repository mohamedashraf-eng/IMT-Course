/**
 * @file DIO_Program.c
 * @brief the main application entry point.
 * @author Mohamed Wx
 * @date 15/08/2022
 *
 */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup Horizontal Layer*/
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																		MACROS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/




/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void DIO_voidSetPinDirection(cu8 A_cu8PortID, cu8 A_cu8PinID, cu8 A_cu8PinDirection)
{
	switch(A_cu8PortID)
	{
		case PORT_A: break;
		case PORT_B: break;
		case PORT_C: break;
		case PORT_D: break;
		default: return;
	}
}/** @end DIO_voidSetPinDirection */


void DIO_voidSetPinValue(cu8 A_cu8PortID, cu8 A_cu8PinID, cu8 A_cu8PinValue)
{
	switch(A_cu8PortID)
	{
		case PORT_A: break;
		case PORT_B: break;
		case PORT_C: break;
		case PORT_D: break;
		default: return;
	}
}/** @end DIO_voidSetPinValue */


void DIO_voidSetRegisterDirection(cu8 A_cu8PortID, cu8 A_cu8RegisterDirection)
{
	switch(A_cu8PortID)
	{
		case PORT_A: break;
		case PORT_B: break;
		case PORT_C: break;
		case PORT_D: break;
		default: return;
	}
}/** @end DIO_voidSetRegisterDirection */


void DIO_voidSetRegisterValue(cu8 A_cu8PortID, cu8 A_cu8RegisterValue)
{
	switch(A_cu8PortID)
	{
		case PORT_A: break;
		case PORT_B: break;
		case PORT_C: break;
		case PORT_D: break;
		default: return;
	}
}/** @end DIO_voidSetRegisterValue */


cu8 DIO_cu8GetPinValue(cu8 A_cu8PortID, cu8 A_cu8PinID)
{
	u8 L_PinValue = 0;

	switch(A_cu8PortID)
	{
		case PORT_A: L_PinValue = BIT_GET(PINA, A_cu8PinID); break;
		case PORT_B: L_PinValue = BIT_GET(PINB, A_cu8PinID); break;
		case PORT_C: L_PinValue = BIT_GET(PINC, A_cu8PinID); break;
		case PORT_D: L_PinValue = BIT_GET(PIND, A_cu8PinID); break;
		default: 	 break;			/* return error */
	}

	return L_PinValue;
}/** @end DIO_cu8GetPinValue */


cu8 DIO_cu8GetRegisterValue(cu8 A_cu8PortID)
{
	u8 L_RegisterValue = 0;

	switch(A_cu8PortID)
	{
		case PORT_A: L_RegisterValue = REG_GET(PINA); break;
		case PORT_B: L_RegisterValue = REG_GET(PINB); break;
		case PORT_C: L_RegisterValue = REG_GET(PINC); break;
		case PORT_D: L_RegisterValue = REG_GET(PIND); break;
		default: 	 break;			/* return error */
	}

	return L_RegisterValue;
}/** @end DIO_cu8GetRegisterValue */



