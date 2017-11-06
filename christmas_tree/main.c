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

int main(void)
{
	init();
	while(1)
	{

	}
	return 0;
}

ISR (TIMER0_COMPA_vect)
{
}
