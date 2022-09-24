/**
 * @file SPI_Config.h
 *
 * @author: Mohamed Wx
 * @date Aug 29, 2022
 * @version v1.0
 * @copyright (c) Mohamed Ashraf WxCo 2022
 **/
/** @def Header Guards */
#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    CONFIGURATION PARAMETERS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/**
 * @def: Configuration Parameters
 * - SPI_DATAxORDER_MSB
 * - SPI_DATAxORDER_LSB
 */
#define SPI_DATAxORDER           SPI_DATAxORDER_MSB
/**
 * @def: Configuration Parameters
 * - SPI_MODE_MASTER
 * - SPI_MODE_SLAVE
 */
#define SPI_MODE                 SPI_MODE_MASTER
/**
 * @def: Configuration Parameters
 * - SPI_CLOCKxPOLARITY_RISING
 * - SPI_CLOCKxPOLARITY_FALLING
 */
#define SPI_CLOCKxPOLARITY       SPI_CLOCKxPOLARITY_RISING
/**
 * @def: Configuration Parameters
 * - SPI_CLOCKxPHASE_LEADING
 * - SPI_CLOCKxPHASE_TRAILING
 */
#define SPI_CLOCKxPHASE          SPI_CLOCKxPHASE_LEADING
/**
 * @def: Configuration Parameters
 * - SPI_CLOCKxRATE_DIV_2
 * - SPI_CLOCKxRATE_DIV_4
 * - SPI_CLOCKxRATE_DIV_8
 * - SPI_CLOCKxRATE_DIV_16
 * - SPI_CLOCKxRATE_DIV_32
 * - SPI_CLOCKxRATE_DIV_64
 * - SPI_CLOCKxRATE_DIV_128
 */
#define SPI_CLOCKxRATE           SPI_CLOCKxRATE_DIV_2
/**
 * @def: Configuration Parameters
 * - SPI_STATE_ENABLE
 * - SPI_STATE_DISABLE
 */
#define SPI_STATE                SPI_STATE_ENABLE

#endif /* MCAL_SPI_SPI_CONFIG_H_ */













