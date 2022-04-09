/******************************************************************************
 *
 * Module     : NVIC Driver
 *
 * File Name  : NVIC_prv.h
 *
 * Description: Header file for the STM32 NVIC Private Registers
 *
 * Author     : Osama Hamdy
 *
 *******************************************************************************/

#ifndef NVIC_PRV_H_
#define NVIC_PRV_H_
#include"Std_types.h"
/*******************************************************************************
 *                          GPIO Registers                                     *
 *******************************************************************************/
typedef struct
{
	volatile u32 NVIC_ISER[8];
	volatile u32 NVIC_RES1[24];
	volatile u32 NVIC_ICER[8];
	volatile u32 NVIC_RES2[24];
	volatile u32 NVIC_ISPR[8];
	volatile u32 NVIC_RES3[24];
	volatile u32 NVIC_ICBR[8];
	volatile u32 NVIC_RES4[24];
	volatile u32 NVIC_IABR[8];
	volatile u32 NVIC_RES5[56];
	volatile u32 NVIC_IPR [60];
	volatile u32 NVIC_STIR[8];

}NVIC_Reg_t;

#define   NVIC          ((NVIC_Reg_t * ) 0xE000E100)   /*NVIC BASE ADDRESS */

#define NVIC_STIR	   *((volatile u32*)0xE000EF00)

#define NVIC_IPR        ((volatile u8*)0xE000E300)

#define SCB_AIRCR	   *((volatile u32*)0xE000ED00+0X0C)

#endif /* NVIC_PRV_H_ */
