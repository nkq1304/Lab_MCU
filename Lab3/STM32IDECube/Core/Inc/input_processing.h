/*
 * input_processing.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Administrator
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

extern int red_duration;
extern int yellow_duration;
extern int green_duration;
extern int Light_state_LR;
extern int Light_state_BT;

void fsm_for_input_processing(void);

#endif /* INC_INPUT_PROCESSING_H_ */
