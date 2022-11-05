/*
 * setTimer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Administrator
 */

#ifndef INC_SETTIMER_H_
#define INC_SETTIMER_H_

extern int timer0_flag;
//1
extern int timer1_flag;
//2
extern int timer2_flag;

void setTimer0(int duration);
//1
void setTimer1(int duration);
//2
void setTimer2(int duration);

void timer_run();

#endif /* INC_SETTIMER_H_ */
