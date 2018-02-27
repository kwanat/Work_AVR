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




void init()
{
	timer_init();
	ports_init();
	sei();
}
void timer_init()
{
}

void timer_start()
{
}

void timer_stop()
{
}
void ports_init() // INICJALIZACJA PORTÓW, USTAWIENIE PORTÓW WEJŒCIOWYCH I WYJŒCIOWYCH
{
MUSICDDR|=MUSIC1|MUSIC2|MUSIC3|MUSIC4;
BUZZER_DDR|=BUZZER1|BUZZER2;
PORTSTART|=KEYSTART;
PORT_KRANCOWKI|=KEY_KRAN_START1|KEY_KRAN_START2|KEY_KRAN_STOP1|KEY_KRAN_STOP2|KEY_KRAN_RACZKA1|KEY_KRAN_RACZKA2;
}


void clear_all()
{
}


