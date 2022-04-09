/******************************************************************************
 *
 * Module: RCC Driver
 *
 * File Name: rcc.h
 *
 * Description: Header file for the STM32 RCC Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#include"Std_types.h"
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum {
	RCC_resError,
	RCC_Controlerror,
	RCC_StateError,
	RCC_NullPointerError,
	RCC_Ready,
	RCC_PLLWrongConfiguration,
	RCC_BusPrescalarError,
	RCC_BusError,
	RCC_ok
} rcc_tenuErrorState;

/*******************************************************************************
 *                            RCC Definitions                                  *
 *******************************************************************************/

#define HSI_CLK              0
#define HSE_CLK              1
#define PLL_CLK              2
#define MAX_CLK_RANGE        2
#define AHB_BUS              0
#define APB1_BUS             1
#define APB2_BUS             2
#define MAX_BUS_RANGE        2
#define MAX_PRESCALAR_RANGE  512
#define MIN_M_RANGE          2
#define MAX_M_RANGE          63
#define MIN_N_RANGE          2
#define MAX_N_RANGE          433
#define MIN_Q_RANGE          2
#define MAX_Q_RANGE          15
#define MIN_CLKSRC_RANGE     0
#define MAX_CLKSRC_RANE      1

/*******************************************************************************
 *                            RCC Registers  Mask                            *
 *******************************************************************************/

#define   HSI_ON_MASK                               0X00000001

#define   HSI_RDY_MASK                              0X00000002

#define   HSE_ON_MASK                               0X00010000

#define   HSE_RDY_MASK                              0X00020000

#define   SW_CLEAR_MASK                             0XFFFFFFFC

#define   SW_SET_MASK                               0X00000003

#define   PLL_ON_MASK                               0X01000000

#define   PLL_RDY_MASK                              0X02000000

#define   PLL_CLEAR_CONFIGURATION_MASK              0X10BC8000

#define   SW_HSI_CLK                                0x00000000

#define   SW_HSE_CLK								0x00000001

#define   SW_PLL_CLK								0x00000002

#define   PLL_P_2_MASK                              0X00000000

#define   PLL_P_4_MASK                              0X00010000

#define   PLL_P_6_MASK                              0X00020000

#define   PLL_P_8_MASK                              0X00030000

/*******************************************************************************
 *                     RCC  Peripheral Enable  Mask                            *
 *******************************************************************************/

#define PERI_AHB_GPIOA_ENABLE                      0X0000000001

#define PERI_AHB_GPIOB_ENABLE                      0X0000000002

#define PERI_AHB_GPIOC_ENABLE                      0X0000000004

#define PERI_AHB_GPIOD_ENABLE                      0X0000000008

#define PERI_AHB_GPIOE_ENABLE                      0X0000000010

#define PERI_AHB_GPIOH_ENABLE                      0X0000000080

#define PERI_AHB_DMA1_ENABLE                       0X0000200000

#define PERI_AHB_DMA2_ENABLE                       0X0000400000

#define PERI_APB1_TIM2_ENABLE                      0X0100000001

#define PERI_APB1_TIM3_ENABLE                      0X0100000002

#define PERI_APB1_TIM4_ENABLE                      0X0100000004

#define PERI_APB1_TIM5_ENABLE                      0X0100000008

#define PERI_APB1_WWDG_ENABLE                      0X0100000800

#define PERI_APB1_SPI12_ENABLE                     0X0100004000

#define PERI_APB1_SPI13_ENABLE                     0X0100008000

#define PERI_APB1_USART2_ENABLE                    0X0100020000

#define PERI_APB1_I2C1_ENABLE                      0X0100200000

#define PERI_APB1_I2C2_ENABLE                      0X0100400000

#define PERI_APB1_I2C3_ENABLE                      0X0100800000

#define PERI_APB2_TIM1_ENABLE                      0X1100000001

#define PERI_APB2_USART1_ENABLE                    0X1100000010

#define PERI_APB2_USART6_ENABLE                    0X1100000020

#define PERI_APB2_ADC1_ENABLE                      0X1100000100

#define PERI_APB2_SDIO_ENABLE                      0X1100000800

#define PERI_APB2_SPI1_ENABLE                      0X1100001000

#define PERI_APB2_SPI4_ENABLE                      0X1100002000

#define PERI_APB2_TIM9_ENABLE                      0X1100010000

#define PERI_APB2_TIM10_ENABLE                     0X1100020000

#define PERI_APB2_TIM11_ENABLE                     0X1100030000

/*******************************************************************************
 *                            RCC Bus Prescalar   Mask                            *
 *******************************************************************************/

/*      AHB Bus Prescalar  mask */

#define BUS_AHB_PRESCALAR_2                        0X00000080

#define BUS_AHB_PRESCALAR_4                        0X00000090

#define BUS_AHB_PRESCALAR_8                        0X000000A0

#define BUS_AHB_PRESCALAR_16                       0X000000B0

#define BUS_AHB_PRESCALAR_64                       0X000000C0

#define BUS_AHB_PRESCALAR_128                      0X000000D0

#define BUS_AHB_PRESCALAR_256                      0X000000E0

#define BUS_AHB_PRESCALAR_512                      0X000000F0

/*      APB1 Bus Prescalar  mask */

#define BUS_APB1_PRESCALAR_2                       0X00001000

#define BUS_APB1_PRESCALAR_4                       0X00001400

#define BUS_APB1_PRESCALAR_8                       0X00001800

#define BUS_APB1_PRESCALAR_16                      0X00001B00

/*      APB2 Bus Prescalar  mask */

#define BUS_APB2_PRESCALAR_2                       0X00008000

#define BUS_APB2_PRESCALAR_4                       0X00009000

#define BUS_APB2_PRESCALAR_8                       0X0000B000

#define BUS_APB2_PRESCALAR_16                      0X0000E000

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/*
 * Public Function
 * Description :
 * Setup the the system clock source
 * If the input system clock out of the  system clock the function will not handle the request and return error .
 * Function Paramters : Type of clock source
 * Function Return : Error Status of RCC
 */

rcc_tenuErrorState Enable_clock(u8 copy_u8clocktype);

/*
 * Public Function
 * Description :
 * Turn on / off  the the system clock source
 * Function Paramters : type of clock source and clock state(on or off )
 * Function Return : Rcc Error state
 */

rcc_tenuErrorState Control_system_clk(u8 copy_u8Clocktype,
		u8 copy_u8Clock_Control_State);

/*
 * Public Function
 * Description :
 * Read the status of the system clock Ready or not Ready
 * if the clock type out of clock range or the pointer is equal to NULL the function will not handle the request and return error
 * Function Paramters : type of clock source & the clock state (ready or not ready)
 * Function Return : Rcc Error status
 */

rcc_tenuErrorState get_Clock_Status(u8 copy_u8Clocktype,
		pu8 add_pu8Clock_RDY_State);

/* Public Function
 * Description :
 * Setup the the PLL Configuration parameters
 * If the input Configuration parameters out of  range the function will not handle the request and return error .
 * Function Paramters :
 * M-> Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock from 2 -> 63
 * N->Main PLL (PLL) multiplication factor for VCO from 2 -> 432
 * P->Main PLL (PLL) division factor for main system clock (2,4,6,8)
 * clk_src-> Main PLL(PLL) and audio PLL (PLLI2S) entry clock source (0->HSI & 1->HSE)
 * Q->Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks From 2->15
 * f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
 * f(PLL general clock output) = f(VCO clock) / PLLP
 * f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLLQ
 * Function Return : Error Status of RCC
 */

rcc_tenuErrorState PLL_Configuration(u8 copy_u8Mprescalar,
		u16 copy_u16Nmultiplier, u8 copy_u8Pprescalar, u8 copy_u8Qprescalar,
		u8 copy_u8clkSrc);

/*
 * Public Function
 * Description :
 * select the the Peripheral clock bus and setup the prescalar value
 * Function Paramters : the type of prescalar bus (AHB | APB1 | APB2) and prescalar value
 * Function Return : Rcc Error status
 */

rcc_tenuErrorState Prescalar_Bus_Control(u32 copy_u32Bustype,
		u32 copy_u32Prescalarvalue);

/*
 * Public Function
 * Description :
 * Turn on/off  the the Peripheral clock
 * Function Paramters : the type of Bus  & the type of Bus Peripheral
 * Function Return : Rcc Error status
 */

rcc_tenuErrorState enable_clock_peripheral(u32 copy_u32Bustype,
		u64 copy_u64Peripheraltype);

#endif /* RCC_INTERFACE_H_ */
