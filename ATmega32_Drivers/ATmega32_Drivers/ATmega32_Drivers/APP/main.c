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
#include "../MCAL/ADC/ADC_Interface.h"

#include "../HAL/LCD/LCD_Interface.h"
//#include "../HAL/KEYPAD/KEYPAD_Interface.h"
//#include "../HAL/LED/LED_Interface.h"
//#include "../HAL/MOTORS/MOTORS_Interface.h"

#include <avr/delay.h>

int  main(void)
{
	LCD_voidSystemInitalaization(LCD_EightBitMode);
	ADC_voidSystemInitilization();

	u16 data = 0;

	while(True)
	{
		data = ADC_u16GetDataSync(ADC_CHANNEL0);

		LCD_voidDisplayInteger(data);

		_delay_ms(50);
		LCD_voidClearScreen();
	}

	return 0;
}


