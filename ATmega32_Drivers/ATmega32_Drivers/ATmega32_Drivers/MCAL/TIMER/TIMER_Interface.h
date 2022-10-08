/**
 * @file TIMER_Interface.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum TIMERS_ID
{
    TIM0_ID,
    TIM1_ID,
    TIM2_ID
};

enum TIMER_PWM_OC_MODES
{
    FAST_PWM_INVERTED,
    FAST_PWM_NONINVERTED,
    PHASECORRECT_PWM_INVERTED,
    PHASECORRECT_PWM_NONINVERTED
};

enum TIMER0_WAVEGENERATION_MODES
{
    TIM0_NORMAL_MODE,
    TIM0_PHASE_CORRECT_PWM,
    TIM0_CTC,
    TIM0_FAST_PWM
};

enum TIMER0_OC_NONPWM_MODES
{
    TIM0_OC_NORMAL,
    TIM0_OC_TOGGLE_CM,
    TIM0_OC_CLEAR_CM,
    TIM0_OC_SET_CM
};

enum TIMER0_PRESCALER
{
    TIM0_NO_CLKSOURCE,
    TIM0_NO_PRESCALER,
    TIM0_8_PRESCALER,
    TIM0_64_PRESCALER,
    TIM0_256_PRESCALER,
    TIM0_1024_PRESCALER,
    TIM0_EXCxFALLINGxEDGE_PRESCALER,
    TIM0_EXCxRISINGxEDGE_PRESCALER
};

enum TIMER_DELAY_AsyncMode
{
	AsyncMode_Single,
	AsyncMode_Periodic
};

enum TIMER0_ISR_ID
{
    TIM0_OVF_ISR_ID,
    TIM0_COMP_ISR_ID
};

#define _TIM1_CAPTURE_RISING                 0
#define _TIM1_CAPTURE_FALLING                1

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup: Timer 0 Public Functions */
void TIMER_voidTIM0Init(void);
void TIMER_voidTIM0SetMode(u8 Copy_u8ModeID);
void TIMER_voidTIM0SetOCmode(u8 Copy_u8OCmode);
void TIMER_voidTIM0DelaySync(f32 Copy_f32Delay);
void TIMER_voidTIM0DelayAsync(u8 Copy_u8AsyncMode, f32 Copy_f32Delay);
void TIMER_voidTIM0GeneratePWM(u8 Copy_u8DutyCycle);
void TIMER_voidTIM0SetCallBack(u8 Copy_u8TIM0isrID, void (*CallBackFunction)(void));
/** @defgroup: Timer 1 Public Functions */
void TIMER_voidTIM1Init(void);
void TIMER_voidTIM1SetMode(u8 Copy_u8ModeID);
void TIMER_voidTIM1ASetOCmode(u8 Copy_u8OCmode);
void TIMER_voidTIM1BSetOCmode(u8 Copy_u8OCmode);
void TIMER_voidSetTIM1xICUxCapture(u8 Copy_u8CaptureMode);
u16 TIMER_u16TIM1GetICR(void);
void TIMER_voidTIM1DisableICU(void);
void TIMER_voidTIM1GeneratePWM(u8 Copy_u8DutyCycle);
void TIMER_voidTIM1MeasurePWMSync(u8  *Address_u8DutyCycle,
                                  u32 *Address_u32Frequency);
void TIMER_voidTIM1MeasurePWMAsync(void);
void TIMER_voidTIM1SetICUCallBack(void (*TIM1_CallBack)(void));
void TIMER_voidTIM1SetOVFCallBack(void (*TIM1_CallBack)(void));

/** @defgroup: Timer 2 Public Functions */

/** @defgroup: General Public Functions */
void TIMER_voidTIMSetPreScaler(u8 Copy_u8TimerID, u16 Copy_u16PreScaler);

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
