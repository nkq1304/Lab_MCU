/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Administrator
 */

#include "button.h"
#include "fsm_automatic.h"
#include "main.h"
#include "display7seg.h"

//button reset
int RESET_flag=0;
int KeyReg0RESET = NORMAL_STATE;  //trang thai muc cao :1
int KeyReg1RESET = NORMAL_STATE;
int KeyReg2RESET = NORMAL_STATE;
int KeyReg3RESET = NORMAL_STATE; //trang thai on dinh truoc do
int TimerForRESETPress = 0; //nhan de 3s

//increase button
int INC_flag=0;
int KeyReg0INC = NORMAL_STATE;  //trang thai muc cao :1
int KeyReg1INC = NORMAL_STATE;
int KeyReg2INC = NORMAL_STATE;
int KeyReg3INC = NORMAL_STATE; //trang thai on dinh truoc do
int TimerForINCPress = 300; //nhan de 3s

//decrease button
int DEC_flag=0;
int KeyReg0DEC = NORMAL_STATE;  //trang thai muc cao :1
int KeyReg1DEC = NORMAL_STATE;
int KeyReg2DEC = NORMAL_STATE;
int KeyReg3DEC = NORMAL_STATE; //trang thai on dinh truoc do
int TimerForDECPress = 300; //nhan de 3s

//NHAN THA
int isRESETPressed(){
	if(RESET_flag==1){//nhan tha //set flag // ham while main truy cap vao duoc
		RESET_flag=0;
		return 1; //tra ve while(1)
	}
	else return 0;
}
int isINCPressed(){
	if(INC_flag==1){//nhan tha //set flag // ham while main truy cap vao duoc
		INC_flag=0;
		return 1; //tra ve while(1)
	}
	else return 0;
}
int isDECPressed(){
	if(DEC_flag==1){//nhan tha //set flag // ham while main truy cap vao duoc
		DEC_flag=0;
		return 1; //tra ve while(1)
	}
	else return 0;
}
//SET FLAG BUTTONS =1
void subRESETProcess(){
	RESET_flag=1;
}
void subINCProcess(){
	INC_flag=1;
}
void subDECProcess(){
	DEC_flag=1;
}
//long pressed
int isINCLongPressed(){
	return 0;
}
int isDECLongPressed(){
	return 0;
}
//IMPLEMENT LONGPRESSED_BUTTON
void getRESETInput(){
		KeyReg0RESET = KeyReg1RESET;
		KeyReg1RESET = KeyReg2RESET;
		KeyReg2RESET = HAL_GPIO_ReadPin(RES_GPIO_Port, RES_Pin); // keyreg2 = trang thai cua button hien tai
		if(KeyReg0RESET == KeyReg1RESET && KeyReg1RESET == KeyReg2RESET){ //trang thai on dinh
			if(KeyReg3RESET != KeyReg2RESET){ //nha tha
				KeyReg3RESET = KeyReg2RESET;
				if(KeyReg2RESET == PRESSED_STATE){
					//todo
					subRESETProcess();
					TimerForRESETPress = 0;
				}
			}
			else{ //neu key3==key2 la TH nhan de
				TimerForRESETPress--;
				if(TimerForRESETPress == 0){ //ket thuc nhan de
					//todo
					if(KeyReg2RESET==PRESSED_STATE){
					subRESETProcess();
					}
					TimerForRESETPress = 0;
				}
			}
		}
}
void getINCInput(){
		KeyReg0INC = KeyReg1INC;
		KeyReg1INC = KeyReg2INC;
		KeyReg2INC = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin); // keyreg2 = trang thai cua button hien tai


		if(KeyReg0INC == KeyReg1INC && KeyReg1INC == KeyReg2INC){ //trang thai on dinh
			if(KeyReg3INC != KeyReg2INC){ //nha tha
				KeyReg3INC = KeyReg2INC;
				if(KeyReg2INC == PRESSED_STATE){
					//todo
					subINCProcess();
					TimerForINCPress = 300;
				}
			}
			else{ //neu key3==key2 la TH nhan de
				TimerForINCPress--;
				if(TimerForINCPress == 0){ //ket thuc nhan de
					//todo
					if(KeyReg2INC==PRESSED_STATE){
					subINCProcess();

					}
					TimerForINCPress = 100;
				}
			}
		}
}
void getDECInput(){
		KeyReg0DEC = KeyReg1DEC;
		KeyReg1DEC = KeyReg2DEC;
		KeyReg2DEC = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin); // keyreg2 = trang thai cua button hien tai

		if(KeyReg0DEC == KeyReg1DEC && KeyReg1DEC == KeyReg2DEC){ //trang thai on dinh
			if(KeyReg3DEC != KeyReg2DEC){ //nha tha
				KeyReg3DEC = KeyReg2DEC;
				if(KeyReg2DEC == PRESSED_STATE){
//					TODO
					subDECProcess();
					TimerForDECPress = 300;
				}
			}
			else{ //neu key3==key2 la TH nhan de
				TimerForDECPress--;
				if(TimerForDECPress == 0){ //ket thuc nhan de
					//todo
					if(KeyReg2DEC==PRESSED_STATE){
					subDECProcess();
					}
					TimerForDECPress = 100;
				}
			}
		}
}
