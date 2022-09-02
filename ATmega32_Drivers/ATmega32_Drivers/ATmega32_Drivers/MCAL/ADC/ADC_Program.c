/**
 * @file ADC_Program.c
 * 
 * @author: Mohamed Wx
 * @date Aug 31, 2022
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

#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_Config.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

ADC_CallBackFunctionPointer G_ADC_CallBackFunction = NULL;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void ADC_voidSystemInitilization(void)
{
	/** @def set VREF */
	ADC_voidSetVREF(AVREF_WITH_INTERNAL_VREF_OFF);
	/** @def set Adjustment */
	ADC_voidAdjustmentControl(ADC_RIGHT_ADJUSTMENT);
	/** @def set Initial Prescaler */
	ADC_voidSetPrescaler(PRESCALER_DIV_2);
	/** @def set Inital Interrupt state*/
	ADC_voidInterruptControl(ADC_INTERRUPT_DISABLE);
	/** @def Disable Auto Trigger */
	BIT_CLR(ADCSRA, ADATE);
	/** @def Enable ADC */
	ADC_voidADCControl(ADC_ENABLE);
}/** @end ADC_voidSystemInitilization */

void ADC_voidSetPrescaler(u8 Copy_u8PrescalerID)
{
	ADCSRA &= (~(0b111));
	ADCSRA |= Copy_u8PrescalerID;
}/** @end ADC_voidSetPrescaler */

void ADC_voidSetChannel(u8 Copy_u8ChannelID)
{
	ADMUX &= (~(0b11111));
	ADMUX |= Copy_u8ChannelID;
}/** @end ADC_voidSetChannel */

void ADC_voidADCControl(u8 Copy_u8ADCState)
{
	switch(Copy_u8ADCState)
	{
		case ADC_DISABLE:	BIT_CLR(ADCSRA, ADEN);	break;
		case ADC_ENABLE:	BIT_SET(ADCSRA, ADEN);	break;
		default: break;	/* Error handler */
	}
}/** @end ADC_voidADCControl */

void ADC_voidSetVREF(u8 Copy_u8VREF)
{
	switch(Copy_u8VREF)
	{
		case AVREF_WITH_INTERNAL_VREF_OFF:
							BIT_CLR(ADMUX, REFS0);
							BIT_CLR(ADMUX, REFS1);
			break;
		case AVCC_WITH_EXTERNAL_AREF_CAP:
							BIT_SET(ADMUX, REFS0);
							BIT_CLR(ADMUX, REFS1);
			break;
		case RESERVED:
							BIT_CLR(ADMUX, REFS0);
							BIT_SET(ADMUX, REFS1);
			break;
		case INTERNAL_2V56VREF_WITH_EXTERNAL_AREF_CAP:
							BIT_SET(ADMUX, REFS0);
							BIT_SET(ADMUX, REFS1);
			break;
		default: break;	/* Error handler */
	}
}/** @end voidSetVREF */

void ADC_voidAdjustmentControl(u8 Copy_u8AdjustmentState)
{
	switch(Copy_u8AdjustmentState)
	{
		case ADC_LEFT_ADJUSTMENT:	BIT_SET(ADMUX, ADLAR);	break;
		case ADC_RIGHT_ADJUSTMENT:	BIT_CLR(ADMUX, ADLAR);	break;
		default: break;	/* Error handler */
	}
}/** @end voidAdjustmentControl */

void ADC_voidStartConversion(void)
{
	BIT_SET(ADCSRA, ADSC);
}/** @end voidConversionControl */

void ADC_voidInterruptControl(u8 Copy_u8InterruptState)
{
	switch(Copy_u8InterruptState)
	{
		case ADC_INTERRUPT_DISABLE:	BIT_CLR(ADCSRA, ADIE);	break;
		case ADC_INTERRUPT_ENABLE:	BIT_SET(ADCSRA, ADIE);	break;
		default: break;	/* Error handler */
	}
}/** @end voidInterruptControl */

void ADC_voidGetFlag(u8 *Address_FlagValue)
{
	*Address_FlagValue = BIT_GET(ADCSRA, ADIF);
}/** @end ADC_voidGetFlag */

void ADC_voidClearFlag(void)
{
	BIT_SET(ADCSRA, ADIF);
}/** @end ADC_voidClearFlag */

u8 ADC_u8Data2VoltageCvt(u8 Copy_u8ADC_Data)
{
	u8 L_u8Voltage = 0;

	/** @todo to be modified */
	L_u8Voltage = (((float) ATMEGA32_ADC_VCC_AREF / ATMEGA32_ADC_RESOLUTION_VALUE)) * Copy_u8ADC_Data;

	return L_u8Voltage;
}/** @end ADC_voidGetVoltage */

u16 ADC_u16GetDataSync(u8 Copy_u8ChannelID)
{
	u8 L_u8ConversionDoneFlag = 0;

	ADC_voidSetChannel(Copy_u8ChannelID);

	ADC_voidStartConversion();

	while(L_u8ConversionDoneFlag) { ADC_voidGetFlag(&L_u8ConversionDoneFlag); }

	ADC_voidClearFlag();

	return ADCD;	/** @note return 2-byte ADC data register */
}/** @end ADC_u16GetDataSync */

void ADC_voidGetDataAsync(u8 Copy_u8ChannelID, ADC_CallBackFunctionPointer ADC_CallBackFunction)
{


}/** @end ADC_voidGetDataAsync */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void __vector_16(void)
{
	if( (G_ADC_CallBackFunction != NULL) )
	{
		/** @todo to be added the function */
	}
	else;
}/** @end __vector_13 */
