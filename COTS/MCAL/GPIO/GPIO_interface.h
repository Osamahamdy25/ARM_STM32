/******************************************************************************
 *
 * Module: GPIO Driver
 *
 * File Name: GPIO_interface.h
 *
 * Description: Header file for the STM32 GPIO Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/* GPIO Enum For Error Status */
typedef enum {
	GPIO_OK,
	GPIO_NOK,
	GPIO_NULL_PointerError,
	GPIO_AFError,
	GPIO_LockError,
	GPIO_LockActive,
} GPIO_ErrorState_t;

typedef struct {
	void * port; /* Address of port */
	u32 Mode;
	u16 pin;
	u8 Speed;
} GPIO_PinCfg_t;
/*******************************************************************************
 *                           GPIO Pins                                   *
 *******************************************************************************/
#define GPIO_PIN_00						   ((U16)0X0001)
#define GPIO_PIN_01						   ((U16)0X0002)
#define GPIO_PIN_02						   ((U16)0X0004)
#define GPIO_PIN_03						   ((U16)0X0008)
#define GPIO_PIN_04						   ((U16)0X0010)
#define GPIO_PIN_05						   ((U16)0X0020)
#define GPIO_PIN_06						   ((U16)0X0040)
#define GPIO_PIN_07						   ((U16)0X0080)
#define GPIO_PIN_08						   ((U16)0X0100)
#define GPIO_PIN_09						   ((U16)0X0200)
#define GPIO_PIN_10						   ((U16)0X0400)
#define GPIO_PIN_11						   ((U16)0X0800)
#define GPIO_PIN_12						   ((U16)0X1000)
#define GPIO_PIN_13						   ((U16)0X2000)
#define GPIO_PIN_14						   ((U16)0X4000)
#define GPIO_PIN_15						   ((U16)0X8000)
/*******************************************************************************
 *                             GPIO MASKS                                 *
 *******************************************************************************/
#define     GPIO_MODE_MASK                          ((u32)0x00000003)
#define     GPIO_PUPD_MASK                          ((u32)0x00000030)
#define     GPIO_PPOD_MASK                          ((u32)0x00000100)
#define     GPIO_OTY_MASK                           ((u32)0x00000800)

/*******************************************************************************
 *                             GPIO Configuration                              *
 *******************************************************************************/

#define     GPIO_u32MODE_OUTPUT_PP                  (0X00000001)
#define     GPIO_u32MODE_OUTPUT_PP_PU               (0X00000101)
#define     GPIO_u32MODE_OUTPUT_PP_PD               (0X00000201)
#define     GPIO_u32MODE_OUTPUT_OD                  (0X00000011)
#define     GPIO_u32MODE_OUTPUT_OD_PU               (0X00000111)
#define     GPIO_u32MODE_OUTPUT_OD_PD               (0X00000211)

#define     GPIO_u32MODE_INPUT_PU                   (0X00000100)
#define     GPIO_u32MODE_INPUT_PD                   (0X00000200)

#define     GPIO_u32MODE_AF_PP                      (0X00000002)
#define     GPIO_u32MODE_AF_PP_PU                   (0X00000102)
#define     GPIO_u32MODE_AF_PP_PD                   (0X00000202)
#define     GPIO_u32MODE_AF_OD                      (0X00000012)
#define     GPIO_u32MODE_AF_OD_PU                   (0X00000112)
#define     GPIO_u32MODE_AF_OD_PD                   (0X00000212)

#define     GPIO_u32MODE_ANALOG                     (0X00000003)

#define     GPIO_u8SPEED_LOW                         ((u8) 0X00 )
#define     GPIO_u8SPEED_MID                         ((u8) 0X01 )
#define     GPIO_u8SPEED_HIGH                        ((u8) 0X02 )
#define     GPIO_u8SPEED_VERY_HIGH                   ((u8) 0X03 )

#define     GPIO_u32LOW                              ((u8) 0x00)
#define     GPIO_u32HIGH                             ((u8) 0x01)

#define     GPIO_u8ALTERNATE_FUNC_00                 ((u8) 0x00)
#define     GPIO_u8ALTERNATE_FUNC_01                 ((u8) 0x01)
#define     GPIO_u8ALTERNATE_FUNC_02                 ((u8) 0x02)
#define     GPIO_u8ALTERNATE_FUNC_03                 ((u8) 0x03)
#define     GPIO_u8ALTERNATE_FUNC_04                 ((u8) 0x04)
#define     GPIO_u8ALTERNATE_FUNC_05                 ((u8) 0x05)
#define     GPIO_u8ALTERNATE_FUNC_06                 ((u8) 0x06)
#define     GPIO_u8ALTERNATE_FUNC_07                 ((u8) 0x07)
#define     GPIO_u8ALTERNATE_FUNC_08                 ((u8) 0x08)
#define     GPIO_u8ALTERNATE_FUNC_09                 ((u8) 0x09)
#define     GPIO_u8ALTERNATE_FUNC_0A                 ((u8) 0x0A)
#define     GPIO_u8ALTERNATE_FUNC_0B                 ((u8) 0x0B)
#define     GPIO_u8ALTERNATE_FUNC_0C                 ((u8) 0x0C)
#define     GPIO_u8ALTERNATE_FUNC_0D                 ((u8) 0x0D)
#define     GPIO_u8ALTERNATE_FUNC_0E                 ((u8) 0x0E)
#define     GPIO_u8ALTERNATE_FUNC_0F                 ((u8) 0x0F)

/*******************************************************************************
 *                            Fuction ProtoTypes                               *
 *******************************************************************************/
/*
 * Public Function
 * Function Description :
 * Setting the Initialzation of  the Gpio Pins
 * if the  the pointer is equal to NULL the function will not handle the request and return Null pointer error
 * Function Paramters : Address of Gpio Configuration Structure Consist of (Mode , Speed , Pin Number ,  Port Address )
 * Function Return : Gpio  Error status
 */
GPIO_ErrorState_t GPIO_Init(GPIO_PinCfg_t * Add_pstrPinCfg);
/*
 * Public Function
 * Function Description :
 * Write the Pin Value to the Gpio Pins
 * if the  the pointer is equal to NULL the function will not handle the request and return Null pointer error
 * Function Paramters : Address of Gpio Configuration Structure Consist of (Mode , Speed , Pin Number ,  Port Address ) and Pin Value (  GPIO_u32HIGH or  GPIO_u32LOW)
 * Function Return : Gpio  Error status
 */
GPIO_ErrorState_t GPIO_WritePinValue(GPIO_PinCfg_t * Add_pstrPinCfg,
		u8 Copy_u8Value);
/*
 * Public Function
 * Function Description :
 * Read the Pin Value Of the GPIO  Pins
 * if the  the pointer is equal to NULL the function will not handle the request and return Null pointer error
 * Function Paramters : Address of Gpio Configuration Structure Consist of (Mode , Speed , Pin Number ,  Port Address ) and Adrres of pin Value
 * Function Return : Gpio  Error status
 */
GPIO_ErrorState_t GPIO_ReadPinValue(GPIO_PinCfg_t * Add_pstrPinCfg,
		pu8 Add_pu8Value);
/*
 * Public Function
 * Function Description :
 * Set the Alternative  Value Of the GPIO  Pins
 * if the  the pointer is equal to NULL the function will not handle the request and return Null pointer error
 * Function Paramters : Address of Gpio Configuration Structure Consist of (Mode , Speed , Pin Number ,  Port Address ) and Alternate Function Value
 * Function Return : Gpio  Error status
 */
GPIO_ErrorState_t GPIO_SetAF(GPIO_PinCfg_t * Add_pstrPinCfg, u8 Copy_u8AFValue);

/*
 * Public Function
 * Function Description :
 * Locking  the GPIO  Pins Configuration
 * if the  the pointer is equal to NULL the function will not handle the request and return Null pointer error
 * Function Paramters : Address of Gpio Configuration Structure Consist of (Mode , Speed , Pin Number ,  Port Address )
 * Function Return : Gpio  Error status
 */
GPIO_ErrorState_t GPIO_SetLockPin(GPIO_PinCfg_t * Add_pstrPinCfg);
#endif /* GPIO_INTERFACE_H_ */
