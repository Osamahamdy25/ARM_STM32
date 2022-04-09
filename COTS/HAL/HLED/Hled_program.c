/******************************************************************************
 *
 * Module: Led Driver
 *
 * Layer : HAL
 *
 * File Name: Hled_program.c
 *
 * Description: Program Source  file for the Led Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/
#include"GPIO_interface.h"
#include"Hled_interface.h"
extern const ledcfg_t leds[];
void led_Init(void) {
	GPIO_PinCfg_t Config;
	for (u8 iterator = 0; iterator < LEDS_NUM; iterator++) {
		if (leds[iterator].otype == OTYPE_PP) {
			Config.Mode = GPIO_u32MODE_OUTPUT_PP;
		} else {
			Config.Mode = GPIO_u32MODE_OUTPUT_OD;
		}
		Config.pin = leds[iterator].pin;
		Config.port = leds[iterator].port;
		Config.Speed = GPIO_u8SPEED_HIGH;
		GPIO_Init(&Config);
	}

}
led_ErrorState Led_SetState(u8 Copy_ledNum, u8 Copy_state) {
led_ErrorState     led_ErrorState = Led_OK;
if(Copy_ledNum > LEDS_NUM)
{
	led_ErrorState = led_NumError;
}
else{
	GPIO_WritePinValue(
			leds[Copy_ledNum].port,
			leds[Copy_ledNum].pin,
			Copy_state ^ leds[Copy_ledNum].Active_State
			);
}

return  led_ErrorState;
}
