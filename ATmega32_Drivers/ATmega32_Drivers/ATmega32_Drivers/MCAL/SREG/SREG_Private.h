/**
 * @file SREG_Private.h
 * 
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_SREG_SREG_PRIVATE_H_
#define MCAL_SREG_SREG_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	REGISTERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup addresses */
#define PERIPHERAL_MMIO_OFFSET		( (u8) (0x20) )

/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)			 	( (PERIPHERAL + PERIPHERAL_MMIO_OFFSET) )

#define SREG	( *((u8 volatile *) (0x5F)) )

enum SREG_BITS
{
	C,
	Z,
	N,
	V,
	S,
	H,
	T,
	I
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


#endif /* MCAL_SREG_SREG_PRIVATE_H_ */
