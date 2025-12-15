/*
 * detection.c
 *
 *  Created on: Dec 15, 2025
 *      Author: satyam singh
 *    Email id: singhsatyamiit2024@gmail.com
 */
#include "detection.h"
#include "pins.h"

uint8_t obj1 = 1;
uint8_t obj2 = 1;

void object_detection(void){
	if(GPIOA_IDR & (1<<5)){
		obj1 = 0;
	}else obj1 = 1;
	if(GPIOA_IDR & (1<<4)){
		obj2 = 0;
	}else obj2 = 1;
}

void led_setup(void){
	APB2_ENR |= (1<<4);
	GPIOC_CRH |= (3<<20);
}
