 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: Std_types.h
 *
 * Description: types for AVR
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/



#ifndef _STD_TYPES_H
#define _STD_TYPES_H

/* NULL Pointer value */
#define NULL_PTR    ((void*)0)
/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

/*      Unsigned Data Type                       */
/*           0 .. 255              */
typedef unsigned char u8;
typedef unsigned char* pu8;
/*           0 .. 65535            */
typedef unsigned short int u16;
typedef unsigned short int* pu16;
/*           0 .. 4294967295       */
typedef unsigned int u32;
typedef unsigned int* pu32;
/*       0 .. 18446744073709551615  */
typedef unsigned long long int u64;
typedef unsigned long long int* pu64;
/*       Signed  Data Type                         */

/*        -128 .. +127             */
typedef signed char s8;
typedef signed char* ps8;
/*      -32768 .. +32767           */
typedef signed short int s16;
typedef signed short int* ps16;
/* -2147483648 .. +2147483647      */
typedef signed int s32;
typedef signed int* ps32;
/* -9223372036854775808 .. 9223372036854775807 */
typedef signed long long int s64;
typedef signed long long int* ps64;
/*       Floating Data Type                              */
typedef float f32;
typedef float* pf32;
typedef double f64;
typedef double* pf64;
typedef long double f128;
typedef long double* pf128;
#endif
