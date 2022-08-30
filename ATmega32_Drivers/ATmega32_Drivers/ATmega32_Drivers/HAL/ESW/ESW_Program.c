/**
 * @file ESW_Program.c
 * 
 * @author: Mohamed Wx
 * @date Aug 28, 2022
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

#include "ESW_Private.h"
#include "ESW_Interface.h"
#include "ESW_Config.h"

#include <avr/delay.h>

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void voidInitalizeRelays(u8 Copy_u8RelayID)
{
	u8 L_u8Iterator;

	for(L_u8Iterator = 0; (L_u8Iterator < NUM_OF_RELAYS); ++L_u8Iterator)
	{
		DIO_voidSetPinDirection(MyESWConfigs.RelayConfig[Copy_u8RelayID].COIL_PORT_ID,
								MyESWConfigs.RelayConfig[Copy_u8RelayID].COIL_PIN_ID,
								OUTPUT);

		DIO_voidSetPinValue(MyESWConfigs.RelayConfig[Copy_u8RelayID].COIL_PORT_ID,
							MyESWConfigs.RelayConfig[Copy_u8RelayID].COIL_PIN_ID,
							LOW);
	}
}/** @end voidInitalizeRelays */

void voidInitalizeOptoCouplers(u8 Copy_u8OcID)
{
	u8 L_u8Iterator;

	for(L_u8Iterator = 0; (L_u8Iterator < NUM_OF_OC); ++L_u8Iterator)
	{
		DIO_voidSetPinDirection(MyESWConfigs.OcConfig[Copy_u8OcID].ANODE_PORT_ID,
								MyESWConfigs.OcConfig[Copy_u8OcID].ANODE_PIN_ID,
								OUTPUT);

		DIO_voidSetPinValue(MyESWConfigs.OcConfig[Copy_u8OcID].ANODE_PORT_ID,
							MyESWConfigs.OcConfig[Copy_u8OcID].ANODE_PIN_ID,
							LOW);
	}
}/** @end voidInitalizeOptoCouplers */


void voidInitalizeTransistors(u8 Copy_u8TransistorID)
{
	u8 L_u8Iterator;

	for(L_u8Iterator = 0; (L_u8Iterator < NUM_OF_TRANSISTORS); ++L_u8Iterator)
	{
		DIO_voidSetPinDirection(MyESWConfigs.TransistorConfig[Copy_u8TransistorID].BASE_PORT_ID,
								MyESWConfigs.TransistorConfig[Copy_u8TransistorID].BASE_PIN_ID,
								OUTPUT);

		DIO_voidSetPinValue(MyESWConfigs.TransistorConfig[Copy_u8TransistorID].BASE_PORT_ID,
							MyESWConfigs.TransistorConfig[Copy_u8TransistorID].BASE_PIN_ID,
							LOW);
	}
}/** @end voidInitalizeTransistors */

void ESW_voidSetRelayValue(u8 Copy_u8ESW_ID, u8 Copy_u8ESW_Value)
{
	DIO_voidSetPinValue(MyESWConfigs.RelayConfig[Copy_u8ESW_ID].COIL_PORT_ID,
						MyESWConfigs.RelayConfig[Copy_u8ESW_ID].COIL_PIN_ID,
						Copy_u8ESW_Value);
}/** @end ESW_voidSetESWValue */

void ESW_voidSetOcValue(u8 Copy_u8ESW_ID, u8 Copy_u8ESW_Value)
{
	DIO_voidSetPinValue(MyESWConfigs.OcConfig[Copy_u8ESW_ID].ANODE_PORT_ID,
						MyESWConfigs.OcConfig[Copy_u8ESW_ID].ANODE_PIN_ID,
						Copy_u8ESW_Value);
}/** @end ESW_voidSetESWValue */

void ESW_voidSetTransistorValue(u8 Copy_u8ESW_ID, u8 Copy_u8ESW_Value)
{
	DIO_voidSetPinValue(MyESWConfigs.TransistorConfig[Copy_u8ESW_ID].BASE_PORT_ID,
						MyESWConfigs.TransistorConfig[Copy_u8ESW_ID].BASE_PIN_ID,
						Copy_u8ESW_Value);
}/** @end ESW_voidSetESWValue */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVIATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


