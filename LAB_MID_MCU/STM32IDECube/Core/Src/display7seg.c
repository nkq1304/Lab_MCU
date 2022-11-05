/*
 * display7seg.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Administrator
 */

#include "display7seg.h"
int counter=9;
unsigned char segmentNumber[10]={
		0x40,
		0x79,
		0x24,
		0x30,
		0x19,
		0x12,
		0x02,
		0x78,
		0x00,
		0x10
};
void display7SEG(int counter){
	unsigned char num = segmentNumber[counter];
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, ((num>>0)&0x01));
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, ((num>>1)&0x01));
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, ((num>>2)&0x01));
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, ((num>>3)&0x01));
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, ((num>>4)&0x01));
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, ((num>>5)&0x01));
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, ((num>>6)&0x01));
}
