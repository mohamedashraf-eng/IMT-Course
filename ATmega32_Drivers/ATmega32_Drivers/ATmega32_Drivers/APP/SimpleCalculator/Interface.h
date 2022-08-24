/**
 * @file Interface.h
 * 
 * @author: Mohamed Wx
 * @date Aug 24, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef APP_SIMPLECALCULATOR_INTERFACE_H_
#define APP_SIMPLECALCULATOR_INTERFACE_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
enum CALCULATOR_OPERATIONS
{
	/** @defgroup operations */
	MUL,
	DIV,
	SUM,
	SUB,
	CLR,
	ENTER
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void voidSystemInitilization(void);
void voidSystemUpdate(void);

void voidValueToFunction(u8 Copy_u8KeyValue, u8 *Address_u8KeyFunction);

#endif /* APP_SIMPLECALCULATOR_INTERFACE_H_ */
