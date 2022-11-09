/*
 * input_processing.c
 *
 *      Author: Administrator
 */

#include "main.h"
#include "traffic_light.h"
#include "software_timer.h"
#include "display7seg.h"
#include "input_processing.h"
#include "button.h"


int red_duration =5;
int green_duration = 3;
int yellow_duration = 2;
int Light_state_LR;
int Light_state_BT;
int value_time_light = 0;
int value_mode=1;
int status=1;
void fsm_for_input_processing ( void )
{
	switch(status){
	case 1: //MODE1
		//process
		if(timer0_flag == 1){
			Traffic_Light_Update_12();
			Traffic_Light_Update_34();
			display7SEG_mode(value_mode);
			setTimer0(100);
			break;
		}
		//change status
		if(isBUTTON1Pressed()==1){
			value_mode++;
			display7SEG_mode(value_mode);
			if(value_mode>4) value_mode=1;
			status=value_mode;
			setTimer0(50);
		}
		break;
	case 2://MODE2
		//display
		if(timer0_flag == 1){
			display7SEG_mode(value_mode);
			HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin );
			HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin );
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
			setTimer0(50);
		}
		//change state
		if(isBUTTON2Pressed()==1){
			value_time_light++;
			red_duration = value_time_light+5;//increase time of red light
			if(red_duration>99) red_duration=1;
			display7SEG_1(red_duration/10);
			display7SEG_2(red_duration%10);
			display7SEG_3(red_duration/10);
			display7SEG_4(red_duration%10);
		}
		if(isBUTTON3Pressed()){
			value_time_light = 0;
			Time_in_state_1=red_duration;
			Time_in_state_2=red_duration;
			status=1;
		}
		if(isBUTTON1Pressed()==1){
			value_mode++;
			display7SEG_mode(value_mode);
			if(value_mode>4) value_mode=1;
			status=value_mode;
			setTimer0(50);
		}
		break;
	case 3://MODE3 //YELLOW
		//display
				if(timer0_flag == 1){
					display7SEG_mode(value_mode);
					HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin );
					HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin );
					HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
					setTimer0(50);
				}
				//change state
				if(isBUTTON2Pressed()==1){
					value_time_light++;
					yellow_duration = value_time_light+2;
					if(yellow_duration>99) yellow_duration=1;
					display7SEG_1(yellow_duration/10);
					display7SEG_2(yellow_duration%10);
					display7SEG_3(yellow_duration/10);
					display7SEG_4(yellow_duration%10);
				}
				if(isBUTTON3Pressed()){
					value_time_light = 0;
					Time_in_state_1=yellow_duration;
					Time_in_state_2=yellow_duration;
					status=1;
				}
				if(isBUTTON1Pressed()==1){
					value_mode++;
					display7SEG_mode(value_mode);
					if(value_mode>4) value_mode=1;
					status=value_mode;
					setTimer0(50);
				}
		break;
	case 4://MODE4
		//display
				if(timer0_flag == 1){
					display7SEG_mode(value_mode);
					HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin );
					HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin );
					HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
					setTimer0(50);
				}
				//change state
				if(isBUTTON2Pressed()==1){
					value_time_light++;
					green_duration = value_time_light+3;
					if(green_duration>99) green_duration=1;
					display7SEG_1(green_duration/10);
					display7SEG_2(green_duration%10);
					display7SEG_3(green_duration/10);
					display7SEG_4(green_duration%10);
				}
				if(isBUTTON3Pressed()){
					value_time_light = 0;
					Time_in_state_1=green_duration;
					Time_in_state_2=green_duration;
					status=1;
				}
				if(isBUTTON1Pressed()==1){
					value_mode++;
					display7SEG_mode(value_mode);
					if(value_mode>4) value_mode=1;
					status=value_mode;
					setTimer0(50);
				}
		break;
	default:
		break;
	}
}

