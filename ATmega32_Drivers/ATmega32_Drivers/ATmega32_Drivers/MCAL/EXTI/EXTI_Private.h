/**
 * @file EXTI_Private.h
 * 
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	REGISTERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define NUM_OF_EXTI ( (u8) (3) )

/** @defgroup addresses */
#define PERIPHERAL_MMIO_OFFSET		( (u8) (0x20) )

/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)			 	( (PERIPHERAL + PERIPHERAL_MMIO_OFFSET) )

#define GICR	( *((u8 volatile *) (MMIO_ADDRESS(0x3B))) )
#define GIFR	( *((u8 volatile *) (MMIO_ADDRESS(0x3A))) )
#define MCUCR	( *((u8 volatile *) (MMIO_ADDRESS(0x35))) )
#define MCUCSR	( *((u8 volatile *) (MMIO_ADDRESS(0x34))) )

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum MCUCR_BITS
{
	ISC00,
	ISC01,
	ISC10,
	ISC11
}; /** @note the other bits are not used in this peripheral */

enum MCUCSR_BITS
{
	ISC2 = 6
}; /** @note the other bits are not used in this peripheral */

enum GICR_BITS
{
	INT0 = 6,
	INT1 = 7,
	INT2 = 5
}; /** @note the other bits are not used in this peripheral */

enum GIFR_BITS
{
	INTF0 = 6,
	INTF1 = 7,
	INTF2 = 5
}; /** @note the other bits are not used in this peripheral */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE STRUCTS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

typedef struct
{
	u8 EXTI_INT0_PORT_ID;
	u8 EXTI_INT0_PIN_ID;

	u8 EXTI_INT1_PORT_ID;
	u8 EXTI_INT1_PIN_ID;

	u8 EXTI_INT2_PORT_ID;
	u8 EXTI_INT2_PIN_ID;

	u8 EXTI_INT0_MODE;
	u8 EXTI_INT1_MODE;
	u8 EXTI_INT2_MODE;
}ST_EXTIConfig_t;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup General Functions */
static void voidINT0Intailze(void);
static void voidINT1Intailze(void);
static void voidINT2Intailze(void);

static void voidINT0SetMode(u8 Copy_u8Mode);
static void voidINT1SetMode(u8 Copy_u8Mode);
static void voidINT2SetMode(u8 Copy_u8Mode);

static void voidINT0Control(u8 Copy_u8State);
static void voidINT1Control(u8 Copy_u8State);
static void voidINT2Control(u8 Copy_u8State);

static void voidINT0ResetFlag(void);
static void voidINT1ResetFlag(void);
static void voidINT2ResetFlag(void);

/** @defgroup ISR Functions */	/** @note Compiler Optimization */
void __vector_1(void) __attribute__( (signal, used) );	/** @def EXTI0 */
void __vector_2(void) __attribute__( (signal, used) );	/** @def EXTI1 */
void __vector_3(void) __attribute__( (signal, used) );	/** @def EXTI2 */


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
