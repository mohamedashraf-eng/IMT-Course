/*
 * SSD_Config.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Wx
 */
/** @def Header Guards */
#ifndef HAL_SSD_SSD_CONFIG_H_
#define HAL_SSD_SSD_CONFIG_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -	MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/**
 * Available ports options :
 *  1. PORT_A
 *  2. PORT_B
 *  3. PORT_C
 *  4. PORT_D
 * */
#define SSD1_PORT		( PORT_B )
#define SSD2_PORT		( PORT_B )

#define SSD1_COMM_PORT	( PORT_A )
#define SSD1_COMM_PIN	( PIN_1	 )

#define SSD2_COMM_PORT  ( PORT_A )
#define SSD2_COMM_PIN	( PIN_2	 )

/**
 * Available common options:
 *  1. COMMON_CATHODE
 *  2. COMMON_ANODE
 * */
#define SSD1_COMMON	 ( COMMON_CATHODE )
#define SSD2_COMMON	 ( COMMON_CATHODE )





#endif /* HAL_SSD_SSD_CONFIG_H_ */
