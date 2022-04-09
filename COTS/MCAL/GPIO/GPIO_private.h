/******************************************************************************
 *
 * Module     : GPIO Driver
 *
 * File Name  : GPIO_private.h
 *
 * Description: Header file for the STM32 GPIO Private Registers
 *
 * Author     : Osama Hamdy
 *
 *******************************************************************************/
#include<LIB/Std_types.h>
#include<LIB/Bit_utils.h>
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/*******************************************************************************
 *                          GPIO Registers                                     *
 *******************************************************************************/
typedef struct {
	volatile u32 GPIOx_MODER;
	volatile u32 GPIOx_OTYPER;
	volatile u32 GPIOx_OSPEEDR;
	volatile u32 GPIOx_PUPDR;
	volatile u32 GPIOx_IDR;
	volatile u32 GPIOx_ODR;
	volatile u32 GPIOx_BSRR;
	volatile u32 GPIOx_LCKR;
	volatile u32 GPIOx_AFRL;
	volatile u32 GPIOx_AFRH;
}GPIOx_Register_t;

#define GPIOA_BASE_ADDRESS                ((void * )0X40020000)
#define GPIOB_BASE_ADDRESS 				  ((void * )0X40020400)
#define GPIOC_BASE_ADDRESS                ((void * )0X40020800)
#define GPIOD_BASE_ADDRESS                ((void * )0X40020C00)
#define GPIOE_BASE_ADDRESS                ((void * )0X40021000)
#define GPIOH_BASE_ADDRESS                ((void * )0X40021C00)

#endif /* GPIO_PRIVATE_H_ */
