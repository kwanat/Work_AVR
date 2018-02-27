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
while(1) // PÊTLA G£ÓWNA
{
	for (int i = 1; i < 9; i++) { // KOLEJNE ITERACJE W£¥CZAJ¥CE KOLEJNE DIODY
		switch (i) {
		case 1:
			PORT_LED &= ~LED5; // WY£¥CZENIE 5 DIODY
			PORT_LED |= LED1;  // W£¥CZENIE 1 DIODY

			break;
		case 2:
			PORT_LED &= ~LED6; // WY£¥CZENIE 6 DIODY
			PORT_LED |= LED2;  // W£¥CZENIE 2 DIODY

			break;
		case 3:
			PORT_LED &= ~LED7; // WY£¥CZENIE 7 DIODY
			PORT_LED |= LED3;  // W£¥CZENIE 3 DIODY
			break;
		case 4:
			PORT_LED &= ~LED8; // WY£¥CZENIE 8 DIODY
			PORT_LED |= LED4;  // W£¥CZENIE 4 DIODY
			break;
		case 5:
			PORT_LED &= ~LED1; // WY£¥CZENIE 1 DIODY
			PORT_LED |= LED5;  // W£¥CZENIE 5 DIODY
			break;
		case 6:
			PORT_LED &= ~LED2; // WY£¥CZENIE 2 DIODY
			PORT_LED |= LED6;  // W£¥CZENIE 6 DIODY
			break;
		case 7:
			PORT_LED &= ~LED3; // WY£¥CZENIE 3 DIODY
			PORT_LED |= LED7;  // W£¥CZENIE 7 DIODY
			break;
		case 8:
			PORT_LED &= ~LED4; // WY£¥CZENIE 4 DIODY
			PORT_LED |= LED8;  // W£¥CZENIE 8 DIODY
			break;
		}
		_delay_ms(250); // PRZERWA 250 MS
	}
}

	return 0;
}

