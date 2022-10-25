/*
 * software_timer.h
 *
 *  Created on: Oct 20, 2022
 *      Author: Administrator
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer1_counter;

void setTimer1(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
