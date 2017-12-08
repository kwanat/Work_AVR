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
	if(!(PIN_KRANCOWKI&KPROGRAM))
	{

		//ZAWOR1
		PORT_ME|=ME1|ME2;
		//_delay_ms(1500);
		//PORT_ME&=~ME1;
		_delay_ms(2000);
		//PORT_ME|=ME2;
		//_delay_ms(1500);
		PORT_ME&=~(ME1|ME2);


		//MOTOR1
		PORT_MT|=MT1;
		do
		{
		}
		while(!(PIN_KRANCOWKI&K1));
		PORT_MT&=~MT1;

		//ZAWOR2
		PORT_PROG_BAR|=PROG_BAR5|PROG_BAR6;
		//_delay_ms(1500);
		//PORT_ME&=~ME3;
		_delay_ms(2000);
		//PORT_ME|=ME4;
		//_delay_ms(1500);
		PORT_PROG_BAR&=~(PROG_BAR5|PROG_BAR6);


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
		//_delay_ms(1000);//delay aby mogla sie wykonac animacja


		//MOTOR12
		PORT_MT|=MT12;
		do
		{
		}
		while(!(PIN_KRANCOWKI&K12));
		PORT_MT&=~MT12;

		//ZAWOR3
		PORT_ME|=ME5|ME6;
		//_delay_ms(1500);
		//PORT_ME&=~ME5;
		_delay_ms(2000);
		//PORT_ME|=ME6;
		//_delay_ms(1500);
		PORT_ME&=~(ME5|ME6);

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
		//_delay_ms(1000);

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

