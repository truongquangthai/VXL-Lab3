/*
 * input_reading.h
 *
 *  Created on: Oct 6, 2021
 *      Author: ACER
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_
# define NO_OF_BUTTONS 3
void button_reading (void);
unsigned char is_counterFor500ms_equal_0 ();
unsigned char is_blinkCounter500ms_equal_0 ();
unsigned char is_counterFor1s_equal_0 ();
unsigned char is_button_pressed_200ms ( uint8_t index );
unsigned char is_button_released ( uint8_t index );
#endif /* INC_INPUT_READING_H_ */
