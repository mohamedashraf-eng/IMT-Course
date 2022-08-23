/**
 * @file LCD_Interface.h
 * 
 * @author: Mohamed Wx
 * @date Aug 22, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum LCD_Private_Commands
{
	LCD_ClearScreen  = 0x01,
	LCD_ReturnHome   = 0x02,
	LCD_EntryMode	 = 0x06,
	LCD_DisplayOFF 	 = 0x08,
	LCD_DisplayON 	 = 0x0C,
	LCD_FourBitMode  = 0x20, /** @note Two line */
	LCD_FuctionReset = 0x30, /** @note Two line */
	LCD_EightBitMode = 0x38, /** @note Two line */
	LCD_SetCursor	 = 0x80,

	LCD_DisplayON_CursorOFF   = 0xC0,
	LCD_DisplayOFF_CursorON   = 0x0A,
	LCD_DisplayON_CursorBlink = 0x0E,

	LCD_DisplaySHL = 0b0001000,
	LCD_DisplaySHR=  0b0001100,

	LCD_CursorSHL = 0x10,
	LCD_CursorSHR = 0x14,

	LCD_CursorrInc = 0x06,
	LCD_CursorDec  = 0x07,

	LCD_DataSHL = 0x18,
	LCD_DataSHR = 0x1C
};

enum LCD_COLUMNS
{
	Column0_ID,
	Column1_ID,
	Column2_ID,
	Column3_ID,
	Column4_ID,
	Column5_ID,
	Column6_ID,
	Column7_ID,
	Column8_ID,
	Column9_ID,
	Column10_ID,
	Column11_ID,
	Column12_ID,
	Column13_ID,
	Column14_ID,
	Column15_ID
};

enum LCD_ROWS
{
	Row0_ID,
	Row1_ID
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup main functions */
void LCD_voidSystemInitalaization(u8 Copy_u8FunctionSet);
void LCD_voidDisplayCharacter(u8 Copy_u8Character);
void LCD_voidDisplayString(u8 *Address_u8String);
void LCD_voidDisplayInteger(u32 Copy_u32Integer);
void LCD_voidGoToRowColumn(u8 Copy_u8RowID, u8 Copy_u8CoumnlID);

/** @defgroup functions modes */
void LCD_voidClearScreen(void);
void LCD_voidDisplayShiftLeft(void);
void LCD_voidDisplayShiftRight(void);

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void LCD_voidSendCommand(u8 Copy_u8Command);
static u8 LCD_u8IsBusy(void);


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
