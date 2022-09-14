/**
 * @file ADC_Private.h
 * 
 * @author: Mohamed Wx
 * @date Aug 31, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	REGISTERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup addresses */
#define PERIPHERAL_MMIO_OFFSET		( (u8) (0x20) )

/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)			 	( (PERIPHERAL + PERIPHERAL_MMIO_OFFSET) )

#define SFIOR	( *((u8 volatile *)  (MMIO_ADDRESS(0x30))) )
#define ADMUX	( *((u8 volatile *)  (MMIO_ADDRESS(0x07))) )
#define ADCSRA	( *((u8 volatile *)  (MMIO_ADDRESS(0x06))) )
#define ADCH	( *((u8 volatile *)  (MMIO_ADDRESS(0x05))) )
#define ADCL	( *((u8 volatile *)  (MMIO_ADDRESS(0x04))) )

#define ADCD	( *((u16 volatile *) (MMIO_ADDRESS(0x04))) )

typedef u16 (*ADC_CallBackFunctionPointer)(u16 Copy_u8DataValue);
/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define ATMEGA32_ADC_RESOLUTION_BITS 	( (cu8)  (10U)   )
#define ATMEGA32_ADC_RESOLUTION_VALUE 	( (cu16) (1024U) )
#define ATMEGA32_ADC_VCC_AREF			( (cu8)  (5U)    )

#define ADC_QUANTIZATION_STEP			(ATMEGA32_ADC_VCC_AREF / ATMEGA32_ADC_RESOLUTION_VALUE);

enum ADMUXR_BITS
{
	MUX0,
	MUX1,
	MUX2,
	MUX3,
	MUX4,
	ADLAR,
	REFS0,
	REFS1
};

enum ADCSRA_BITS
{
	ADPS0,
	ADPS1,
	ADPS2,
	ADIE,
	ADIF,
	ADATE,
	ADSC,
	ADEN
};


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE STRUCTS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @note inital configuration parameters */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void __vector_16(void) __attribute__((signal, used));

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
