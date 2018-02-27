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
	init();
	_delay_ms(20);
	while(1) //P�TLA G��WNA
	{
		_delay_ms(20);


		if (!key_lock && !(PINKEY & KEY)) { // OCZEKIWANIE NA WCI�NI�CIE PRZYCISKU PRZEZ U�YTKOWNIKA
			static_led_on(); // W��CZENIE STATYCZNYCH DI�D
			lantern_on();    // W��CZENIE LATARNII
			timer_start();   // W��CZENIE TIMERA
		} else if (key_lock && (PINKEY & KEY))
			key_lock++;
	}
	return 0;
}



ISR (TIM0_COMPA_vect) // OBS�UGA PROCEDURY PRZERWANIA TIMERA 0
{
	t_counter++; // ZWI�KSZENIE ZMIENNEJ POMOCNICZEJ
	if(t_counter==1) // PIERWSZY PRZYPADEK
	{
		PORT_LED|=LED1; // ZAPALENIE PIERWSZEJ DIODY
	}
	else if(t_counter==2) // DRUGI PRZYPADEK
	{
		PORT_LED&=~LED1; // ZGASZENIE PIERWSZEJ DIODY
		PORT_LED|=LED2; // ZAPALENIE DRUGIEJ DIODY
	}
	else if(t_counter==3) //TRZECI PRZYPADEK
		{
			PORT_LED&=~LED2; // ZGASZENIE DRUGIEJ DIODY
			PORT_LED|=LED3;  // ZAPALENIE TRZECIEJ DIODY
		}
	else if(t_counter==4) //CZWARTY PRZYPADEK
		{
			PORT_LED&=~LED3; // ZGASZENIE TRZECIEJ DIODY
			PORT_LED|=LED4;  // ZAPALENIE CZWARTEJ DIODY
		}
	else if(t_counter==5) // PI�TY PRZYPADEK
		{
			PORT_LED&=~LED4; //ZGASZENIE CZWARTEJ DIODY
			PORT_LED|=LED3; // ZAPALENIE TRZECIEJ DIODY
		}
	else if(t_counter==6) // SZ�STY PRZYPADEK
		{
			PORT_LED&=~LED3;  // ZGASZENIE TRZECIEJ DIODY
			PORT_LED|=LED2;   // ZAPALENIE DRUGIEJ DIODY
		}
	else if(t_counter==7) // SI�DMY PRZYPADEK
		{
			PORT_LED&=~LED2;  // ZGASZENIE DRUGIEJ DIODY
			PORT_LED|=LED1;   // ZAPALENIE PIERWSZEJ DIODY
		}
	else if(t_counter==8) // �SMY PRZYPADEK
	{
		PORT_LED&=~LED1; // ZGASZENIE PIERWSZEJ DIODY
		t_counter=0;     // WYZEROWANIE ZMIENNEJ POMOCNICZEJ
		p_counter++;	 // ZWI�KSZENIE ILO�CI PRZEBIEG�W

	}
	if (p_counter>=PROGRAM_TIME) // JE�ELI OSI�GNI�TO ZA�O�ON� LICZB� PRZEBIEG�W PROGRAMU
	{
		clear_all(); // WY��CZENIE WSZYSTKICH DI�D
		timer_stop(); // ZATRZYMANIE TIMERA
		p_counter=0; // WYZEROWANIE ZMIENNEJ LICZ�CEJ PRZEBIEGI
	}

}
