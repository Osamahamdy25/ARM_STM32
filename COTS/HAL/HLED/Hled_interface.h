/******************************************************************************
 *
 * Module: Led HAL Driver
 *
 * Layer : HAL
 *
 * File Name: Hled_interface.h
 *
 * Description: Interface Header file for the Led Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/
#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_
#include"Std_types.h"
#include"Bit_utils.h"
#include"Hled_config.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define  OTYPE_PP                      0
#define  OTYPE_OD                      1
#define  LED_ON                        1
#define  LED_OFF                       0
#define  ACTIVE_HIGH                   1
#define  ACTIVE_LOW                    0

/********************************************************************************************
 *                               Types Declaration                                          *
 ********************************************************************************************/
typedef enum {
	Led_OK,
	led_NumError,
}led_ErrorState;

typedef struct {
	void* port;
	u32 pin;
	u32 Active_State;
	u32 otype;
}ledcfg_t;

/*******************************************************************************
 *                            Fuction ProtoTypes                               *
 *******************************************************************************/

void   led_Init(void );
led_ErrorState Led_SetState(u8 Copy_led , u8 Copy_state);


#endif /* HLED_INTERFACE_H_ */
