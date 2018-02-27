/*
 * main.c
 *
 *  Created on: 10 lis 2017
 *      Author: Kamil
 */


#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include "peripheral_config.h"
#include "functions.h"

uint8_t t_counter =0;
uint8_t p_counter =0;

int main(void)
{
	uint8_t key_lock=0;
	init(); // inicjalizacja portów i pinów
	_delay_ms(20);
	while(1)
	{
		_delay_ms(20);


		if (!key_lock && !(PINKEY & KEY)) {     // oczekiwanie na wciœniêcie przez u¿ytkownika przycisku startu
			static_led_on(); //w³¹czenie diód statycznych
			lantern_on();  // w³¹czenie latarni
			timer_start(); // rozpoczêcie odliczania na timerze

		} else if (key_lock && (PINKEY & KEY))
			key_lock++;
	}
	return 0;
}


ISR (TIM0_COMPA_vect) // procedua przerwania od timera 0
{
	t_counter++;   // zwiêkszenie zmiennej pomocniczej licz¹ce przep³nienia timera 0
	if(t_counter==1) //PIERWSZY PRZYPADEK
	{
		PORT_LED|=LED1;  // W£¥CZENIE PIERWSZYCH DIÓD W £AÑCUCHU
	}
	else if(t_counter==2) //DRUGI PRZYPADEK
	{
		PORT_LED&=~LED1; // WY£¥CZENIE PIERWSZYCH DIÓD
		PORT_LED|=LED2; // W£¥CZENIE DRUGICH DIÓD
	}
	else if(t_counter==3)  // TRZECI PRZYPADEK
		{
			PORT_LED&=~LED2; // WY£¥CZENIE DRUGICH DIÓD
			PORT_LED|=LED3;  // W£¥CZENIE TRZECICH DIÓD
		}
	else if(t_counter==4)  // CZWARTY PRZYPADEK
	{
		PORT_LED&=~LED3;   // WY£¥CZENIE 3 DIÓD
		t_counter=0;       // WYZEROWANIE ZMIENNNEJ POMOCNICZEJ
		p_counter++;       // ZWIÊKSZENIE ZMIENNEJ LICZNIKA PRZEJŒC PROGRAMU
		//clear_all();
	}
	if (p_counter>=PROGRAM_TIME)
	{
		clear_all();       // WY£¥CZENIE WSZYSTKICH DIÓD
		timer_stop();	   // ZATRZYMANIE TIMERA
		p_counter=0;	   // WYZEROWANIE LICZNIKA PRZEJŒC PROGRAMU
	}

}
