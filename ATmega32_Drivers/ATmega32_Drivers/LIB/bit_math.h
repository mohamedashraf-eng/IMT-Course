/**
 * @File: std_types.h
 * @Author: Mohamed Wx
 * @Date: 12/8/2022
 * @brief: file for macro like functions for bit manipulations.
 *
 */

/** @def header guards */
#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	BIT MATH
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup bit level */
//#define BIT_WRT(REG, BIT_NUM, NUM)	( (REG) |= )
#define BIT_SET(REG, BIT_NUM)   ( (REG) |=   (1 << ((BIT_NUM)))  ) /* Sets the bits as '1' 	 */
#define BIT_CLR(REG, BIT_NUM)   ( (REG) &= (~(1 << ((BIT_NUM)))) ) /* Sets the bits as '0' 	 */
#define BIT_TOG(REG, BIT_NUM)   ( (REG) ^=   (1 << ((BIT_NUM)))  ) /* Sets the bits as '~BIT' */
#define BIT_GET(REG, BIT_NUM)   ( ((REG) >> (BIT_NUM)) & (1)     ) /* Reads the bit  		 */

/** @defgroup register level */
#define REG_SET(REG)        ( (REG) |= (0xFF) ) /* Sets all the bits in the register as '1'	 */
#define REG_CLR(REG)        ( (REG) &= (0x00) ) /* Sets all the bits in the register as '0' 	 */
#define REG_GET(REG)		( (REG)	& (0xFF)  )
#define REG_TOG(REG)        ( (REG) ^= (REG)  ) /* Sets all the bits in the register as '~BIT' */
#define REG_WRT(REG, NUM)   ( (REG)  = (NUM)  ) /* Sets all the bits in the register as 'NUM'  */

//#define REG_SWP(REG1, REG2) ( () /* Swaps two registers  */

#endif /* LIB_BIT_MATH_H_ */
