/**
 * @file TWI_Program.c
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

#include "TWI_Private.h"
#include "TWI_Config.h"
#include "TWI_Interface.h"

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

void TWI_voidInit(void)
{
/**
 * @def: Setting the acknolgment bit.
 */
#if   (TWI_ACK_STATE == TWI_ACK_DISABLE)
    BIT_CLR(TWCR, TWEA);
#elif (TWI_ACK_STATE == TWI_ACK_ENABLE)
    BIT_SET(TWCR, TWEA);
#else
    /** @def: Setting the default value */
    #warning ("INVALID TWI ACK BIT!")
    BIT_CLR(TWCR, TWEA);
#endif
/**
 * @def: Setting the prescaler
 */
    TWSR &= (~(0b11));
    TWSR |= (TWI_PRESCALER);
/**
 * @def: Setting the bit rate.
 */
    TWBR &= (~(0xFFU));
    TWBR |= (TWI_BITRATE_VALUE);
/**
 * @def: Setting the device slave address.
 */
    TWAR &= (~(0xFFU));
    TWAR |= (TWI_DEVICE_SLAVE_ADDRESS);
    TWAR &= (~(0xFEU)); /** @brief: Disabling the General call */
/**
 * @def: Setting TWI periphral state
 */
#if   (TWI_STATE == TWI_STATE_DISABLE)
    BIT_CLR(TWCR, TWEN);
#elif (TWI_STATE == TWI_STATE_ENABLE)
    BIT_SET(TWCR, TWEN);
#else
    /** @def: Setting the default value */
    #warning ("INVALID TWI STATE!")
    BIT_CLR(TWCR, TWEN);
#endif
}/** @end TWI_voidInit*/

void TWI_voidTransmitDataSync(u16 Copy_u16SlaveAddress, u8 Copy_u8DataToTransmit)
{
    /** def: Send a start bit */
    BIT_SET(TWCR, TWSTA);
    /** @def: Wait for the flag to be set.
     */
    while( !(BIT_GET(TWCR, TWINT)) ) {;}
    /** @def: Clear the flag by setting it */
    BIT_SET(TWCR, TWINT);

    /** @def: Check if the start condition is sent successfully. */
    if( !(TWI_STATUS_START_SUCCSESS == TWI_u8GetStatus()) )
    { /** @todo: Handle the error */ }
    else { ; }
    BIT_CLR(TWCR, TWSTA);

    /** @def: Load the SLA+W */
    REG_WRT(TWDR, (u8) (Copy_u16SlaveAddress & 0xFEU));
    /** @def: Wait for the flag to be set.
     */
    while( !(BIT_GET(TWCR, TWINT)) ) {;}
    /** @def: Clear the flag by setting it */
    BIT_SET(TWCR, TWINT);
    /** @def: Check if the SLA+W packet is sent successfully. */
    if( (TWI_STATUS_SLAW_ACK_TRANSMITTED != TWI_u8GetStatus()) ||
        (TWI_STATUS_SLAW_NACK_TRANSMITTED != TWI_u8GetStatus()) )
    { /** @todo: Handle the error */ ;}
    else if( (TWI_STATUS_SLAW_NACK_TRANSMITTED == TWI_u8GetStatus()) )
    { /** @todo: Handle the error */ ;}
    else { ; }

    /** @def: Writing the data to be transmit */
    REG_WRT(TWDR, Copy_u8DataToTransmit);
    /** @def: Wait for the flag to be set.
     */
    while( !(BIT_GET(TWCR, TWINT)) ) {;}
    /** @def: Clear the flag by setting it */
    BIT_SET(TWCR, TWINT);
    /** @def: Check if the SLA+W packet is sent successfully. */
    if( (TWI_STATUS_DATA_ACK_TRANSMITTED != TWI_u8GetStatus()) ||
        (TWI_STATUS_DATA_NACK_TRANSMITTED != TWI_u8GetStatus()) )
    { /** @todo: Handle the error */ ;}
    else if( (TWI_STATUS_DATA_NACK_TRANSMITTED == TWI_u8GetStatus()) )
    { /** @todo: Handle the error */  ;}
    else { ; }

    /** @def: Send a stop bit. */
    BIT_SET(TWCR, TWSTO);
}/** @end TWI_voidTransmitDataSync*/

void TWI_voidReceiveDataSync(u16 Copy_u16SlaveAddress, u8 Copy_u8DataToReceive)
{

}/** @end TWI_voidReceiveDataSync*/

u8 TWI_u8GetStatus(void)
{
    return ( (TWSR & 0xF8U) );
}/** @end TWI_voidGetStatus */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void TWI_ISR(void)
{

}/** @end TWI_ISR */

