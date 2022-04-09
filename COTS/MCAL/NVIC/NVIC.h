/******************************************************************************
 *
 * Module     : NVIC Driver
 *
 * File Name  : NVIC.h
 *
 * Description: Header file for the STM32 NVIC Private Registers
 *
 * Author     : Osama Hamdy
 *
 *******************************************************************************/

#ifndef NVIC_H_
#define NVIC_H_
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/* GPIO Enum For Error Status */
typedef enum {
	NVIC_OK,
	NVIC_NOK,
	NVIC_NULL_PointerError,
	NVIC_PinError
} NVIC_ErrorState_t;

typedef struct {
	u8 copy_u8IntID;
	u8 copy_u8GroupPriority;
	u8 copy_u8SubPriority;
	u32 copy_u32Group_type;
}NVIC_PRI;

#define  MAX_INT_NUM                                256

/*******************************************************************************
 *                      NVIC GROUP PRIORITY  MASKS                             *
 *******************************************************************************/
/* 4 BITS FOR GROUP PRIORITY (IPR) => GROUP */
#define GROUP3_PRI     0x05FA0300
/* 3 BITS FOR GROUP AND 1 BIT FOR SUBPRIORITY => IPR   */
#define GROUP4_PRI     0x05FA0400
/* 2 BITS FOR GROUP AND 2 BIT FOR SUBPRIORITY  => IPR  */
#define GROUP5_PRI     0x05FA0500
/* 1 BIT FOR GROUP AND  3 BITS FOR SUBPRIORITY => IPR */
#define GROUP6_PRI     0x05FA0600
/* 0 BITS FOR GROUP AND 4 BITS FOR SUBPRIORITY => IPR */
#define GROUP7_PRI     0x05FA0700

/*******************************************************************************
 *                      NVIC  INTERRUPT DEFINITIONS                            *
 *******************************************************************************/

#define             INT_WWDG                               0
#define             INT_PVD                                1
#define             INT_TAMP_STAMP                         1
#define             INT_RTC_WKUP                           2
#define             INT_FLASH                              3
#define             INT_RCC                                4
#define             INT_EXT10                              5
#define             INT_EXT11                              6
#define             INT_EXT12                              7
#define             INT_EXT13                              8
#define             INT_EXT14                              9


#define             INT_DMA1_Stream0                       10
#define             INT_DMA1_Stream1                       12
#define             INT_DMA1_Stream2                       13
#define             INT_DMA1_Stream3                       14
#define             INT_DMA1_Stream4                       15
#define             INT_DMA1_Stream5                       16
#define             INT_DMA1_Stream6                       17
#define             INT_ADC                                18
#define             INT_EXTI9_5                            23
#define             INT_TIM1_BRK_TIM9                      24
#define             INT_TIM1_UP_TIM10                      25
#define             INT_TIM1_TRG_COM_TIM11                 26
#define             INT_TIM1_CC                            27

#define             INT_TIM2                               28
#define             INT_TIM3                               29
#define             INT_TIM4                               30
#define             INT_I2C1_EV                            31
#define             INT_I2C1_ER                            32
#define             INT_I2C2_EV                            33
#define             INT_I2C1_ER                            34
#define             INT_SPI11                              35
#define             INT_SPI12                              36
#define             INT_USART1                             37
#define             INT_USART2                             38
#define             INT_EXTI15_10                          40
#define             INT_EXTI17 / RTC_Alarm                 41
#define             INT_EXTI18/OTG_FS_WKUP                 42

#define             INT_DMA1_Stream7                       47
#define             INT_SDIO                               49
#define             INT_TIM5                               50
#define             INT_SPI3                               51

#define             INT_DMA2_Stream0                       56
#define             INT_DMA2_Stream1                       57
#define             INT_DMA2_Stream2                       58
#define             INT_DMA2_Stream3                       59
#define             INT_DMA2_Stream4                       60

#define             INT_OTG_FS                             67
#define             INT_DMA2_Stream5                       68
#define             INT_DMA2_Stream6                       69
#define             INT_DMA2_Stream7                       70
#define             INT_USART6                             71
#define             INT_I2C3_EV                            72
#define             INT_I2C3_ER                            73
#define             INT_FPU                                81
#define             INT_SPI4                               84


/*******************************************************************************
 *                            Fuction ProtoTypes                               *
 *******************************************************************************/
/****************************************************************************************************************
 * Public Function
 * Description : Enable the the NVIC Interupt Pin
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_enutEnableInterrupt(u8 Copy_u8IntID);
/****************************************************************************************************************
 * Public Function
 * Description : Disable the the NVIC Interupt Pin
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_enutDisableInterrupt(u8 Copy_u8IntID);
/****************************************************************************************************************
 * Public Function
 * Description : Enable the the NVIC Pending Flag
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_SetPendingFlag  (u8 Copy_u8IntNum) ;
/****************************************************************************************************************
 * Public Function
 * Description : Disable the the NVIC Pending Flag
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_ClearPendingFlag(u8 Copy_u8IntNum);
/****************************************************************************************************************
 * Public Function
 * Description : Get the Status Value of  the NVIC Pending Flag
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_u8GetPendingFlag(u8 Copy_u8IntNum,pu8 Add_pu8PendingState);
/****************************************************************************************************************
 * Public Function
 * Description : Get the Status Value of  the NVIC Active Flag
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t NVIC_u8GetActiveFlag (u8 Copy_u8IntNum,pu8 Add_pu8ActiveState);
/****************************************************************************************************************
 * Public Function
 * Description : Get the Status Value of  the NVIC Pending Flag
 * Function Paramters : Interrupt ID Number
 * Function Return : Error Status of NVIC
 ****************************************************************************************************************/
NVIC_ErrorState_t  NVIC_vidSetPriority(s8 copy_s8PriorityId , u8 copy_u8GroupPriority,u8 copy_u8SubPriority , u32 copy_u32Group );

#endif /* NVIC_H_ */
