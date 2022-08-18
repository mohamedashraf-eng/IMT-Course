/**
 * @file DIO_Interface.h
 * @brief
 * @author Mohamed Wx
 * @date 15/08/2022
 *
 */
/** @def Header Guards */
#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

typedef enum DIO_PORTS
{
	PORT_A,
	PORT_B,
	PORT_D,
	PORT_C
}port_et;

enum DIO_PINS
{
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8
};

enum DIO_PIN_DIRECTION
{
	INPUT,
	OUTPUT
};

enum DIO_PIN_STATE
{
	LOW,
	HIGH
};

enum DIO_PIN_TYPE
{
	DIGITAL,
	ANALOG
};

enum DIO_PIN_FUNCTION
{
	GPIO,
	SPI,
	I2C,
	ADC
};


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void
DIO_voidDioInitialization(void);

void
DIO_voidDioClear(void);

/** @defgroup control - bit level*/
void
DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDirection);

void
DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue);

/** @defgroup control - register level*/
void
DIO_voidSetRegisterDirection(u8 Copy_u8PortID, u8 Copy_u8RegisterDirection);

void
DIO_voidSetRegisterValue(u8 Copy_u8PortID, u8 Copy_u8RegisterValue);

/** @defgroup input */
u8
DIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);

u8
DIO_u8GetRegisterValue(u8 Copy_u8PortID);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
