
/*
 * functions.c
 *
 *  Created on: 27 paü 2017
 *      Author: Kamil
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "functions.h"



void init() { // INICJALIZACJA TIMERA ORAZ PORT”W WE/WY
	timer_init();
	DDRLEDA |= LED1A|LED2A|LED3A|LED4A|LED5A;
	DDRLEDK |= LED1K|LED2K|LED3K|LED4K|LED5K;
	PORTKEY |= KEY;

	sei();

}

void timer_init() { //INICJALIZACJA TIMERA

//	TCCR0 |=  (1<<CS01); //1024 bit prescaler
	TIMSK |= (1 << TOIE0);

}

void start_timer() {  //W£•CZENIE TIMERA
	TCCR0 |= (1 << CS01);
}

void stop_timer() {  //WY£•CZENIE TIMERA
	TCCR0 &=  (~(1 << CS01));
}



