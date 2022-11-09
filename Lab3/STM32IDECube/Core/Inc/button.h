/*
 * button.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Administrator
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_



#include "main.h"


#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE		GPIO_PIN_RESET

extern int BUTTON1_flag;
extern int BUTTON2_flag;
extern int BUTTON3_flag;

//nhan tha
int isBUTTON1Pressed();
int isBUTTON2Pressed();
int isBUTTON3Pressed();

// set button flag
void subBUTTON1Process();
void subBUTTON2Process();
void subBUTTON3Process();

//implement button
void getBUTTON1Input();
void getBUTTON2Input();
void getBUTTON3Input();

#endif /* INC_BUTTON_H_ */
