/*
 * SSD_Private.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Wx
 */
/** @def Header Guards */
#ifndef HAL_SSD_SSD_PRIVATE_H_
#define HAL_SSD_SSD_PRIVATE_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define SSD1_NUM_OF_PINS (9) /** @note SSD pins + Common pin */
#define SSD2_NUM_OF_PINS (9) /** @note SSD pins + Common pin */

typedef struct
{
	u8 PORT_ID;
	u8 PIN_ID;
	u8 PIN_STATE;
}ST_SsdPinConfig_t;

/** @defgroup SSD1 Pin Configuration */
ST_SsdPinConfig_t mySSD1_PinConfig[] =
{
		{SSD1_PORT, PIN_1, LOW},
		{SSD1_PORT, PIN_2, LOW},
		{SSD1_PORT, PIN_3, LOW},
		{SSD1_PORT, PIN_4, LOW},
		{SSD1_PORT, PIN_5, LOW},
		{SSD1_PORT, PIN_6, LOW},
		{SSD1_PORT, PIN_7, LOW},
		{SSD1_PORT, PIN_8, LOW},
		{SSD1_COMM_PORT, SSD1_COMM_PIN, SSD1_COMM_OFF}
};
/** @defgroup SSD2 Pin Configuration */
ST_SsdPinConfig_t mySSD2_PinConfig[] =
{
		{SSD2_PORT, PIN_1, LOW},
		{SSD2_PORT, PIN_2, LOW},
		{SSD2_PORT, PIN_3, LOW},
		{SSD2_PORT, PIN_4, LOW},
		{SSD2_PORT, PIN_5, LOW},
		{SSD2_PORT, PIN_6, LOW},
		{SSD2_PORT, PIN_7, LOW},
		{SSD2_PORT, PIN_8, LOW},
		{SSD2_COMM_PORT, SSD2_COMM_PIN, SSD2_COMM_OFF}
};


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS PROTOYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void SSD_voidSSD1Initialize(void);
static void SSD_voidSSD2Initialize(void);

static void SSD_voidSetSsdInitPinDirection(u8 Copy_u8SsdID, u8 Copy_SsdPinID);
static void SSD_voidSetSsdInitPinValue(u8 Copy_u8SsdID, u8 Copy_SsdPinID);

#endif /* HAL_SSD_SSD_PRIVATE_H_ */
