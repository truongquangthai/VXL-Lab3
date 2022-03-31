/*
 * input_processing.c
 *
 *  Created on: Oct 6, 2021
 *      Author: ACER
 */




#include "main.h"
#include"input_reading.h"
#include "display7SEG.h"
#include "LED_Timer_structer.h"
#include "extern_variable.h"
#include"led_display.h"

enum MODE mode=MODE_4;
enum ButtonState { BUTTON_RELEASED =1,BUTTON_PRESSED_MORE_THAN_200ms_SECOND };
static enum ButtonState buttonState[NO_OF_BUTTONS]={BUTTON_RELEASED,BUTTON_RELEASED,BUTTON_RELEASED};

void sum(uint8_t *x, uint8_t *y, uint8_t *z, uint8_t *t){
	*t= *x + *y + *z;
}
void fsm_for_input_processing ( void ) {
	static int valueBuffer=1;
	static uint8_t switchedFlag=0;
	////////////////////////////////
	for(uint8_t i=0;i<NO_OF_BUTTONS;i++)
	{
		switch ( buttonState[i] ){
			case BUTTON_RELEASED :
				if(i==0) switchedFlag = 0;
				if(is_button_pressed_200ms(i)==1 &&is_button_released(i)==0 ){
					buttonState[i]=BUTTON_PRESSED_MORE_THAN_200ms_SECOND;
				}
			break;
			case BUTTON_PRESSED_MORE_THAN_200ms_SECOND:
				//BUTTON 1 process
				if(switchedFlag==0 && i==0){
					switch (mode) {
						case MODE_1:
							mode=MODE_2;
						break;
						case MODE_2:
							mode=MODE_3;
							//counterFor500ms=50;
						break;
						case MODE_3:
							mode=MODE_4;
							//counterFor500ms=50;
						break;
						case MODE_4:
							mode=MODE_1;
							//counterFor500ms=50;
						break;
					}
					switchedFlag=1;
				}
				if(is_button_pressed_200ms(i)==0 &&is_button_released(i)==1 ){
						buttonState[i]=BUTTON_RELEASED;
				}
			break ;
		}
	}
	///////////////////process of setting value/////////////////////
	if(is_counterFor500ms_equal_0()){
		if(valueBuffer<=98)valueBuffer++;
		else valueBuffer=1;
	}
	/////////////////////////PROCESSing MODE/////////////////////////
	switch (mode) {
		case MODE_1:
			if(is_counterFor1s_equal_0()){
				led_display(led_timer.MAX_RED_TIMER, led_timer.MAX_YELLOW_TIMER, led_timer.MAX_GREEN_TIMER,led_timer.total_value);
				if(led_timer.total_value>0) led_timer.total_value--;
				//else led_timer.total_value=led_timer.MAX_RED_TIMER + led_timer.MAX_GREEN_TIMER + led_timer.MAX_YELLOW_TIMER;
				else sum(&led_timer.MAX_RED_TIMER, &led_timer.MAX_GREEN_TIMER, &led_timer.MAX_YELLOW_TIMER, &led_timer.total_value);
			}
			split_digit_to_display(led_timer.total_value,mode);
			break;

		case MODE_2:
			if(is_blinkCounter500ms_equal_0()){
				HAL_GPIO_TogglePin(H_RED_GPIO_Port, H_RED_PIN);
				HAL_GPIO_TogglePin(V_RED_GPIO_Port, V_RED_PIN);
			}
			if(buttonState[2]==BUTTON_PRESSED_MORE_THAN_200ms_SECOND){
				if(( valueBuffer+led_timer.MAX_GREEN_TIMER + led_timer.MAX_YELLOW_TIMER)<99){
					led_timer.MAX_RED_TIMER=valueBuffer;
					sum(&led_timer.MAX_RED_TIMER, &led_timer.MAX_GREEN_TIMER, &led_timer.MAX_YELLOW_TIMER, &led_timer.total_value);
				}
				split_digit_to_display(led_timer.total_value,mode);
			}
			else split_digit_to_display(valueBuffer,mode);
			break;

		case MODE_3:
			if(is_blinkCounter500ms_equal_0()) {
				HAL_GPIO_TogglePin(H_YELLOW_GPIO_Port, H_YELLOW_PIN);
				HAL_GPIO_TogglePin(V_YELLOW_GPIO_Port, V_YELLOW_PIN);
			}
			if(buttonState[2]==BUTTON_PRESSED_MORE_THAN_200ms_SECOND){
				if((led_timer.MAX_RED_TIMER+ led_timer.MAX_GREEN_TIMER + valueBuffer )<99){
					led_timer.MAX_YELLOW_TIMER=valueBuffer;
					sum(&led_timer.MAX_RED_TIMER, &led_timer.MAX_GREEN_TIMER, &led_timer.MAX_YELLOW_TIMER, &led_timer.total_value);
				}
				split_digit_to_display(led_timer.total_value,mode);
			}
			else split_digit_to_display(valueBuffer,mode);
			break;

		case MODE_4:
			if(is_blinkCounter500ms_equal_0()) {
				HAL_GPIO_TogglePin(H_GREEN_GPIO_Port, H_GREEN_PIN);
				HAL_GPIO_TogglePin(V_GREEN_GPIO_Port, V_GREEN_PIN);
			}
			if(buttonState[2]==BUTTON_PRESSED_MORE_THAN_200ms_SECOND){
				if((led_timer.MAX_RED_TIMER + valueBuffer + led_timer.MAX_YELLOW_TIMER)<99){
					led_timer.MAX_GREEN_TIMER=valueBuffer;
					sum(&led_timer.MAX_RED_TIMER, &led_timer.MAX_GREEN_TIMER , &led_timer.MAX_YELLOW_TIMER, &led_timer.total_value);
				}
				split_digit_to_display(led_timer.total_value,mode);
			}
			else split_digit_to_display(valueBuffer,mode);
			break;
	}

}
