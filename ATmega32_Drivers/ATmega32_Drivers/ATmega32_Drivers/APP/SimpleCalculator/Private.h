/**
 * @file Private.h
 * 
 * @author: Mohamed Wx
 * @date Aug 24, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef APP_SIMPLECALCULATOR_PRIVATE_H_
#define APP_SIMPLECALCULATOR_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define MAX_OPERAND_BUFFER_SIZE 	(10)

enum CALCULATIONS_EXCEPTIONS_FLAGS
{
	DIV_BY_ZERO_FLAG= 133
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static u32 u32ValueToOperation(u16 Copy_u16Number1, u16 Copy_u16Number2, u8 Copy_u8KeyValue);
static u16 u16DigitsToInt(u8 *Address_u8DigitsArray);

static void voidClearAndReset(void);
static void voidClearOperandBuffer(u8 *Address_u8BufferArray);

#endif /* APP_SIMPLECALCULATOR_PRIVATE_H_ */
