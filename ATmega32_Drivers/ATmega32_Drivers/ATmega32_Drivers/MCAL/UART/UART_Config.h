/**
 * @file UART_Config.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    CONFIGURATION PARAMETERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/**
 * @def: Configuration Parameters
 * - UART_TYPE_SYNCHRONOUS
 * - UART_TYPE_ASYNCHRONOUS
 */
#define UART_TYPE       UART_TYPE_ASYNCHRONOUS
/**
 * Configuration Parameters:
 * - UART_SPEED_NORMAL
 * - UART_SPEED_DOUBLE
 */
#define UART_SPEED      UART_SPEED_NORMAL
/**
 * @def: Configuration Parameters
 * - UART_DATA_5BIT
 * - UART_DATA_6BIT
 * - UART_DATA_7BIT
 * - UART_DATA_8BIT
 * - UART_DATA_9BIT
 */
#define UART_DATA       UART_DATA_8BIT
/**
 * @def: Configuration Parameters
 * @brief: Make sure to check the "F_CLK" before chosing
 * @defgroup: F_CLK: 4Mhz setup
 * - UART_N_f4Mhz_BAUDRATE_9600bps
 * - UART_N_f4Mhz_BAUDRATE_115200bps
 * - UART_N_f4Mhz_BAUDRATE_230400bps
 * - UART_N_f4Mhz_BAUDRATE_250000bps
 * - UART_N_f4Mhz_BAUDRATE_500000bps
 * @defgroNup: F_CLK: 8Mhz setup
 * - UART_N_f8Mhz_BAUDRATE_9600bps
 * - UART_N_f8Mhz_BAUDRATE_57600bps
 * - UART_N_f8Mhz_BAUDRATE_115200bps
 * - UART_N_f8Mhz_BAUDRATE_230400bps
 * - UART_N_f8Mhz_BAUDRATE_250000bps
 * - UART_N_f8Mhz_BAUDRATE_500000bps
 * @todo:To be add more options.
 */
#define UART_BAUDRATE   UART_N_f8Mhz_BAUDRATE_9600bps
/**
 * @def: Configuration Parameters
 * - UART_PARITY_NON
 * - UART_PARITY_EVEN
 * - UART_PARITY_ODD
 */
#define UART_PARITY     UART_PARITY_NON
/**
 * @def: Configuration Parameters
 * - UART_STOP_1BIT
 * - UART_STOP_2BIT
 */
#define UART_STOP       UART_STOP_1BIT
/**
 * @def: Configuration Parameters
 * - UART_TRANSMITTER_MODE
 * - UART_RECEIVER_MODE
 * - UART_TRANSMITTERxRECEIVER_MODE
 */
#define UART_MODE       UART_TRANSMITTER_MODE
/**
 * @def: Configuration Parameters
 * - UART_DISABLED
 * - UART_ENABLED
 */
#define UART_STATE      UART_ENABLED


#endif /* MCAL_UART_UART_CONFIG_H_ */
