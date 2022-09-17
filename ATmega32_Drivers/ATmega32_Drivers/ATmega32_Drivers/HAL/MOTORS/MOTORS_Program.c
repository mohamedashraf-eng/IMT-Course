/**
 * @file MOTORS_Program.c
 * 
 * @author: Mohamed Wx
 * @date Aug 25, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	HEADERS INCLUDED
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER/TIMER_Interface.h"

#include "MOTORS_Private.h"
#include "MOTORS_Interface.h"
#include "MOTORS_Config.h"

#include <avr/delay.h>

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup DC Motor */
void MOTOR_voidDcSystemInitalization(void)
{
	u8 L_u8Iterator;

	for(L_u8Iterator = 0; (L_u8Iterator < NUM_OF_DC_MOTORS); ++L_u8Iterator)
	{ voidDCMotorInitalization(L_u8Iterator); }
}/** @end MOTOR_voidDcSystemInitalization */

void MOTOR_voidSetDcMotorSpeed(u8 Copy_u8MotorID, u8 Copy_u8MotorSpeed)
{
	/** @todo to be added after PWM Timer */
	switch(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].TIM_CH)
	{
		case TIM0_ID: TIMER_voidTIM0GeneratePWM(Copy_u8MotorSpeed);	break;
		case TIM1_ID: break;
		case TIM2_ID: break;
		default: break; /* Error handler */
	}
}/** @end MOTOR_voidSetDcMotorSpeed */

void MOTOR_voidSetDcMotorDirection(u8 Copy_u8MotorID, u8 Copy_u8MotorDirection)
{
	switch(Copy_u8MotorDirection)
	{
		case ClockWise: voidSetDCMotorCW(Copy_u8MotorID);	break;
		case CounterClockWise: voidSetDCMotorCCW(Copy_u8MotorID);	break;
		default: break; /* Error handler */
	}
}/** @end MOTOR_voidSetDcMotorDirection */


/** @defgroup Servo Motor */
void MOTOR_voidServoSystemInitalization(void)
{
	u8 L_u8Iterator;

	for(L_u8Iterator = 0; (L_u8Iterator < NUM_OF_DC_MOTORS); ++L_u8Iterator)
	{ voidServoMotorInitalization(L_u8Iterator); }
}/** @end MOTOR_voidServoSystemInitalization */

void MOTOR_voidSetServoAngle(u8 Copy_u8ServoID, u8 Copy_u8ServoAngle)
{
	u8 L_u8AngleDutyCycle = u8ServoMotorAngleToPWM(Copy_u8ServoAngle);

	switch(MyMotorsConfig.MyServoMotorConfig[Copy_u8ServoID].TIM_CH)
	{
		case TIM0_ID: TIMER_voidTIM0GeneratePWM(L_u8AngleDutyCycle);	break;
		case TIM1_ID: break;
		case TIM2_ID: break;
		default: break; /* Error handler */
	}
}/** @end MOTOR_voidSetServoAngle */

/** @defgroup Stepper Motor */
void MOTOR_voidStepperSystemInitalization(void)
{
	u8 L_u8Iterator;

	for(L_u8Iterator = 0; (L_u8Iterator < NUM_OF_DC_MOTORS); ++L_u8Iterator)
	{ voidStepperMotorInitalization(L_u8Iterator); }
}/** @end MOTOR_voidStepperSystemInitalization */

void MOTOR_voidSetStepperStep(u8 Copy_u8StepperID, u8 Copy_u8StepMode, u8 Copy_u8StepperStep)
{
	if( (Copy_u8StepMode == FullStep) )
	{
		switch(Copy_u8StepperStep)
		{
			case Step_1: 	voidStepperFullStep_1(Copy_u8StepperID);	break;
			case Step_2:	voidStepperFullStep_2(Copy_u8StepperID);	break;
			case Step_3:	voidStepperFullStep_3(Copy_u8StepperID);	break;
			case Step_4:	voidStepperFullStep_4(Copy_u8StepperID);	break;
			default: break; /* Error handler */
		}
	}/* End: full step*/
	else if( (Copy_u8StepMode == HalfStep) )
	{
		switch(Copy_u8StepperStep)
		{
			case Step_1:	voidStepperHalfStep_1(Copy_u8StepperID);	break;
			case Step_2:	voidStepperHalfStep_2(Copy_u8StepperID);	break;
			case Step_3:	voidStepperHalfStep_3(Copy_u8StepperID);	break;
			case Step_4:	voidStepperHalfStep_4(Copy_u8StepperID);	break;
			case Step_5:	voidStepperHalfStep_5(Copy_u8StepperID);	break;
			case Step_6:	voidStepperHalfStep_6(Copy_u8StepperID);	break;
			case Step_7:	voidStepperHalfStep_7(Copy_u8StepperID);	break;
			case Step_8:	voidStepperHalfStep_8(Copy_u8StepperID);	break;
			default: break; /* Error handler */
		}
	}/* End: half step*/
	else
	{
		/* Error handler */
		return;
	}
}/** @end MOTOR_voidSetStepperStep */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup DC Motor */
static void voidSetDCMotorCW(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN1_PORT_ID,
						MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN1_PIN_ID,
						HIGH);

	DIO_voidSetPinValue(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN2_PORT_ID,
						MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN2_PIN_ID,
						LOW);
}/** @end MOTOR_voidSetDCMotorCW */

static void voidSetDCMotorCCW(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN1_PORT_ID,
						MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN1_PIN_ID,
						LOW);

	DIO_voidSetPinValue(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN2_PORT_ID,
						MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN2_PIN_ID,
						HIGH);
}/** @end MOTOR_voidSetDCMotorCCW */

static void voidDCMotorInitalization(u8 Copy_u8MotorID)
{
	/** @defgroup set directions */
	DIO_voidSetPinDirection(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].SPD_PORT_ID,
							MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].SPD_PIN_ID,
							OUTPUT);
	DIO_voidSetPinDirection(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN1_PORT_ID,
							MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN1_PIN_ID,
							OUTPUT);
	DIO_voidSetPinDirection(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN2_PORT_ID,
							MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN2_PIN_ID,
							OUTPUT);
	/** @defgroup set inital values  */
	DIO_voidSetPinValue(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].SPD_PORT_ID,
						MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].SPD_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN1_PORT_ID,
						MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN1_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN2_PORT_ID,
						MyMotorsConfig.MyDcMotorConfig[Copy_u8MotorID].IN2_PIN_ID,
						LOW);

	switch(MyMotorsConfig.MyServoMotorConfig[Copy_u8MotorID].TIM_CH)
	{
		case TIM0_ID:
				DIO_voidSetPinDirection(PORT_B, PIN_4, OUTPUT);
				TIMER_voidTIM0Init();
			break;
		case TIM1_ID: break;
		case TIM2_ID: break;
		default: break; /* Error handler */
	}
}/** @end voidDCMotorInitalization */

/** @defgroup Servo Motor */
static void voidServoMotorInitalization(u8 Copy_u8MotorID)
{
	DIO_voidSetPinDirection(MyMotorsConfig.MyServoMotorConfig[Copy_u8MotorID].PORT_ID,
							MyMotorsConfig.MyServoMotorConfig[Copy_u8MotorID].PIN_ID,
							OUTPUT);

	DIO_voidSetPinValue(MyMotorsConfig.MyServoMotorConfig[Copy_u8MotorID].PORT_ID,
						MyMotorsConfig.MyServoMotorConfig[Copy_u8MotorID].PIN_ID,
						LOW);

	switch(MyMotorsConfig.MyServoMotorConfig[Copy_u8MotorID].TIM_CH)
	{
		case TIM0_ID: TIMER_voidTIM0Init();	break;
		case TIM1_ID: break;
		case TIM2_ID: break;
		default: break; /* Error handler */
	}
}/** @end voidServoMotorInitalization */
static u8 u8ServoMotorAngleToPWM(u8 Copy_u8ServoAngle)
{
	f32 L_f32ServoPulse = f32ServoMotorGetAnglePulse(Copy_u8ServoAngle);

	u8 L_u8PulseDutyCycle = (L_f32ServoPulse / SERVO_MAX_PERIOD_MS) * 100;

	return L_u8PulseDutyCycle;
}/** @end u8ServoMotorAngleToPWM */
static f32 f32ServoMotorGetAnglePulse(u8 Copy_u8ServoAngle)
{
	f32 L_f32ServoPulse =
	((Copy_u8ServoAngle * (SERVO_MAX_PERIOD_MS - SERVO_MIN_PERIOD_MS)/(180.0))) + (SERVO_MIN_PERIOD_MS);

	return L_f32ServoPulse;
}/** @end voidServoMotorAngleToPWM */

/** @defgroup Stepper Motor */
static void voidStepperMotorInitalization(u8 Copy_u8MotorID)
{
	/** @defgroup set directions */
	DIO_voidSetPinDirection(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
							OUTPUT);
	DIO_voidSetPinDirection(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
							OUTPUT);
	DIO_voidSetPinDirection(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
							OUTPUT);
	DIO_voidSetPinDirection(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
							OUTPUT);

	/** @defgroup set inital values  */
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						LOW);
}/** @end voidStepperMotorInitalization */
/** @def Full Steps*/
static void voidStepperFullStep_1(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						LOW);
}/** @end voidStepperFullStep_1 */
static void voidStepperFullStep_2(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						LOW);
}/** @end voidStepperFullStep_2 */
static void voidStepperFullStep_3(u8 Copy_u8MotorID)
{
	{
		DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
							LOW);
		DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
							LOW);
		DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
							HIGH);
		DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
							LOW);
	}/** @end voidStepperFullStep_3 */
}
static void voidStepperFullStep_4(u8 Copy_u8MotorID)
{
	{
		DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
							LOW);
		DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
							LOW);
		DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
							LOW);
		DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
							MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
							HIGH);
	}/** @end voidStepperFullStep_4 */
}
/** @def Half Steps*/
static void voidStepperHalfStep_1(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						HIGH);
}/** @end voidStepperHalfStep_1 */
static void voidStepperHalfStep_2(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						LOW);
}/** @end voidStepperHalfStep_2 */
static void voidStepperHalfStep_3(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						LOW);
}/** @end voidStepperHalfStep_3 */
static void voidStepperHalfStep_4(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						LOW);
}/** @end voidStepperHalfStep_4 */
static void voidStepperHalfStep_5(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						LOW);
}/** @end voidStepperHalfStep_5 */
static void voidStepperHalfStep_6(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						LOW);
}/** @end voidStepperHalfStep_6 */
static void voidStepperHalfStep_7(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						HIGH);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						HIGH);
}/** @end voidStepperHalfStep_7 */
static void voidStepperHalfStep_8(u8 Copy_u8MotorID)
{
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE1_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE2_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE3_PIN_ID,
						LOW);
	DIO_voidSetPinValue(MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PORT_ID,
						MyMotorsConfig.MyStepperMotorConfig[Copy_u8MotorID].POLE4_PIN_ID,
						HIGH);
}/** @end voidStepperHalfStep_8 */
