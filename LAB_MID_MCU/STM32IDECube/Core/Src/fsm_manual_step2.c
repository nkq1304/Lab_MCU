/*
 * fsm_manual_step2.c
 *
 *  Created on: 6 thg 11, 2022
 *      Author: Administrator
 */
#include "main.h"
#include "display7seg.h"
#include "fsm_manual_step2.h"

// khong nhan nut sau 10s
//void fsm_manual_step2 (){
//	switch(status){
//	case AUTO_DEC:
//		//process
//		if (timer0_flag==1){
//			setTimer0(1000);
//			if(counter==-1) counter=9;
//			display7SEG(counter);
//			counter--;
//			status=AUTO_DEC;
//			break;
//		}
//		//change state
//		if(isRESETPressed() == 1){
//			setTimer1(10000);
//			counter = 0;
//			display7SEG(counter);
//			status = RESET;
//		}
//		if(isINCPressed() == 1){
//			setTimer1(10000);
//			counter++;
//			display7SEG(counter);
//			status = INC;
//		}
//		if (isDECPressed() == 1){
//			setTimer1(10000);
//			counter--;
//			if(counter == -1) counter = 9;
//			display7SEG(counter);
//			status = DEC;
//		}
//		break;
//	case AUTO_INC:
//		//process
//		if (timer0_flag==1){
//			setTimer0(1000);
//			if(counter==10) counter=0;
//			display7SEG(counter);
//			counter++;
//			status=AUTO_INC;
//			break;
//		}
//		//change state
//		if(isRESETPressed() == 1){
//			setTimer1(10000);
//			counter = 0;
//			display7SEG(counter);
//			status = RESET;
//		}
//		if(isINCPressed() == 1){
//			setTimer1(10000);
//			counter++;
//			display7SEG(counter);
//			status = INC;
//		}
//		if (isDECPressed() == 1){
//			setTimer1(10000);
//			counter--;
//			if(counter == -1) counter = 9;
//			display7SEG(counter);
//			status = DEC;
//		}
//		break;
//	default:
//		break;
//	}
//}
