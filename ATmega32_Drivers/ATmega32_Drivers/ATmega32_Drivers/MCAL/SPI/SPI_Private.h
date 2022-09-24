/**
 * @file SPI_Private.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    REGISTERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup addresses */
#define PERIPHERAL_MMIO_OFFSET      ( (u8) (0x20) )

/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)    ( (PERIPHERAL + PERIPHERAL_MMIO_OFFSET) )

#define SPCR   ( *((u8 volatile *)  (MMIO_ADDRESS(0x0D))) )
#define SPSR   ( *((u8 volatile *)  (MMIO_ADDRESS(0x0E))) )
#define SPDR   ( *((u8 volatile *)  (MMIO_ADDRESS(0x0F))) )

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    DEFINES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum SPCR_BITS
{
    SPR0,
    SPR1,
    CPHA,
    CPOL,
    MSTR,
    DORD,
    SPE,
    SPIE
};

enum SPSR_BITS
{
    SPI2X = 0,
    WCOL  = 6,
    SPIF  = 7
};

/** @defgroup: SPI DATA ORDER */
#define SPI_DATAxORDER_MSB              (0u)
#define SPI_DATAxORDER_LSB              (1u)
/** @defgroup: SPI MODE */
#define SPI_MODE_MASTER                 (0u)
#define SPI_MODE_SLAVE                  (1u)
/** @defgroup: SPI CLOCK POLARITY */
#define SPI_CLOCKxPOLARITY_RISING       (0u)
#define SPI_CLOCKxPOLARITY_FALLING      (1u)
/** @defgroup: CLOCK PHASE */
#define SPI_CLOCKxPHASE_LEADING         (0u)
#define SPI_CLOCKxPHASE_TRAILING        (1u)
/** @defgroup: SPI CLOCK RATE */
#define SPI_CLOCKxRATE_DIV_2            (0u)
#define SPI_CLOCKxRATE_DIV_4            (1u)
#define SPI_CLOCKxRATE_DIV_8            (2u)
#define SPI_CLOCKxRATE_DIV_16           (3u)
#define SPI_CLOCKxRATE_DIV_32           (4u)
#define SPI_CLOCKxRATE_DIV_64           (5u)
#define SPI_CLOCKxRATE_DIV_128          (6u)
/** @defgroup: SPI STATE */
#define SPI_STATE_ENABLE                (0u)
#define SPI_STATE_DISABLE               (1u)

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup: ISR */
#define ISR_SPI_STC  ( __vector_12 )

void __vector_12(void) __attribute__( (signal, used) );


#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
