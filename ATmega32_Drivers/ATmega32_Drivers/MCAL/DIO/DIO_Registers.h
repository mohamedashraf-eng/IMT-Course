/*
 * DIO_Registers.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Wx
 */

#ifndef MCAL_DIO_DIO_REGISTERS_H_
#define MCAL_DIO_DIO_REGISTERS_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup addresses */
//#define DIO_PERIPHERAL_BASE_ADDRESS		( (u8) (0x10) )
#define DIO_PERIPHERAL_MMIO_OFFSET		( (u8) (0x20) )
//#define DIO_PERIPHERAL_REG_OFFSET		( (u8) (0x01) )

/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)			 	( (PERIPHERAL + DIO_PERIPHERAL_MMIO_OFFSET) )
//#define DIO_PERIPHERAL_ADDRRESS(ADDRESS)		( (ADDRESS + DIO_PERIPHERAL_REG_OFFSET)     )

/** @defgroup PORTA Registers */
#define PORTA	( *((u8 volatile *) ( MMIO_ADDRESS(0x1B)))  )
#define DDRA	( *((u8 volatile *) ( MMIO_ADDRESS(0x1A)))  )
#define PINA	( *((u8 volatile *) ( MMIO_ADDRESS(0x19)))  )

/** @defgroup PORTB Registers */
#define PORTB	( *((u8 volatile *) ( MMIO_ADDRESS(0x18)))  )
#define DDRB	( *((u8 volatile *) ( MMIO_ADDRESS(0x17)))  )
#define PINB	( *((u8 volatile *) ( MMIO_ADDRESS(0x16)))  )


/** @defgroup PORTC Registers */
#define PORTC	( *((u8 volatile *) ( MMIO_ADDRESS(0x15)))  )
#define DDRC	( *((u8 volatile *) ( MMIO_ADDRESS(0x14)))  )
#define PINC	( *((u8 volatile *) ( MMIO_ADDRESS(0x13)))  )

/** @defgroup PORTD Registers */
#define PORTD	( *((u8 volatile *) ( MMIO_ADDRESS(0x12))) )
#define DDRD	( *((u8 volatile *) ( MMIO_ADDRESS(0x11))) )
#define PIND	( *((u8 volatile *) ( MMIO_ADDRESS(0x10))) )

/* @def Pointer Array */
#define NUM_OF_PORTS		( (cu8) (4) )
#define NUM_OF_REGISTERS	( (cu8) (3) )
#define PORT_PIN_NUM		( (cu8) (8)	)

//
//enum GPIOS_REGISTERS_ADDRESS
//{
//	GPIO_PIND	= DIO_PERIPHERAL_BASE_ADDRESS,
//	GPIO_PORTD,
//	GPIO_DDRD,
//
//	GPIO_PINC,
//	GPIO_PORTC,
//	GPIO_DDRC,
//
//	GPIO_PINB,
//	GPIO_PORTB,
//	GPIO_DDRB,
//
//	GPIO_PINA,
//	GPIO_PORTA,
//	GPIO_DDRA
//};
//
//enum GPIOS_REGISTERS_ID
//{
//	DDRA,
//	PORTA,
//	PINA,
//	DDRB,
//	PORTB,
//	PINB,
//	DDRC,
//	PORTC,
//	PINC,
//	DDRD,
//	PORTD,
//	PIND
//};
//
//u8 volatile * const GPIOX_ADDRS[NUM_OF_PORTS * NUM_OF_REGISTERS] =
//{
//		(u8 volatile * const) (GPIO_DDRA),  /** @def base address of DDRA  */
//		(u8 volatile * const) (GPIO_PORTA), /** @def base address of PORTA */
//		(u8 volatile * const) (GPIO_PINA),  /** @def base address of PINA  */
//
//		(u8 volatile * const) (GPIO_DDRB),  /** @def base address of DDRB  */
//		(u8 volatile * const) (GPIO_PORTB), /** @def base address of PORTB */
//		(u8 volatile * const) (GPIO_PINB),  /** @def base address of PINB  */
//
//		(u8 volatile * const) (GPIO_DDRC),  /** @def base address of DDRC  */
//		(u8 volatile * const) (GPIO_PORTC), /** @def base address of PORTC */
//		(u8 volatile * const) (GPIO_PINC),  /** @def base address of PINC  */
//
//		(u8 volatile * const) (GPIO_DDRD),  /** @def base address of DDRBD */
//		(u8 volatile * const) (GPIO_PORTD), /** @def base address of PORTD */
//};


#endif /* MCAL_DIO_DIO_REGISTERS_H_ */
