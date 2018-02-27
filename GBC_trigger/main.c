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
	init(); // INICJALIZACJA PORTÓW

	while(1)  // PÊTLA G£ÓWNA
	{
		if(!(PINKEY&KEY))  // OCZEKIWANIE NA WCIŒNIÊCIE PRZYCISKU
		{
			Motor_ON(); // W£¥CZENIE SILNIKÓW
			_delay_ms(180000); // OCZEKIWANIE 3 MINUTY
			Motor_OFF(); // WY£¥CZENIE SILNIKÓW
		}
	}
	return 0;
}

void init() // INICJALIZACJA PORTÓW
{
	DDR1=0xFF;
	DDR2=0xFF;
	PORTKEY|=KEY;
	_delay_ms(500);
}

void Motor_ON() // W£¥CZENIE SILNIKÓW
{
	PORT1=0xFF;
	PORT2=0xFF;
}

void Motor_OFF() // WY£¥CZENIE SILNIKÓW
{
	PORT1=0x00;
	PORT2=0x00;
}
