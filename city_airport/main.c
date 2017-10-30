// Created by: KAMIL WANAT
// uC: Atmega 8A
// dostêpne porty: PC4-6, PB3-7
// port przycisku: PB0


#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include "functions.h"

int t_counter0 = 0;
//int t_counter1 = 0;
//uint8_t t_counter2 = 0;
uint8_t p_counter = 0;


int main(void) {
	uint8_t key_lock;
	init();
	_delay_ms(20);
	while (1) {
		_delay_ms(20);


		if (!key_lock && !(PINKEY & KEY)) {
		start_timer();

			key_lock = 1;
			//reakcja na wcisniecie klawisza
		} else if (key_lock && (PINKEY & KEY))
			key_lock++;



//		PORTLEDA |= LED1A|LED2A|LED3A|LED4A|LED5A;
//		PORTLEDK |= LED1K|LED2K|LED3K|LED4K|LED5K;
	}
	return 0;
}


ISR (TIMER0_OVF_vect) {
	//PORTLED ^=LED1;

	t_counter0++;
	//t_counter1++;
	//t_counter2++;
/*
	if (t_counter0 == TIME) {
		PORTLEDA |= LED1A;
		PORTLEDK |= LED1K;
	} else if (t_counter0 == (2 * TIME)) {
		PORTLEDK &= !LED1K;
		PORTLEDK |= LED2K;
	} else if (t_counter0 == (3 * TIME)) {
		PORTLEDK &= !LED2K;
		PORTLEDK |= LED3K;
	} else if (t_counter0 == (4 * TIME)) {
		PORTLEDK &= !LED3K;
		PORTLEDK |= LED4K;
	} else if (t_counter0 == (5 * TIME)) {
		PORTLEDK &= !LED4K;
		PORTLEDK |= LED5K;
	} else if (t_counter0 == (6 * TIME)) {
		PORTLEDK &= !LED5K;
		PORTLEDA &= !LED1A;
		PORTLEDA |= LED2A;
		PORTLEDK |= LED1K;
	} else if (t_counter0 == (7 * TIME)) {
		PORTLEDK &= !LED1K;
		PORTLEDK |= LED2K;
	} else if (t_counter0 == (8 * TIME)) {
		PORTLEDK &= !LED2K;
		PORTLEDK |= LED3K;
	} else if (t_counter0 == (9 * TIME)) {
		PORTLEDK &= !LED3K;
		PORTLEDK |= LED4K;
	} else if (t_counter0 == (10 * TIME)) {
		PORTLEDK &= !LED4K;
		PORTLEDK |= LED5K;
	} else if (t_counter0 == (11 * TIME)) {
		PORTLEDK &= !LED5K;
		PORTLEDA &= !LED2A;
		PORTLEDA |= LED3A;
		PORTLEDK |= LED1K;
	} else if (t_counter0 == (12 * TIME)) {
		PORTLEDK &= !LED1K;
		PORTLEDK |= LED2K;
	} else if (t_counter0 == (13 * TIME)) {
		PORTLEDK &= !LED2K;
		PORTLEDK |= LED3K;
	} else if (t_counter0 == (14 * TIME)) {
		PORTLEDK &= !LED3K;
		PORTLEDK |= LED4K;
	} else if (t_counter0 == (15 * TIME)) {
		PORTLEDK &= !LED4K;
		PORTLEDK |= LED5K;
	} else if (t_counter0 == (16 * TIME)) {
		PORTLEDK &= !LED5K;
		PORTLEDA &= !LED2A;
		PORTLEDA |= LED4A;
		PORTLEDK |= LED1K;
	} else if (t_counter0 == (17 * TIME)) {
		PORTLEDK &= !LED1K;
		PORTLEDK |= LED2K;
	} else if (t_counter0 == (18 * TIME)) {
		PORTLEDK &= !LED2K;
		PORTLEDK |= LED3K;
	} else if (t_counter0 == (19 * TIME)) {
		PORTLEDK &= !LED3K;
		PORTLEDK |= LED4K;
	} else if (t_counter0 == (20 * TIME)) {
		PORTLEDK &= !LED4K;
		PORTLEDK |= LED5K;
	} else if (t_counter0 == (21 * TIME)) {
		PORTLEDK &= !LED5K;
		PORTLEDA &= !LED4A;
		PORTLEDA |= LED5A;
		PORTLEDK |= LED1K;
	} else if (t_counter0 == (22 * TIME)) {
		PORTLEDK &= !LED1K;
		PORTLEDK |= LED2K;
	} else if (t_counter0 == (23 * TIME)) {
		PORTLEDK &= !LED2K;
		PORTLEDK |= LED3K;
	} else if (t_counter0 == (24 * TIME)) {
		PORTLEDK &= !LED3K;
		PORTLEDK |= LED4K;
	} else if (t_counter0 == (25 * TIME)) {
		PORTLEDK &= !LED4K;
		PORTLEDK |= LED5K;
	} else if (t_counter0 == (26 * TIME)) {
		t_counter0 = 0;
		p_counter++;
	} else if (p_counter == 60) {
		stop_timer();
		ALL_OFF();
		p_counter = 0;
	}
*/





	// WERSJA 2
	 if (t_counter0 == TIME) {
		PORTLEDA |= LED1A|LED2A|LED3A|LED4A|LED5A;
		PORTLEDK |= LED1K;
	} else if (t_counter0 == (2 * TIME)) {
		PORTLEDK &= !LED1K;
		PORTLEDK |= LED2K;
	} else if (t_counter0 == (3 * TIME)) {
		PORTLEDK &= !LED2K;
		PORTLEDK |= LED3K;
	} else if (t_counter0 == (4 * TIME)) {
		PORTLEDK &= !LED3K;
		PORTLEDK |= LED4K;
	} else if (t_counter0 == (5 * TIME)) {
		PORTLEDK &= !LED4K;
		PORTLEDK |= LED5K;
	} else if (t_counter0 == (6 * TIME)) {
		PORTLEDK &= !LED5K;
		t_counter0 = (TIME-1);
		p_counter++;
	}
	 if (p_counter == PROGRAM_TIME) {
		stop_timer();
		ALL_OFF();
		p_counter = 0;
	}


	}
