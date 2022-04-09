/******************************************************************************
 *
 * Module: RCC Driver
 *
 * File Name: rcc.h
 *
 * Description: Header file for the STM32 RCC Private Registers
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/

/*******************************************************************************
 *                          RCC Registers  Definitions                     *
 *******************************************************************************/
#define RCC_BASE_ADDRESS  0x40023800
typedef struct {
	volatile u32 RCC_CR;
	volatile u32 RCC_PLLCFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RSTR;
	volatile u32 RCC_AHB2RSTR;
	volatile u32 RESERVED0[2];
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_APB2RSTR;
	volatile u32 RESERVED1[2];
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 RESERVED2[2];
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 RESERVED3[2];
	volatile u32 RCC_APB1LPENR;
	volatile u32 RCC_APB2LPENR;
	volatile u32 RESERVED4[2];
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 RESERVED5[2];
	volatile u32 RCC_SSCGR;
	volatile u32 RCC_PLLI2SCFGR;
	volatile u32 RESERVED6[2];
	volatile u32 RCC_DCKCFGR;
} RCC_RegDef_Struct;

#define RCC     ((RCC_RegDef_Struct *) RCC_BASE_ADDRESS)

