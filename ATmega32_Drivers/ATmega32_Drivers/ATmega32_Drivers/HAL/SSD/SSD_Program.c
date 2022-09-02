/*
 * SSD_Program.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Wx
 */


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "SSD_Config.h"
#include "SSD_Private.h"
#include "SSD_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION -- PUBLIC
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup public functions */
void SSD_voidSsdInitalization(u8 Copy_u8SsdID)
{
	switch(Copy_u8SsdID)
	{
		case SSD_1:	SSD_voidSSD1Initialize();
			break;

		case SSD_2:	SSD_voidSSD2Initialize();
			break;

		default: return;
	}
}/** @end SSD_voidSsdInitalization */

void SSD_voidSsdTurnOn(u8 Copy_u8SsdID)
{
	switch(Copy_u8SsdID)
	{
		case SSD_1:	DIO_voidSetPinValue(mySSD1_PinConfig[PIN_COMM].PORT_ID,
										mySSD1_PinConfig[PIN_COMM].PIN_ID,
										SSD1_COMM_ON);
			break;
		case SSD_2:	DIO_voidSetPinValue(mySSD2_PinConfig[PIN_COMM].PORT_ID,
										mySSD2_PinConfig[PIN_COMM].PIN_ID,
										SSD2_COMM_ON);
			break;
		default: return;
	}
}/** @end SSD_voidSsdTurnOn */

void SSD_voidSsdTurnOff(u8 Copy_u8SsdID)
{
	switch(Copy_u8SsdID)
	{
		case SSD_1:	DIO_voidSetPinValue(mySSD1_PinConfig[PIN_COMM].PORT_ID,
										mySSD1_PinConfig[PIN_COMM].PIN_ID,
										SSD1_COMM_OFF);
			break;
		case SSD_2:	DIO_voidSetPinValue(mySSD2_PinConfig[PIN_COMM].PORT_ID,
										mySSD2_PinConfig[PIN_COMM].PIN_ID,
										SSD2_COMM_OFF);
			break;
		default: return;
	}
}/** @end SSD_voidSsdTurnOff */

void SSD_voidSsdSetNumber(u8 Copy_u8SsdID, u8 Copy_u8Number)
{
	cu8 L_u8NumbersLookupTable[] =
								{
									0x3F, /** Equivalent value for: 0 */
									0x06, /** Equivalent value for: 1 */
									0x5B, /** Equivalent value for: 2 */
									0x4F, /** Equivalent value for: 3 */
									0x66, /** Equivalent value for: 4 */
									0x6D, /** Equivalent value for: 5 */
									0x7D, /** Equivalent value for: 6 */
									0x07, /** Equivalent value for: 7 */
									0x7F, /** Equivalent value for: 8 */
									0x6F, /** Equivalent value for: 9 */
									0x77, /** Equivalent value for: A */
									0x7C, /** Equivalent value for: B */
									0x39, /** Equivalent value for: C */
									0x5E, /** Equivalent value for: D */
									0x79, /** Equivalent value for: E */
									0x71  /** Equivalent value for: F */
								};

	switch(Copy_u8SsdID)
	{
		case SSD_1:
#if (SSD1_COMMON == COMMON_CATHODE)
			DIO_voidSetRegisterValue(SSD1_PORT, L_u8NumbersLookupTable[Copy_u8Number]);
#else
			DIO_voidSetRegisterValue(SSD1_PORT, ~L_u8NumbersLookupTable[Copy_u8Number]);
#endif
			break;

		case SSD_2:
#if (SSD2_COMMON == COMMON_CATHODE)
			DIO_voidSetRegisterValue(SSD2_PORT, L_u8NumbersLookupTable[Copy_u8Number]);
#else
			DIO_voidSetRegisterValue(SSD2_PORT, ~L_u8NumbersLookupTable[Copy_u8Number]);
#endif
			break;
		default: return;
	}
}/** @end SSD_voidSsdSetNumber */


void SSD_voidSsdSetPin(u8 Copy_u8SsdID, u8 Copy_u8SsdPin)
{
	cu8 L_u8PinsLookupTable[] =
								{
									0b00000001, /** Equivalent value for pin: a 	*/
									0b00000010, /** Equivalent value for pin: b 	*/
									0b00000100, /** Equivalent value for pin: c 	*/
									0b00001000, /** Equivalent value for pin: d 	*/
									0b00010000, /** Equivalent value for pin: e 	*/
									0b00100000, /** Equivalent value for pin: f 	*/
									0b01000000, /** Equivalent value for pin: g     */
									0b10000000, /** Equivalent value for pin: dot   */
								};
	switch(Copy_u8SsdID)
	{
		case SSD_1:
#if (SSD1_COMMON == COMMON_CATHODE)
			DIO_voidSetRegisterValue(SSD1_PORT, L_u8PinsLookupTable[Copy_u8SsdPin]);
#else
			DIO_voidSetRegisterValue(SSD1_PORT, ~L_u8PinsLookupTable[Copy_u8SsdPin]);
#endif
		break;

		case SSD_2:
#if (SSD1_COMMON == COMMON_CATHODE)
			DIO_voidSetRegisterValue(SSD2_PORT, L_u8PinsLookupTable[Copy_u8SsdPin]);
#else
			DIO_voidSetRegisterValue(SSD2_PORT, ~L_u8PinsLookupTable[Copy_u8SsdPin]);
#endif
			break;
		default: return;
	}
}/** @end SSD_voidSsdSetPin */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS IMPLEMENTATION -- PRIVATE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void SSD_voidSSD1Initialize(void)
{
	u8 L_u8Counter;
	for(L_u8Counter = 0; (L_u8Counter < SSD1_NUM_OF_PINS); ++L_u8Counter)
	{
		SSD_voidSetSsdInitPinDirection(SSD_1, L_u8Counter);
		SSD_voidSetSsdInitPinValue(SSD_1, L_u8Counter);
	}
}/** @end SSD_voidSSD1Initialize */

static void SSD_voidSSD2Initialize(void)
{
	u8 L_u8Counter;
	for(L_u8Counter = 0; (L_u8Counter < SSD1_NUM_OF_PINS); ++L_u8Counter)
	{
		SSD_voidSetSsdInitPinDirection(SSD_2, L_u8Counter);
		SSD_voidSetSsdInitPinValue(SSD_2, L_u8Counter);
	}
}/** @end SSD_voidSSD2Initialize */

static void SSD_voidSetSsdInitPinDirection(u8 Copy_u8SsdID, u8 Copy_SsdPinID)
{
	switch(Copy_u8SsdID)
	{
		case SSD_1:		DIO_voidSetPinDirection(mySSD1_PinConfig[Copy_SsdPinID].PORT_ID,
												mySSD1_PinConfig[Copy_SsdPinID].PIN_ID,
												OUTPUT);
			break;
		case SSD_2:		DIO_voidSetPinDirection(mySSD2_PinConfig[Copy_SsdPinID].PORT_ID,
												mySSD2_PinConfig[Copy_SsdPinID].PIN_ID,
												OUTPUT);
			break;
		default: return;
	}
}/** @end SSD_voidSetSsdInitPinDirection */

static void SSD_voidSetSsdInitPinValue(u8 Copy_u8SsdID, u8 Copy_SsdPinID)
{
	switch(Copy_u8SsdID)
	{
		case SSD_1:		DIO_voidSetPinValue(mySSD1_PinConfig[Copy_SsdPinID].PORT_ID,
											mySSD1_PinConfig[Copy_SsdPinID].PIN_ID,
											mySSD1_PinConfig[Copy_SsdPinID].PIN_STATE);
			break;
		case SSD_2:		DIO_voidSetPinValue(mySSD2_PinConfig[Copy_SsdPinID].PORT_ID,
											mySSD2_PinConfig[Copy_SsdPinID].PIN_ID,
											mySSD2_PinConfig[Copy_SsdPinID].PIN_STATE);
			break;
		default: return;
	}
}/** @end SSD_voidSetSsdInitPinValue */

