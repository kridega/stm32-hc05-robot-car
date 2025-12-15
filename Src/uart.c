/*1024
 * uart.c
 *
 *  Created on: Dec 10, 2025
 *      Author: satyam singh
 *    Email id: singhsatyamiit2024@gmail.com
 */
#include <stdint.h>
#include "uart.h"
#include "pins.h"

uint8_t arr[3];
uint16_t i=0;

void uart_init(){
	/*uint32_t *pUSART_DR=(uint32_t*)0x40013804;
	uint32_t *pSR = (uint32_t*)0x40013800;*/

	APB2_ENR |= (1<<2)|(1<<14);

	GPIOA_CRH &= ~(0xFF0);
	GPIOA_CRH |= (0x8 << 4);
	GPIOA_CRH |= (0x4 << 8);


	USART_BRR_t *pBaud = (USART_BRR_t*)0x40013808;
	pBaud->fraction=0x1;
	pBaud->mantissa=0x34;

	uint32_t *pCR1 = (uint32_t*)0x4001380C;
	*pCR1 |= 0b10000000101100;

	uint32_t *NVIC_ISER1 = (uint32_t*)0xE000E104;
	*NVIC_ISER1 |= (1<<5);
}




