/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Administrator
 */

#include "fsm_automatic.h"
#include "main.h"
#include "display7seg.h"
#include "fsm_manual_step2.h"

void fsm_simple_buttons_run (){
	switch(status){
	case INIT:
		// process
		if(timer0_flag == 1){
			setTimer0(1000);
			if(counter==-1) counter=9;
			display7SEG(counter);
			counter--;
			break;
		}
		 //change state
			if(isRESETPressed() == 1){
				setTimer1(10000);
				counter = 0;
				display7SEG(counter);
				status = RESET;
			}
			if(isINCPressed() == 1){
				if(counter>9) counter=0;
				setTimer1(10000);
				counter++;
				display7SEG(counter);
				status = INC;
			}
			if (isDECPressed() == 1){
				if(counter<0) counter=9;
				setTimer1(10000);
				counter--;
				display7SEG(counter);
				status = DEC;
			}
			break;

		case RESET:
			//process
			display7SEG(0);
			// BUTTON PRESSED
			if(isRESETPressed() == 1){
				counter = 0;
				setTimer1(10000);
				display7SEG(counter);
				status = RESET;
			}
			if(isINCPressed() == 1){
				counter=1;
				setTimer1(10000);
				display7SEG(counter);
				status = INC;
			}
			if(isDECPressed() == 1){
				counter=9;
				setTimer1(10000);
				display7SEG(counter);
				status = DEC;
			}
			if(isINCLongPressed()==1){
				counter = 1;
				display7SEG(counter);
				status = AUTO_INC;
			}
			if(isDECLongPressed()==1){
				counter = 9;
				display7SEG(counter);
				status = AUTO_DEC;
			}
			if(timer1_flag == 1){
				counter = 0;
				display7SEG(counter);
				status = AUTO_DEC;
				setTimer1(10000);
				setTimer0(1000);
				break;
			}
			break;
		case INC:
			//TO DO
			// BUTTON PRESSED
			if(isRESETPressed() == 1){
				setTimer1(10000);
				counter = 0;
				display7SEG(counter);
				status = RESET;
			}
			if(isINCPressed() == 1){
				setTimer1(10000);
				counter++;
				if(counter >9) counter = 0;
				display7SEG(counter);
				status = INC;
			}
			if (isDECPressed() == 1){
				setTimer1(10000);
				counter--;
				display7SEG(counter);
				status = DEC;
			}
//			//LONG_PRESSED BUTTON
			if(isINCLongPressed()==1){
				counter++;
				if(counter >9) counter = 0;
				display7SEG(counter);
				status = AUTO_INC;
			}
			if(isDECLongPressed()==1){
				counter --;
				display7SEG(counter);
				status = AUTO_DEC;
			}
			// sau 10s sec auto_dec
			if(timer1_flag == 1){
				display7SEG(counter);
				counter--;
				status = AUTO_DEC;
				setTimer1(10000);
				setTimer0(1000);
				break;
			}
			break;
		case DEC:
			//TO DO
			// BUTTON PRESSED
			if(isRESETPressed() == 1){
				setTimer1(10000);
				counter = 0;
				display7SEG(counter);
				status = RESET;
			}
			if(isINCPressed() == 1){
				setTimer1(10000);
				counter++;
				display7SEG(counter);
				status = INC;
			}
			if (isDECPressed() == 1){
				setTimer1(10000);
				counter--;
				if(counter<0) counter = 9;
				display7SEG(counter);
				status = DEC;
			}
//			//LONG_PRESSED BUTTON
			if(isINCLongPressed()==1){
				counter ++;
				display7SEG(counter);
				status = AUTO_INC;
			}
			if(isDECLongPressed()==1){
				counter --;
				if(counter <0) counter = 9;
				display7SEG(counter);
				status = AUTO_DEC;
			}
			// sau 10s sec auto_dec
			if(timer1_flag == 1){
				display7SEG(counter);
				counter--;
				status = AUTO_DEC;
				setTimer1(10000);
				setTimer0(1000);
				break;
			}
			break;
		case AUTO_DEC:
			//process
			if (isDECLongPressed()==1){
				setTimer0(1000);
				counter--;
				if(counter<0) counter=9;
				display7SEG(counter);
				status=AUTO_DEC;
				break;
			}
			if(isINCLongPressed()==1){
				counter ++;
				display7SEG(counter);
				status = AUTO_INC;
			}

			//change state
			if(isRESETPressed() == 1){
				setTimer1(10000);
				counter = 0;
				display7SEG(counter);
				status = RESET;
			}
			if(isINCPressed() == 1){
				setTimer1(10000);
				counter++;
				display7SEG(counter);
				status = INC;
			}
			if (isDECPressed() == 1){
				setTimer1(10000);
				counter--;
				if(counter <0) counter = 9;
				display7SEG(counter);
				status = DEC;
			}
			break;
		case AUTO_INC:
			//process
			if (isINCLongPressed()==1){
				setTimer0(1000);//////////////////////////////////
				counter++;
				if(counter==10) counter=0;
				display7SEG(counter);
				status=AUTO_INC;
				break;
			}
			//change state
			if(isRESETPressed() == 1){
				setTimer1(10000);
				counter = 0;
				display7SEG(counter);
				status = RESET;
			}
			if(isINCPressed() == 1){
				setTimer1(10000);
				counter++;
				display7SEG(counter);
				status = INC;
			}
			if (isDECPressed() == 1){
				setTimer1(10000);
				counter--;
				if(counter == -1) counter = 9;
				display7SEG(counter);
				status = DEC;
			}
			break;
	default:
		break;
	}
}
