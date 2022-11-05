/*
 * led_blinky.c
 *
 *  Created on: 6 thg 11, 2022
 *      Author: Administrator
 */


#include "led_blinky.h"

void led_blinky(){
	switch(led){
	case 0:
		setTimer2(1000);
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		led = 1;
		break;
	case 1:
		if(timer2_flag == 1){
			setTimer2(1000);
			led = 0;
		}
		break;
	default:
		break;
	}
}
