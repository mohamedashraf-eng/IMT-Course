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
 * -																	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/



/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup addresses */
#define DIO_PERIPHERAL_BASE_ADDRESS		( (cu8) (0x10) )
#define DIO_PERIPHERAL_REG_OFFSET		( (cu8) (0x01) )
#define DIO_PERIPHERAL_MMIO_OFFSET		( (cu8) (0x20) )

/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)			 	( (PERIPHERAL + DIO_PERIPHERAL_MMIO_OFFSET) )
#define DIO_PERIPHERAL_ADDRRESS(ADDRESS)		( (ADDRESS + DIO_PERIPHERAL_REG_OFFSET)     )

/** @defgroup PORTA Registers */
#define DDRA	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PORTA)))) )
#define PORTA	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PINA))))  )
#define PINA	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(DDRB))))  )

/** @defgroup PORTB Registers */
#define DDRB	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PORTB)))) )
#define PORTB	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PINB))))  )
#define PINB	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(DDRC))))  )


/** @defgroup PORTC Registers */
#define DDRC	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PORTC)))) )
#define PORTC	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PINC))))  )
#define PINC	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(DDRD))))  )


/** @defgroup PORTD Registers */
#define DDRD	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PORTD)))) )
#define PORTD	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_ADDRRESS(PIND))))  )
#define PIND	( *((u8 volatile * const) (MMIO_ADDRESS(DIO_PERIPHERAL_BASE_ADDRESS))) 	  )


#endif /* MCAL_DIO_DIO_CONFIG_H_ */
