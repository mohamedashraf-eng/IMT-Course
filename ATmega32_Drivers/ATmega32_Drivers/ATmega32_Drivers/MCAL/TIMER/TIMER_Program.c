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

#include "TIMER_Private.h"
#include "TIMER_Config.h"
#include "TIMER_Interface.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

Timer0CallBackFunction_t G_Timer0CallBackFunction[2u] = {NULL, NULL};

/** @defgroup: Async Delay Parameters */
u8 G_u8DelayAsyncFlag = 0;
u8 G_u8DelayAsyncMode =0;
u32 volatile G_u32DelayAsyncOVFCounter = 0;
u32 volatile G_u32DelayAsyncOVFValue   = 0;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/**
 * @defgroup TIMER0
 */
void TIMER_voidTIM0Init(void)
{
    TIMER_voidTIM0SetMode(TIM0_MODE);
    TIMER_voidTIM0SetOCmode(TIM0_COM_MODE);
    voidStopTimer0();
}/** @end TIMER_voidTIM0Init */
void TIMER_voidTIM0SetMode(u8 Copy_u8ModeID)
{
    switch(Copy_u8ModeID)
    {
        case _TIM0_NORMAL_MODE:
                        BIT_CLR(TCCR0, WGM01);
                        BIT_CLR(TCCR0, WGM00);
                    break;
        case _TIM0_PHASE_CORRECT_PWM:
                        BIT_CLR(TCCR0, WGM01);
                        BIT_SET(TCCR0, WGM00);
                    break;
        case _TIM0_CTC:
                        BIT_SET(TCCR0, WGM01);
                        BIT_CLR(TCCR0, WGM00);
                    break;
        case _TIM0_FAST_PWM:
                        BIT_SET(TCCR0, WGM01);
                        BIT_SET(TCCR0, WGM00);
                    break;
        default: break; /* Error handler */
    }
}/** @end TIMER_voidTIM0SetMode */

void TIMER_voidTIM0SetOCmode(u8 Copy_u8OCmode)
{
    switch(Copy_u8OCmode)
    {
        case _TIM0_OC_NORMAL:
                        BIT_CLR(TCCR0, COM01);
                        BIT_CLR(TCCR0, COM00);
                    break;
        case _TIM0_OC_TOGGLE_CM: /** @note: This mode is disabled while using any PWM */
                        BIT_CLR(TCCR0, COM01);
                        BIT_SET(TCCR0, COM00);
                    break;
        case _TIM0_OC_CLEAR_CM:
                        BIT_SET(TCCR0, COM01);
                        BIT_CLR(TCCR0, COM00);
                    break;
        case _TIM0_OC_SET_CM:
                        BIT_SET(TCCR0, COM01);
                        BIT_SET(TCCR0, COM00);
                    break;
        default: break; /* Error handler */
    }
}/** @end TIMER_voidTIM0SetOCmode */
void TIMER_voidTIM0DelaySync(f32 Copy_f32Delay)
{
    voidStopTimer0();

    f32 L_f32Delay_s = (Copy_f32Delay * 0.001f);
    u32 L_u32NumberOfOVs = 0;
    u8  L_u8RegisterValue =
    (u8) u16CalculateTimerInitalValue(TIM0_ID, L_f32Delay_s, &L_u32NumberOfOVs);
    u32 L_u32OverFlowCounter = 0;

    voidSetTimer0StartValue(L_u8RegisterValue);

    voidStartTimer0();
    while( (L_u32OverFlowCounter < L_u32NumberOfOVs) )
    {
        /* Busy Wait */
        while( !(BIT_GET(TIFR, TOV0)) ) {;}

        /* Clear the OVF flag by writing 1 */
        BIT_SET(TIFR, TOV0);

        ++L_u32OverFlowCounter;
    }/** @end while: OVs < NoOVS */
    voidStopTimer0();
}/** @end TIMER_voidTIM0DelaySync*/

void TIMER_voidTIM0DelayAsync(u8 Copy_u8AsyncMode, f32 Copy_f32Delay)
{
    voidStopTimer0();

    f32 L_f32Delay_s = (Copy_f32Delay * 0.001f);
    u8  L_u8RegisterValue = (u8) u16CalculateTimerInitalValue(TIM0_ID,
                                                              L_f32Delay_s,
                                                             ((u32 *) &G_u32DelayAsyncOVFValue));
    G_u8DelayAsyncFlag = 1;
    G_u8DelayAsyncMode = Copy_u8AsyncMode;

    voidSetTimer0StartValue(L_u8RegisterValue);
    /** Enable TOV0 Interrupt */
    BIT_SET(TIMSK, TOIE0);
    voidStartTimer0();
}/** @end TIMER_voidTIM0DelayAsync*/

/**
 * @brief:
 * The signal frequency is determined by (Timer PreScaler, Timer Peripheral Frequency) (Hz)
 *  @note Signal Frequency equation is dependent on the MCU Peripheral
 * The signal Effective Voltage: RMS = A*sqrt(D.C) (v)
 * The signal Duty Cycly: D.C = Ton/T * 100 (Percentage)
 */
void TIMER_voidTIM0GeneratePWM(u8 Copy_u8DutyCycle)
{
    voidStopTimer0();
    voidTIM0SetDutyCycle(Copy_u8DutyCycle);
    voidStartTimer0();
}/** @end TIMER_voidTIM0GeneratePWM */

void TIMER_voidTIM0SetCallBack(u8 Copy_u8TIM0isrID,
                               Timer0CallBackFunction_t Copy_CallBackFunction)
{
    if( (Copy_CallBackFunction != NULL) )
    {
        G_Timer0CallBackFunction[Copy_u8TIM0isrID] = Copy_CallBackFunction;
    }else{;}
}/** @end TIMER_voidTIM0SetCallBack */

/**
 * @defgroup TIMER1
 */
void TIMER_voidTIM1Init(void)
{
    TIMER_voidTIM1SetMode(TIM1_MODE);
    voidStopTimer1();
}/** @end TIMER_voidTIM1Init */
void TIMER_voidTIM1SetMode(u8 Copy_u8ModeID)
{
    switch(Copy_u8ModeID)
    {
        case _TIM1_NORMAL_MODE:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b00);    TCCR1B |= (0b00 << 3U);
            break;
        case _TIM1_PHASE_CORRECT_PWM_8:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b01);    TCCR1B |= (0b00 << 3U);
            break;
        case _TIM1_PHASE_CORRECT_PWM_9:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b10);    TCCR1B |= (0b00 << 3U);
            break;
        case _TIM1_PHASE_CORRECT_PWM_10:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b11);    TCCR1B |= (0b00 << 3U);
            break;
        case _TIM1_PHASE_CORRECT_PWM_ICR:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b10);    TCCR1B |= (0b10 << 3U);
            break;
        case _TIM1_PHASE_CORRECT_PWM_OCRA:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b11);    TCCR1B |= (0b10 << 3U);
            break;
        case _TIM1_PHASE_FREQ_CORRECT_PWM_ICR:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b00);    TCCR1B |= (0b10 << 3U);
            break;
        case _TIM1_PHASE_FREQ_CORRECT_PWM_OCRA:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b01);    TCCR1B |= (0b10 << 3U);
            break;
        case _TIM1_FAST_PWM_8:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b01);    TCCR1B |= (0b01 << 3U);
            break;
        case _TIM1_FAST_PWM_9:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b10);    TCCR1B |= (0b01 << 3U);
            break;
        case _TIM1_FAST_PWM_10:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b11);    TCCR1B |= (0b01 << 3U);
            break;
        case _TIM1_FAST_PWM_ICR:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b10);    TCCR1B |= (0b11 << 3U);
            break;
        case _TIM1_FAST_PWM_OCRA:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b11);    TCCR1B |= (0b11 << 3U);
            break;
        case _TIM1_CTC_OCRA:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b00);    TCCR1B |= (0b01 << 3U);
            break;
        case _TIM1_CTC_ICR:
                TCCR1A &= (~(0b11)); TCCR1B &= (~(0b11 << 3U));
                TCCR1A |= (0b00);    TCCR1B |= (0b11 << 3U);
            break;
        default: break; /* Error handler */
    }
}/** @end TIMER_voidTIM1SetMode */
void TIMER_voidTIM1ASetOCmode(u8 Copy_u8OCmode)
{
    switch(Copy_u8OCmode)
    {
        case _TIM1_NORMAL_MODE:
                        BIT_CLR(TCCR1A, COM1A1);
                        BIT_CLR(TCCR1A, COM1A0);
                    break;
        case _TIM1_OC_TOGGLE_CM:
                        BIT_CLR(TCCR1A, COM1A1);
                        BIT_SET(TCCR1A, COM1A0);
                    break;
        case _TIM1_OC_CLEAR_CM:
                        BIT_SET(TCCR1A, COM1A1);
                        BIT_CLR(TCCR1A, COM1A0);
                    break;
        case _TIM1_OC_SET_CM:
                        BIT_SET(TCCR1A, COM1A1);
                        BIT_SET(TCCR1A, COM1A0);
                    break;
        default: break; /* Error handler */
    }
}/** @end TIMER_voidTIM1ASetOCmode */
void TIMER_voidTIM1BSetOCmode(u8 Copy_u8OCmode)
{
    switch(Copy_u8OCmode)
    {
        case _TIM1_OC_NORMAL:
                        BIT_CLR(TCCR1A, COM1B1);
                        BIT_CLR(TCCR1A, COM1B0);
                    break;
        case _TIM1_OC_TOGGLE_CM:
                        BIT_CLR(TCCR1A, COM1B1);
                        BIT_SET(TCCR1A, COM1B0);
                    break;
        case _TIM1_OC_CLEAR_CM:
                        BIT_SET(TCCR1A, COM1B1);
                        BIT_CLR(TCCR1A, COM1B0);
                    break;
        case _TIM1_OC_SET_CM:
                        BIT_SET(TCCR1A, COM1B1);
                        BIT_SET(TCCR1A, COM1B0);
                    break;
        default: break; /* Error handler */
    }
}/** @end TIMER_voidTIM1BSetOCmode */

/**
 * @defgroup TIMER2
 */

/**
 * @defgroup GENERAL USE
 */
void TIMER_voidTIMSetPreScaler(u8 Copy_u8TimerID, u16 Copy_u16PreScaler)
{
    u8 L_u8PrescalerValue = 0;

    switch(Copy_u8TimerID)
    {
        case TIM0_ID:
                L_u8PrescalerValue = u8GetPreScalerValue(Copy_u16PreScaler);
                TCCR0 &= (~(0b111));
                TCCR0 |= L_u8PrescalerValue;
            break;
        case TIM1_ID:
                L_u8PrescalerValue = u8GetPreScalerValue(Copy_u16PreScaler);
                TCCR1B &= (~(0b111));
                TCCR1B |= L_u8PrescalerValue;
            break;
        case TIM2_ID:
                L_u8PrescalerValue = u8GetPreScalerValue(Copy_u16PreScaler);
                TCCR0 &= (~(0b111));
                TCCR0 |= L_u8PrescalerValue;
            break;
        default: break; /* Error handler */
    }
}/** @end TIMER_voidTIMSetPreScaler */
/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup: Timer 0 Private Functions */
static void voidStartTimer0(void)
{
    TCNT0 = (u8) 0;
    TIMER_voidTIMSetPreScaler(TIM0_ID, TIM0_PRESCALER);
}/** @end voidStartTimer0 */
static void voidStopTimer0(void)
{
    TCNT0 = (u8) 0;
    TIMER_voidTIMSetPreScaler(TIM0_ID, _TIM_NO_CLKSOURCE);
}/** @end voidSetTimerStopValue */
static void voidSetTimer0StartValue(u8 Copy_u8StartValue)
{
	if( (Copy_u8StartValue > 255) )
	{
		Copy_u8StartValue = 255;
	}
	else if( (Copy_u8StartValue < 0) )
	{
		Copy_u8StartValue = 0;
	}
	else {;}

	TCNT0 = Copy_u8StartValue;
}/** @end voidSetTimer0StartValue */

/**
 * @brief:
 * DutyCycle: The ratio between Ton to Toff
 * 60% D.C means 60% Ton 40% Toff
 * Generated PWM Frequency: Depends on the CPU_CLOCK & Timer_Prescaler.
 * - For Timer_0. FAST_PWM_Freq = (CPU_CLOCK / (256*Timer0_Prescaler))
 * Max FAST_PWM_Freq: (MAX_CPU_CLOCK / (256*1))
 * Low FAST_PWM_Freq: (MIN_CPU_CLOCK / (256*MAX_Timer0_Prescaler))
 *
 * - For Timer_0. PC_PWM_Freq = (CPU_CLOCK / (512*Timer0_Prescaler))
 * Max PC_PWM_Freq: (MAX_CPU_CLOCK / (512*1))
 * Low PC_PWM_Freq: (MIN_CPU_CLOCK / (512*MAX_Timer0_Prescaler))
 * CPU_CLOCK can be fixed but will narrow the PWM_Freq range.
 */
static void voidTIM0SetDutyCycle(u8 Copy_u8DutyCycle)
{
    /** Error handling */
    if( (Copy_u8DutyCycle > 100) )
    { Copy_u8DutyCycle = 100; }
    else if( (Copy_u8DutyCycle < 0) )
    { Copy_u8DutyCycle = 0; }
    else {;}

#if ( (TIM0_MODE == _TIM0_FAST_PWM) )
    /** @note: PWM Configuration Parameters can be changed */
    OCR0 = (u8) u16CalculateFastPWMDutyCycleOCR(TIM0_ID, TIM0_PWM_MODE, Copy_u8DutyCycle);
#elif ( (TIM0_MODE == _TIM0_PHASE_CORRECT_PWM) )
    /** @note: PWM Configuration Parameters can be changed */
    OCR0 = (u8) u16CalculatePhaseCorrectPWMDutyCycleOCR(TIM0_ID, TIM0_PWM_MODE, Copy_u8DutyCycle);
#elif ( (TIM0_MODE == _TIM0_CTC) )
    OCR0 = OCR_VALUE; //(u8) u16CalculateCTCfreqOCR(TIM0_ID, CTC_PWM_FREQ);
#endif
}/** @end TIMER_voidTIM0SetDutyCycle */

/** @defgroup: Timer 1 Private Functions */
static void voidStartTimer1(void)
{
    TCNT1 = (u16) 0;
    TIMER_voidTIMSetPreScaler(TIM1_ID, TIM1_PRESCALER);
}/** @end voidStartTimer1 */

static void voidStopTimer1(void)
{
    TCNT1 = (u16) 0;
    TIMER_voidTIMSetPreScaler(TIM1_ID, TIM1_PRESCALER);
}/** @end voidStopTimer1 */


/** @defgroup: Timer 2 Private Functions */
/** @todo */

/** @defgroup: General Purpose Private Functions */
/**
* @brief:
* 1. Calculate Timer Ticks = (Timer_PS/F_CPU).
* 2. Calculate Max Delay = (Timer_Ticks / Timer_Resolution).
* 3. Calculate Timer Inital Value = ((Max_Delay-Delay)/ Timer_Ticks)
* 4. Calculate Number of Over Flows = (ceil)(Delay/MaxDelay).
* 5. Calculate Timer Inital Value = (Timer_Resolution - ((Copy_u32Delay/Timer_Ticks)/NOF))
*/
static u16 u16CalculateTimerInitalValue(u8 Copy_u8TimerID, f32 Copy_f32Delay, u32 *Address_u32OVFs)
{
    f32 L_f32TimerTicks = 0.0;
    f32 L_f32MaxDelay   = 0.0;
    u16 L_u16TimerInitalValue = 0;

    /** @def: Calculate the timer max delay */
    switch(Copy_u8TimerID)
    {
        case TIM0_ID:
                L_f32TimerTicks = (TIM0_PRESCALER / (f32)CPU_CLOCK);
                L_f32MaxDelay   = (L_f32TimerTicks * 0xFFU);
             break;
        case TIM1_ID:
                L_f32TimerTicks = (TIM1_PRESCALER / (f32)CPU_CLOCK);
                L_f32MaxDelay   = (L_f32TimerTicks * 0xFFFFU);
             break;
        case TIM2_ID:
                L_f32TimerTicks = (TIM2_PRESCALER / (f32)CPU_CLOCK);
                L_f32MaxDelay   = (L_f32TimerTicks * 0xFFU);
             break;
        default: break; /* Error handler */
    }/** @end switch: Copy_u8TimerID */
    /** @def: Calculate the Inital Value based on the condition */
    if( (Copy_f32Delay < L_f32MaxDelay) )
    {
        L_u16TimerInitalValue = ((L_f32MaxDelay-Copy_f32Delay)/(L_f32TimerTicks));
    }/** @end if */
    else if( (Copy_f32Delay == L_f32MaxDelay) )
    {
        L_u16TimerInitalValue = 0;
    }/** @end else if */
    else
    {
        u32 L_u32NumberOfOverFlows = u32MyCeil( (Copy_f32Delay/L_f32MaxDelay) );
        f32 L_f32TimeDelayOverTimerTicks = (Copy_f32Delay/L_f32TimerTicks);

        switch(Copy_u8TimerID)
        {   /** @note: The literal constant value is timer resulation. */
            case TIM0_ID:
                    L_u16TimerInitalValue = ( 0xFFU -
                    (L_f32TimeDelayOverTimerTicks/L_u32NumberOfOverFlows) );
                 break;
            case TIM1_ID:
                    L_u16TimerInitalValue = ( 0xFFFFU -
                    (L_f32TimeDelayOverTimerTicks/L_u32NumberOfOverFlows) );
                 break;
            case TIM2_ID:
                    L_u16TimerInitalValue = ( 0xFFU -
                    (L_f32TimeDelayOverTimerTicks/L_u32NumberOfOverFlows) );
                 break;
            default: break; /* Error handler */
        }/** @end switch: Copy_u8TimerID */
        /* Get the total number of over flows */
        *Address_u32OVFs = L_u32NumberOfOverFlows;
    }/** @end else */
    return L_u16TimerInitalValue;
}/** @end voidCalculateTimerInitalValue */

/**
 * @breif: Duty Cycle Calulcations
 * 1. NON-INVERTING-FAST_PWM
 *  DutyCycle = ((OCRx+1)/Timer_Resulution) * 100.
 *
 * 2. INVERTING-FAST_PWM
 *  DutyCycle = ((Timer_Resulution-(OCRx+1))/Timer_Resulution) * 100.
 * @note: PWM values should be the percentage value (0%-100%)D.C
 *        ex: For 56% DC => (Copy_u8DutyCycle = 56)
 */
static u16 u16CalculateFastPWMDutyCycleOCR(u8 Copy_u8TimerID, u8 Copy_u8OCmode, u8 Copy_u8DutyCycle)
{
    u16 L_u16RegisterValue = 0;

    switch(Copy_u8TimerID)
    { /** @note: Constant literals are specific used for this equation. */
        case TIM0_ID:
                if( (Copy_u8OCmode == _TIM_PWM_INVERTED) )
                {
                    L_u16RegisterValue = ( (255U) - ((2.56f) * Copy_u8DutyCycle) );
                }
                else if( ((Copy_u8OCmode == _TIM_PWM_NONINVERTED)) )
                {
                    L_u16RegisterValue = ( ((2.56f) * Copy_u8DutyCycle) - (1U) );
                }
                else {;}
             break;
        case TIM1_ID:
                if( (Copy_u8OCmode == _TIM_PWM_INVERTED) )
                {
                    L_u16RegisterValue = ( (65535U) - ((655.36f) * Copy_u8DutyCycle) );
                }
                else if( ((Copy_u8OCmode == _TIM_PWM_NONINVERTED)) )
                {
                    L_u16RegisterValue = ( ((655.36f) * Copy_u8DutyCycle) - (1U));
                }
                else {;}
             break;
        case TIM2_ID:
                if( (Copy_u8OCmode == _TIM_PWM_INVERTED) )
                {
                    L_u16RegisterValue = ( (255U) - ((2.56f) * Copy_u8DutyCycle) );
                }
                else if( ((Copy_u8OCmode == _TIM_PWM_NONINVERTED)) )
                {
                    L_u16RegisterValue = ( ((2.56f) * Copy_u8DutyCycle) - (1U));
                }
                else {;}
             break;
        default: break; /* Error handler */
    }/** @end switch: Copy_u8TimerID */
    return L_u16RegisterValue;
}/** @end u8CalculateTimerInitalValue */
/**
 * @breif: Duty Cycle Calulcations
 * 1. NON-INVERTING-FAST_PWM
 *  DutyCycle = ( ((2*OCR)/(2*(Timer_Resulution-1))) * 100).
 *
 * 2. INVERTING-FAST_PWM
 *  DutyCycle = (((2*(Timer_Resulution-1))-(2*OCR))/(2*(Timer_Resulution-1))) * 100
 * @note: PWM values should be the percentage value (0%-100%)D.C
 *        ex: For 56% DC => (Copy_u8DutyCycle = 56)
 */
static u16 u16CalculatePhaseCorrectPWMDutyCycleOCR(u8 Copy_u8TimerID,
                                                   u8 Copy_u8OCmode,
                                                   u8 Copy_u8DutyCycle)
{
    u16 L_u16RegisterValue = 0;

    switch(Copy_u8TimerID)
    { /** @note: Constant literals are specific used for this equation. */
        case TIM0_ID:
                if( (Copy_u8OCmode == _TIM_PWM_INVERTED) )
                {
                    L_u16RegisterValue = ( (255U) - ((2.55f) * Copy_u8DutyCycle) );
                }
                else if( ((Copy_u8OCmode == _TIM_PWM_NONINVERTED)) )
                {
                    L_u16RegisterValue = (2.55f * Copy_u8DutyCycle);
                }
                else {;}
             break;
        case TIM1_ID:
                if( (Copy_u8OCmode == _TIM_PWM_INVERTED) )
                {
                    L_u16RegisterValue = ( (65535U) - ((655.35f) * Copy_u8DutyCycle) );
                }
                else if( ((Copy_u8OCmode == _TIM_PWM_NONINVERTED)) )
                {
                    L_u16RegisterValue = ((655.35f) * Copy_u8DutyCycle);
                }
                else {;}
             break;
        case TIM2_ID:
                if( (Copy_u8OCmode == _TIM_PWM_INVERTED) )
                {
                    L_u16RegisterValue = ( (255U) - ((2.55f) * Copy_u8DutyCycle) );
                }
                else if( ((Copy_u8OCmode == _TIM_PWM_NONINVERTED)) )
                {
                    L_u16RegisterValue = (2.55f * Copy_u8DutyCycle);
                }
                else {;}
             break;
        default: break; /* Error handler */
    }/** @end switch: Copy_u8TimerID */
    return L_u16RegisterValue;
}/** @end u16CalculatePhaseCorrectPWMDutyCycleOCR */

/**
 * @brief:
 * F = CPU_CLOCK/(2*PreScaler*(1+OCR)) Hz
 */
u16 u16CalculateCTCfreqOCR(u8 Copy_u8TimerID, u16 Copy_u16Frequency)
{
    u16 L_u16OCRValue = 0;
    f32 L_f32Temporary = 0.0;

    switch(Copy_u8TimerID)
    {
        case TIM0_ID:
                L_f32Temporary = ((2U*TIM0_PRESCALER)/CPU_CLOCK);
                L_u16OCRValue = (1U/(L_f32Temporary*Copy_u16Frequency)) - 1;
            break;
        case TIM1_ID:
                L_f32Temporary = ((2U*TIM1_PRESCALER)/CPU_CLOCK);
                L_u16OCRValue = (1U/(L_f32Temporary*Copy_u16Frequency)) - 1;
            break;
        case TIM2_ID:
                L_f32Temporary = ((2U*TIM2_PRESCALER)/CPU_CLOCK);
                L_u16OCRValue = (1U/(L_f32Temporary*Copy_u16Frequency)) - 1;
            break;
        default: break; /* Error handler */
    }
    return L_u16OCRValue;
}/** @end u16CalculateCTCfreqOCR */

static u8 u8GetPreScalerValue(u16 Copy_u16PreScaler)
{
    u8 L_u8PreScalerValue = 0;

   switch(Copy_u16PreScaler)
    {
        case _TIM_NO_CLKSOURCE: L_u8PreScalerValue = (0b000); break;
        case _TIM_NO_PRESCALER: L_u8PreScalerValue = (0b001); break;
        case _TIM_8_PRESCALER:  L_u8PreScalerValue = (0b010); break;
        case _TIM_64_PRESCALER: L_u8PreScalerValue = (0b011); break;
        case _TIM_256_PRESCALER:  L_u8PreScalerValue = (0b100); break;
        case _TIM_1024_PRESCALER: L_u8PreScalerValue = (0b101); break;
        case _TIM_EXCxFALLINGxEDGE_PRESCALER: L_u8PreScalerValue = (0b110); break;
        case _TIM_EXCxRISINGxEDGE_PRESCALER:  L_u8PreScalerValue = (0b111); break;
        default: break; /* Error handler */
    }
    return L_u8PreScalerValue;
}/** @end u8GetPreScalerValue */

static u32 u32MyCeil(f32 Copy_f32Value)
{
    u32 L_ValueAsInteger = (u32) Copy_f32Value;
    u32 L_CeilValue = 0;

    if (Copy_f32Value == (f32) L_ValueAsInteger)
    {
        L_CeilValue = L_ValueAsInteger;
    }
    else
    {
        L_CeilValue = L_ValueAsInteger + 1;
    }
    return L_CeilValue;
}/** @end u32MyCeil */

void TIM0_COMP_ISR(void)
{
    if( (G_Timer0CallBackFunction[TIM0_COMP_ISR_ID] != NULL) )
    {
        G_Timer0CallBackFunction[TIM0_COMP_ISR_ID]();
    }
    else
    {
        #if (TIM0_MODE == _TIM0_CTC)
            #if (CTC_PWM_FREQ > 0)

            /** @todo: Do operation */

            #endif
        #endif
    }/** @end else: CallBack */
}/* @end TIM0_COMP_ISR */

void TIM0_OVF_ISR(void)
{
    /** @note: Alternate ISR functionality */
    if( (1 == G_u8DelayAsyncFlag) )
    {
        if( (G_u32DelayAsyncOVFCounter >= G_u32DelayAsyncOVFValue) )
        {
            /** Evaluate the needed function */
        	G_Timer0CallBackFunction[TIM0_OVF_ISR_ID]();

        	G_u32DelayAsyncOVFCounter = 0;

            if( (G_u8DelayAsyncMode == AsyncMode_Single) )
            {
            	/** Disable TimerOverFlow Interrupt */
            	BIT_CLR(TIMSK, TOIE0);
                voidStopTimer0();
                G_u8DelayAsyncFlag = 0;
            }else {;}/** @end else: AsyncMode_Periodic */
        }
        else
        {
            ++G_u32DelayAsyncOVFCounter;
        }/** @end else: OVF Counter */
    }
    /** @note: The actual functionality of the ISR */
    else
    {
        if( (NULL != G_Timer0CallBackFunction[TIM0_OVF_ISR_ID]) )
        {
            G_Timer0CallBackFunction[TIM0_OVF_ISR_ID]();
        }else {;}
    }/** @end else: CallBack */
}/* @end TIM0_OVF_ISR */
