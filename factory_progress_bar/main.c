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

	init();
	_delay_ms(100);

	while(1)
	{
		if(!(PIN_SIGNAL&SIGNAL1))
		{
			PORT_MOTOR|=MOTOR1|MOTOR2;
			for (int i=1;i<9;i++)
			{
				switch(i)
				{
				case 1:
					PORT_LED|=LED1;
					break;
				case 2:
					PORT_LED|=LED2;
					break;
				case 3:
					PORT_LED|=LED3;
					break;
				case 4:
					PORT_LED|=LED4;
					break;
				case 5:
					PORT_LED|=LED5;
					break;
				case 6:
					PORT_LED|=LED6;
					break;
				case 7:
					PORT_LED|=LED7;
					break;
				case 8:
					PORT_LED|=LED8;
					break;
				}
				_delay_ms(500);
			}
			clear_all();
		}

	}
	return 0;
}

