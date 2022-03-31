/*
 * LED_Timer_structure.h
 *
 *  Created on: Oct 11, 2021
 *      Author: ACER
 */

#ifndef INC_LED_TIMER_STRUCTER_H_
#define INC_LED_TIMER_STRUCTER_H_

struct MAX_TIMER{
	uint8_t MAX_RED_TIMER;
	uint8_t MAX_GREEN_TIMER;
	uint8_t MAX_YELLOW_TIMER;
	uint8_t total_value;
}led_timer={15,10,5,30};

#endif /* INC_LED_TIMER_STRUCTER_H_ */
