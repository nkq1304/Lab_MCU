/*
 * setTimer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Administrator
 */

#include "setTimer.h"
//timer1 1s
int timer0_counter = 0;
int timer0_flag = 0;
int timer1_counter = 0;
int timer1_flag = 0;
int timer2_counter = 0;
int timer2_flag = 0;
int TIMER_CYCLE = 10;

void setTimer0 ( int duration ){
	timer0_counter = duration / TIMER_CYCLE ;
	timer0_flag = 0;
}
void clearTimer0() {
	timer0_counter=0;
	timer0_flag=0;
}
void timer_run (){
	if( timer0_counter > 0){
		timer0_counter --;
		if( timer0_counter == 0) timer0_flag = 1; // TODO
	}
	if( timer1_counter > 0){
		timer1_counter --;
		if( timer1_counter == 0) timer1_flag = 1; // TODO
	}
	if( timer2_counter > 0){
		timer2_counter --;
		if( timer2_counter == 0) timer2_flag = 1; // TODO
	}
}

//timer2 10

void setTimer1 ( int duration ){
	timer1_counter = duration / TIMER_CYCLE ;
	timer1_flag = 0;
}
void clearTimer1() {
	timer1_counter=0;
	timer1_flag=0;
}
void setTimer2 ( int duration ){
	timer2_counter = duration / TIMER_CYCLE ;
	timer2_flag = 0;
}
