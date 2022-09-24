/**
 * @file SPI_Interface.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup: Macros for readability */
#define SPI_WriteByte 	       SPI_voidTransmitDataSync
#define SPI_ReadByte 		   SPI_voidReceiveDataSync
#define SPI_WriteMultipleBytes SPI_voidTransmitStreamSync
#define SPI_ReadMultipleBytes  SPI_voidReceiveStreamSync

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void SPI_voidInit(void);
void SPI_voidTransmitDataSync(cu8 Copy_cu8CharToTransmit);
void SPI_voidReceiveDataSync(u8 *Copy_cu8CharToReceive);
void SPI_voidTransmitStreamSync(cu8 *Address_cu8StreamToTransmit, cu8 Copy_cu8StreamSize);
void SPI_voidReceiveStreamSync(u8 *Address_cu8StreamReceiveBuffer, cu8 Copy_cu8StreamSize);
void SPI_voidTransmitStreamAsync(cu8 *Address_cu8StreamToTransmit, cu8 Copy_cu8StreamSize);
void SPI_voidReceiveStreamAsync(u8 *Address_u8StreamToReceive);


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
