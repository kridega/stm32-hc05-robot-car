/*
 * pins.h
 *
 *  Created on: Dec 11, 2025
 *      Author: satyam singh
 *    Email id: singhsatyamiit2024@gmail.com
 */
#include <stdint.h>

#ifndef PINS_H_
#define PINS_H_

#define TIM2_CR1      (*(volatile uint32_t*)0x40000000)
#define TIM2_CCMR1    (*(volatile uint32_t*)0x40000018)
#define TIM2_CCMR2    (*(volatile uint32_t*)0x4000001C)
#define TIM2_CCER     (*(volatile uint32_t*)0x40000020)
#define TIM2_PSC      (*(volatile uint32_t*)0x40000028)
#define TIM2_ARR      (*(volatile uint32_t*)0x4000002C)
#define TIM2_CCR1     (*(volatile uint32_t*)0x40000034)
#define TIM2_CCR2     (*(volatile uint32_t*)0x40000038)
#define TIM2_CCR3     (*(volatile uint32_t*)0x4000003C)
#define TIM2_CCR4     (*(volatile uint32_t*)0x40000040)

#define TIM4_CR1      (*(volatile uint32_t*)0x40000800)
#define TIM4_CCMR1    (*(volatile uint32_t*)0x40000818)
#define TIM4_CCMR2    (*(volatile uint32_t*)0x4000081C)
#define TIM4_CCER     (*(volatile uint32_t*)0x40000820)
#define TIM4_PSC      (*(volatile uint32_t*)0x40000828)
#define TIM4_ARR      (*(volatile uint32_t*)0x4000082C)
#define TIM4_CCR1     (*(volatile uint32_t*)0x40000834)
#define TIM4_CCR2     (*(volatile uint32_t*)0x40000838)
#define TIM4_CCR3     (*(volatile uint32_t*)0x4000083C)
#define TIM4_CCR4     (*(volatile uint32_t*)0x40000840)

#define APB1_ENR      (*(volatile uint32_t*)0x4002101C)
#define APB2_ENR      (*(volatile uint32_t*)0x40021018)

#define GPIOA_CRL     (*(volatile uint32_t*)0x40010800)
#define GPIOA_CRH     (*(volatile uint32_t*)0x40010804)
#define GPIOB_CRL     (*(volatile uint32_t*)0x40010C00)
#define GPIOB_CRH     (*(volatile uint32_t*)0x40010C04)
#define GPIOC_CRH     (*(volatile uint32_t*)0x40011004)

#define GPIOA_IDR     (*(volatile uint32_t*)0x40010808)
#define GPIOC_ODR     (*(volatile uint32_t*)0x4001100C)




#endif /* PINS_H_ */
