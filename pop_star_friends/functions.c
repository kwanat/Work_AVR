/*
 * functions.c
 *
 *  Created on: 23 paü 2017
 *      Author: Kamil
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "functions.h"



void init() { // INICJALIZACJA TIMEROW, PORT”W, PRZERWA—
	PWM_init();
	timer_init();
	DDRLED = 0xFF;
	DDR_DISCO |= DISCO_LED1;
	DDR_DISCO|= DISCO_LED2;
	DDR_DISCO|= DISCO_LED3;
	MOTOR_DDR |= MOTOR1;
	PORTKEY |= KEY;

	sei();

}

void PWM_init() { // INICJALIZACJA TRYBU PWM DLA DI”D NA PORTACH PB1 I PB2
	DDRB = (1 << PB2) | (1 << PB1); //LEDY podpiÍte pod: PB2-LED lewy, PB1-LED prawy


	TCCR1A = (1 << COM1A1) | (1 << COM1A0) | (1 << COM1B1) | (1 << COM1B0)
	| (1 << WGM10);

}

void PWM_start() { // W£•CZENIE TIMERA Z TRYBEM PWM
	DDRB = (1 << PB2) | (1 << PB1); //LEDY podpiÍte pod: PB2-LED lewy, PB1-LED prawy

	OCR1A = 255;
	OCR1B = 255;
	TCCR1B = (1 << CS11); //preskaler = 256

}

void PWM_stop() { // ZATRZYMANIE TIMERA W TRYBIE PWM
	DDRB = (0 << PB2) | (0 << PB1); //LEDY podpiÍte pod: PB2-LED lewy, PB1-LED prawy

	OCR1A = 255;
	OCR1B = 255;
	TCCR1B = (0 << CS11); //preskaler = 256
	OCR1A = 255;
	OCR1B = 255;

}
void timer_init() { // INICJALIZACJA TIMERA 0

	TIMSK |= (1 << TOIE0);

}

void start_timer() { // W£•CZENIE TIMERA 0
	TCCR0 |= (1 << CS01);
}

void stop_timer() {  // WY£•CZENIE TIMERA 0
	TCCR0 &= (!(1 << CS00)) & (!(1 << CS02));
}


void static_LED_ON() { // W£•CZENIE DI”D STATYCZNYCH
	PORTLED |= STATIC_LED;
}
void static_LED_OFF() { // WY£•CZENIE DI”D STATYCZNYCH
	PORTLED &= !STATIC_LED;
}
void disco_LED_OFF() { // WY£•CZENIE DI”D MIGAJ•CYCH
	PORT_DISCO &= !DISCO_LED1;
	PORT_DISCO &= !DISCO_LED2;
	PORT_DISCO &= !DISCO_LED3;

}
void motor_ON() // W£•CZENIE SILNIK”W
{
	MOTOR_PORT|=MOTOR1;
}
void motor_OFF() { // WY£•CZENIE SILNIK”W
	MOTOR_PORT&=~MOTOR1;
}
void ALL_OFF() { // WY£ACZENIE WSZYSTKICH DI”D I SILNIK”W
	static_LED_OFF();
	disco_LED_OFF();
	motor_OFF();
}

