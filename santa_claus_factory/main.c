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



int main(void) {

	init();
	_delay_ms(100);
while(1)
{
	while(!(PIN_KRANCOWKI&KPROGRAM))
	{
		/*
		//ELF1
		PORT_ME|=ME1;
		_delay_ms(2000);
		PORT_ME&=~ME1;
*/

		//MOTOR1
		PORT_MT|=MT1;
		do
		{
		}
		while(!(PIN_KRANCOWKI&K1));
		PORT_MT&=~MT1;

/*
		//ELF2
		PORT_ME|=ME2;
		_delay_ms(2000);
		PORT_ME&=~ME2;
*/
		//MOTOR2
		PORT_MT|=MT2;
		do
		{
		}
		while(!(PIN_KRANCOWKI&K2));
		PORT_MT&=~MT2;

		//PROGRESS BAR1
		PORT_PROG_BAR|=PROG_BAR1;
		_delay_ms(3000);
		PORT_PROG_BAR&=~PROG_BAR1;
		_delay_ms(1000);//delay aby mogla sie wykonac animacja
/*
		//ELF12
		PORT_ME|=ME12;
		_delay_ms(2000);
		PORT_ME&=~ME12;
*/
		//MOTOR12
		PORT_MT|=MT12;
		do
		{
		}
		while(!(PIN_KRANCOWKI&K12));
		PORT_MT&=~MT12;
/*
		//ELF3
		PORT_ME|=ME3;
		_delay_ms(2000);
		PORT_ME&=~ME3;
*/
		//MOTOR3
		PORT_MT|=MT3;
		do
		{
		}
		while(!(PIN_KRANCOWKI&K3));
		PORT_MT&=~MT3;
//		_delay_ms(2000);

		//PROGRESS BAR2
		PORT_PROG_BAR|=PROG_BAR2;
		_delay_ms(3000);
		PORT_PROG_BAR&=~PROG_BAR2;
		_delay_ms(1000);

		//MOTOR123
		PORT_MT|=MT123;
		do
		{
		}
		while(!(PIN_KRANCOWKI&K123));
		PORT_MT&=~MT123;
		_delay_ms(2000);

/*
		//PROGRESS BAR3
		PORT_PROG_BAR|=PROG_BAR3;
		_delay_ms(20);
		PORT_PROG_BAR&=~PROG_BAR3;
		_delay_ms(4000);
*/

/*		//MOTORP
		PORT_MT|=MTP;
		do
		{
		}
		while(!(PIN_KRANCOWKI&KP));
		PORT_MT&=~MTP;*/

	}
}
	return 0;
}

