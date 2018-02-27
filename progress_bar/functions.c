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




void init() // INICJALIZACJA TIMER�W, PORT�W, PRZERWA�
{
	timer_init();
	ports_init();
	sei();
}
void timer_init() // INICJALIZACJA TIMERA
{


}

void timer_start() // W��CZENIE TIMERA
{

}

void timer_stop() // ZATRZYMANIE TIMERA
{

}
void ports_init() // INICJALIZACJA PORT�W
{
	DDR_LED|=LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8;

}


void clear_all()  // WY��CZENIE WSZYSTKICH DI�D
{

	PORT_LED&=~(LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8);
}


