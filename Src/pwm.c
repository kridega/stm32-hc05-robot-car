/*
 * pwm.c
 *
 *  Created on: Dec 10, 2025
 *      Author: satyam singh
 *    Email id: singhsatyamiit2024@gmail.com
 */
#include<stdint.h>
#include "pwm.h"
#include "pins.h"

void pwm_init(){
	//APB2_ENR |= (1<<4); //test
	APB2_ENR |= (1<<3)|(1<<2)|(1<<0); //enable B gpio, A gpio, alternate function

	APB1_ENR |= (1<<2)|(1<<0);//enable timer 4, 2

	GPIOA_CRL &= ~0xFFFF;//clearing bits for A
	GPIOA_CRL |= 0xAAAA; //setting alternate for A

	GPIOB_CRL &= ~(0xFF000000);
	GPIOB_CRL |= 0xAA000000;
	GPIOB_CRH &= ~(0xFF);
	GPIOB_CRH |= 0xAA;


	TIM2_CCMR1 =(0b110100001101000);
	TIM2_CCMR2 =(0b110100001101000);

	TIM4_CCMR1 =(0b110100001101000);
	TIM4_CCMR2 =(0b110100001101000);

	TIM2_PSC = 71;

	TIM4_PSC = 71;

	TIM2_CR1 |= (1<<7);
	TIM2_CR1 |= (1<<0);

	TIM4_CR1 |= (1<<7);
	TIM4_CR1 |= (1<<0);

	TIM2_ARR = 255;

	TIM4_ARR = 255;

	TIM2_CCER = (1<<0)|(1<<4)|(1<<8)|(1<<12);

	TIM4_CCER = (1<<0)|(1<<4)|(1<<8)|(1<<12);

	for(int i=0;i<9;i++) analogWrite(i, 0);
}

void analogWrite(uint8_t channel,uint8_t speed){
	if (speed>255) speed =255;

	if (channel == 1) TIM2_CCR1=speed;
	else if (channel == 2) TIM2_CCR2=speed;
	else if (channel == 3) TIM2_CCR3=speed;
	else if (channel == 4) TIM2_CCR4=speed;
	else if (channel == 5) TIM4_CCR1=speed;
	else if (channel == 6) TIM4_CCR2=speed;
	else if (channel == 7) TIM4_CCR3=speed;
	else if (channel == 8) TIM4_CCR4=speed;
}

void pwm_test(uint8_t channel){
	for (int i=0;i<=255;i++){
		analogWrite(channel, i);
		delay_ms(10);
	}
	for (int i=255;i>=0;i--){
		analogWrite(channel, i);
		delay_ms(10);
	}
}

void move_motor(uint8_t motor, uint8_t speed, uint8_t dir){
	if (motor == 1){
		if(dir == 0){
			analogWrite(1, speed);
			analogWrite(2, 0);
		}else if(dir == 1){
			analogWrite(2, speed);
			analogWrite(1, 0);
		}
	}
	else if (motor == 2){
		if(dir == 0){
			analogWrite(3, speed);
			analogWrite(4, 0);
		}else if(dir == 1){
			analogWrite(4, speed);
			analogWrite(3, 0);
		}
	}
	else if (motor == 3){
		if(dir == 0){
			analogWrite(5, speed);
			analogWrite(6, 0);
		}else if(dir == 1){
			analogWrite(6, speed);
			analogWrite(5, 0);
		}
	}
	else if (motor == 4){
		if(dir == 0){
			analogWrite(7, speed);
			analogWrite(8, 0);
		}else if(dir == 1){
			analogWrite(8, speed);
			analogWrite(7, 0);
		}
	}
}
