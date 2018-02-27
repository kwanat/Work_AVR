/*
 * functions.c
 *
 *  Created on: 6 lis 2017
 *      Author: Kamil
 */



#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include "peripheral_config.h"
#include "functions.h"




void init() // INICJALIZACJA PORT�W, TIMERA ORAZ ODBLOKOWANIE PRZERWA�
{
	timer_init();
	ports_init();
	sei();
}
void timer_init()  // INICJALIZACJA TIMERA 0 W TRYBIE CTC
{

TCCR0A |= (1 << WGM01);  //tryb CTC
	OCR0A = 99;
	TIMSK0 |= (1 << OCIE0A);
}

void timer_start() // W�ACZENIE TIMERA
{
	TCCR0B |= (1 << CS00)|(1<<CS02); //preskaler 1024bit
}

void timer_stop() // ZATRZYMANIE TIMERA
{
	TCCR0B &= ~((1 << CS00) |(1 << CS01)| (1 << CS02));
}
void ports_init() // INICJALIZACJA PORT�W WEJ�CIOWYCH I WYJ�CIOWYCH
{
DDRSTAR |=STAR;
DDRLEVEL1 |=LED1_1|LED1_2;
DDRLEVEL2 |=LED2_1|LED2_2 |LED2_3|LED2_4;
DDRLEVEL3 |=LED3_1|LED3_2 |LED3_3|LED3_4;
DDRLEVEL4 |=LED4_1|LED4_2 |LED4_3|LED4_4;
DDRLEVEL5 |=LED5_1|LED5_2 |LED5_3|LED5_4;

PORTKEY|=KEY;

}


void clear_all()  // WY��CZENIE WSZYSTKICH DI�D
{
	PORTSTAR &= ~STAR;
	PORTLEVEL1 &=~(LED1_1|LED1_2);
	PORTLEVEL2 &=~(LED2_1|LED2_2 |LED2_3|LED2_4);
	PORTLEVEL3 &=~(LED3_1|LED3_2 |LED3_3|LED3_4);
	PORTLEVEL4 &=~(LED4_1|LED4_2 |LED4_3|LED4_4);
	PORTLEVEL5 &=~(LED5_1|LED5_2 |LED5_3|LED5_4);
}


