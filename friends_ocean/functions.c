/*
 * functions.c
 *
 *  Created on: 3 lis 2017
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
}
void timer_init()
{
TCCR0A |= (1 << WGM01);  //tryb CTC
	//TCCR0B |= (1<<CS00)|(1<<CS02); //1024 bit prescaler
	OCR0A = 39; //przerwanie co 40ms
	TIMSK0 |= (1 << OCIE0A);
	//sei();
}

void timer_start() {
	TCCR0B |= (1 << CS00) | (1 << CS02);
}

void timer_stop() {
	TCCR0B &= (!(1 << CS00)) & (!(1 << CS02));
}
