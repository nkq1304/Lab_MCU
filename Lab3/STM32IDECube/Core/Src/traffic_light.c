/*
 * traffic_light.c
 *
 *      Author: Administrator
 */


#include "main.h"
#include "button.h"
#include "input_processing.h"
#include "display7seg.h"
#include "software_timer.h"

typedef enum {RED, GREEN, YELLOW } eLightState;
int Time_in_state_1 = 5;//red_duration
int Time_in_state_2 = 3;// green_duration
void Traffic_Light_Init(void)
{
	Light_state_LR = RED;  //RIGHT is red
	Light_state_BT = GREEN; // TOP is green
}

void Traffic_Light_Update_12(void)
{
	switch(Light_state_LR) //led red is first
	{
	case RED:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
		Time_in_state_1--; // led red increase every sec
		display7SEG_1(Time_in_state_1/10);
		display7SEG_2(Time_in_state_1%10);
		if(Time_in_state_1 == 0)
		{
			Light_state_LR = GREEN;
			Time_in_state_1 = green_duration;
		}
		break;
	case YELLOW:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
		Time_in_state_1--;
		display7SEG_1(Time_in_state_1/10);
		display7SEG_2(Time_in_state_1%10);
		if(Time_in_state_1 == 0)
		{
			Light_state_LR = RED;
			Time_in_state_1 = red_duration;
		}
		break;
	case GREEN:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
		Time_in_state_1--;
		display7SEG_1(Time_in_state_1/10);
		display7SEG_2(Time_in_state_1%10);
		if(Time_in_state_1 == 0)
		{
			Light_state_LR = YELLOW;
			Time_in_state_1 = yellow_duration;
		}
		break;
	default:
		break;
	}
}
void Traffic_Light_Update_34(void)
{
	switch(Light_state_BT)
	{
	case RED:
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
		Time_in_state_2--;
		display7SEG_3(Time_in_state_2/10);
		display7SEG_4(Time_in_state_2%10);
		if(Time_in_state_2 == 0)
		{
			Light_state_BT = GREEN;
			Time_in_state_2 = green_duration;
		}
		break;
	case YELLOW:
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
		Time_in_state_2--;
		display7SEG_3(Time_in_state_2/10);
		display7SEG_4(Time_in_state_2%10);
		if(Time_in_state_2 == 0)
		{
			Light_state_BT = RED;
			Time_in_state_2 = red_duration;
		}
		break;
	case GREEN:
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
		Time_in_state_2--;
		display7SEG_3(Time_in_state_2/10);
		display7SEG_4(Time_in_state_2%10);
		if(Time_in_state_2 == 0)
		{
			Light_state_BT = YELLOW;
			Time_in_state_2 = yellow_duration;
		}
		break;
	}
}


