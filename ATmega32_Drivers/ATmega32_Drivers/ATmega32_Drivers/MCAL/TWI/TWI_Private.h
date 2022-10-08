/**
 * @file TWI_Private.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    REGISTERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup addresses */
#define PERIPHERAL_MMIO_OFFSET      ( (u8) (0x20) )

/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)    ( (PERIPHERAL + PERIPHERAL_MMIO_OFFSET) )


#define TWCR     ( *((u8 volatile *)  (MMIO_ADDRESS(0x36))) )
#define TWDR     ( *((u8 volatile *)  (MMIO_ADDRESS(0x03))) )
#define TWAR     ( *((u8 volatile *)  (MMIO_ADDRESS(0x02))) )
#define TWSR     ( *((u8 volatile *)  (MMIO_ADDRESS(0x01))) )
#define TWBR     ( *((u8 volatile *)  (MMIO_ADDRESS(0x00))) )

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    DEFINES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum TWCR_BITS
{
    TWIE  = 0,
    TWEN  = 2,
    TWWC  = 3,
    TWSTO = 4,
    TWSTA = 5,
    TWEA  = 6,
    TWINT = 7
};

/**
 * @defgroup: Acknologement bit state.
 */
 #define TWI_ACK_ENABLE         (0u)
 #define TWI_ACK_DISABLE        (1u)
/**
 * @defgroup: Prescaler value
 */
 #define TWI_PRESCALER_1        (0u)
 #define TWI_PRESCALER_4        (1u)
 #define TWI_PRESCALER_16       (2u)
 #define TWI_PRESCALER_64       (3u)
/**
 * @defgroup: Acknologement bit state.
 */
 #define TWI_STATE_ENABLE       (0u)
 #define TWI_STATE_DISABLE      (1u)

/**
 * @defgroup: TWI Status code indications.
 * @brief:
 *  TWI Status code is a 5-bit value that indicates several
 *  conditions about the device in action state.
 */
/** @defgroup: Master general status */
#define TWI_STATUS_START_SUCCSESS            (0x08u)
#define TWI_STATUS_RESTART_SUCCSESS          (0x10u)
#define TWI_STATUS_ARBITRATION_LOST          (0x38u)
/** @defgroup: Master Transmitter Status */
#define TWI_STATUS_SLAW_ACK_TRANSMITTED      (0x18u)
#define TWI_STATUS_SLAW_NACK_TRANSMITTED     (0x20u)
#define TWI_STATUS_DATA_ACK_TRANSMITTED      (0x28u)
#define TWI_STATUS_DATA_NACK_TRANSMITTED     (0x30u)
/** @defgroup: Master Transmitter Receiver */
#define TWI_STATUS_SLAR_ACK_RECEIVED         (0x40u)
#define TWI_STATUS_SLAR_NACK_RECEIVED        (0x48u)
#define TWI_STATUS_DATA_ACK_RECEIVED         (0x50u)
#define TWI_STATUS_DATA_NACK_RECEIVED        (0x58u)

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define TWI_ISR  (__vector_19)

void __vector_19(void) __attribute__( (signal, used) );

#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
