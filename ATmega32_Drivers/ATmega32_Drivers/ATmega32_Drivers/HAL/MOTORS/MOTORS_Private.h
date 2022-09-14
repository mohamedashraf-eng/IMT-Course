/**
 * @file MOTORS_Private.h
 * 
 * @author: Mohamed Wx
 * @date Aug 25, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef HAL_MOTORS_MOTORS_PRIVATE_H_
#define HAL_MOTORS_MOTORS_PRIVATE_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define NUM_OF_DC_MOTORS		   (1U)
#define NUM_OF_SERVO_MOTORS	  	   (1U)
#define NUM_OF_STEPPER_MOTORS      (1U)

#define STEPPER_DELAY              (5U)

#define SERVO_MAX_PERIOD_MS        (2U)
#define SERVO_MIN_PERIOD_MS        (1U)

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	STRUCTS & GLOBALS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

struct DC_MOTOR_CONFIG
{
	u8 SPD_PORT_ID;
	u8 IN1_PORT_ID;
	u8 IN2_PORT_ID;

	u8 SPD_PIN_ID;
	u8 IN1_PIN_ID;
	u8 IN2_PIN_ID;

    u8 TIM_CH;
};

struct SERVO_MOTOR_CONFIG
{
	u8 PORT_ID;
	u8 PIN_ID;
    u8 TIM_CH;
};

struct STEPPER_MOTOR_CONFIG
{
	u8 POLE1_PORT_ID;
	u8 POLE2_PORT_ID;
	u8 POLE3_PORT_ID;
	u8 POLE4_PORT_ID;

	u8 POLE1_PIN_ID;
	u8 POLE2_PIN_ID;
	u8 POLE3_PIN_ID;
	u8 POLE4_PIN_ID;
};

typedef struct
{
	struct DC_MOTOR_CONFIG MyDcMotorConfig[NUM_OF_DC_MOTORS];
	struct SERVO_MOTOR_CONFIG MyServoMotorConfig[NUM_OF_SERVO_MOTORS];
	struct STEPPER_MOTOR_CONFIG MyStepperMotorConfig[NUM_OF_STEPPER_MOTORS];
}ST_MotorsConfig_t;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup DC Motor */
static void voidSetDCMotorCW(u8 Copy_u8MotorID);
static void voidSetDCMotorCCW(u8 Copy_u8MotorID);
static void voidDCMotorInitalization(u8 Copy_u8MotorID);

/** @defgroup Servo Motor */
static void voidServoMotorInitalization(u8 Copy_u8MotorID);
static u8 u8ServoMotorAngleToPWM(u8 Copy_u8ServoAngle);
static f32 f32ServoMotorGetAnglePulse(u8 Copy_u8ServoAngle);

/** @defgroup Stepper Motor */
static void voidStepperMotorInitalization(u8 Copy_u8MotorID);

static void voidStepperFullStep_1(u8 Copy_u8MotorID);
static void voidStepperFullStep_2(u8 Copy_u8MotorID);
static void voidStepperFullStep_3(u8 Copy_u8MotorID);
static void voidStepperFullStep_4(u8 Copy_u8MotorID);


static void voidStepperHalfStep_1(u8 Copy_u8MotorID);
static void voidStepperHalfStep_2(u8 Copy_u8MotorID);
static void voidStepperHalfStep_3(u8 Copy_u8MotorID);
static void voidStepperHalfStep_4(u8 Copy_u8MotorID);
static void voidStepperHalfStep_5(u8 Copy_u8MotorID);
static void voidStepperHalfStep_6(u8 Copy_u8MotorID);
static void voidStepperHalfStep_7(u8 Copy_u8MotorID);
static void voidStepperHalfStep_8(u8 Copy_u8MotorID);

#endif /* HAL_MOTORS_MOTORS_PRIVATE_H_ */
