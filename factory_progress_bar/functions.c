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




void init() //INICJALIZACJA TIMER�W, PORT�W ORAZ PRZERWA�
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
void ports_init() //INICJALIZACJA PORT�W
{
	DDR_MOTOR|=MOTOR1|MOTOR2;
	DDR_LED|=LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8;

}


void clear_all() // WY�ACZENIE WSZYSTKICH DI�D I SILNIK�W
{

	PORT_MOTOR&=~(MOTOR1|MOTOR2);
	PORT_LED&=~(LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8);
}


