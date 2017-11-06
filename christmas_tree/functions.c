/*
 * functions.c
 *
 *  Created on: 6 lis 2017
 *      Author: Kamil
 */



#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include "peripheral_config.h"
#include "functions.h"




void init()
{
	timer_init();
	ports_init();
}
void timer_init()
{

TCCR0A |= (1 << WGM01);  //tryb CTC
	OCR0A = 39;
	TIMSK0 |= (1 << OCIE0A);
}

void timer_start()
{
	TCCR0B |= (1 << CS00)|(1<<CS02); //preskaler 1bit
}

void timer_stop()
{
	TCCR0B &= (!(1 << CS00)) &(!(1 << CS01))& (!(1 << CS02));
}
void ports_init()
{

}


