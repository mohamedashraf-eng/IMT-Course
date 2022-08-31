/**
 * @file main.c
 * @brief the main application entry point.
 * @author Mohamed Wx
 * @date 15/08/2022
 *
 */

/*
	888       888Y88b   d88P    .d8888b.  .d88888b. 8888888b. 8888888888
	888   o   888 Y88b d88P    d88P  Y88bd88P" "Y88b888  "Y88b888
	888  d8b  888  Y88o88P     888    888888     888888    888888
	888 d888b 888   Y888P      888       888     888888    8888888888
	888d88888b888   d888b      888       888     888888    888888
	88888P Y88888  d88888b     888    888888     888888    888888
	8888P   Y8888 d88P Y88b    Y88b  d88PY88b. .d88P888  .d88P888
	888P     Y888d88P   Y88b    "Y8888P"  "Y88888P" 8888888P" 8888888888
 */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/SREG/SREG_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"

//#include "../HAL/LCD/LCD_Interface.h"
//#include "../HAL/KEYPAD/KEYPAD_Interface.h"
//#include "../HAL/LED/LED_Interface.h"
//#include "../HAL/MOTORS/MOTORS_Interface.h"

#include <avr/delay.h>

void LedToggle(void);

int  main(void)
{
	DIO_voidSetPinDirection(PORT_D, PIN_8, OUTPUT);
	DIO_voidSetPinValue(PORT_D, PIN_8, LOW);

	DIO_voidSetPinDirection(PORT_B, PIN_2, OUTPUT);
	DIO_voidSetPinValue(PORT_B, PIN_2, LOW);

	/** @defgroup setting the interrupt */
	EXTI_voidInterruptInitalize(EXTI_INT0);
	EXTI_voidSetInterruptMode(EXTI_INT0, EXTI_FALLING_EDGE);
	EXTI_voidINT0_CallBackFunction(LedToggle);
	EXTI_voidInterruptControl(EXTI_INT0, EXTI_Enable);

	SREG_voidGlobalInterruptControl(SREG_Enable);

	while(True)
	{
		DIO_voidSetPinValue(PORT_B, PIN_2, LOW);
		_delay_ms(200);
		DIO_voidSetPinValue(PORT_B, PIN_2, HIGH);
		_delay_ms(200);
	}

	return 0;
}


void LedToggle(void)
{
	 u8 static volatile counter = 0;

		DIO_voidSetPinValue(PORT_D, PIN_8, HIGH);

	if( (counter >= 3) )
	{
		DIO_voidSetPinValue(PORT_D, PIN_8, LOW);
		counter = 0;
	}
	else
	{
		counter++;
	}
}
