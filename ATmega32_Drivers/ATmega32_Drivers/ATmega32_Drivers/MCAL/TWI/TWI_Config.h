/**
 * @file TWI_Config.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_TWI_TWI_CONFIG_H_
#define MCAL_TWI_TWI_CONFIG_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    CONFIGURATION PARAMETERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/


/**
 * @brief: General notes for good expierence.
 * - Higher the bus bit rate - lower the physical bus pullup resestior.
 * - Bus Bit rate equation:  SCL_FREQ = (CPU_CLK / (16+2*(TWBR))*(4^PreScaler))
 */

/**
 * @brief:
 *  The user should write (7-bit) Device slave address.
 */
#define TWI_DEVICE_SLAVE_ADDRESS   (0x02u)
/**
 * @brief: The TWI Bit rate value.
 */
#define TWI_BITRATE_VALUE           (0x12u)
/**
 * @brief: TWI Acknologement action state.
 * - TWI_ACK_ENABLE
 * - TWI_ACK_DISABLE
 */
#define TWI_ACK_STATE               (TWI_ACK_ENABLE)
/**
 * @brief: The TWI bus prescaler.
 * - TWI_PRESCALER_1
 * - TWI_PRESCALER_4
 * - TWI_PRESCALER_16
 * - TWI_PRESCALER_64
 */
#define TWI_PRESCALER               (TWI_PRESCALER_4)
/**
 * @brief: The TWI peripheral state.
 * - TWI_STATE_ENABLE
 * - TWI_STATE_DISABLE
 */
#define TWI_STATE                   (TWI_STATE_ENABLE)


#endif /* MCAL_TWI_TWI_CONFIG_H_ */
