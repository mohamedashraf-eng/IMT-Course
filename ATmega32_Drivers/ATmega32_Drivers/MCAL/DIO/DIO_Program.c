/**
 * @file DIO_Program.c
 * @brief the main application entry point.
 * @author Mohamed Wx
 * @date 15/08/2022
 *
 */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
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
 * -	MACROS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/




/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void DIO_voidSetPinDirection(cu8 Copy_cu8PortID, cu8 Copy_cu8PinID, cu8 Copy_cu8PinDirection)
{
	if( (Copy_cu8PortID < NUM_OF_PORTS) && (Copy_cu8PinID < PORT_PIN_NUM) )
	{
		switch(Copy_cu8PortID)
		{
			case PORT_A: BIT_WRT(DDRA, Copy_cu8PinID, Copy_cu8PinDirection);	break;
			case PORT_B: BIT_WRT(DDRB, Copy_cu8PinID, Copy_cu8PinDirection);	break;
			case PORT_C: BIT_WRT(DDRC, Copy_cu8PinID, Copy_cu8PinDirection);	break;
			case PORT_D: BIT_WRT(DDRD, Copy_cu8PinID, Copy_cu8PinDirection);	break;
			default: return;
		}
	}
	else
	{
		/* return error */
	}
}/** @end DIO_voidSetPinDirection */


void DIO_voidSetPinValue(cu8 Copy_cu8PortID, cu8 Copy_cu8PinID, cu8 Copy_cu8PinValue)
{
	if( (Copy_cu8PortID < NUM_OF_PORTS) && (Copy_cu8PinID < PORT_PIN_NUM) )
	{
		switch(Copy_cu8PortID)
		{
			case PORT_A: BIT_WRT(PORTA, Copy_cu8PinID, Copy_cu8PinValue);	break;
			case PORT_B: BIT_WRT(PORTB, Copy_cu8PinID, Copy_cu8PinValue);	break;
			case PORT_C: BIT_WRT(PORTC, Copy_cu8PinID, Copy_cu8PinValue);	break;
			case PORT_D: BIT_WRT(PORTD, Copy_cu8PinID, Copy_cu8PinValue);	break;
			default: return;
		}
	}
	else
	{
		/* return error */
	}
}/** @end DIO_voidSetPinValue */


void DIO_voidSetRegisterDirection(cu8 Copy_cu8PortID, cu8 Copy_cu8RegisterDirection)
{
	if( (Copy_cu8PortID < NUM_OF_PORTS) )
	{
		switch(Copy_cu8PortID)
		{
			case PORT_A: REG_WRT(DDRA, Copy_cu8RegisterDirection);	break;
			case PORT_B: REG_WRT(DDRB, Copy_cu8RegisterDirection);	break;
			case PORT_C: REG_WRT(DDRC, Copy_cu8RegisterDirection);	break;
			case PORT_D: REG_WRT(DDRD, Copy_cu8RegisterDirection);	break;
			default: return;
		}
	}
	else
	{
		/* return error */
	}
}/** @end DIO_voidSetRegisterDirection */


void DIO_voidSetRegisterValue(cu8 Copy_cu8PortID, cu8 Copy_cu8RegisterValue)
{
	if( (Copy_cu8PortID < NUM_OF_PORTS) )
	{
		switch(Copy_cu8PortID)
		{
			case PORT_A: REG_WRT(PORTA, Copy_cu8RegisterValue);	break;
			case PORT_B: REG_WRT(PORTB, Copy_cu8RegisterValue);	break;
			case PORT_C: REG_WRT(PORTC, Copy_cu8RegisterValue);	break;
			case PORT_D: REG_WRT(PORTD, Copy_cu8RegisterValue);	break;
			default: return;
		}
	}
	else
	{
		/* return error */
	}
}/** @end DIO_voidSetRegisterValue */


cu8 DIO_cu8GetPinValue(cu8 Copy_cu8PortID, cu8 Copy_cu8PinID)
{
	u8 L_PinValue = 0;

	if( (Copy_cu8PortID < NUM_OF_PORTS) )
	{
		switch(Copy_cu8PortID)
		{
			case PORT_A: L_PinValue = BIT_GET(PINA, Copy_cu8PinID); 	break;
			case PORT_B: L_PinValue = BIT_GET(PINB, Copy_cu8PinID); 	break;
			case PORT_C: L_PinValue = BIT_GET(PINC, Copy_cu8PinID); 	break;
			case PORT_D: L_PinValue = BIT_GET(PIND, Copy_cu8PinID); 	break;
			default: 	 break;			/* return error */
		}
	}
	else
	{
		/* return error */
	}
	return L_PinValue;
}/** @end DIO_cu8GetPinValue */


cu8 DIO_cu8GetRegisterValue(cu8 Copy_cu8PortID)
{
	u8 L_RegisterValue = 0;

	if( (Copy_cu8PortID < NUM_OF_PORTS) )
	{
		switch(Copy_cu8PortID)
		{
			case PORT_A: L_RegisterValue = REG_GET(PINA); break;
			case PORT_B: L_RegisterValue = REG_GET(PINB); break;
			case PORT_C: L_RegisterValue = REG_GET(PINC); break;
			case PORT_D: L_RegisterValue = REG_GET(PIND); break;
			default: 	 break;			/* return error */
		}
	}
	else
	{
		/* return error */
	}
	return L_RegisterValue;
}/** @end DIO_cu8GetRegisterValue */



