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

/*
 * WRT_BIT is to assign 1 or 0 to  a specific bit in a register
 * while maintaining all the bits' value as it is.
 * Steps:
 * 		1- Clear the specific bit you want to write on
 * 		2- Insert the new value you want to write
 */
#define BIT_WRT(REG, BIT, VAL) ( (REG) = ( ( (REG) & (~(1<<(BIT))) ) | ( (VAL) << (BIT)  ) ) )

#define BIT_SET(REG, BIT_NUM)  		 ( (REG) |=   (1 << ((BIT_NUM)))  ) /* Sets the bits as '1'    */
#define BIT_CLR(REG, BIT_NUM)   	 ( (REG) &= (~(1 << ((BIT_NUM)))) ) /* Sets the bits as '0'    */
#define BIT_TOG(REG, BIT_NUM)   	 ( (REG) ^=   (1 << ((BIT_NUM)))  ) /* Sets the bits as '~BIT' */
#define BIT_GET(REG, BIT_NUM)   	 ( (REG)  &   (1 << (BIT_NUM))    ) /* Reads the bit  		   */

/** @defgroup register level */
#define REG_SET(REG)        ( (REG) |= (0xFF) ) /* Sets all the bits in the register as '1'	   */
#define REG_CLR(REG)        ( (REG) &= (0x00) ) /* Sets all the bits in the register as '0'    */
#define REG_GET(REG)		( (REG)	& (0xFF)  )
#define REG_TOG(REG)        ( (REG) ^= (REG)  ) /* Sets all the bits in the register as '~BIT' */
#define REG_WRT(REG, NUM)   ( (REG)  = (NUM)  ) /* Sets all the bits in the register as 'NUM'  */

//#define REG_SWP(REG1, REG2) ( () /* Swaps two registers  */

#endif /* LIB_BIT_MATH_H_ */
