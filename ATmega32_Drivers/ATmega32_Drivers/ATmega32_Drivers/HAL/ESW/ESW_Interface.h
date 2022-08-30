/**
 * @file ESW_Interface.h
 * 
 * @author: Mohamed Wx
 * @date Aug 28, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef HAL_ESW_ESW_INTERFACE_H_
#define HAL_ESW_ESW_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum ESW_IDS
{
	ESW1_ID,
	ESW2_ID,
	ESW3_ID,
	ESW4_ID		/** @todo to be continued */
};

enum ESW_VALUES
{
	ESW_OFF,
	ESW_ON
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	STRUCTS & GLOBALS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/



/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void EWS_voidInitalizeRelays(u8 Copy_u8RelayID);
void EWS_voidInitalizeOptoCouplers(u8 Copy_u8OcID);
void EWS_voidInitalizeTransistors(u8 Copy_u8TransistorID);

void ESW_voidSetRelayValue(u8 Copy_u8ESW_ID, u8 Copy_u8ESW_Value);
void ESW_voidSetOcValue(u8 Copy_u8ESW_ID, u8 Copy_u8ESW_Value);
void ESW_voidSetTransistorValue(u8 Copy_u8ESW_ID, u8 Copy_u8ESW_Value);


#endif /* HAL_ESW_ESW_INTERFACE_H_ */
