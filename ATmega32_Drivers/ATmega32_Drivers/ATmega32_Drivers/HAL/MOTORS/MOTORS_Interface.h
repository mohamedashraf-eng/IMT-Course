/**
 * @file MOTORS_Interface.h
 * 
 * @author: Mohamed Wx
 * @date Aug 25, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef HAL_MOTORS_MOTORS_INTERFACE_H_
#define HAL_MOTORS_MOTORS_INTERFACE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

enum MOTOR_DIRECTION
{
	ClockWise,
	CounterClockWise
};

enum STEPPER_MOTOR_MODES
{
	HalfStep,
	FullStep
};

enum STEPPER_STEPS
{
	Step_1,
	Step_2,
	Step_3,
	Step_4,
	Step_5,
	Step_6,
	Step_7,
	Step_8
};

enum SET_OF_MOTORS_ID
{
	MOTOR1_ID,
	MOTOR2_ID,
	MOTOR3_ID,
	MOTOR4_ID
};

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	STRUCTS & GLOBALS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup DC Motors */

void MOTOR_voidDcSystemInitalization(void);
void MOTOR_voidSetDcMotorSpeed(u8 Copy_u8MotorID, u8 Copy_u8MotorSpeed);
void MOTOR_voidSetDcMotorDirection(u8 Copy_u8MotorID, u8 Copy_u8MotorDirection);

/** @defgroup Servo Motors */
void MOTOR_voidServoSystemInitalization(void);
void MOTOR_voidSetServoAngle(u8 Copy_u8ServoID, u8 Copy_u8ServoAngle);

/** @defgroup Stepper Motors */
void MOTOR_voidStepperSystemInitalization(void);
void MOTOR_voidSetStepperStep(u8 Copy_u8StepperID, u8 Copy_u8StepMode, u8 Copy_u8StepperStep);

#endif /* HAL_MOTORS_MOTORS_INTERFACE_H_ */
