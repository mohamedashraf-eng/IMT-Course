/**
 * @file OTF_Interface.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef APP_OTF_OTF_INTERFACE_H_
#define APP_OTF_OTF_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum CAR_TF_LEDS
{
    CAR_G_LED   = 0,
    CAR_Y_LED   = 1,
    CAR_R_LED   = 2
};

enum PAS_TF_LEDS
{
    PAS_G_LED   = 3,
    PAS_Y_LED   = 4,
    PAS_R_LED   = 5
};

enum PAS_PASSING_BUTTON
{
    PASS_BUTTON = 0
};

enum UsefulRE
{
    Delay_5s    = 5000,
    Delay_500ms = 500
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void OTF_voidSysInit(void);
void OTF_voidSysUpdate(void);

#endif /* MCAL_OTF_OTF_INTERFACE_H_ */
