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

#include "DIO_Registers.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void
DIO_voidDioInitialization(void)
{
	/** @todo add code */

}/** @end DIO_voidDioInitialization */

void
DIO_voidDioReset(void)
{

}/** @end DIO_voidDioReset */

void
DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDirection)
{
	if( (Copy_u8PortID < NUM_OF_PORTS) && (Copy_u8PinID < PORT_PIN_NUM) )
	{
		switch(Copy_u8PortID)
		{
			case PORT_A: BIT_WRT(DDRA, Copy_u8PinID, Copy_u8PinDirection);	break;
			case PORT_B: BIT_WRT(DDRB, Copy_u8PinID, Copy_u8PinDirection);	break;
			case PORT_C: BIT_WRT(DDRC, Copy_u8PinID, Copy_u8PinDirection);	break;
			case PORT_D: BIT_WRT(DDRD, Copy_u8PinID, Copy_u8PinDirection);	break;
			default: return;
		}
	}
	else
	{
		/* return error */
	}
}/** @end DIO_voidSetPinDirection */

void
DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue)
{
	if( (Copy_u8PortID < NUM_OF_PORTS) && (Copy_u8PinID < PORT_PIN_NUM) )
	{
		switch(Copy_u8PortID)
		{
			case PORT_A: BIT_WRT(PORTA, Copy_u8PinID, Copy_u8PinValue);	break;
			case PORT_B: BIT_WRT(PORTB, Copy_u8PinID, Copy_u8PinValue);	break;
			case PORT_C: BIT_WRT(PORTC, Copy_u8PinID, Copy_u8PinValue);	break;
			case PORT_D: BIT_WRT(PORTD, Copy_u8PinID, Copy_u8PinValue);	break;
			default: return;
		}
	}
	else
	{
		/* return error */
	}
}/** @end DIO_voidSetPinValue */

void
DIO_voidTogPin(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	if( (Copy_u8PortID < NUM_OF_PORTS) && (Copy_u8PinID < PORT_PIN_NUM) )
	{
		switch(Copy_u8PortID)
		{
			case PORT_A: BIT_TOG(PORTA, Copy_u8PinID);   break;
			case PORT_B: BIT_TOG(PORTB, Copy_u8PinID);   break;
			case PORT_C: BIT_TOG(PORTC, Copy_u8PinID);   break;
			case PORT_D: BIT_TOG(PORTD, Copy_u8PinID);   break;
			default: return;
		}
	}
	else
	{
		/* return error */
	}
}/** @end DIO_voidTogPin */

void
DIO_voidSetRegisterDirection(u8 Copy_u8PortID, u8 Copy_u8RegisterDirection)
{
	if( (Copy_u8PortID < NUM_OF_PORTS) )
	{
		switch(Copy_u8PortID)
		{
			case PORT_A: REG_WRT(DDRA, Copy_u8RegisterDirection);	break;
			case PORT_B: REG_WRT(DDRB, Copy_u8RegisterDirection);	break;
			case PORT_C: REG_WRT(DDRC, Copy_u8RegisterDirection);	break;
			case PORT_D: REG_WRT(DDRD, Copy_u8RegisterDirection);	break;
			default: return;
		}
	}
	else
	{
		/* return error */
	}
}/** @end DIO_voidSetRegisterDirection */

void
DIO_voidSetRegisterValue(u8 Copy_u8PortID, u8 Copy_u8RegisterValue)
{
	if( (Copy_u8PortID < NUM_OF_PORTS) )
	{
		switch(Copy_u8PortID)
		{
			case PORT_A: REG_WRT(PORTA, Copy_u8RegisterValue);	break;
			case PORT_B: REG_WRT(PORTB, Copy_u8RegisterValue);	break;
			case PORT_C: REG_WRT(PORTC, Copy_u8RegisterValue);	break;
			case PORT_D: REG_WRT(PORTD, Copy_u8RegisterValue);	break;
			default: return;
		}
	}
	else
	{
		/* return error */
	}
}/** @end DIO_voidSetRegisterValue */

u8
DIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	u8 L_PinValue = 0;

	if( (Copy_u8PortID < NUM_OF_PORTS) )
	{
		switch(Copy_u8PortID)
		{
			case PORT_A: L_PinValue = BIT_GET(PINA, Copy_u8PinID); 	break;
			case PORT_B: L_PinValue = BIT_GET(PINB, Copy_u8PinID); 	break;
			case PORT_C: L_PinValue = BIT_GET(PINC, Copy_u8PinID); 	break;
			case PORT_D: L_PinValue = BIT_GET(PIND, Copy_u8PinID); 	break;
			default: 	 break;			/* return error */
		}
	}
	else
	{
		/* return error */
	}
	return L_PinValue;
}/** @end DIO_u8GetPinValue */

u8
DIO_u8GetRegisterValue(u8 Copy_u8PortID)
{
	u8 L_RegisterValue = 0;

	if( (Copy_u8PortID < NUM_OF_PORTS) )
	{
		switch(Copy_u8PortID)
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
}/** @end DIO_u8GetRegisterValue */


