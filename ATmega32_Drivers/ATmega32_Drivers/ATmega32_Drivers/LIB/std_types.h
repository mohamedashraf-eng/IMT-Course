/**
 * @File: std_types.h
 * @Author: Mohamed Wx
 * @Date: 12/8/2022
 * @brief: file for standard types.
 *
 */
/** @def header guards */
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -																	STANDARD TYPES 																-
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define NULL ( (void *) (0) )

/** @defgroup signed */
typedef signed char         s8;
typedef signed short int    s16;
typedef signed long  int    s32;
typedef signed long         s64;

/** @defgroup const signed */
typedef const signed char         cs8;
typedef const signed short int    cs16;
typedef const signed long  int    cs32;
typedef const signed long         cs64;

/** @defgroup unsigned */
typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned long  int  u32;
typedef unsigned long       u64;

/** @defgroup const unsigned */
typedef const unsigned char       cu8;
typedef const unsigned short int  cu16;
typedef const unsigned long  int  cu32;
typedef const unsigned long       cu64;

/** @defgroup decimal point */
typedef float               f32;
typedef double              f64;
typedef long double         f128;

/** @defgroup const decimal point */
typedef const float               cf32;
typedef const double              cf64;
typedef const long double         cf128;


/** @def defined types */
typedef enum BOOLEN_TYPES
{
	False,
	True
}bool_t;


#endif /* STD_TYPES_H_ */
