/*
 * main.c
 *
 *  Created on: 12 lut 2018
 *      Author: Kamil
 */

#include <avr/io.h>
#include <avr/interrupt.h>
# include <util/delay.h>
# include "peripheral_config.h"



int main()
{
	init(); // INICJALIZACJA PORT�W

	while(1)  // P�TLA G��WNA
	{
		if(!(PINKEY&KEY))  // OCZEKIWANIE NA WCI�NI�CIE PRZYCISKU
		{
			Motor_ON(); // W��CZENIE SILNIK�W
			_delay_ms(180000); // OCZEKIWANIE 3 MINUTY
			Motor_OFF(); // WY��CZENIE SILNIK�W
		}
	}
	return 0;
}

void init() // INICJALIZACJA PORT�W
{
	DDR1=0xFF;
	DDR2=0xFF;
	PORTKEY|=KEY;
	_delay_ms(500);
}

void Motor_ON() // W��CZENIE SILNIK�W
{
	PORT1=0xFF;
	PORT2=0xFF;
}

void Motor_OFF() // WY��CZENIE SILNIK�W
{
	PORT1=0x00;
	PORT2=0x00;
}
