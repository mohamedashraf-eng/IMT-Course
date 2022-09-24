/**
 * @file UART_Interface.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup: Macros for readability */
#define UART_WriteByte			UART_voidTransmitDataSync
#define UART_ReadByte			UART_voidReceiveDataSync
#define UART_WriteMultipleBytes	UART_voidTransmitStreamSync
#define UART_ReadMultipleBytes	UART_voidReceiveStreamSync

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void UART_voidInit(void);
void UART_voidTransmitDataSync(cu8 Copy_cu8DataToTransmit);
void UART_voidReceiveDataSync(u8 *Address_cu8DataToReceive);
void UART_voidTransmitStreamSync(cu8 *Address_cu8StreamToTransmit, cu8 Copy_cu8StreamSize);
void UART_voidReceiveStreamSync(u8 *Address_cu8StreamReceiveBuffer, cu8 Copy_cu8StreamSize);
void UART_voidTransmitStreamAsync(cu8 *Address_cu8StreamToTransmit, cu8 Copy_cu8StreamSize);
void UART_voidReceiveStreamAsync(u8 *Address_u8StreamToReceive);


#endif /* MCAL_UART_UART_INTERFACE_H_ */
