/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Administrator
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "setTimer.h"
#include "main.h"
#include "display7seg.h"
#define		INIT		0
#define 	RESET		1
#define 	INC			2
#define		DEC			3
#define		AUTO_DEC	4
#define		AUTO_INC	5
//#define timer 2000;
extern int status;
extern int counter;

int led;
#endif /* INC_GLOBAL_H_ */
