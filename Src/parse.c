/*
 * move.c
 *
 *  Created on: Dec 14, 2025
 *      Author: satyam singh
 *    Email id: singhsatyamiit2024@gmail.com
 */
#include "parse.h"
#include <stdint.h>

#include "parse.h"

uint8_t rxBuf[RX_BUF_SIZE];
volatile uint8_t rxIndex = 0;
volatile Command_t rxCmd;


void parseMotorCommand(void)
{
    // Format: F99R60

    if (
        (rxBuf[0]=='F' || rxBuf[0]=='B') &&
        (rxBuf[3]=='R' || rxBuf[3]=='L')
       )
    {
        uint8_t v1 =
            (rxBuf[1]-'0')*10 +
            (rxBuf[2]-'0');

        uint8_t v2 =
            (rxBuf[4]-'0')*10 +
            (rxBuf[5]-'0');

        if (v1 <= 99 && v2 <= 60)
        {
            rxCmd.type = CMD_MOTOR;
            rxCmd.dir1 = rxBuf[0];
            rxCmd.val1 = v1;
            rxCmd.dir2 = rxBuf[3];
            rxCmd.val2 = v2;
        }
        else {
            rxCmd.type = CMD_NONE; // Out of range
        }
    }
}

uint8_t isSingleCommand(char c)
{
    return (
        c=='V' || c=='v' ||
        c=='U' || c=='u' ||
        c=='W' || c=='w' ||
        c=='X' || c=='x' ||
        c=='Z' || c=='Y'
    );
}

void handle_single(char c)
{
    if (c == 'V'){
    }
    else if (c == 'v'){
    }
    else if (c == 'U'){
    }
    else if (c == 'u'){
    }
    else if (c == 'W'){
    }
    else if (c == 'w'){
    }
    else if (c == 'X'){
    }
    else if (c == 'x'){
    }
    else if (c == 'Z'){
    }
    else if (c == 'Y'){
    }
    else if (c == '1'){
    }
    else if (c == '2'){
    }
    else if (c == '3'){
    }
    else if (c == '4'){
    }
}


void motor_control(char dir1,uint8_t val1,char dir2,uint8_t val2){
	uint16_t v = val1*MAX_SPEED;
	val1=v/99;
	v = val2*MAX_SPEED;
	val2 = v/60;

	if (val2 >= val1)
	    v = 0;
	else
	    v = val1 - val2;


	if (dir1 == 'F'){
		if(dir2 == 'L'){
			move_motor(1, val1,0);
			move_motor(2, v, 1);
			move_motor(3, val1, 0);
			move_motor(4, v, 0);
		}
		else if (dir2 == 'R'){
			move_motor(1, v, 0);
			move_motor(2, val1, 1);
			move_motor(3, v, 0);
			move_motor(4, val1, 0);
		}
	}
	else if (dir1 == 'B'){
		if(dir2 == 'L'){
			move_motor(1, val1,1);
			move_motor(2, v, 0);
			move_motor(3, val1, 1);
			move_motor(4, v, 1);
		}
		else if (dir2 == 'R'){
			move_motor(1, v, 1);
			move_motor(2, val1, 0);
			move_motor(3, v, 1);
			move_motor(4, val1, 1);
		}
	}
}
