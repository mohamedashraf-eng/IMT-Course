/**
 * @file ESW_Private.h
 * 
 * @author: Mohamed Wx
 * @date Aug 28, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef HAL_ESW_ESW_PRIVATE_H_
#define HAL_ESW_ESW_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define NUM_OF_RELAYS 		(2)
#define NUM_OF_OC			(2)
#define NUM_OF_TRANSISTORS	(4)

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	STRUCTS & GLOBALS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

typedef struct
{
	u8 COIL_PORT_ID;
	u8 COIL_PIN_ID;
}ST_RelayConfig_t;

typedef struct
{
	u8 ANODE_PORT_ID;
	u8 ANODE_PIN_ID;
}ST_OcConfig_t;

typedef struct
{
	u8 BASE_PORT_ID;
	u8 BASE_PIN_ID;
}ST_TransistorConfig_t;


typedef struct
{
	ST_RelayConfig_t RelayConfig[NUM_OF_RELAYS];
	ST_OcConfig_t OcConfig[NUM_OF_OC];
	ST_TransistorConfig_t TransistorConfig[NUM_OF_TRANSISTORS];
}ST_MyESWConfig_t;



/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


#endif /* HAL_ESW_ESW_PRIVATE_H_ */
