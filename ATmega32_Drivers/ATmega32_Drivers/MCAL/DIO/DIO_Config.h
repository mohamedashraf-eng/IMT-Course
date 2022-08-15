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
#define PERIPHERAL_MMIO_OFFSET		( (cu8) (0x20) )
#define PERIPHERAL_REG_OFFSET		( (cu8) (0x01) )
/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)	( (PERIPHERAL + PERIPHERAL_MMIO_OFFSET) )

/** @defgroup PORTA Registers */
#define DDRA	( *((volatile u8 *) (MMIO_ADDRESS(0x1B))) )
#define PORTA	( *((volatile u8 *) (MMIO_ADDRESS(0x1A))) )
#define PINA	( *((volatile u8 *) (MMIO_ADDRESS(0x19))) )

/** @defgroup PORTB Registers */
#define DDRB	( *((volatile u8 *) (MMIO_ADDRESS(0x18))) )
#define PORTB	( *((volatile u8 *) (MMIO_ADDRESS(0x17))) )
#define PINB	( *((volatile u8 *) (MMIO_ADDRESS(0x16))) )


/** @defgroup PORTC Registers */
#define DDRC	( *((volatile u8 *) (MMIO_ADDRESS(0x15))) )
#define PORTC	( *((volatile u8 *) (MMIO_ADDRESS(0x14))) )
#define PINC	( *((volatile u8 *) (MMIO_ADDRESS(0x13))) )


/** @defgroup PORTD Registers */
#define DDRD	( *((volatile u8 *) (MMIO_ADDRESS(0x12))) )
#define PORTD	( *((volatile u8 *) (MMIO_ADDRESS(0x11))) )
#define PIND	( *((volatile u8 *) (MMIO_ADDRESS(0x10))) )


#endif /* MCAL_DIO_DIO_CONFIG_H_ */
