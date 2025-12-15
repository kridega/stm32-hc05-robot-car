/*
 * parse.h
 *
 *  Created on: Dec 14, 2025
 *      Author: satyam singh
 *    Email id: singhsatyamiit2024@gmail.com
 */
#include <stdint.h>

#ifndef PARSE_H_
#define PARSE_H_

void parseMotorCommand(void);
uint8_t isSingleCommand(char c);
void handle_single(char c);
void motor_control(char dir1,uint8_t val1,char dir2,uint8_t val2);
void move_motor(uint8_t motor, uint8_t speed, uint8_t dir);

#define RX_BUF_SIZE 8
#define MAX_SPEED 180
extern  uint8_t rxBuf[RX_BUF_SIZE];
extern volatile uint8_t rxIndex;


typedef enum {
    CMD_NONE,
    CMD_MOTOR,
    CMD_SINGLE
} CmdType_t;

typedef struct {
    CmdType_t type;

    // Motor command
    char dir1;      // F or B
    uint8_t val1;   // 0–99
    char dir2;      // R or L
    uint8_t val2;   // 0–60

    // Single char command
    char single;

} Command_t;

extern volatile Command_t rxCmd;

#endif /* PARSE_H_ */
