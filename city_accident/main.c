// Created by: KAMIL WANAT
// uC: Attiny 24
// dostêpne porty: PA0-7, PB0-3
// port przycisku: PB0
// porty wyjsciowe: PA0-7

#include <avr/io.h>
#include<avr/interrupt.h>
# include <util/delay.h>

//makra uzytkownika
#define il_migniec 8
#define czas_migniecia 40
#define czas_calosci 18

// MAKRA DIÓD 1 POJAZDU
#define LED1 (1<<PA0)
#define LED2 (1<<PA1)

// MAKRA DIÓD 2 POJAZDU
#define LED3 (1<<PA2)
#define LED4 (1<<PA3)

// MAKRA DIÓD 3 POJAZDU
#define LED5 (1<<PA4)
#define LED6 (1<<PA5)

// PIN TRIGGERUJ¥CY MUZYKÊ
#define music (1<<PA7)

// PIN PRZYCISKU
#define KEY (1<<PB0)

// PORTY
#define PORTLED PORTA
#define DDRLED DDRA
#define PORTLED1 PORTB
#define DDRLED1 DDRB
#define PINKEY PINB
#define PORTKEY PORTB

// ZMIENNE POMOCNICZE W OBSLUDZE PRZERWANIA
uint8_t t_counter0 = 0;
uint8_t t_counter1 = 0;
uint8_t t_counter2 = 0;
uint8_t p_counter = 0;

//FUNKCJE POMOCNICZE
void timer_init();
void start_timer();
void stop_timer();

int main(void) {
	timer_init();
	uint8_t key_lock;
	DDRLED = 0xFF;  // INICJALIZACJA PORTÓW
	DDRLED |= music;
	PORTKEY |= KEY;

	sei();
	while (1) { //PÊTLA G£ÓWNA

		if (!key_lock && !(PINKEY & KEY)) { // OCZEKIWANIE NA WCIŒNIÊCIE PRZYCISKU
			PORTLED ^= music;         // WYTRIGEROWANIE MUZYKI NA PORCIE WYJŒCIOWYM
			_delay_ms(50);
			PORTLED ^= music;

			start_timer();   // W£¥CZENIE TIMERA
			key_lock = 1;
		} else if (key_lock && (PINKEY & KEY))
			key_lock++;

	}
	return 0;
}

void timer_init() {  // INICJALIZACJA TIMERA 0
	TCCR0A |= (1 << WGM01);  //tryb CTC

	OCR0A = 39; //przerwanie co 40ms
	TIMSK0 |= (1 << OCIE0A);

}

void start_timer() { // W£¥CZENIE TIMERA
	TCCR0B |= (1 << CS00) | (1 << CS02);
}

void stop_timer() {  // ZATRZYMANIE TIMERA
	TCCR0B &= (!(1 << CS00)) & (!(1 << CS02));
}

ISR (TIM0_COMPA_vect) {  // OBS£UGA PROCEDURY PRZERWANIA TIMERA 0
	//PORTLED ^=LED1;

	t_counter0++;   // WYZEROWANIE ZMIENNYCH POMOCNICZYCH
	t_counter1++;
	t_counter2++;
// OBS£UGA PIERWSZEGO POJAZDU
	if ((t_counter0 > 0) && (t_counter0 < 9)) { // 9 KROTNE MIGNIECIE JEDN¥ DIOD¥

		PORTLED ^= LED1;
	}
	if ((t_counter0 > 8) && (t_counter0 < 17)) { // 9 KROTNE MIGNIECIE DRUG¥ DIOD¥
		PORTLED ^= LED2;
		if (t_counter0 >= 16) // WYZEROWANIE ZMIENNEJ POMOCNICZEJ
			t_counter0 = 0;
	}
// OBS£UGA DRUGIEGO POJAZDU
	if ((t_counter1 > 2) && (t_counter1 < 11)) { // 9 KROTNE MIGNIECIE JEDN¥ DIOD¥
		PORTLED ^= LED3;
	}
	if ((t_counter1 > 10) && (t_counter1 < 19)) { // 9 KROTNE MIGNIECIE DRUG¥ DIOD¥
		PORTLED ^= LED4;
		if (t_counter1 >= 18) // WYZEROWANIE ZMIENNEJ POMOCNICZEJ
			t_counter1 = 2;
	}
// OBS£UGA TRZECIEGO POJAZDU
	if ((t_counter2 > 4) && (t_counter2 < 13)) {   // 9 KROTNE MIGNIECIE JEDN¥ DIOD¥
		PORTLED ^= LED5;
	}
	if ((t_counter2 > 12) && (t_counter2 < 21)) {  // 9 KROTNE MIGNIECIE DRUG¥ DIOD¥
		PORTLED ^= LED6;
		if (t_counter2 >= 20) { // WYZEROWANIE ZMIENNEJ POMOCNICZEJ
			t_counter2 = 4;
			p_counter++;   // ZWIÊKSZENIE ZMIENNEJ PROGRAMOWEJ
		}
	}
	if (p_counter >= czas_calosci) { //ZAKOÑCZENIE CZASU PROGRAMU
		stop_timer();  // ZATRZYMANIE TIMERA
		p_counter = 0;  // WYZEROWANIE ZMIENNEJ PROGRAMOWEJ
	}
}
