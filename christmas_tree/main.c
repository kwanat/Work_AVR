/*
 * main.c
 *
 *  Created on: 6 lis 2017
 *      Author: Kamil
 */


#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include "peripheral_config.h"
#include "functions.h"

uint8_t t_counter =0;
uint8_t p_counter = 0;
uint8_t seq_counter=0;
int main(void) {
	uint8_t key_lock=0;
	init();   // INICJALIZACJA PORTÓW I TIMERA
	_delay_ms(20);
	while (1) {       // PÊTLA G£ÓWNA

		_delay_ms(20);


		if (!key_lock && !(PINKEY & KEY)) {    // OCZEKIWANIE NA WCISNIÊCIE PRZYCISKU PRZEZ U¯YTKOWNIKA
			timer_start(); //W£¥CZENIE TIMERA

		} else if (key_lock && (PINKEY & KEY))
			key_lock++;
	}
	return 0;
}

ISR (TIMER0_COMPA_vect) // OBS£UGA PROCEDURY PRZERWANIA TIMERA 0
{
	t_counter ++;  // ZWIÊKSZENIE ZMIENNEJ POMOCNICZEJ
	if(seq_counter<5){ // PIERWSZA CZÊŒC SEKWENCJI
	if (t_counter==1)
	{
		PORTLEVEL5|=LED5_1|LED5_2|LED5_3|LED5_4; //ZAPALENIE 5 POZIOMU
	}
	else if (t_counter==2)
	{
		PORTLEVEL4|=LED4_1|LED4_2|LED4_3|LED4_4;  // ZAPALENIE 4 POZIOMU
	}
	else if (t_counter==3)
		{
		PORTLEVEL3|=LED3_1|LED3_2|LED3_3|LED3_4;  // ZAPALENIE 3 POZIOMU
		}
	else if (t_counter==4)
		{
		PORTLEVEL2|=LED2_1|LED2_2|LED2_3|LED2_4;  // ZAPALENIE 2 POZIOMU
		}
	else if (t_counter==5)
		{
		PORTLEVEL1|=LED1_1|LED1_2; //ZAPALENIE 1 POZIOMU
		}
	else if (t_counter==6)
		{
			PORTSTAR|=STAR;  // ZAPALENIE GWIAZDY
		}
	else if (t_counter==7)
		{
			clear_all();     // ZGASZENIE CA£OŒCI
			seq_counter++;	 // ZWIÊKSZENIE LICZNIKA SEKWENCJI
			t_counter=0; 	// WYZEROWANIE ZMIENNEJ POMOCNICZEJ
			p_counter++;	// ZWIEKSZENIE LICZNIKA PROGRAMOWEGO
		}
	}
	else if(seq_counter<10){  // PRZEJŒCIE DO DRUGIEJ SEKWENCJI

// ZAPALENIE KOLEJNYCH DIÓD W KOLEJNOŒCI SPIRALNEJ
	if (t_counter==8)
		{
			PORTLEVEL5|=LED5_1;
		}

	else if (t_counter==9)
		{
		PORTLEVEL5|=LED5_2;
		}

	else if (t_counter==10)
		{
		PORTLEVEL5|=LED5_3;
		}

	else if (t_counter==11)
		{
		PORTLEVEL5|=LED5_4;
		}

	else if (t_counter==12)
		{
		PORTLEVEL4|=LED4_1;
		}
	else if (t_counter==13)
		{
		PORTLEVEL4|=LED4_2;
		}
	else if (t_counter==14)
		{
		PORTLEVEL4|=LED4_3;
		}
	else if (t_counter==15)
		{
		PORTLEVEL4|=LED4_4;
		}
	else if (t_counter==16)
		{
		PORTLEVEL3|=LED3_1;
		}
	else if (t_counter==17)
		{
		PORTLEVEL3|=LED3_2;
		}
	else if (t_counter==18)
		{
		PORTLEVEL3|=LED3_3;
		}

	else if (t_counter==19)
		{
		PORTLEVEL3|=LED3_4;
		}

	else if (t_counter==20)
		{
		PORTLEVEL2|=LED2_1;
		}

	else if (t_counter==21)
		{
		PORTLEVEL2|=LED2_2;
		}

	else if (t_counter==22)
		{
		PORTLEVEL2|=LED2_3;
		}

	else if (t_counter==23)
		{
		PORTLEVEL2|=LED2_4;
		}

	else if (t_counter==24)
		{
		PORTLEVEL1|=LED1_1;
		}

	else if (t_counter==25)
		{
		PORTLEVEL1|=LED1_2;
		}

	else if (t_counter==26)
		{
		PORTSTAR|=STAR;
		}

	else if (t_counter==27)
		{
	clear_all();  // WY£ACZENIE WSZYSTKICH DIÓD
	t_counter=7;  // POWRÓT DO POCZ¥TKU DRUGIEJ SEKWENCJI
	p_counter++;   // ZWIÊKSZENIE LICZNIKA PROGRAMOWEGO
	seq_counter++; // ZWIEKSZENIE ZMIENNEJ SEKWENCYJNEJ
		}

	}
	else
		seq_counter=0; // WYZEROWANIE ZMIENNEJ SEKWENCYJNEJ


	if (p_counter>=PROGRAM_TIME)
	{
		timer_stop();  // ZATRZYMANIE ZEGARA
		p_counter=0;   // WYZEROWANIE LICZNIKA PROGRAMOWEGO
	}
}
