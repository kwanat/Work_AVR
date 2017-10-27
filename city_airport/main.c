// Created by: KAMIL WANAT
// uC: Attiny 24
// dost�pne porty: PA0-7, PB0-3
// port przycisku: PB0
// porty wyjsciowe: PA0-7

#include <avr/io.h>
#include<avr/interrupt.h>
# include <util/delay.h>

//makra uzytkownika
#define il_migniec 8
#define czas_migniecia 40
#define czas_calosci 18

//makra sprzetowe
#define LED1 (1<<PA0)
#define LED2 (1<<PA1)
#define LED3 (1<<PA2)
#define LED4 (1<<PA3)
#define LED5 (1<<PA4)
#define LED6 (1<<PA5)
#define music (1<<PA7)
#define KEY (1<<PB0)
#define PORTLED PORTA
#define DDRLED DDRA
#define PORTLED1 PORTB
#define DDRLED1 DDRB
#define PINKEY PINB
#define PORTKEY PORTB
uint8_t d1;
uint8_t d2;
uint8_t d3;
uint8_t d4;
uint8_t d5;
uint8_t d6;
uint8_t t_counter0 = 0;
uint8_t t_counter1 = 0;
uint8_t t_counter2 = 0;
uint8_t p_counter = 0;
void timer_init();
void start_timer();
void stop_timer();
int main(void) {
	timer_init();
	uint8_t key_lock;
	DDRLED = 0xFF;
	DDRLED |= music;
	PORTKEY |= KEY;

	sei();
	while (1) {

		if (!key_lock && !(PINKEY & KEY)) {
			PORTLED ^= music;
			_delay_ms(50);
			PORTLED ^= music;

			start_timer();
			key_lock = 1;
			//reakcja na wcisniecie klawisza
		} else if (key_lock && (PINKEY & KEY))
			key_lock++;

	}
	return 0;
}

void timer_init() {
	TCCR0A |= (1 << WGM01);  //tryb CTC
	//TCCR0B |= (1<<CS00)|(1<<CS02); //1024 bit prescaler
	OCR0A = 39; //przerwanie co 40ms
	TIMSK0 |= (1 << OCIE0A);
	//sei();
}

void start_timer() {
	TCCR0B |= (1 << CS00) | (1 << CS02);
}

void stop_timer() {
	TCCR0B &= (!(1 << CS00)) & (!(1 << CS02));
}

ISR (TIM0_COMPA_vect) {
	//PORTLED ^=LED1;

	t_counter0++;
	t_counter1++;
	t_counter2++;


	switch(t_counter0)


	if(t_counter0==)

	if ((t_counter0 > 0) && (t_counter0 < 9)) {

		PORTLED ^= LED1;
	}
	if ((t_counter0 > 8) && (t_counter0 < 17)) {
		PORTLED ^= LED2;
		if (t_counter0 >= 16)
			t_counter0 = 0;
	}

	if ((t_counter1 > 2) && (t_counter1 < 11)) {
		PORTLED ^= LED3;
	}
	if ((t_counter1 > 10) && (t_counter1 < 19)) {
		PORTLED ^= LED4;
		if (t_counter1 >= 18)
			t_counter1 = 2;
	}

	if ((t_counter2 > 4) && (t_counter2 < 13)) {
		PORTLED ^= LED5;
	}
	if ((t_counter2 > 12) && (t_counter2 < 21)) {
		PORTLED ^= LED6;
		if (t_counter2 >= 20) {
			t_counter2 = 4;
			p_counter++;
		}
	}
	if (p_counter >= czas_calosci) {
		stop_timer();
		p_counter = 0;
	}
}
