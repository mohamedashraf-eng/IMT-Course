/**
 * @file ADC_Interface.h
 * 
 * @author: Mohamed Wx
 * @date Aug 31, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum ADC_VREF
{
	AVREF_WITH_INTERNAL_VREF_OFF,
	AVCC_WITH_EXTERNAL_AREF_CAP,
	RESERVED,
	INTERNAL_2f56VREF_WITH_EXTERNAL_AREF_CAP
};

enum ADC_CHANNELS
{
	ADC_CHANNEL0	= 0b00000,
	ADC_CHANNEL1	= 0b00001,
	ADC_CHANNEL2	= 0b00010,
	ADC_CHANNEL3	= 0b00011,
	ADC_CHANNEL4	= 0b00100,
	ADC_CHANNEL5	= 0b00101,
	ADC_CHANNEL6	= 0b00110,
	ADC_CHANNEL7	= 0b00111
};

enum ADC_PRESCALER
{
	PRESCALER_DIV_2		= 0b001,
	PRESCALER_DIV_4		= 0b010,
	PRESCALER_DIV_8		= 0b011,
	PRESCALER_DIV_16	= 0b100,
	PRESCALER_DIV_32	= 0b101,
	PRESCALER_DIV_64	= 0b110,
	PRESCALER_DIV_128	= 0b111
};

enum ADC_LR_ADJUSTMENT
{
	ADC_LEFT_ADJUSTMENT,
	ADC_RIGHT_ADJUSTMENT
};

enum ADC_INTERRUPT_CONTROL
{
	ADC_INTERRUPT_ENABLE,
	ADC_INTERRUPT_DISABLE
};


enum ADC_STATE
{
	ADC_ENABLE,
	ADC_DISABLE
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup Settings Functions */
void ADC_voidSystemInitilization(void);
void ADC_voidSetPrescaler(u8 Copy_u8PrescalerID);
void ADC_voidSetChannel(u8 Copy_u8ChannelID);
void ADC_voidSetVREF(u8 Copy_u8VREF);
void ADC_voidAdjustmentControl(u8 Copy_u8AdjustmentState);
void ADC_voidStartConversion(void);
void ADC_voidInterruptControl(u8 Copy_u8InterruptState);
void ADC_voidADCControl(u8 Copy_u8ADCState);
void ADC_voidGetFlag(u8 *Address_FlagValue);
void ADC_voidClearFlag(void);

/** @defgroup Action Functions */
u16 ADC_u16GetDataSync(u8 Copy_u8ChannelID);
void ADC_voidGetDataAsync(u8 Copy_u8ChannelID, ADC_CallBackFunctionPointer ADC_CallBackFunction);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
