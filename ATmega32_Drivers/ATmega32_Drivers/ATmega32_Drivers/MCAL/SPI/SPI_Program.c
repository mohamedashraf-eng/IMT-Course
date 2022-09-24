/**
 * @file SPI_Program.c
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup Horizontal Layer*/
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

#include "SPI_Private.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void SPI_voidInit(void)
{
/**
 * @defgroup: SPI Data Order Setup
 */
#if   (SPI_DATAxORDER == SPI_DATAxORDER_MSB)
    BIT_SET(SPCR, DORD);
#elif (SPI_DATAxORDER == SPI_DATAxORDER_LSB)
    BIT_CLR(SPCR, DORD);
#else
    #warning ("Invalid SPI DATA ORDER Selected!")
    /** @def: Set to the default */
    BIT_SET(SPCR, DORD);
#endif
/**
 * @defgroup: SPI Mode Setup
 */
#if   (SPI_MODE == SPI_MODE_MASTER)
    BIT_SET(SPCR, MSTR);
#elif (SPI_MODE == SPI_MODE_SLAVE)
    BIT_CLR(SPCR, MSTR);
#else
    #warning ("Invalid SPI MODE Selected!")
    /** @def: Set to the default */
    BIT_SET(SPCR, MSTR);
#endif
/**
 * @defgroup: SPI Clock Polarity
 */
#if   (SPI_CLOCKxPOLARITY == SPI_CLOCKxPOLARITY_FALLING)
    BIT_SET(SPCR, CPOL);
#elif (SPI_CLOCKxPOLARITY == SPI_CLOCKxPOLARITY_RISING)
    BIT_CLR(SPCR, CPOL);
#else
    #warning ("Invalid SPI CLOCK POLARITY Selected!")
    /** @def: Set to the default */
    BIT_SET(SPCR, CPOL);
#endif
/**
 * @defgroup: SPI Clock Phase
 */
#if   (SPI_CLOCKxPHASE == SPI_CLOCKxPHASE_LEADING)
    BIT_CLR(SPCR, CPHA);
#elif (SPI_CLOCKxPHASE == SPI_CLOCKxPHASE_TRAILING)
    BIT_SET(SPCR, CPHA);
#else
    #warning ("Invalid SPI CLOCK PHASE Selected!")
    /** @def: Set to the default */
    BIT_CLR(SPCR, CPHA);
#endif
/**
 * @defgroup: SPI Clock Rate
 */
#if   (SPI_CLOCKxRATE == SPI_CLOCKxRATE_DIV_2)
    BIT_CLR(SPCR, SPR0);
    BIT_CLR(SPCR, SPR1);
    BIT_SET(SPSR, SPI2X);
#elif (SPI_CLOCKxRATE == SPI_CLOCKxRATE_DIV_4)
    BIT_CLR(SPCR, SPR0);
    BIT_CLR(SPCR, SPR1);
    BIT_CLR(SPSR, SPI2X);
#elif (SPI_CLOCKxRATE == SPI_CLOCKxRATE_DIV_8)
    BIT_SET(SPCR, SPR0);
    BIT_CLR(SPCR, SPR1);
    BIT_SET(SPSR, SPI2X);
#elif (SPI_CLOCKxRATE == SPI_CLOCKxRATE_DIV_16)
    BIT_SET(SPCR, SPR0);
    BIT_CLR(SPCR, SPR1);
    BIT_CLR(SPSR, SPI2X);
#elif (SPI_CLOCKxRATE == SPI_CLOCKxRATE_DIV_32)
    BIT_CLR(SPCR, SPR0);
    BIT_SET(SPCR, SPR1);
    BIT_SET(SPSR, SPI2X);
#elif (SPI_CLOCKxRATE == SPI_CLOCKxRATE_DIV_64)
    BIT_CLR(SPCR, SPR0);
    BIT_SET(SPCR, SPR1);
    BIT_CLR(SPSR, SPI2X);
#elif (SPI_CLOCKxRATE == SPI_CLOCKxRATE_DIV_128)
    BIT_SET(SPCR, SPR0);
    BIT_SET(SPCR, SPR1);
    BIT_CLR(SPSR, SPI2X);
#else
    #warning ("Invalid SPI CLOCK RATE Selected!")
    /** @def: Set to the default */
    BIT_CLR(SPCR, SPR0);
    BIT_CLR(SPCR, SPR1);
    BIT_CLR(SPSR, SPI2X);
#endif
/**
 * @defgroup: SPI State
 */
#if   (SPI_STATE == SPI_STATE_DISABLE)
    BIT_CLR(SPCR, SPE);
#elif (SPI_STATE == SPI_STATE_ENABLE)
    BIT_SET(SPCR, SPE);
#else
    #warning ("Invalid SPI CLOCK STATE Selected!")
    /** @def: Set to the default */
    BIT_CLR(SPCR, SPE);
#endif
}/** @end SPI_voidInit */

void SPI_voidTransmitDataSync(cu8 Copy_cu8DataToTransmit)
{
    /** @def: Start the transmission */
    REG_WRT(SPDR, Copy_cu8DataToTransmit);
    /** @def: Wait for the transmission to complete */
    while( (0 == BIT_GET(SPSR, SPIF)) ) {;}
}/** @end SPI_voidTransmitDataSync */

void SPI_voidReceiveDataSync(u8 *Copy_cu8DataToReceive)
{
    /** @def: Wait for the Reception to complete */
    while( (0 == BIT_GET(SPSR, SPIF)) ) {;}
    /** @def: Get the data */
    (*Copy_cu8DataToReceive) = SPDR;
}/** @end SPI_voidReceiveDataSync */

void SPI_voidTransmitStreamSync(cu8 *Address_cu8StreamToTransmit, cu8 Copy_cu8StreamSize)
{
    u8 L_u8StreamIterator = 0;

    for(L_u8StreamIterator = 0; (L_u8StreamIterator < Copy_cu8StreamSize); ++L_u8StreamIterator)
    {
        SPI_voidTransmitDataSync(Address_cu8StreamToTransmit[L_u8StreamIterator]);
    }
}/** @end SPI_voidTransmitStreamSync */

void SPI_voidReceiveStreamSync(u8 *Address_cu8StreamReceiveBuffer, cu8 Copy_cu8StreamSize)
{
    u8 L_u8StreamIterator = 0;

    for(L_u8StreamIterator = 0; (L_u8StreamIterator < Copy_cu8StreamSize); ++L_u8StreamIterator)
    {
        SPI_voidReceiveDataSync(&Address_cu8StreamReceiveBuffer[L_u8StreamIterator]);
    }
}/** @end SPI_voidReceiveStreamSync */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void ISR_SPI_STC(void)
{
    /** @def: If spi is slave */
}/** @end ISR_SPI_STC */
