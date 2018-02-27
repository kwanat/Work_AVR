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
	init(); // inicjalizacja port�w i pin�w
	_delay_ms(20);
	while(1)
	{
		_delay_ms(20);


		if (!key_lock && !(PINKEY & KEY)) {     // oczekiwanie na wci�ni�cie przez u�ytkownika przycisku startu
			static_led_on(); //w��czenie di�d statycznych
			lantern_on();  // w��czenie latarni
			timer_start(); // rozpocz�cie odliczania na timerze

		} else if (key_lock && (PINKEY & KEY))
			key_lock++;
	}
	return 0;
}


ISR (TIM0_COMPA_vect) // procedua przerwania od timera 0
{
	t_counter++;   // zwi�kszenie zmiennej pomocniczej licz�ce przep�nienia timera 0
	if(t_counter==1) //PIERWSZY PRZYPADEK
	{
		PORT_LED|=LED1;  // W��CZENIE PIERWSZYCH DI�D W �A�CUCHU
	}
	else if(t_counter==2) //DRUGI PRZYPADEK
	{
		PORT_LED&=~LED1; // WY��CZENIE PIERWSZYCH DI�D
		PORT_LED|=LED2; // W��CZENIE DRUGICH DI�D
	}
	else if(t_counter==3)  // TRZECI PRZYPADEK
		{
			PORT_LED&=~LED2; // WY��CZENIE DRUGICH DI�D
			PORT_LED|=LED3;  // W��CZENIE TRZECICH DI�D
		}
	else if(t_counter==4)  // CZWARTY PRZYPADEK
	{
		PORT_LED&=~LED3;   // WY��CZENIE 3 DI�D
		t_counter=0;       // WYZEROWANIE ZMIENNNEJ POMOCNICZEJ
		p_counter++;       // ZWI�KSZENIE ZMIENNEJ LICZNIKA PRZEJ�C PROGRAMU
		//clear_all();
	}
	if (p_counter>=PROGRAM_TIME)
	{
		clear_all();       // WY��CZENIE WSZYSTKICH DI�D
		timer_stop();	   // ZATRZYMANIE TIMERA
		p_counter=0;	   // WYZEROWANIE LICZNIKA PRZEJ�C PROGRAMU
	}

}
