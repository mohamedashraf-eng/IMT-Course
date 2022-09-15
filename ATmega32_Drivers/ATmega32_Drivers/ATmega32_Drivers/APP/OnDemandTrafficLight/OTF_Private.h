/**
 * @file OTM_Private.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef APP_OTM_OTM_PRIVATE_H_
#define APP_OTM_OTM_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define RESET_MCU  asm volatile ("JMP 0x000");

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void voidSysLedInit(void);
static void voidSysButtonInit(void);
static void voidSysInterruptInit(void);
static void voidPassengerEventHandle(void);

static void voidClrLeds(void);

#endif /* MCAL_OTM_OTM_PRIVATE_H_ */
