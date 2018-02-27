// Created by: KAMIL WANAT
// uC: Atmega 8A
// dost�pne porty: PC4-6, PB3-7
// port przycisku: PB0


#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include "functions.h"

int t_counter0 = 0;
uint8_t p_counter = 0;


int main(void) {
	uint8_t key_lock;
	init();
	_delay_ms(20);
	while (1) {
		_delay_ms(20);


		if (!key_lock && !(PINKEY & KEY)) { // OCZEKIWANIE NA WCI�NI�CIE PRZYCISKU
		start_timer();  // W��CZENIE TIMERA

			key_lock = 1;
		} else if (key_lock && (PINKEY & KEY))
			key_lock++;

	}
	return 0;
}


ISR (TIMER0_OVF_vect) {  //OBS�UGA PROCEDURY PRZERWANIA TIMERA 0


	t_counter0++;

	 if (t_counter0 == TIME) { // 1 OKRES CZASU
		PORTLEDA |= LED1A|LED2A|LED3A|LED4A|LED5A;  // W��CZENIE ANOD DI�D
		PORTLEDK |= LED1K;    // W��CZENIE 1 DI�D
	} else if (t_counter0 == (2 * TIME)) {// 2 OKRES CZASU
		PORTLEDK &= !LED1K;  // WY��CZENIE 1 DI�D
		PORTLEDK |= LED2K;	 // W��CZENIE 2 DI�D
	} else if (t_counter0 == (3 * TIME)) {// 3 OKRES CZASU
		PORTLEDK &= !LED2K;  // WY��CZENIE 2 DI�D
		PORTLEDK |= LED3K;   // W��CZENIE 3 DI�D
	} else if (t_counter0 == (4 * TIME)) {// 4 OKRES CZASU
		PORTLEDK &= !LED3K;  // WY��CZENIE 3 DI�D
		PORTLEDK |= LED4K;   // W��CZENIE 4 DI�D
	} else if (t_counter0 == (5 * TIME)) {// 5 OKRES CZASU
		PORTLEDK &= !LED4K;  // WY��CZENIE 4 DI�D
		PORTLEDK |= LED5K;   // W��CZENIE 5 DI�D
	} else if (t_counter0 == (6 * TIME)) {// 6 OKRES CZASU
		PORTLEDK &= !LED5K; // WY��CZENIE 5 DI�D
		t_counter0 = (TIME-1);
		p_counter++; // ZWI�KSZENIE LICZNIKA PROGRAMOWEGO
	}
	 if (p_counter == PROGRAM_TIME) { // JE�ELI OSI�GNI�TO LICZNIK PROGRAMOWY
		stop_timer(); // ZATRZYMANIE TIMERA
		p_counter = 0; // WYZEROWANIE LICZNIKA
	}


	}
