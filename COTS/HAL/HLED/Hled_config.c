/******************************************************************************
 *
 * Module: Led HAL Driver
 *
 * Layer : HAL
 *
 * File Name: Hled_config.c
 *
 * Description: Configuration Source file for the Led Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/
#include"GPIO_private.h"
#include"GPIO_interface.h"
#include"Hled_interface.h"

const ledcfg_t leds [] =
{
		[LED_START]={
				.port=GPIOA_BASE_ADDRESS,
				.pin=3,
				.Active_State=OTYPE_PP,
				.Active_State=ACTIVE_HIGH,
		},
		[LED_STOP]={
					.port=GPIOA_BASE_ADDRESS,
					.pin=8,
					.Active_State=OTYPE_PP,
					.Active_State=ACTIVE_HIGH,
			},


} ;
