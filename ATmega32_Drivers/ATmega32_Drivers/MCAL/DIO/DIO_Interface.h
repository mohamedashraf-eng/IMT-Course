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
 * -																	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/



/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

typedef enum DIO_PORTS
{
	PORT_A,
	PORT_B,
	PORT_D,
	PORT_C
}ports_et;

typedef enum DIO_PINS
{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}pins_et;

typedef enum DIO_PINS_DIRECTION
{
	INPUT,
	OUTPUT
}dir_et;

typedef enum DIO_PINS_STATE
{
	LOW,
	HIGH
}state_et;


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup control - bit level*/
void DIO_voidSetPinDirection(cu8 A_cu8PortID, cu8 A_cu8PinID, cu8 A_cu8PinDirection);
void DIO_voidSetPinValue(cu8 A_cu8PortID, cu8 A_cu8PinID, cu8 A_cu8PinValue);
/** @defgroup control - register level*/
void DIO_voidSetRegisterDirection(cu8 A_cu8PortID, cu8 A_cu8RegisterDirection);
void DIO_voidSetRegisterValue(cu8 A_cu8PortID, cu8 A_cu8RegisterValue);
/** @defgroup input */
cu8 DIO_cu8GetPinValue(cu8 A_cu8PortID, cu8 A_cu8PinID);
cu8 DIO_cu8GetRegisterValue(cu8 A_cu8PortID);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
