/**
 * @file OTF_Program.c
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
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER/TIMER_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"
#include "../../MCAL/SREG/SREG_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/BUTTON/BUTTON_Interface.h"

#include "OTF_Private.h"
#include "OTF_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

u8 L_u8FLAG_CAR_R_LED = 0, L_u8FLAG_CAR_Y_LED = 0, L_u8FLAG_CAR_G_LED = 0;
u8 L_u8FLAG_PAS_R_LED = 0, L_u8FLAG_PAS_Y_LED = 0, L_u8FLAG_PAS_G_LED = 0;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void OTF_voidSysInit(void)
{
    voidSysLedInit();
    voidSysButtonInit();
    TIMER_voidTIM0Init();
}/** @end OTF_voidSysInit */

void OTF_voidSysUpdate(void)
{
    voidClrLeds();
    LED_voidLedSetValue(PAS_R_LED, LED_ON);
    LED_voidLedSetValue(CAR_G_LED, LED_ON);
    L_u8FLAG_CAR_G_LED = HIGH;
    TIMER_voidTIM0DelaySync(Delay_5s);
    LED_voidLedSetValue(CAR_G_LED, LED_OFF);
    L_u8FLAG_CAR_G_LED = LOW;

    /** @def: Flashing Mechanism */
    L_u8FLAG_CAR_Y_LED = HIGH;
    for(u8 L_u8Iterator = 0; (L_u8Iterator < 5); ++L_u8Iterator)
    {
        LED_voidLedSetValue(CAR_Y_LED, LED_ON);
        TIMER_voidTIM0DelaySync(Delay_500ms);
        LED_voidLedSetValue(CAR_Y_LED, LED_OFF);
        TIMER_voidTIM0DelaySync(Delay_500ms);
    }
    L_u8FLAG_CAR_Y_LED = LOW;

    LED_voidLedSetValue(CAR_R_LED, LED_ON);
    L_u8FLAG_CAR_R_LED = HIGH;
    TIMER_voidTIM0DelaySync(Delay_5s);
    LED_voidLedSetValue(CAR_R_LED, LED_OFF);
    L_u8FLAG_CAR_R_LED = LOW;

    /** @def: Flashing Mechanism */
    L_u8FLAG_CAR_Y_LED = HIGH;
    for(u8 L_u8Iterator = 0; (L_u8Iterator < 5); ++L_u8Iterator)
    {
        LED_voidLedSetValue(CAR_Y_LED, LED_ON);
        TIMER_voidTIM0DelaySync(Delay_500ms);
        LED_voidLedSetValue(CAR_Y_LED, LED_OFF);
        TIMER_voidTIM0DelaySync(Delay_500ms);
    }
    L_u8FLAG_CAR_Y_LED = LOW;
}/** @end OTF_voidSysUpdate */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void voidPassengerEventHandle(void)
{
    if( (L_u8FLAG_CAR_R_LED) )
    {
        LED_voidLedSetValue(PAS_G_LED, LED_ON);
        LED_voidLedSetValue(CAR_R_LED, LED_ON);
        TIMER_voidTIM0DelaySync(Delay_5s);
    }
    else if( (L_u8FLAG_CAR_G_LED) || (L_u8FLAG_CAR_Y_LED) )
    {
        LED_voidLedSetValue(PAS_R_LED, LED_ON);
        if( (L_u8FLAG_CAR_Y_LED) )
        {
            for(u8 L_u8Iterator = 0; (L_u8Iterator < 5); ++L_u8Iterator)
            {
                LED_voidLedSetValue(CAR_Y_LED, LED_ON);
                TIMER_voidTIM0DelaySync(Delay_500ms);
                LED_voidLedSetValue(CAR_Y_LED, LED_OFF);
                TIMER_voidTIM0DelaySync(Delay_500ms);
            }
        }
        else
        { TIMER_voidTIM0DelaySync(Delay_5s); }
        LED_voidLedSetValue(CAR_Y_LED, LED_OFF);
        LED_voidLedSetValue(PAS_R_LED, LED_OFF);
        LED_voidLedSetValue(CAR_G_LED, LED_OFF);
        /** @def: Flashing Mechanism */
        for(u8 L_u8Iterator = 0; (L_u8Iterator < 5); ++L_u8Iterator)
        {
            LED_voidLedSetValue(CAR_Y_LED, LED_ON);
            LED_voidLedSetValue(PAS_Y_LED, LED_ON);
            TIMER_voidTIM0DelaySync(Delay_500ms);
            LED_voidLedSetValue(CAR_Y_LED, LED_OFF);
            LED_voidLedSetValue(PAS_Y_LED, LED_OFF);
            TIMER_voidTIM0DelaySync(Delay_500ms);
        }
        LED_voidLedSetValue(CAR_R_LED, LED_ON);
        LED_voidLedSetValue(PAS_G_LED, LED_ON);
        TIMER_voidTIM0DelaySync(Delay_5s);
    }
    else {;}
    /** @def: General after state proceducre */
    LED_voidLedSetValue(CAR_R_LED, LED_OFF);
    /** @def: Flashing Mechanism */
    for(u8 L_u8Iterator = 0; (L_u8Iterator < 5); ++L_u8Iterator)
    {
        LED_voidLedSetValue(CAR_Y_LED, LED_ON);
        LED_voidLedSetValue(PAS_Y_LED, LED_ON);
        TIMER_voidTIM0DelaySync(Delay_500ms);
        LED_voidLedSetValue(CAR_Y_LED, LED_OFF);
        LED_voidLedSetValue(PAS_Y_LED, LED_OFF);
        TIMER_voidTIM0DelaySync(Delay_500ms);
    }
    LED_voidLedSetValue(PAS_G_LED, LED_OFF);
    LED_voidLedSetValue(PAS_R_LED, LED_ON);
    LED_voidLedSetValue(CAR_G_LED, LED_ON);
    TIMER_voidTIM0DelaySync(1000);
    LED_voidLedSetValue(PAS_R_LED, LED_OFF);

    /** @def: RESET The Micro Controller assembly instruction */
    //RESET_MCU;
}/** @end voidPassengerEventHandle */

static void voidSysLedInit(void)
{
    LED_voidLedInitalaization(CAR_G_LED);
    LED_voidLedInitalaization(CAR_Y_LED);
    LED_voidLedInitalaization(CAR_R_LED);
    LED_voidLedInitalaization(PAS_G_LED);
    LED_voidLedInitalaization(PAS_Y_LED);
    LED_voidLedInitalaization(PAS_R_LED);
}/** @end voidSysLedInit */

static void voidSysButtonInit(void)
{
    BUTTON_voidButtonInitalaization(PASS_BUTTON);
    voidSysInterruptInit();
}/** @end voidSysButtonInit */

static void voidSysInterruptInit(void)
{
    EXTI_voidInterruptInitalize(EXTI_INT0);
    EXTI_voidSetInterruptMode(EXTI_INT0, EXTI_FALLING_EDGE);
    EXTI_voidINT0_CallBackFunction(&voidPassengerEventHandle);
    EXTI_voidInterruptControl(EXTI_INT0, EXTI_Enable);
    SREG_voidGlobalInterruptControl(SREG_Enable);
}/** @end voidSysInterruptInit */

static void voidClrLeds(void)
{
    LED_voidLedSetValue(CAR_G_LED, LED_OFF);
    LED_voidLedSetValue(CAR_Y_LED, LED_OFF);
    LED_voidLedSetValue(CAR_R_LED, LED_OFF);
    LED_voidLedSetValue(PAS_G_LED, LED_OFF);
    LED_voidLedSetValue(PAS_Y_LED, LED_OFF);
    LED_voidLedSetValue(PAS_R_LED, LED_OFF);
}/** @end voidClrLeds*/
