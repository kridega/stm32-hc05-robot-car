/*
 * pwm.h
 *
 *  Created on: Dec 10, 2025
 *      Author: satyam singh
 *    Email id: singhsatyamiit2024@gmail.com
 */
#include <stdint.h>
#ifndef PWM_H_
#define PWM_H_

void pwm_init();
void analogWrite(uint8_t channel,uint8_t speed);
void pwm_test(uint8_t channel);
void move_motor(uint8_t motor, uint8_t speed, uint8_t dir);

#endif /* PWM_H_ */
