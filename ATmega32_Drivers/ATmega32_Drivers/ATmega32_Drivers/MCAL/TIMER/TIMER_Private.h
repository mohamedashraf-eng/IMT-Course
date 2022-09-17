/**
 * @file TIMER_Private.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    REGISTERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup addresses */
#define PERIPHERAL_MMIO_OFFSET      ( (u8) (0x20) )

/** @def macro like function to convert the peripheral address to its mmio address */
#define MMIO_ADDRESS(PERIPHERAL)    ( (PERIPHERAL + PERIPHERAL_MMIO_OFFSET) )

/** @defgroup: Global timer registers */
#define TIMSK    ( *((u8 volatile *) (MMIO_ADDRESS(0x39))) )
#define TIFR     ( *((u8 volatile *) (MMIO_ADDRESS(0x38))) )
#define SFIOR    ( *((u8 volatile *) (MMIO_ADDRESS(0x30))) )
/** @defgroup: Timer/Counter 0 Registers */
#define OCR0     ( *((u8 volatile *) (MMIO_ADDRESS(0x3C))) )
#define TCCR0    ( *((u8 volatile *) (MMIO_ADDRESS(0x33))) )
#define TCNT0    ( *((u8 volatile *) (MMIO_ADDRESS(0x32))) )
/** @defgroup: Timer/Counter 1 Registers */
#define TCCR1A   ( *((u8 volatile *) (MMIO_ADDRESS(0x2F))) )
#define TCCR1B   ( *((u8 volatile *) (MMIO_ADDRESS(0x2E))) )
#define TCNT1H   ( *((u8 volatile *) (MMIO_ADDRESS(0x2D))) )
#define TCNT1L   ( *((u8 volatile *) (MMIO_ADDRESS(0x2C))) )
#define TCNT1    ( *((u16 volatile *) (MMIO_ADDRESS(0x2C))) ) /** @def: The Full Register */
#define OCR1AH   ( *((u8 volatile *) (MMIO_ADDRESS(0x2B))) )
#define OCR1AL   ( *((u8 volatile *) (MMIO_ADDRESS(0x2A))) )
#define OCR1A    ( *((u16 volatile *) (MMIO_ADDRESS(0x2A))) ) /** @def: The Full Register */
#define OCR1BH   ( *((u8 volatile *) (MMIO_ADDRESS(0x29))) )
#define OCR1BL   ( *((u8 volatile *) (MMIO_ADDRESS(0x28))) )
#define OCR1B    ( *((u16 volatile *) (MMIO_ADDRESS(0x28))) ) /** @def: The Full Register */
#define ICR1H    ( *((u8 volatile *) (MMIO_ADDRESS(0x27))) )
#define ICR1L    ( *((u8 volatile *) (MMIO_ADDRESS(0x26))) )
#define ICR1     ( *((u16 volatile *) (MMIO_ADDRESS(0x26))) ) /** @def: The Full Register */
/** @defgroup: Timer/Counter 2 Registers */
#define TCCR2    ( *((u8 volatile *) (MMIO_ADDRESS(0x25))) )
#define TCNT2    ( *((u8 volatile *) (MMIO_ADDRESS(0x24))) )
#define OCR2     ( *((u8 volatile *) (MMIO_ADDRESS(0x23))) )

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

typedef void (*Timer0CallBackFunction_t)(void);

enum TCCR0_BITS
{
    CS00,
    CS01,
    CS02,
    WGM01,
    COM00,
    COM01,
    WGM00,
    FOC0
};

enum TIMSK_BITS
{
    TOIE0,
    OCIE0,
    TOIE1,
    OCIE1B,
    OCIE1A,
    TICIE1,
    TOIE2,
    OCIE2
};

enum TIFR_BITS
{
    TOV0,
    OCF0,
    TOV1,
    OCF1B,
    OCF1A,
    ICF1,
    TOV2,
    OCF2
};

enum TCCR1A_BITS
{
    WGM10,
    WGM11,
    FOC1B,
    FOC1A,
    COM1B0,
    COM1B1,
    COM1A0,
    COM1A1
};

enum TCCR1B_BITS
{
    CS10    = 0,
    CS11    = 1,
    CS12    = 2,
    WGM12   = 3,
    WGM13   = 4,
    ICES1   = 6,
    ICNC1   =7
};


/**
 * @defgroup TIMER0
 */
#define _TIM0_NORMAL_MODE                    0
#define _TIM0_PHASE_CORRECT_PWM              1
#define _TIM0_CTC                            2
#define _TIM0_FAST_PWM                       3

#define _TIM0_OC_NORMAL                      0
#define _TIM0_OC_TOGGLE_CM                   1
#define _TIM0_OC_CLEAR_CM                    2
#define _TIM0_OC_SET_CM                      3

/**
 * @defgroup TIMER1
 */
#define _TIM1_NORMAL_MODE                    0
#define _TIM1_PHASE_CORRECT_PWM_8            1
#define _TIM1_PHASE_CORRECT_PWM_9            2
#define _TIM1_PHASE_CORRECT_PWM_10           3
#define _TIM1_PHASE_CORRECT_PWM_ICR          4
#define _TIM1_PHASE_CORRECT_PWM_OCRA         5
#define _TIM1_PHASE_FREQ_CORRECT_PWM_ICR     6
#define _TIM1_PHASE_FREQ_CORRECT_PWM_OCRA    7
#define _TIM1_FAST_PWM_8                     8
#define _TIM1_FAST_PWM_9                     9
#define _TIM1_FAST_PWM_10                    10
#define _TIM1_FAST_PWM_ICR                   11
#define _TIM1_FAST_PWM_OCRA                  12
#define _TIM1_CTC_OCRA                       13
#define _TIM1_CTC_ICR                        14

#define _TIM1_OC_NORMAL                      0
#define _TIM1_OC_TOGGLE_CM                   1
#define _TIM1_OC_CLEAR_CM                    2
#define _TIM1_OC_SET_CM                      3

/**
 * @defgroup TIMER2
 */

/**
 * @defgroup GENERAL CONFIGS
 */
#define _TIM_NO_CLKSOURCE                   0
#define _TIM_NO_PRESCALER                   1
#define _TIM_8_PRESCALER                    8
#define _TIM_64_PRESCALER                   64
#define _TIM_256_PRESCALER                  256
#define _TIM_1024_PRESCALER                 1024
#define _TIM_EXCxFALLINGxEDGE_PRESCALER     13
#define _TIM_EXCxRISINGxEDGE_PRESCALER      14

#define _TIM_PWM_INVERTED       0
#define _TIM_PWM_NONINVERTED    1

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/
/** @defgroup: Timer 0 Private Functions */
static void voidTIM0SetDutyCycle(u8 Copy_u8DutyCycle);
static void voidStartTimer0(void);
static void voidStopTimer0(void);
static void voidSetTimer0StartValue(u8 Copy_u8StartValue);
/** @defgroup: Timer 1 Private Functions */
static void voidTIM1SetDutyCycle(u8 Copy_u8DutyCycle);
static void voidStartTimer1(void);
static void voidStopTimer1(void);
static void voidSetTimer1StartValue(u8 Copy_u8StartValue);

/** @defgroup: General Purpose Private Functions */
u16 u16CalculateCTCfreqOCR(u8 Copy_u8TimerID, u16 Copy_u16Frequency);
static u16 u16CalculateTimerInitalValue(u8 Copy_u8TimerID, f32 Copy_f32Delay, u32 *Address_u32OVFs);
static u16 u16CalculateFastPWMDutyCycleOCR(u8 Copy_u8TimerID, u8 Copy_u8OCmode, u8 Copy_u8DutyCycle);
static u16 u16CalculatePhaseCorrectPWMDutyCycleOCR(u8 Copy_u8TimerID,
                                                   u8 Copy_u8OCmode,
                                                   u8 Copy_u8DutyCycle);
static u8 u8GetPreScalerValue(u16 Copy_u16PreScaler);
static u32 u32MyCeil(f32 Copy_f32Value);




/** @defgroup ISR Functions */  /** @note Compiler Optimization */
#define TIM0_OVF_ISR   ( __vector_11 )
#define TIM0_COMP_ISR  ( __vector_10 )
#define TIM1_OVF_ISR   ( __vector_9  )
#define TIM1_COMPB_ISR ( __vector_8  )
#define TIM1_COMPA_ISR ( __vector_7  )
#define TIM1_CAPT_ISR  ( __vector_6  )
#define TIM2_OVF_ISR   ( __vector_5  )
#define TIM2_COMP_ISR  ( __vector_4  )

void __vector_11(void) __attribute__( (signal, used) );   /** @def TIMER0 OVF   */
void __vector_10(void) __attribute__( (signal, used) );   /** @def TIMER0 COMP  */
void __vector_9(void)  __attribute__( (signal, used) );   /** @def TIMER1 OVF   */
void __vector_8(void)  __attribute__( (signal, used) );   /** @def TIMER1 COMPB */
void __vector_7(void)  __attribute__( (signal, used) );   /** @def TIMER1 COMPA */
void __vector_6(void)  __attribute__( (signal, used) );   /** @def TIMER1 CAPT  */
void __vector_5(void)  __attribute__( (signal, used) );   /** @def TIMER2 OVF   */
void __vector_4(void)  __attribute__( (signal, used) );   /** @def TIMER2 COMP  */

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
