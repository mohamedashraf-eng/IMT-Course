/**
 * @file UART_Program.c
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

#include "UART_Private.h"
#include "UART_Config.h"
#include "UART_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

cu8 *G_cu8TxBuffer = NULL;
u16 G_u16TxStreamSize = 0;
u8 volatile G_u8TxCounter = 0;

u8 *G_u8RxBuffer = NULL;
u8 volatile G_u8RxCounter = 0;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void UART_voidInit(void)
{
    /** @brief: Writing 1 to this bit to access the UCSRC */
    BIT_SET(UCSRC, URSEL);
/**
 * @defgroup: Selecting the uart speed
 */
#if   (UART_SPEED == UART_SPEED_NORMAL)
    BIT_CLR(UCSRA, U2X);
#elif (UART_SPEED == UART_SPEED_DOUBLE)
    BIT_SET(UCSRA, U2X);
#else
    #warning ("Invalid UART Speed selected!")
    /** @def: Set the default */
    BIT_CLR(UCSRA, U2X);
#endif
/**
 * @defgroup: Selecting the uart mode
 */
#if   (UART_MODE == UART_TRANSMITTER_MODE)
    BIT_CLR(UCSRB, RXEN);
    BIT_SET(UCSRB, TXEN);
#elif (UART_MODE == UART_RECEIVER_MODE)
    BIT_CLR(UCSRB, TXEN);
    BIT_SET(UCSRB, RXEN);
#elif (UART_MODE == UART_TRANSMITTERxRECEIVER_MODE)
    BIT_SET(UCSRB, RXEN);
    BIT_SET(UCSRB, TXEN);
#else
    #warning ("Invalid UART mode selected!")
    /** @def: Set the default */
    BIT_SET(UCSRB, RXEN);
    BIT_SET(UCSRB, TXEN);
#endif
/**
 * @def: Selecting the uart parity
 */
#if   (UART_PARITY == UART_PARITY_NON)
    BIT_CLR(UCSRC, UPM0);
    BIT_CLR(UCSRC, UPM1);
#elif (UART_PARITY == UART_PARITY_EVEN)
    BIT_CLR(UCSRC, UPM0);
    BIT_SET(UCSRC, UPM1);
#elif (UART_PARITY == UART_PARITY_ODD)
    BIT_SET(UCSRC, UPM0);
    BIT_SET(UCSRC, UPM1);
#else
    #warning ("Invalid UART parity selected!")
    /** @def: Set the default */
    BIT_CLR(UCSRC, UPM0);
    BIT_CLR(UCSRC, UPM1);
#endif
/**
 * @defgroup: Selecting the uart stop
 */
#if   (UART_STOP == UART_STOP_1BIT)
    BIT_CLR(UCSRC, USBS);
#elif (UART_STOP == UART_STOP_2BIT)
    BIT_SET(UCSRC, USBS);
#else
    #warning ("Invalid UART stop selected!")
    /** @def: Set the default */
    BIT_CLR(UCSRC, USBS);
#endif
/**
 * @defgroup: Selecting the uart type
 */
#if   (UART_TYPE == UART_TYPE_ASYNCHRONOUS)
    BIT_CLR(UCSRC, UMSEL);
#elif (UART_TYPE == UART_TYPE_SYNCHRONOUS)
    BIT_SET(UCSRC, UMSEL);
#else
    #warning ("Invalid UART type selected!")
    /** @def: Set the default */
    BIT_CLR(UCSRC, UMSEL);
#endif
/**
 * @defgroup: Selecting the uart data
 */
#if   (UART_DATA == UART_DATA_5BIT)
    BIT_CLR(UCSRC, UCSZ0);
    BIT_CLR(UCSRC, UCSZ1);
    BIT_CLR(UCSRB, UCSZ2);
#elif (UART_DATA == UART_DATA_6BIT)
    BIT_SET(UCSRC, UCSZ0);
    BIT_CLR(UCSRC, UCSZ1);
    BIT_CLR(UCSRB, UCSZ2);
#elif (UART_DATA == UART_DATA_7BIT)
    BIT_CLR(UCSRC, UCSZ0);
    BIT_SET(UCSRC, UCSZ1);
    BIT_CLR(UCSRB, UCSZ2);
#elif (UART_DATA == UART_DATA_8BIT)
    BIT_SET(UCSRC, UCSZ0);
    BIT_SET(UCSRC, UCSZ1);
    BIT_CLR(UCSRB, UCSZ2);
#elif (UART_DATA == UART_DATA_9BIT)
    BIT_SET(UCSRC, UCSZ0);
    BIT_SET(UCSRC, UCSZ1);
    BIT_SET(UCSRB, UCSZ2);
#else
    #warning ("Invalid UART data selected!")
    /** @def: Set the default */
    BIT_SET(UCSRC, UCSZ0);
    BIT_SET(UCSRC, UCSZ1);
    BIT_CLR(UCSRB, UCSZ2);
#endif
/**
 * @defgroup: Writing the uart baudrate to the BBR Register.
 */
    /** @brief: Writing 0 to this bit to access the UCSRC */
    BIT_CLR(UCSRC, URSEL);
    REG_WRT(UBRRH, (UART_BAUDRATE >> 8U));
    REG_WRT(UBRRL, UART_BAUDRATE);
}/** @end UART_voidInit */

void UART_voidTransmitDataSync(cu8 Copy_cu8DataToTransmit)
{
    /** @def: Wait for the data buffer to be empty. */
    while( (0 == BIT_GET(UCSRA, UDRE)) ) {;}
    /** @def: Write the data */
    REG_WRT(UDR, Copy_cu8DataToTransmit);
    /** @def: Wait for the transmission to be completed */
    while( (0 == BIT_GET(UCSRA, TXC)) ) {;}
/** @def: Pairty Error algorithm. */
#if ( (UART_PARITY > 0) ) /** @note: This statement checks \
                            *        if pariity is enabled */
    if( (BIT_GET(UCSRA, PE)) )
    {   /** @brief: Send the charachter again */
        UART_voidTransmitCharachterSync(Copy_cu8DataToTransmit);
    }   /** @brief: Make sure to clear the flag. */
    else { BIT_CLR(UCSRA, PE); }
#endif
    /** @def: Clear the TXC Flag */
    BIT_CLR(UCSRA, TXC);
}/** @end UART_voidTransmitDataSync */

void UART_voidTransmitStreamSync(cu8 *Address_cu8StreamToTransmit, cu8 Copy_cu8StreamSize)
{
	u8 L_u8StreamIterator = 0;

	for(L_u8StreamIterator = 0; (L_u8StreamIterator < Copy_cu8StreamSize); ++L_u8StreamIterator)
	{
		UART_voidTransmitDataSync(Address_cu8StreamToTransmit[L_u8StreamIterator]);
	}
}/** @end UART_voidTransmitStreamSync */

void UART_voidReceiveDataSync(u8 *Address_cu8DataToReceive)
{
    /** @def: Wait for the data to be received */
    while( (0 == BIT_GET(UCSRA, RXC)) ) {;}
    /** @def: Clear the RXC Flag */
    BIT_CLR(UCSRA, RXC);
    /** @def: Get the data */
    *(Address_cu8DataToReceive) = UDR;
}/** @end UART_voidReceiveDataSync */

void UART_voidReceiveStreamSync(u8 *Address_cu8StreamReceiveBuffer, cu8 Copy_cu8StreamSize)
{
	u8 L_u8StreamIterator = 0;

	for(L_u8StreamIterator = 0; (L_u8StreamIterator < Copy_cu8StreamSize); ++L_u8StreamIterator)
	{
		UART_voidReceiveDataSync(&Address_cu8StreamReceiveBuffer[L_u8StreamIterator]);
	}
}/** @end UART_voidReceiveStreamSync */

void UART_voidTransmitStreamAsync(cu8 *Address_cu8StreamToTransmit, cu8 Copy_cu8StreamSize)
{
    if( (NULL != Address_cu8StreamToTransmit) )
    {
    	G_cu8TxBuffer = Address_cu8StreamToTransmit;
    	if( (Copy_cu8StreamSize != 0) )
    	{
    		G_u16TxStreamSize = Copy_cu8StreamSize;
    	}
    }else {;}
    /** @def: Enable Data Register Empty Interrupt */
//    BIT_SET(UCSRB, UDRIE);
    /** @def: Enable TX Complete Interrupt */
    BIT_SET(UCSRB, TXCIE);

    REG_WRT(UDR, Address_cu8StreamToTransmit[0]);
}/** @end UART_voidTransmitStreamAsync*/

void UART_voidReceiveStreamAsync(u8 *Address_u8StreamToReceive)
{
	G_u8RxBuffer = Address_u8StreamToReceive;
    /** @def: Enable Data Register Empty Interrupt */
//    BIT_SET(UCSRB, UDRIE);
    /** @def: Enable RX Complete Interrupt */
    BIT_SET(UCSRB, RXCIE);
}/** @end UART_voidReceiveStreamAsync */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void voidUartTransmitViaInterrupt(cu8 *Address_cu8Stream,
                                         cu8 Copy_cu8StreamSize,
                                         u8 volatile *Address_u8StreamCounter)
{
    /** @def: Check if the transmitter is enabled */
    if( (BIT_GET(UCSRB, TXEN)) )
    {
        if( ((*Address_u8StreamCounter) < Copy_cu8StreamSize) &&
             (BIT_GET(UCSRA, UDRE)) ) /** @note: Check if the Data  Register is empty */
        {
            ++(*Address_u8StreamCounter);
            REG_WRT(UDR, Address_cu8Stream[(*Address_u8StreamCounter)]);
        }
        else
        {
            (*Address_u8StreamCounter) = (u8) 0;
            /** @def: Disable Data Register Empty Interrupt */
            BIT_CLR(UCSRB, UDRIE);
            /** @def: Disable TX Complete Interrupt */
            BIT_CLR(UCSRB, TXCIE);
        }/** @end if: Counter < Size */
    }/** @end if: TXEN */
    else {;}
}/** @end voidUartTransmitViaInterrupt */

static void voidUartReceiveViaInterrupt(u8 *Address_u8Stream,
                                        u8 volatile *Address_u8StreamCounter)
{
    /** @def: Check if the transmitter is enabled */
    if( (BIT_GET(UCSRB, RXEN)) )
    {
        if( ((*Address_u8StreamCounter) < UART_MAX_BUFFER_SIZE) &&
             !(BIT_GET(UCSRA, UDRE)) ) /** @note: Check if the Data  Register is not empty */
        {
        	Address_u8Stream[(*Address_u8StreamCounter)] = UDR;
        	++(*Address_u8StreamCounter);
        }
        else
        {
        	(*Address_u8StreamCounter) = (u8) 0; /** @brief: Circular Buffer */
        }/** @end if: Counter < Size */
    }/** @end if: TXEN */
    else {;}
}/** @end voidUartReceiveViaInterrupt */

void ISR_USART_RXC(void)
{
    voidUartReceiveViaInterrupt(G_u8RxBuffer, &G_u8RxCounter);
}/** @end ISR_USART_RXC */

void ISR_USART_UDRE(void)
{

}/** @end ISR_USART_UDRE */

void ISR_USART_TXC(void)
{
	voidUartTransmitViaInterrupt(G_cu8TxBuffer, G_u16TxStreamSize, &G_u8TxCounter);
/** @def: Pairty Error algorithm. */
#if ( (UART_PARITY > 0) ) /** @note: This statement checks \
                            *        if pariity is enabled */
    if( (BIT_GET(UCSRA, PE)) )
    {   /** @brief: Send the charachter again */
        voidUartReceiveViaInterrupt(G_u8RxBuffer, &G_u8RxCounter);
    }   /** @brief: Make sure to clear the flag. */
    else { BIT_CLR(UCSRA, PE); }
#endif
}/** @end ISR_USART_TXC */
