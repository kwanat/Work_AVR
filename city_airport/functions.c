/*
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



void init() {
	timer_init();
	DDRLEDA |= LED1A|LED2A|LED3A|LED4A|LED5A;
	DDRLEDK |= LED1K|LED2K|LED3K|LED4K|LED5K;
	//MOTOR_DDR |= MOTOR1;
	//	DDRLED1 |= music;
	PORTKEY |= KEY; //key pullup

	sei();

}

void timer_init() {

//	TCCR0 |=  (1<<CS01); //1024 bit prescaler
	TIMSK |= (1 << TOIE0);

}

void start_timer() {
	TCCR0 |= (1 << CS01);
}

void stop_timer() {
	TCCR0 &=  (~(1 << CS01));
}


void motor_ON()
{
	//MOTOR_PORT|=MOTOR1;
}
void motor_OFF() {
	//MOTOR_PORT&=~MOTOR1;
}
void ALL_OFF() {
	//motor_OFF();
}
