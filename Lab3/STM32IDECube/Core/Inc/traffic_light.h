/*
 * traffic_light.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Administrator
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

typedef enum {RED, GREEN, YELLOW } eLightState;

extern int Time_in_state_1;
extern int Time_in_state_2;

void Traffic_Light_Init(void);
void Traffic_Light_Update_12(void);
void Traffic_Light_Update_34(void);


#endif /* INC_TRAFFIC_LIGHT_H_ */
