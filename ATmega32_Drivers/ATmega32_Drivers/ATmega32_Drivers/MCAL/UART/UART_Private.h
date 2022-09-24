/**
 * @file uart_Private.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    REGISTERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup addresses */
#define PERIPHERAL_MMIO_OFFSET      ( (u8) (0x20) )

/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)    ( (PERIPHERAL + PERIPHERAL_MMIO_OFFSET) )

#define UDR     ( *((u8 volatile *)  (MMIO_ADDRESS(0x0C))) )
#define UCSRA   ( *((u8 volatile *)  (MMIO_ADDRESS(0x0B))) )
#define UCSRB   ( *((u8 volatile *)  (MMIO_ADDRESS(0x0A))) )
#define UCSRC   ( *((u8 volatile *)  (MMIO_ADDRESS(0x20))) )
#define UBRRH   ( *((u8 volatile *)  (MMIO_ADDRESS(0x20))) )
#define UBRRL   ( *((u8 volatile *)  (MMIO_ADDRESS(0x09))) )
//#define UBRR    ( *((u16 volatile *) (MMIO_ADDRESS(0x00))) )


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    DEFINES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define UART_MAX_BUFFER_SIZE			(32u)

enum UCSRA_BITS
{
    MPCM,
    U2X,
    PE,
    DOR,
    FE,
    UDRE,
    TXC,
    RXC
};

enum UCSRB_BITS
{
    TXB8,
    RXB8,
    UCSZ2,
    TXEN,
    RXEN,
    UDRIE,
    TXCIE,
    RXCIE
};

enum UCSRC_BITS
{
    UPOL,
    UCSZ0,
    UCSZ1,
    USBS,
    UPM0,
    UPM1,
    UMSEL,
    URSEL
};

/** @defgroup: UART_MODE */
#define UART_TRANSMITTER_MODE           (0u)
#define UART_RECEIVER_MODE              (1u)
#define UART_TRANSMITTERxRECEIVER_MODE  (2u)
/** @defgroup: UART_STATE */
#define UART_DISABLED                   (0u)
#define UART_ENABLED                    (1u)
/** @defgroup: UART_BAUDRATE */
 /** @defgroup: F_CLK: 4Mhz setup */
	/** @note: Normal Speed Mode */
#define UART_N_f4Mhz_BAUDRATE_9600bps   (25u)
#define UART_N_f4Mhz_BAUDRATE_57600bps  (3u)
#define UART_N_f4Mhz_BAUDRATE_115200bps (1u)
#define UART_N_f4Mhz_BAUDRATE_250000bps (0u)
    /** @note: 2X Speed Mode */
#define UART_2X_f4Mhz_BAUDRATE_9600bps   (51u)
#define UART_2X_f4Mhz_BAUDRATE_57600bps  (8u)
#define UART_2X_f4Mhz_BAUDRATE_115200bps (3u)
#define UART_2X_f4Mhz_BAUDRATE_250000bps (1u)
/** @defgroup: F_CLK: 8Mhz setup */
	/** @note: Normal Speed Mode */
#define UART_N_f8Mhz_BAUDRATE_9600bps   (51u)
#define UART_N_f8Mhz_BAUDRATE_57600bps  (8u)
#define UART_N_f8Mhz_BAUDRATE_115200bps (3u)
#define UART_N_f8Mhz_BAUDRATE_230400bps (1u)
#define UART_N_f8Mhz_BAUDRATE_250000bps (1u)
#define UART_N_f8Mhz_BAUDRATE_500000bps (0u)
    /** @note: 2X Speed Mode */
#define UART_2X_f8Mhz_BAUDRATE_9600bps   (103u)
#define UART_2X_f8Mhz_BAUDRATE_57600bps  (16u)
#define UART_2X_f8Mhz_BAUDRATE_115200bps (8u)
#define UART_2X_f8Mhz_BAUDRATE_230400bps (3u)
#define UART_2X_f8Mhz_BAUDRATE_250000bps (3u)
#define UART_2X_f8Mhz_BAUDRATE_500000bps (1u)
/** @defgroup: UART_SPEED*/
#define UART_SPEED_NORMAL               (0u)
#define UART_SPEED_DOUBLE               (1u)
/** @defgroup: UART_DATA */
#define UART_DATA_5BIT                  (0u)
#define UART_DATA_6BIT                  (1u)
#define UART_DATA_7BIT                  (2u)
#define UART_DATA_8BIT                  (3u)
#define UART_DATA_9BIT                  (4u)
/** @defgroup: UART_PARITY */
#define UART_PARITY_NON                 (0u)
#define UART_PARITY_EVEN                (1u)
#define UART_PARITY_ODD                 (2u)
/** @defgroup: UART_STOP */
#define UART_STOP_1BIT                  (0u)
#define UART_STOP_2BIT                  (1u)
/** @defgroup: UART_TYPE */
#define UART_TYPE_SYNCHRONOUS           (0u)
#define UART_TYPE_ASYNCHRONOUS          (1u)

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void voidUartTransmitViaInterrupt(cu8 *Address_cu8Stream,
                                         cu8 Copy_cu8StreamSize,
                                         u8 volatile *Address_u8StreamCounter);
static void voidUartReceiveViaInterrupt(u8 *Address_u8Stream,
                                        u8 volatile *Address_u8StreamCounter);

/** @defgroup: ISR */
#define ISR_USART_RXC  ( __vector_13 )
#define ISR_USART_UDRE ( __vector_14 )
#define ISR_USART_TXC  ( __vector_15 )

void __vector_13(void) __attribute__( (signal, used) );
void __vector_14(void) __attribute__( (signal, used) );
void __vector_15(void) __attribute__( (signal, used) );

#endif /* MCAL_UART_UART_PRIVATE_H_ */
