/**
 * @file TWI_Interface.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void TWI_voidInit(void);
void TWI_voidTransmitDataSync(u16 Copy_u16SlaveAddress, u8 Copy_u8DataToTransmit);
void TWI_voidReceiveDataSync(u16 Copy_u16SlaveAddress, u8 Copy_u8DataToReceive);
void TWI_voidTransmitDataAsync(u16 Copy_u16SlaveAddress, u8 Copy_u8DataToTransmit);
void TWI_voidReceiveDataAsync(u16 Copy_u16SlaveAddress, u8 Copy_u8DataToReceive);

u8 TWI_u8GetStatus(void);

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
