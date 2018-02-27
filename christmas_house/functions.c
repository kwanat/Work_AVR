/*
 * functions.c
 *
 *  Created on: 10 lis 2017
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
void timer_init()  //INICJALIZACJA TIMERA 0 W TRYB CTC

TCCR0A |= (1 << WGM01);  //tryb CTC
	OCR0A = 200;
	TIMSK0 |= (1 << OCIE0A);
}

void timer_start()  // START TIMERA
{
	TCCR0B |= (1 << CS00)|(1<<CS02); //preskaler 1024bit
}

void timer_stop()   //ZATRZYMANIE TIMERA
{
	TCCR0B &= ~((1 << CS00) |(1 << CS01)| (1 << CS02));
}

void ports_init() // INICJALIZACJA PORTÓW WEJŒCIOWYCH I WYJŒCIOWYCH
{
DDR_STATIC_LED |= STATIC_LED1;
DDR_LED |=LED1|LED2|LED3;
DDR_LANTERN|=LANTERN1|LANTERN2;

PORTKEY |=KEY|KEY1;
}

void clear_all()  // WY£ACZENIE WSZYSTKICH WYJŒC
{
PORT_STATIC_LED&=~STATIC_LED1;
PORT_LED&=~(LED1|LED2|LED3);
PORT_LANTERN&=~(LANTERN1|LANTERN2);
}








void static_led_on()
{
	PORT_STATIC_LED|=STATIC_LED1;
}
void lantern_on()
{
	PORT_LANTERN|=LANTERN1|LANTERN2;
}
