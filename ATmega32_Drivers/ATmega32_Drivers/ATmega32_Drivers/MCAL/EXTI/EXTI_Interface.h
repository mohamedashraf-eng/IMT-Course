/**
 * @file EXTI_Interface.h
 * 
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum EXTI_INTERRUPTS
{
	EXTI_INT0,
	EXTI_INT1,
	EXTI_INT2
};

enum EXTI_TRIGER_MODES
{
	EXTI_LOW_LEVEL,
	EXTI_LOGICAL_CHANGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_EDGE,
	EXTI_MIN_PW
};

enum EXTI_INTERRUPT_STATE
{
	EXTI_Disable,
	EXTI_Enable
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup General Functions */
void EXTI_voidInterruptInitalize(u8 Copy_u8InterruptID);
void EXTI_voidInterruptControl(u8 Copy_u8InterruptID, u8 Copy_u8State);
void EXTI_voidSetInterruptMode(u8 Copy_u8InterruptID, u8 Copy_u8Mode);
void EXTI_voidInterruptFlagReset(u8 Copy_u8InterruptID);

/** @defgroup Call back functions */
void EXTI_voidINT0_CallBackFunction(void (*Copy_voidINT0_CallBack)(void));
void EXTI_voidINT1_CallBackFunction(void (*Copy_voidINT1_CallBack)(void));
void EXTI_voidINT2_CallBackFunction(void (*Copy_voidINT2_CallBack)(void));


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
