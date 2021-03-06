/*
 * main.c
 *
 *  Created on: 6 lis 2017
 *      Author: Kamil
 */

#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include "peripheral_config.h"
#include "functions.h"

int main(void) {

	init(); // INICJALIZACJA
	_delay_ms(100);

	for (int i = 1; i < 9; i++) { //W��CZANIE KOLEJNYCH DI�D
		switch (i) {
		case 1:
			PORT_MOTOR |= MOTOR1; //W��CZENIE PIERWSZEGO SILNIKA
			PORT_LED |= LED1;  // W��CZENIE 1 DIODY
			break;
		case 2:
			PORT_LED |= LED2;  // W��CZENIE 2 DIODY
			break;
		case 3:
			PORT_LED |= LED3;  // W��CZENIE 3 DIODY
			break;
		case 4:
			PORT_LED |= LED4;  // W��CZENIE 4 DIODY
			break;
		case 5:
			PORT_MOTOR &= ~MOTOR1; // WY��CZENIE PIERWSZEGO SILNIKA
			PORT_MOTOR |= MOTOR2;  // W��CZENIE DRUGIEGO SILNIKA
			PORT_LED |= LED5;  // W��CZENIE 5 DIODY
			break;
		case 6:
			PORT_LED |= LED6;  // W��CZENIE 6 DIODY
			break;
		case 7:
			PORT_LED |= LED7;  // W��CZENIE 7 DIODY
			break;
		case 8:
			PORT_LED |= LED8;  // W��CZENIE 8 DIODY
			break;
		}
		_delay_ms(250);
	}
	clear_all(); // WY��CZENIE SILNIK�W I DI�D

	return 0;
}

