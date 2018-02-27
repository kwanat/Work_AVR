// Created by: KAMIL WANAT
// uC: Atmega 8A
// dostêpne porty: PC4-6, PB3-7
// port przycisku: PB0

#include <avr/io.h>
#include<avr/interrupt.h>
# include <util/delay.h>
#include "functions.h"

// ZMIENNE POMOCNICZE W PROCEDURZE PRZERWANIA ZLICZAJ¥CE KOLEJNE PRZERWANIA
int t_counter0 = 0;
int t_counter1 = 0;
uint8_t p_counter = 0;

// ZMIENNE OKREŒLAJ¥CE WARTOŒC NASYCENIA DIÓD LED POD£¥CZONYCH DO PWM
char pwm1 = 255;
char pwm2 = 255;
char w_gore = 1; // ZMIENNA OKREŒLAJ¥CA KIERUNEK PWM (ROZJAŒNIANIE/ŒCIEMNIANIE)
uint8_t currentpwm = 1;

void PWM1_led(volatile uint16_t *PWMregister, uint8_t pwmnumber); // FUNKCJA POZWALAJ¥CA NA WPISANIE W WYBRANY PWM ODPOWIEDNIEJ WARTOŒCI JASNOŒCI

int main(void) {
	uint8_t key_lock;
	init(); // INICJALIZACJA
	while (1) { // PÊTLA G£ÓWNA

		_delay_ms(20);
		PWM1_led(&OCR1A, 1);
		PWM1_led(&OCR1B, -1);

		if (!key_lock && !(PINKEY & KEY)) { //OCZEKIWANIE NA WCIŒNIÊCIE PRZYCISKU
		PORTLED ^= music; // W£¥CZENIE MUZYKI
			_delay_ms(50);
			PORTLED ^= music;
			static_LED_ON();  // W£¥CZENIE DIÓD STATYCZNYCH
			motor_ON(); // W£¥CZENIE SILNIKÓW
			PWM_start(); // W£¥CZENIE PWM
			start_timer(); // W£¥CZENIE TIMERA

			key_lock = 1;
		} else if (key_lock && (PINKEY & KEY))
			key_lock++;

	}
	return 0;
}

ISR (TIMER0_OVF_vect) {  // OBS£UGA PROCEDURY PRZERWANIA TIMERA 0


	t_counter0++; // INKREMENTACJA ZMIENNYCH POMOCNICZYCH
	t_counter1++;

	// OBS£UGA SEKWENCJI W£¥CZAJ¥CEJ KOLEJNE DIODY NA WYBIEGU SCENY
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
		p_counter++; // ZWIÊKSZENIE PROGRAM COUNTERA
	} else if (p_counter == 60) { // JE¯ELI PROGRAM COUNTER OSI¥GN¥£ LIMIT
		PWM_stop(); // ZATRZYMANIE PWM
		stop_timer(); // ZATRZYMANIE TIMERA 0
		ALL_OFF(); // WY£ACZENIE SILNIKÓW I DIÓD
		p_counter = 0; // WYZEROWANIE PROGRAM COUNTERA
	}

	// OBS£UGA SEKWENCJI DIÓD NAD SCEN¥
	if (t_counter1 == 1) {

		PORT_DISCO &= ~DISCO_LED2;
		PORT_DISCO &= ~DISCO_LED3;
		PORT_DISCO |= DISCO_LED1;
	} else if (t_counter1 == 200) {
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

	}
}

void PWM1_led(volatile uint16_t *PWMregister, uint8_t pwmnumber) {
	if (currentpwm == pwmnumber) {
		if (w_gore) {

//rozjaœnianie LED

			if (pwm1 > 5) {
				pwm1 -= 5;
			} else {
//osi¹gniêto górn¹ granicê
				pwm1 = 0;
				w_gore = 0;  // zmieñ kierunek

			}

		} else {

//œciemnianie LED

			if (pwm1 < 250) {
				pwm1 += 5;

			} else {
//osi¹gniêto doln¹ granicê
				pwm1 = 255;
				w_gore = 1;  // zmieñ kierunek
				currentpwm *= -1;
			}
		}

		*PWMregister = pwm1;
	}
}

