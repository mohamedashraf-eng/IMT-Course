/**
 * @file EXTI_Program.c
 * 
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup Horizontal Layer*/
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "../DIO/DIO_Interface.h"	/** @todo to be modified */

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void EXTI_voidInterruptInitalize(u8 Copy_u8InterruptID)
{
	switch(Copy_u8InterruptID)
	{
		case EXTI_INT0:	voidINT0Intailze();	break;
		case EXTI_INT1:	voidINT1Intailze();	break;
		case EXTI_INT2:	voidINT2Intailze();	break;
		default: break; /* Error handler */
	}
}/** @end EXTI_voidInterruptInitalize */

void EXTI_voidInterruptControl(u8 Copy_u8InterruptID, u8 Copy_u8State)
{
	switch(Copy_u8InterruptID)
	{
		case EXTI_INT0:	voidINT0Control(Copy_u8State);	break;
		case EXTI_INT1:	voidINT1Control(Copy_u8State);	break;
		case EXTI_INT2:	voidINT2Control(Copy_u8State);	break;
		default: break; /* Error handler */
	}
}/** @end EXTI_voidInterruptControl */

void EXTI_voidSetInterruptMode(u8 Copy_u8InterruptID, u8 Copy_u8Mode)
{
	switch(Copy_u8InterruptID)
	{
		case EXTI_INT0:	voidINT0SetMode(Copy_u8Mode);	break;
		case EXTI_INT1:	voidINT1SetMode(Copy_u8Mode);	break;
		case EXTI_INT2:	voidINT2SetMode(Copy_u8Mode);	break;
		default: break; /* Error handler */
	}
}/** @end EXTI_voidSetInterruptMode */

void EXTI_voidInterruptFlagReset(u8 Copy_u8InterruptID)
{
	switch(Copy_u8InterruptID)
	{
		case EXTI_INT0:	voidINT0ResetFlag();	break;
		case EXTI_INT1:	voidINT1ResetFlag();	break;
		case EXTI_INT2:	voidINT2ResetFlag();	break;
		default: break; /* Error handler */
	}
}/** @end EXTI_voidInterruptFlagReset */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
static void voidINT0Intailze(void)
{
	DIO_voidSetPinDirection(MyEXTIConfigs.EXTI_INT0_PORT_ID,
							MyEXTIConfigs.EXTI_INT0_PIN_ID,
							INPUT);
	DIO_voidSetPinValue(MyEXTIConfigs.EXTI_INT0_PORT_ID,
						MyEXTIConfigs.EXTI_INT0_PIN_ID,
						LOW);
	voidINT0SetMode(MyEXTIConfigs.EXTI_INT0_MODE);
	BIT_CLR(GICR, INT0);
}/** @end voidINT0Intailze */
static void voidINT1Intailze(void)
{
	DIO_voidSetPinDirection(MyEXTIConfigs.EXTI_INT1_PORT_ID,
							MyEXTIConfigs.EXTI_INT1_PIN_ID,
							INPUT);
	DIO_voidSetPinValue(MyEXTIConfigs.EXTI_INT1_PORT_ID,
						MyEXTIConfigs.EXTI_INT1_PIN_ID,
						LOW);
	voidINT1SetMode(MyEXTIConfigs.EXTI_INT1_MODE);
	BIT_CLR(GICR, INT1);
}/** @end voidINT1Intailze */
static void voidINT2Intailze(void)
{
	DIO_voidSetPinDirection(MyEXTIConfigs.EXTI_INT2_PORT_ID,
							MyEXTIConfigs.EXTI_INT2_PIN_ID,
							INPUT);
	DIO_voidSetPinValue(MyEXTIConfigs.EXTI_INT2_PORT_ID,
						MyEXTIConfigs.EXTI_INT2_PIN_ID,
						LOW);
	voidINT2SetMode(MyEXTIConfigs.EXTI_INT2_MODE);
	BIT_CLR(GICR, INT2);
}/** @end voidINT2Intailze */

static void voidInterrupModetReset(void)
{
	BIT_CLR(MCUCR, ISC00);
	BIT_CLR(MCUCR, ISC01);
}/** @end voidInterrupModetReset */

static void voidINT0SetMode(u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case EXTI_LOW_LEVEL:
							voidInterrupModetReset();
							BIT_CLR(MCUCR, ISC00);
							BIT_CLR(MCUCR, ISC01);
						break;
		case EXTI_LOGICAL_CHANGE:
							voidInterrupModetReset();
							BIT_SET(MCUCR, ISC00);
							BIT_CLR(MCUCR, ISC01);
						break;
		case EXTI_FALLING_EDGE:
							voidInterrupModetReset();
							BIT_CLR(MCUCR, ISC00);
							BIT_SET(MCUCR, ISC01);
						break;
		case EXTI_RISING_EDGE:
							voidInterrupModetReset();
							BIT_SET(MCUCR, ISC00);
							BIT_SET(MCUCR, ISC01);
						break;
		default: break; /* Error handler */
	}
}/** @end voidINT0SetMode */
static void voidINT1SetMode(u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case EXTI_LOW_LEVEL:
							voidInterrupModetReset();
							BIT_CLR(MCUCR, ISC10);
							BIT_CLR(MCUCR, ISC11);
						break;
		case EXTI_LOGICAL_CHANGE:
							voidInterrupModetReset();
							BIT_SET(MCUCR, ISC10);
							BIT_CLR(MCUCR, ISC11);
						break;
		case EXTI_FALLING_EDGE:
							voidInterrupModetReset();
							BIT_CLR(MCUCR, ISC10);
							BIT_SET(MCUCR, ISC11);
						break;
		case EXTI_RISING_EDGE:
							voidInterrupModetReset();
							BIT_SET(MCUCR, ISC10);
							BIT_SET(MCUCR, ISC11);
						break;
		default: break; /* Error handler */
	}
}/** @end voidINT1SetMode */
static void voidINT2SetMode(u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case EXTI_FALLING_EDGE:	BIT_CLR(MCUCSR, ISC2);	break;
		case EXTI_RISING_EDGE: 	BIT_SET(MCUCSR, ISC2);	break;
		default: break; /* Error handler */
	}
}/** @end voidINT2SetMode */


static void voidINT0Control(u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
		case EXTI_Disable:	BIT_CLR(GICR, INT0);	break;
		case EXTI_Enable:	BIT_SET(GICR, INT0);	break;
		default: break; /* Error handler */
	}
}/** @end voidINT0Control */
static void voidINT1Control(u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
		case EXTI_Disable:	BIT_CLR(GICR, INT1);	break;
		case EXTI_Enable:	BIT_SET(GICR, INT1);	break;
		default: break; /* Error handler */
	}
}/** @end voidINT1Control */
static void voidINT2Control(u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
		case EXTI_Disable:	BIT_CLR(GICR, INT2);	break;
		case EXTI_Enable:	BIT_SET(GICR, INT2);	break;
		default: break; /* Error handler */
	}
}/** @end voidINT2Control */

static void voidINT0ResetFlag(void)
{
	BIT_CLR(GIFR, INTF0);
}/** @end voidINT0ResetFlag */
static void voidINT1ResetFlag(void)
{
	BIT_CLR(GIFR, INTF1);
}/** @end voidINT1ResetFlag */
static void voidINT2ResetFlag(void)
{
	BIT_CLR(GIFR, INTF2);
}/** @end voidINT2ResetFlag */


