/**
 * @file TIMER_Config.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    CONFIGURATION PARAMETERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define CPU_CLOCK   (8000000UL)

/** @defgroup: Timer_0 Configuration Parameters */
/**
 * @brief: Configuration Parameters for Timer 0
 *
 * For TIM0_MODE:
 *   _TIM0_NORMAL_MODE
 *   _TIM0_PHASE_CORRECT_PWM
 *   _TIM0_CTC
 *   _TIM0_FAST_PWM
 *
 * For TIM0_COM_MODE:
 *   _TIM0_OC_NORMAL
 *   _TIM0_OC_TOGGLE_CM
 *   _TIM0_OC_CLEAR_CM
 *   _TIM0_OC_SET_CM
 *
 * For TIM0_PWM_MODE:
 *   _PWM_INVERTED
 *   _PWM_NONINVERTED
 */
#define TIM0_MODE       _TIM0_PHASE_CORRECT_PWM
#define TIM0_COM_MODE   _TIM0_OC_SET_CM
#define TIM0_PRESCALER  _TIM_8_PRESCALER

#if ( (TIM0_MODE == _TIM0_FAST_PWM) || \
      (TIM0_MODE == _TIM0_PHASE_CORRECT_PWM) )

    #define TIM0_PWM_MODE  _TIM_PWM_INVERTED

#elif (TIM0_MODE == _TIM0_CTC)

	#define OCR_VALUE (77U) /** @todo: To be modified (Debug the equation function) */
      #define CTC_PWM_FREQ (50U)

#endif

/** @defgroup: Timer_1 Configuration Parameters */
/**
 * @brief: Configuration Parameters for Timer 1
 *
 * For TIM1_MODE:
 * _TIM1_NORMAL_MODE
 * _TIM1_PHASE_CORRECT_PWM_8
 * _TIM1_PHASE_CORRECT_PWM_9
 * _TIM1_PHASE_CORRECT_PWM_10
 * _TIM1_PHASE_CORRECT_PWM_ICR
 * _TIM1_PHASE_CORRECT_PWM_OCRA
 * _TIM1_PHASE_FREQ_CORRECT_PWM_ICR
 * _TIM1_PHASE_FREQ_CORRECT_PWM_OCRA
 * _TIM1_FAST_PWM_8
 * _TIM1_FAST_PWM_9
 * _TIM1_FAST_PWM_10
 * _TIM1_FAST_PWM_ICR
 * _TIM1_FAST_PWM_OCRA
 * _TIM1_CTC_OCRA
 * _TIM1_CTC_ICR 
 *
 * For TIM1_COM_MODE:
 *   _TIM1_OC_NORMAL
 *   _TIM1_OC_TOGGLE_CM
 *   _TIM1_OC_CLEAR_CM
 *   _TIM1_OC_SET_CM
 *
 * For TIM1_PWM_MODE:
 *   _PWM_INVERTED
 *   _PWM_NONINVERTED
 */
#define TIM1_MODE       _TIM1_NORMAL_MODE
#define TIM1_COM_MODE   _TIM1_OC_NORMAL
#define TIM1_PRESCALER  _TIM_1024_PRESCALER

#if ( (TIM1_MODE == _TIM1_FAST_PWM) || \
      (TIM1_MODE == _TIM1_PHASE_CORRECT_PWM) )

    #define TIM1_PWM_MODE  _TIM_PWM_INVERTED

#endif
/** @defgroup: Timer_2 Configuration Parameters */
#define TIM2_MODE       _TIM2_NORMAL_MODE
#define TIM2_COM_MODE   _TIM2_OC_NORMAL
#define TIM2_PRESCALER  _TIM_1024_PRESCALER

#if ( (TIM2_MODE == _TIM2_FAST_PWM) || \
      (TIM2_MODE == _TIM2_PHASE_CORRECT_PWM) )

    #define TIM0_PWM_MODE  _TIM_PWM_INVERTED

#endif
#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
