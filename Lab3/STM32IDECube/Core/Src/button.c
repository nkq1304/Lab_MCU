/*
 * button.c
 *

 *      Author: Administrator
 */



#include "button.h"
#include "input_processing.h"
#include "main.h"
#include "display7seg.h"

//button BUTTON1
int BUTTON1_flag=0;
int KeyReg0BUTTON1 = NORMAL_STATE;  //trang thai muc cao :1
int KeyReg1BUTTON1 = NORMAL_STATE;
int KeyReg2BUTTON1 = NORMAL_STATE;
int KeyReg3BUTTON1 = NORMAL_STATE; //trang thai on dinh truoc do
int TimerForBUTTON1Press = 0; //nhan de 3s

//increase button
int BUTTON2_flag=0;
int KeyReg0BUTTON2 = NORMAL_STATE;  //trang thai muc cao :1
int KeyReg1BUTTON2 = NORMAL_STATE;
int KeyReg2BUTTON2 = NORMAL_STATE;
int KeyReg3BUTTON2 = NORMAL_STATE; //trang thai on dinh truoc do
int TimerForBUTTON2Press = 300; //nhan de 3s

//BUTTON3rease button
int BUTTON3_flag=0;
int KeyReg0BUTTON3 = NORMAL_STATE;  //trang thai muc cao :1
int KeyReg1BUTTON3 = NORMAL_STATE;
int KeyReg2BUTTON3 = NORMAL_STATE;
int KeyReg3BUTTON3 = NORMAL_STATE; //trang thai on dinh truoc do
int TimerForBUTTON3Press = 300; //nhan de 3s

//NHAN THA
int isBUTTON1Pressed(){
	if(BUTTON1_flag==1){//nhan tha //set flag // ham while main truy cap vao duoc
		BUTTON1_flag=0;
		return 1; //tra ve while(1)
	}
	else return 0;
}
int isBUTTON2Pressed(){
	if(BUTTON2_flag==1){//nhan tha //set flag // ham while main truy cap vao duoc
		BUTTON2_flag=0;
		return 1; //tra ve while(1)
	}
	else return 0;
}
int isBUTTON3Pressed(){
	if(BUTTON3_flag==1){//nhan tha //set flag // ham while main truy cap vao duoc
		BUTTON3_flag=0;
		return 1; //tra ve while(1)
	}
	else return 0;
}
//SET FLAG BUTTONS =1
void subBUTTON1Process(){
	BUTTON1_flag=1;
}
void subBUTTON2Process(){
	BUTTON2_flag=1;
}
void subBUTTON3Process(){
	BUTTON3_flag=1;
}
//long pressed
int isBUTTON2LongPressed(){
	return 0;
}
int isBUTTON3LongPressed(){
	return 0;
}
//IMPLEMENT LONGPRESSED_BUTTON
void getBUTTON1Input(){
		KeyReg0BUTTON1 = KeyReg1BUTTON1;
		KeyReg1BUTTON1 = KeyReg2BUTTON1;
		KeyReg2BUTTON1 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin); // keyreg2 = trang thai cua button hien tai
		if(KeyReg0BUTTON1 == KeyReg1BUTTON1 && KeyReg1BUTTON1 == KeyReg2BUTTON1){ //trang thai on dinh
			if(KeyReg3BUTTON1 != KeyReg2BUTTON1){ //nha tha
				KeyReg3BUTTON1 = KeyReg2BUTTON1;
				if(KeyReg2BUTTON1 == PRESSED_STATE){
					subBUTTON1Process();
					TimerForBUTTON1Press = 100;
				}
			}
			else{ //neu key3==key2 la TH nhan de
				TimerForBUTTON1Press--;
				if(TimerForBUTTON1Press == 0){ //ket thuc nhan de
					if(KeyReg2BUTTON1==PRESSED_STATE){
					subBUTTON1Process();
					}
					TimerForBUTTON1Press = 100;
				}
			}
		}
}
void getBUTTON2Input(){
		KeyReg0BUTTON2 = KeyReg1BUTTON2;
		KeyReg1BUTTON2 = KeyReg2BUTTON2;
		KeyReg2BUTTON2 = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin); // keyreg2 = trang thai cua button hien tai


		if(KeyReg0BUTTON2 == KeyReg1BUTTON2 && KeyReg1BUTTON2 == KeyReg2BUTTON2){ //trang thai on dinh
			if(KeyReg3BUTTON2 != KeyReg2BUTTON2){ //nha tha
				KeyReg3BUTTON2 = KeyReg2BUTTON2;
				if(KeyReg2BUTTON2 == PRESSED_STATE){
					subBUTTON2Process();
					TimerForBUTTON2Press = 100;
				}
			}
			else{ //neu key3==key2 la TH nhan de
				TimerForBUTTON2Press--;
				if(TimerForBUTTON2Press == 0){ //ket thuc nhan de
					if(KeyReg2BUTTON2==PRESSED_STATE){
					subBUTTON2Process();
					}
					TimerForBUTTON2Press = 100;
				}
			}
		}
}
void getBUTTON3Input(){
		KeyReg0BUTTON3 = KeyReg1BUTTON3;
		KeyReg1BUTTON3 = KeyReg2BUTTON3;
		KeyReg2BUTTON3 = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin); // keyreg2 = trang thai cua button hien tai

		if(KeyReg0BUTTON3 == KeyReg1BUTTON3 && KeyReg1BUTTON3 == KeyReg2BUTTON3){ //trang thai on dinh
			if(KeyReg3BUTTON3 != KeyReg2BUTTON3){ //nha tha
				KeyReg3BUTTON3 = KeyReg2BUTTON3;
				if(KeyReg2BUTTON3 == PRESSED_STATE){
					subBUTTON3Process();
					TimerForBUTTON3Press = 100;
				}
			}
			else{ //neu key3==key2 la TH nhan de
				TimerForBUTTON3Press--;
				if(TimerForBUTTON3Press == 0){ //ket thuc nhan de
					if(KeyReg2BUTTON3==PRESSED_STATE){
					subBUTTON3Process();
					}
					TimerForBUTTON3Press = 100;
				}
			}
		}
}
