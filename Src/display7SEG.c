/*
 * display7SEG.c
 *
 *  Created on: Oct 6, 2021
 *      Author: ACER
 */
#include"main.h"


void  display7SEG_1(int digit)
{								//0    1	2	3	  4	   5    6    7    8    9
	unsigned char disp_array[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	unsigned char disp_bit,disp_hex;
	disp_hex=disp_array[digit];
	disp_bit=disp_hex & 0x01;
	HAL_GPIO_WritePin(first_O7SEG_1_Port, first_O7SEG_1_PIN, disp_bit);

	disp_bit=(disp_hex>>1)& 0x01;
	HAL_GPIO_WritePin(first_O7SEG_2_Port, first_O7SEG_2_PIN, disp_bit);

	disp_bit=(disp_hex>>2)& 0x01;
	HAL_GPIO_WritePin(first_O7SEG_3_Port, first_O7SEG_3_PIN, disp_bit);

	disp_bit=(disp_hex>>3)& 0x01;
	HAL_GPIO_WritePin(first_O7SEG_4_Port, first_O7SEG_4_PIN, disp_bit);

	disp_bit=(disp_hex>>4)& 0x01;
	HAL_GPIO_WritePin(first_O7SEG_5_Port, first_O7SEG_5_PIN, disp_bit);

	disp_bit=(disp_hex>>5)& 0x01;
	HAL_GPIO_WritePin(first_O7SEG_6_Port, first_O7SEG_6_PIN, disp_bit);

	disp_bit=(disp_hex>>6)& 0x01;
	HAL_GPIO_WritePin(first_O7SEG_7_Port, first_O7SEG_7_PIN, disp_bit);
}

void  display7SEG_2(int digit)
{								//0    1	2	3	  4	   5    6    7    8    9
	unsigned char disp_array[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	unsigned char disp_bit,disp_hex;
	disp_hex=disp_array[digit];
	disp_bit=disp_hex & 0x01;
	HAL_GPIO_WritePin(second_O7SEG_1_Port, second_O7SEG_1_PIN, disp_bit);

	disp_bit=(disp_hex>>1)& 0x01;
	HAL_GPIO_WritePin(second_O7SEG_2_Port, second_O7SEG_2_PIN, disp_bit);

	disp_bit=(disp_hex>>2)& 0x01;
	HAL_GPIO_WritePin(second_O7SEG_3_Port, second_O7SEG_3_PIN, disp_bit);

	disp_bit=(disp_hex>>3)& 0x01;
	HAL_GPIO_WritePin(second_O7SEG_4_Port, second_O7SEG_4_PIN, disp_bit);

	disp_bit=(disp_hex>>4)& 0x01;
	HAL_GPIO_WritePin(second_O7SEG_5_Port, second_O7SEG_5_PIN, disp_bit);

	disp_bit=(disp_hex>>5)& 0x01;
	HAL_GPIO_WritePin(second_O7SEG_6_Port, second_O7SEG_6_PIN, disp_bit);

	disp_bit=(disp_hex>>6)& 0x01;
	HAL_GPIO_WritePin(second_O7SEG_7_Port, second_O7SEG_7_PIN, disp_bit);
}

void display7SEG_3(int digit){
	unsigned char disp_array[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	unsigned char disp_bit,disp_hex;
	disp_hex=disp_array[digit];
	disp_bit=disp_hex & 0x01;
	HAL_GPIO_WritePin(third_O7SEG_1_Port, third_O7SEG_1_PIN, disp_bit);

	disp_bit=(disp_hex>>1)& 0x01;
	HAL_GPIO_WritePin(third_O7SEG_2_Port, third_O7SEG_2_PIN, disp_bit);

	disp_bit=(disp_hex>>2)& 0x01;
	HAL_GPIO_WritePin(third_O7SEG_3_Port, third_O7SEG_3_PIN, disp_bit);

	disp_bit=(disp_hex>>3)& 0x01;
	HAL_GPIO_WritePin(third_O7SEG_4_Port, third_O7SEG_4_PIN, disp_bit);

	disp_bit=(disp_hex>>4)& 0x01;
	HAL_GPIO_WritePin(third_O7SEG_5_Port, third_O7SEG_5_PIN, disp_bit);

	disp_bit=(disp_hex>>5)& 0x01;
	HAL_GPIO_WritePin(third_O7SEG_6_Port, third_O7SEG_6_PIN, disp_bit);

	disp_bit=(disp_hex>>6)& 0x01;
	HAL_GPIO_WritePin(third_O7SEG_7_Port, third_O7SEG_7_PIN, disp_bit);
}

void split_digit_to_display(int number,int mode){
	if(mode==1){
		HAL_GPIO_WritePin(Enable_third_7SEG_Port, Enable_third_7SEG_PIN, RESET);//turn on third 7SEG
		if(number<10){
			display7SEG_1(0);
			display7SEG_2(number);
			display7SEG_3(number);
		}
		else{
			display7SEG_2(number%10);
			display7SEG_3(number%10);
			display7SEG_1(number/10);

		}
	}
	else if(mode==2 || mode==3 || mode==4){
		//display value
		HAL_GPIO_WritePin(Enable_third_7SEG_Port, Enable_third_7SEG_PIN, SET);//turn off third 7SEG
		if(number<10){display7SEG_1(0);display7SEG_2(number);}
		else
		{
			display7SEG_2(number%10);
			display7SEG_1(number/10);
		}
		//display mode
		display7SEG_3(mode);
	}
}

