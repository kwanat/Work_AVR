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
void ports_init()
{
	DDR_MT|=MT1|MT2|MT12|MT3|MT123|MTP;
	DDR_ME|=ME1|ME2|ME3|ME4|ME5|ME6;
	DDR_PROG_BAR|=PROG_BAR1|PROG_BAR2|PROG_BAR3|PROG_BAR4|PROG_BAR5|PROG_BAR6;
	PORT_KRANCOWKI|=K1|K2|K12|K3|K123|KP|KPROGRAM;
//	PORT_PROG_BAR|=PROG_BAR1|PROG_BAR2|PROG_BAR3;
}


void clear_all()
{

}


