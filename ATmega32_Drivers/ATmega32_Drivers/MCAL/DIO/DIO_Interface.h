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

void DIO_voidDioInitialization(void);
void DIO_voidDioClear(void);

/** @defgroup control - bit level*/
void DIO_voidSetPinDirection(cu8 Copy_cu8PortID, cu8 Copy_cu8PinID, cu8 Copy_cu8PinDirection);
void DIO_voidSetPinValue(cu8 Copy_cu8PortID, cu8 Copy_cu8PinID, cu8 Copy_cu8PinValue);

/** @defgroup control - register level*/
void DIO_voidSetRegisterDirection(cu8 Copy_cu8PortID, cu8 Copy_cu8RegisterDirection);
void DIO_voidSetRegisterValue(cu8 Copy_cu8PortID, cu8 Copy_cu8RegisterValue);

/** @defgroup input */
cu8 DIO_cu8GetPinValue(cu8 Copy_cu8PortID, cu8 Copy_cu8PinID);
cu8 DIO_cu8GetRegisterValue(cu8 Copy_cu8PortID);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
