/**
 * @file LCD_Program.c
 * 
 * @author: Mohamed Wx
 * @date Aug 22, 2022
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

#include "LCD_Private.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"

#include <avr/delay.h>

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void LCD_voidSystemInitalaization(u8 Copy_u8FunctionSet)
{
	/** @def Pin Configuration */
	DIO_voidSetPinDirection(myLCD_Configs.EN_PORT_ID,
							myLCD_Configs.EN_PIN_ID,
							OUTPUT);

	DIO_voidSetPinDirection(myLCD_Configs.RW_PORT_ID,
							myLCD_Configs.RW_PIN_ID,
							OUTPUT);

	DIO_voidSetPinDirection(myLCD_Configs.RS_PORT_ID,
							myLCD_Configs.RS_PIN_ID,
							OUTPUT);

	DIO_voidSetRegisterDirection(myLCD_Configs.DATA_PORT_ID,
								 OUTPUT_ALL);

	/** @defgroup LCD Configuration */
	_delay_ms(30);
	LCD_voidSendCommand(LCD_ReturnHome);
	_delay_ms(15);
	LCD_voidSendCommand(Copy_u8FunctionSet);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_DisplayON);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_ClearScreen);
	_delay_ms(15);
	LCD_voidSendCommand(LCD_EntryMode);
	_delay_ms(2);
}/** @end LCD_voidSystemInitalaization */

void LCD_voidClearScreen(void)
{
	LCD_voidSendCommand(LCD_ClearScreen);
	_delay_ms(16);
}/** @end LCD_voidClearScreen */

void LCD_voidDisplayCharacter(u8 Copy_u8Character)
{
	DIO_voidSetPinValue(myLCD_Configs.RS_PORT_ID,
						myLCD_Configs.RS_PIN_ID,
						HIGH);

	DIO_voidSetPinValue(myLCD_Configs.RW_PORT_ID,
						myLCD_Configs.RW_PIN_ID,
						LOW);

	DIO_voidSetPinValue(myLCD_Configs.EN_PORT_ID,
						myLCD_Configs.EN_PIN_ID,
						HIGH);

	DIO_voidSetRegisterValue(myLCD_Configs.DATA_PORT_ID,
							 Copy_u8Character);

	DIO_voidSetPinValue(myLCD_Configs.EN_PORT_ID,
						myLCD_Configs.EN_PIN_ID,
						LOW);

	_delay_ms(6);


	DIO_voidSetPinValue(myLCD_Configs.EN_PORT_ID,
						myLCD_Configs.EN_PIN_ID,
						HIGH);

	_delay_ms(11);

}/** @end LCD_voidDisplayCharacter */

void LCD_voidDisplayString(u8 *Address_u8String)
{
	u8 L_u8Counter;

	for(L_u8Counter = 0; (Address_u8String[L_u8Counter] != '\0'); ++L_u8Counter)
	{
		LCD_voidDisplayCharacter(Address_u8String[L_u8Counter]);

		_delay_ms(1);
	}
}/** @end LCD_voidDisplayString */

void LCD_voidDisplayInteger(u32 Copy_u32Integer)
{
	u8 L_u8IntegerDigitsSTACK[DIGIT_STACK_MAX];
	s8 L_u8StackTop = 0;

	/* Extract digits */
	while(Copy_u32Integer)
	{
		L_u8IntegerDigitsSTACK[L_u8StackTop] = Copy_u32Integer%10;
		Copy_u32Integer /= 10;

		++L_u8StackTop;

		if( (L_u8StackTop >= DIGIT_STACK_MAX) )
		{
			break;
		}
		else;
	}

	/* Convert them to ASCII string & Print them */
	while(1)
	{
		--L_u8StackTop;
		L_u8IntegerDigitsSTACK[L_u8StackTop] += '0';
		LCD_voidDisplayCharacter(L_u8IntegerDigitsSTACK[L_u8StackTop]);

		_delay_ms(1);

		if( (L_u8StackTop <= 0 ) )
			break;
		else;
	}
}/** @end LCD_voidDisplayInteger */

void LCD_voidGoToRowColumn(u8 Copy_u8RowID, u8 Copy_u8CoumnlID)
{
	u8 L_u8Address = 0;

	if( (Copy_u8CoumnlID > 0) && (Copy_u8CoumnlID < 17) )
	{
		switch(Copy_u8RowID)
		{									/** @todo change the magic numbers */
			case Row0_ID: L_u8Address = Copy_u8CoumnlID; 		 	break;
			case Row1_ID: L_u8Address = Copy_u8CoumnlID + 0x40; 	break;
			default: return; /* error handler */
		}
	}
	else
	{
		return; /* error handler */
	}

	LCD_voidSendCommand(LCD_SetCursor | L_u8Address);
}/** @end LCD_voidGoToRowColumn */

void LCD_voidDisplayShiftLeft(void)
{
	LCD_voidSendCommand(LCD_DisplaySHL);
}/** @end LCD_voidDisplayShiftLeft */

void LCD_voidDisplayShiftRight(void)
{
	LCD_voidSendCommand(LCD_DisplaySHR);
}/** @end LCD_voidDisplayShiftRight */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_voidSetPinValue(myLCD_Configs.RS_PORT_ID,
						myLCD_Configs.RS_PIN_ID,
						LOW);

	DIO_voidSetPinValue(myLCD_Configs.RW_PORT_ID,
						myLCD_Configs.RW_PIN_ID,
						LOW);

	DIO_voidSetPinValue(myLCD_Configs.EN_PORT_ID,
						myLCD_Configs.EN_PIN_ID,
						HIGH);

	DIO_voidSetRegisterValue(myLCD_Configs.DATA_PORT_ID,
						   Copy_u8Command);

	DIO_voidSetPinValue(myLCD_Configs.EN_PORT_ID,
						myLCD_Configs.EN_PIN_ID,
						LOW);

	_delay_ms(6);

	DIO_voidSetPinValue(myLCD_Configs.EN_PORT_ID,
						myLCD_Configs.EN_PIN_ID,
						HIGH);

	_delay_ms(11);
}/** @end LCD_voidSendCommand */
