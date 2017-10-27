/*
 * functions.c
 *
 *  Created on: 23 pa� 2017
 *      Author: Kamil
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "functions.h"



void init() {
	PWM_init();
	timer_init();
	DDRLED = 0xFF;
	DDR_DISCO |= DISCO_LED1;
	DDR_DISCO|= DISCO_LED2;
	DDR_DISCO|= DISCO_LED3;
	MOTOR_DDR |= MOTOR1;
	//	DDRLED1 |= music;
	PORTKEY |= KEY;

	sei();

}

void PWM_init() {
	DDRB = (1 << PB2) | (1 << PB1); //LEDY podpi�te pod: PB2-LED lewy, PB1-LED prawy

	//PWM Mode 5 - Fast PWM, 8-bit
	//piny OC1A i OC1B ustawiane na Compare Match, kasowane przy BOTTOM czyli
	//Set OC1A/OC1B on Compare Match, clear OC1A/OC1B at BOTTOM, (inverting mode)
	TCCR1A = (1 << COM1A1) | (1 << COM1A0) | (1 << COM1B1) | (1 << COM1B0)/*| (1<<WGM13)| (1<<WGM12)| (1<<WGM11) */
	| (1 << WGM10);

}

void PWM_start() {
	DDRB = (1 << PB2) | (1 << PB1); //LEDY podpi�te pod: PB2-LED lewy, PB1-LED prawy

	OCR1A = 255;
	OCR1B = 255;
	TCCR1B = (1 << CS11); //preskaler = 256

}

void PWM_stop() {
	DDRB = (0 << PB2) | (0 << PB1); //LEDY podpi�te pod: PB2-LED lewy, PB1-LED prawy

	OCR1A = 255;
	OCR1B = 255;
	TCCR1B = (0 << CS11); //preskaler = 256
	OCR1A = 255;
	OCR1B = 255;

}
void timer_init() {

//	TCCR0 |=  (1<<CS01); //1024 bit prescaler
	TIMSK |= (1 << TOIE0);

}

void start_timer() {
	TCCR0 |= (1 << CS01);
}

void stop_timer() {
	TCCR0 &= (!(1 << CS00)) & (!(1 << CS02));
}


void static_LED_ON() {
	PORTLED |= STATIC_LED;
}
void static_LED_OFF() {
	PORTLED &= !STATIC_LED;
}
void disco_LED_OFF() {
	PORT_DISCO &= !DISCO_LED1;
	PORT_DISCO &= !DISCO_LED2;
	PORT_DISCO &= !DISCO_LED3;

}
void motor_ON()
{
	MOTOR_PORT|=MOTOR1;
}
void motor_OFF() {
	MOTOR_PORT&=~MOTOR1;
}
void ALL_OFF() {
	static_LED_OFF();
	disco_LED_OFF();
	motor_OFF();
}

char LED_przelicz_jasnosc(char wartosc) {

	//funkcja koryguj�ca jasno�� �wiecenia, warto�ci dobrane do�wiadczalnie

	if (wartosc > prog_0) {
		return 255;
	} else if (wartosc > prog_1) {
		return 128;
	} else if (wartosc > prog_2) {
		return 80;
	} else if (wartosc > prog_3) {
		return 60;
	} else if (wartosc > prog_4) {
		return 50;
	} else if (wartosc > prog_5) {
		return 35;
	} else if (wartosc > prog_6) {
		return 20;
	} else if (wartosc > prog_7) {
		return 10;
	} else if (wartosc > prog_8) {
		return 6;
	} else if (wartosc > prog_9) {
		return 3;
	} else {
		return 0;
	}
}