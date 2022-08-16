/**
 * @file DIO_Config.h
 * @brief
 * @author Mohamed Wx
 * @date 15/08/2022
 *
 */
/** @def Header Guards */
#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/



/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup addresses */
#define DIO_PERIPHERAL_BASE_ADDRESS		( (u8) (0x10) )
#define DIO_PERIPHERAL_REG_OFFSET		( (u8) (0x01) )
#define DIO_PERIPHERAL_MMIO_OFFSET		( (u8) (0x20) )

/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)			 	( (PERIPHERAL + DIO_PERIPHERAL_MMIO_OFFSET) )
#define DIO_PERIPHERAL_ADDRRESS(ADDRESS)		( (ADDRESS + DIO_PERIPHERAL_REG_OFFSET)     )

/** @defgroup PORTA Registers */
#define DDRA	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PORTA) ))) )
#define PORTA	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PINA) )))  )
#define PINA	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(DDRB) )))  )

/** @defgroup PORTB Registers */
#define DDRB	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PORTB) ))) )
#define PORTB	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PINB) )))  )
#define PINB	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(DDRC) )))  )


/** @defgroup PORTC Registers */
#define DDRC	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PORTC )))) )
#define PORTC	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PINC) )))  )
#define PINC	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(DDRD) )))  )


/** @defgroup PORTD Registers */
#define DDRD	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PORTD) ))) )
#define PORTD	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PIND) )))  )
#define PIND	( *((u8 volatile * const) ( MMIO_ADDRESS(DIO_PERIPHERAL_BASE_ADDRESS) ))    )

/** @def Pointer Array */
#define NUM_OF_PORTS		( (cu8) (4) )
#define NUM_OF_REGISTERS	( (cu8) (3) )
#define PORT_PIN_NUM		( (cu8) (8)	)

enum GPIOS_REGISTERS
{
	GPIO_PIND	= DIO_PERIPHERAL_BASE_ADDRESS,
	GPIO_PORTD,
	GPIO_DDRD,
	GPIO_PINC,
	GPIO_PORTC,
	GPIO_DDRC,
	GPIO_PINB,
	GPIO_PORTB,
	GPIO_DDRB,
	GPIO_PINA,
	GPIO_PORTA,
	GPIO_DDRA
};

u8 volatile * const GPIOX_ADDRS[NUM_OF_PORTS * NUM_OF_REGISTERS] =
{
		(u8 volatile *) (GPIO_DDRA),  /** @def base address of DDRA  */
		(u8 volatile *) (GPIO_PORTA), /** @def base address of PORTA */
		(u8 volatile *) (GPIO_PINA),  /** @def base address of PINA  */

		(u8 volatile *) (GPIO_DDRB),  /** @def base address of DDRB  */
		(u8 volatile *) (GPIO_PORTB), /** @def base address of PORTB */
		(u8 volatile *) (GPIO_PINB),  /** @def base address of PINB  */

		(u8 volatile *) (GPIO_DDRC),  /** @def base address of DDRC  */
		(u8 volatile *) (GPIO_PORTC), /** @def base address of PORTC */
		(u8 volatile *) (GPIO_PINC),  /** @def base address of PINC  */

		(u8 volatile *) (GPIO_DDRD),  /** @def base address of DDRBD */
		(u8 volatile *) (GPIO_PORTD), /** @def base address of PORTD */
};

#endif /* MCAL_DIO_DIO_CONFIG_H_ */
