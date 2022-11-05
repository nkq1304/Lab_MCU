/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Administrator
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE		GPIO_PIN_RESET

extern int RESET_flag;
extern int INC_flag;
extern int DEC_flag;

//nhan tha
int isRESETPressed();
int isINCPressed();
int isDECPressed();

// set button flag
void subRESETProcess();
void subINCProcess();
void subDECProcess();

//long pressed
int isINCLongPressed();
int isDECLongPressed();

//implement button
void getRESETInput();
void getINCInput();
void getDECInput();

//int isButton1LongPress(); 	//nhan de
//void subKeyProcess();


#endif /* INC_BUTTON_H_ */
