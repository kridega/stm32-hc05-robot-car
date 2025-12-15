/*
 * uart.h
 *
 *  Created on: Dec 10, 2025
 *      Author: satyam singh
 *    Email id: singhsatyamiit2024@gmail.com
 */
#include <stdint.h>

#ifndef UART_H_
#define UART_H_

void uart_init();

typedef struct{
    uint32_t fraction :4;
	uint32_t mantissa :12;
   	uint32_t reserved :16;
}USART_BRR_t;

typedef struct{
	uint32_t SBK :1;
	uint32_t RWU :1;
	uint32_t RE :1;
	uint32_t TE :1;
	uint32_t IDLEIE :1;
	uint32_t RXNEIE :1;
	uint32_t TCIE :1;
	uint32_t TXEIE :1;
	uint32_t PEIE :1;
	uint32_t PS :1;
	uint32_t PCE :1;
	uint32_t WAKE :1;
	uint32_t M :1;
	uint32_t UE :1;
	uint32_t reserved :18;
}USART_CR1_t;

typedef struct{
	uint32_t ADD :4;
	uint32_t reserved1 :1;
	uint32_t LBDL :1;
	uint32_t LBDIE :1;
	uint32_t reserved2 :1;
	uint32_t LBCL :1;
	uint32_t CPHA :1;
	uint32_t CPOL :1;
	uint32_t CLKEN :1;
	uint32_t STOP :2;
	uint32_t LINEN :1;
	uint32_t reserved3 :17;
}USART_CR2_t;

typedef struct{
	uint32_t EIE :1;
	uint32_t IREN :1;
	uint32_t IRLP :1;
	uint32_t HDSEL :1;
	uint32_t NACK :1;
	uint32_t SCEN :1;
	uint32_t DMAR :1;
	uint32_t DMAT :1;
	uint32_t RTSE :1;
	uint32_t CTSE :1;
	uint32_t CTSIE :1;
	uint32_t reserved :21;
}USART_CR3_t;

extern uint8_t arr[3];
extern uint16_t i;

#endif /* UART_H_ */
