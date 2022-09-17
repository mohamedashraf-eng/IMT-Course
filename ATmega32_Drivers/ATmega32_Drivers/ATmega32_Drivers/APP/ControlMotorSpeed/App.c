/**
 * @file TIMER_Program.c
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

#include "../../MCAL/TIMER/TIMER_Interface.h"
#include "../../HAL/MOTORS/MOTORS_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../HAL/BUTTON/BUTTON_Interface.h"
#include "App.h"


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void voidApplicationInit(void)
{
    /** @defgroup: Push Button Initalization */
    BUTTON_voidButtonInitalaization(BUTTON_1);
    BUTTON_voidButtonInitalaization(BUTTON_2);
    /** @defgroup: LCD Initalization */
    LCD_voidSystemInitalaization(LCD_EightBitMode);
    /** @defgroup: MOTOR Initalization */
    MOTOR_voidDcSystemInitalization();
    MOTOR_voidSetDcMotorSpeed(MOTOR1_ID, 0);
}/** @end voidApplicationInit */

void voidApplicationUpdate(void)
{
    static u8 L_u8SpeedValue    = 0;
    static u8 L_u8SpeedValueChangeFlag = 1;

    if( (BUTTON_u8ButtonGetValue(BUTTON_1) == BUTTON_ON) )
    {
        if( (L_u8SpeedValue > 100U) )
        {
            L_u8SpeedValue = 100U;
        }else { ++L_u8SpeedValue; }
        L_u8SpeedValueChangeFlag = 1;
    }
    else if( (BUTTON_u8ButtonGetValue(BUTTON_2) == BUTTON_ON) )
    {
        if( (L_u8SpeedValue <= 0U) )
        {
            L_u8SpeedValue = 0U;
        }else { --L_u8SpeedValue; }
        L_u8SpeedValueChangeFlag = 1;
    }
    else {;}
    /** @def: Execution limit */
    if( (L_u8SpeedValueChangeFlag == 1) )
    {
    	MOTOR_voidSetDcMotorSpeed(MOTOR1_ID, L_u8SpeedValue);
        LCD_voidClearScreen();
        LCD_voidDisplayString("Duty Cycle: ");
        LCD_voidDisplayInteger(L_u8SpeedValue);
        LCD_voidDisplayCharacter('%');
        L_u8SpeedValueChangeFlag = 0;
    }else {;}

    return;
}/** @end voidApplicationUpdate */
