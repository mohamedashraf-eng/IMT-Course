/**
 * @file Program.c
 * 
 * @author: Mohamed Wx
 * @date Aug 24, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "../../HAL/LCD/LCD_Interface.h"
#include "../../HAL/KEYPAD/KEYPAD_Interface.h"

#include "Private.h"
#include "Interface.h"

#include <avr/delay.h>

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void voidSystemInitilization(void)
{
	LCD_voidSystemInitalaization(LCD_EightBitMode);
	KEYPAD_voidSystemInitialization();
}/** @end voidSystemInitilization */


/**
 * @def algorithm used:
 * 1. Ask user to enter the first operand.
 * 		1. Check if the operand is operation.
 * 		2. If operand exceed max size-1.
 * 			1. Stop getting numerical input.
 * 			2. Force user to input only operations.
 * 			3. Get operation.
 *	2. Ask user to enter second operand.
 *	  	1. Check if the operand is operation.
 * 		2. If operand exceed max size-1.
 * 			1. Stop getting numerical input.
 * 			2. Force user to input only operations.
 * 			3. Get operation.
 * 	3.
 **/
void voidSystemUpdate(void)
{
	/* Variables declaration */
	u8 L_u8InputKeyValue = 0;

	//u8 L_u8OperandBuffer[MAX_OPERAND_BUFFER_SIZE] = {0};
	//u8 L_u8BufferIterator = 0;

	u8 L_u8OperandPositionFlag  = 0;
	u8 L_u8OperationSetFlag = 0;
	u8 L_u8CalculationFinishFlag = 0;

	u16 L_u16Number1 = 0,
	    L_u16Number2 = 0;
	u8 L_u8Operation = 0;
	u32 L_u32Result  = 0;

	/* Doing the operation */
	while(True)
	{
		KEYPAD_voidGetPressedKey(&L_u8InputKeyValue);

		if( (L_u8InputKeyValue == NO_KEY_PRESSED) ) { continue; }
		else;

		switch(L_u8InputKeyValue)
		{
			case KP_MUL:
					if( (L_u8OperationSetFlag == 0) )
					{
						L_u8Operation = KP_MUL;
						LCD_voidDisplayCharacter('*');

						L_u8OperationSetFlag = 1;
					}else;
				break;
			case KP_DIV:
					if( (L_u8OperationSetFlag == 0) )
					{
						L_u8Operation = KP_DIV;
						LCD_voidDisplayCharacter('/');

						L_u8OperationSetFlag = 1;
					}else;
				break;
			case KP_SUM:
					if( (L_u8OperationSetFlag == 0) )
					{
						L_u8Operation = KP_SUM;
						LCD_voidDisplayCharacter('+');

						L_u8OperationSetFlag = 1;
					}else;
				break;
			case KP_SUB:
					if( (L_u8OperationSetFlag == 0) )
					{
						L_u8Operation = KP_SUB;
						LCD_voidDisplayCharacter('-');

						L_u8OperationSetFlag = 1;
					}else;
				break;

			case KP_CLR:
					L_u16Number1 = 0; L_u16Number2 = 0;
					L_u8OperandPositionFlag = 0;
					L_u8OperationSetFlag = 0;
					L_u8CalculationFinishFlag = 0;
					voidClearAndReset();
				break;

			case KP_ENTER:
					L_u32Result	= u32ValueToOperation(L_u16Number1, L_u16Number2, L_u8Operation);
					if( (L_u32Result == DIV_BY_ZERO_FLAG) )
					{LCD_voidGoToRowColumn(Row1_ID, Column1_ID); LCD_voidDisplayString("ERR: DIV_BY_ZERO_FLAG!");}
					else;
					LCD_voidDisplayCharacter('=');
					LCD_voidDisplayInteger(L_u32Result);
					L_u8OperandPositionFlag = 0;
					L_u8OperationSetFlag = 0;
					L_u8CalculationFinishFlag = 1;
				break;

			default:
					if( (L_u8OperandPositionFlag == 0) )
					{
						L_u16Number1 = L_u16Number1 * 10 + L_u8InputKeyValue;
						L_u8OperandPositionFlag = 1;
					}
					else
					{
						L_u16Number2 = L_u16Number2 * 10 + L_u8InputKeyValue;
					}
					LCD_voidDisplayInteger(L_u8InputKeyValue); break;
		}

		if( (L_u8CalculationFinishFlag == 1) ) { break; }
		else;
	}
}/** @end voidSystemUpdate */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static u32 u32ValueToOperation(u16 Copy_u16Number1, u16 Copy_u16Number2, u8 Copy_u8Operation)
{
	u32 L_u32Result = 0;

	switch(Copy_u8Operation)
	{
		case KP_MUL: L_u32Result = (Copy_u16Number1 * Copy_u16Number2); break;
		case KP_DIV:
			if( (Copy_u16Number2 == 0) )
			{ L_u32Result = DIV_BY_ZERO_FLAG;}
			else {L_u32Result = (Copy_u16Number1 / Copy_u16Number2);}
		break;
		case KP_SUM: L_u32Result = (Copy_u16Number1 + Copy_u16Number2);	break;
		case KP_SUB: L_u32Result = (Copy_u16Number1 - Copy_u16Number2); break;

		case KP_CLR:  voidClearAndReset();	break;
		case KP_ENTER: break;
		default: break; /* error handler */
	}

	return L_u32Result;
}/** @end KEYPAD_voidValueToFunction */

static u16 u16DigitsToInt(u8 *Address_u8DigitsArray)
{
	u16 L_u16IntegerValue = 0;

	u8 L_u8Iterator = 0;

	while( (L_u8Iterator < MAX_OPERAND_BUFFER_SIZE) )
	{
		L_u16IntegerValue = (10 * L_u16IntegerValue) + (Address_u8DigitsArray[L_u8Iterator]);
	}

	return L_u16IntegerValue;
}/** @end voidDigitsToInt */

static void voidClearAndReset(void)
{
	LCD_voidClearScreen();

}/** @end voidClearAndReset */

static void voidClearOperandBuffer(u8 *Address_u8BufferArray)
{
	u8 L_u8Iterator;

	for(L_u8Iterator = 0; (L_u8Iterator < MAX_OPERAND_BUFFER_SIZE); ++L_u8Iterator)
	{
		Address_u8BufferArray[L_u8Iterator] = 0;
	}
}/** @end voidClearBuffer */
