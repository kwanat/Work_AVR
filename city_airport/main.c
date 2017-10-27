// Created by: KAMIL WANAT
// uC: Atmega 8A
// dostêpne porty: PC4-6, PB3-7
// port przycisku: PB0


#include <avr/io.h>
#include<avr/interrupt.h>
# include <util/delay.h>
#include "functions.h"

int t_counter0 = 0;
int t_counter1 = 0;
uint8_t t_counter2 = 0;
uint8_t p_counter = 0;

char pwm1 = 255; //zaczynamy od PWM z duty cycle = 0
char pwm2 = 255;
char w_gore = 1; //
uint8_t currentpwm = 1;


int main(void) {
	uint8_t key_lock;
	init();
	while (1) {

		_delay_ms(20);

		if (!key_lock && !(PINKEY & KEY)) {
			PORTLED ^= music;
			_delay_ms(50);
			PORTLED ^= music;
			motor_ON();
			start_timer();

			key_lock = 1;
			//reakcja na wcisniecie klawisza
		} else if (key_lock && (PINKEY & KEY))
			key_lock++;

	}
	return 0;
}


ISR (TIMER0_OVF_vect) {
	//PORTLED ^=LED1;

	t_counter0++;
	t_counter1++;
	//t_counter2++;

	if (t_counter0 == 1)
		PORTLED ^= LED1;
	else if (t_counter0 == 20)
		PORTLED ^= LED2;
	else if (t_counter0 == 40)
		PORTLED ^= LED3;
	else if (t_counter0 == 60)
		PORTLED ^= LED4;
	else if (t_counter0 == 80)
		PORTLED ^= LED5;
	else if (t_counter0 == 100)
		PORTLED ^= LED6;
	else if (t_counter0 == 120) {
		t_counter0 = 0;
		p_counter++;
	} else if (p_counter == 60) {
		stop_timer();
		ALL_OFF();
		p_counter = 0;
	}
/*
	if (t_counter1 == 1){

		PORT_DISCO &= ~DISCO_LED2;
		PORT_DISCO &= ~DISCO_LED3;
		PORT_DISCO |= DISCO_LED1;
	}
	else if (t_counter1 == 200) {
		PORT_DISCO &= ~DISCO_LED1;
		PORT_DISCO |= DISCO_LED2;
	} else if (t_counter1 == 400) {
		PORT_DISCO &= ~DISCO_LED2;
		PORT_DISCO |= DISCO_LED3;
	} else if (t_counter1 == 600) {
		PORT_DISCO &= ~DISCO_LED1;
		PORT_DISCO &= ~DISCO_LED2;
		PORT_DISCO &= ~DISCO_LED3;
		PORT_DISCO ^= DISCO_LED1;
		PORT_DISCO ^= DISCO_LED2;
		PORT_DISCO ^= DISCO_LED3;
	} else if (t_counter1 == 620) {
		PORT_DISCO ^= DISCO_LED1;
		PORT_DISCO ^= DISCO_LED2;
		PORT_DISCO ^= DISCO_LED3;
	} else if (t_counter1 == 640) {
		PORT_DISCO ^= DISCO_LED1;
		PORT_DISCO ^= DISCO_LED2;
		PORT_DISCO ^= DISCO_LED3;
	} else if (t_counter1 == 660) {
		PORT_DISCO ^= DISCO_LED1;
		PORT_DISCO ^= DISCO_LED2;
		PORT_DISCO ^= DISCO_LED3;
	} else if (t_counter1 == 680) {
		PORT_DISCO ^= DISCO_LED1;
		PORT_DISCO ^= DISCO_LED2;
		PORT_DISCO ^= DISCO_LED3;
	} else if (t_counter1 == 700) {
		PORT_DISCO ^= DISCO_LED1;
		PORT_DISCO ^= DISCO_LED2;
		PORT_DISCO ^= DISCO_LED3;
	} else if (t_counter1 == 720) {
		PORT_DISCO ^= DISCO_LED1;
		PORT_DISCO ^= DISCO_LED2;
		PORT_DISCO ^= DISCO_LED3;
	} else if (t_counter1 == 740) {
		PORT_DISCO ^= DISCO_LED1;
		PORT_DISCO ^= DISCO_LED2;
		PORT_DISCO ^= DISCO_LED3;
	} else if (t_counter1 == 760) {
		t_counter1 = 0;

		PORT_DISCO &= ~DISCO_LED1;
		PORT_DISCO &= ~DISCO_LED2;
		PORT_DISCO &= ~DISCO_LED3;

	}*/
}


