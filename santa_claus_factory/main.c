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

	init();   // INICJALIZACJA
	_delay_ms(100);
while(1)  // PÊTLA G£ÓWNA
{
	if(!(PIN_KRANCOWKI&KPROGRAM)) // SPRAWDZENIE CZY PRZYCISK WCIŒNIÊTY
	{

		//ZAWOR1
		PORT_ME|=ME1|ME2;		// W£¥CZENIE ZAWORU
		_delay_ms(2000);		// OCZEKIWANIE 2S
		PORT_ME&=~(ME1|ME2);	// WY£¥CZENIE ZAWORU


		//TASMA 1
		PORT_MT|=MT1; 			// W£¥CZENIE TAŒMY
		do
		{
		}
		while(!(PIN_KRANCOWKI&K1)); // OCZEKIWANIE NA KRAÑCÓWKÊ
		PORT_MT&=~MT1;			// WY£¥CZENIE TAŒMY

		//ZAWOR2
		PORT_PROG_BAR|=PROG_BAR5|PROG_BAR6; // W£¥CZENIE ZAWORU
		_delay_ms(2000); 					// OCZEKIWANIE 2S
		PORT_PROG_BAR&=~(PROG_BAR5|PROG_BAR6); // WY£¥CZENIE ZAWORU


		//TAŒMA 2
		PORT_MT|=MT2;			// W£¥CZENIE TAŒMY
		do
		{
		}
		while(!(PIN_KRANCOWKI&K2)); // oCZEKIWANIE NA KRAÑCÓWKÊ
		PORT_MT&=~MT2; 			// WY£¥CZENIE TAŒMY

		//PROGRESS BAR1
		PORT_PROG_BAR|=PROG_BAR1; 	// W£¥CZENIE PROGRESS BARA
		_delay_ms(3000);			// OCZEKIWANIE 3S
		PORT_PROG_BAR&=~PROG_BAR1;	// WY£¥CZENIE PROGRES BARA


		//TAŒMA 12
		PORT_MT|=MT12;					// W£ACZENIE TAŒMY
		do
		{
		}
		while(!(PIN_KRANCOWKI&K12));	// OCZEKIWANIE NA KRAÑCÓWKÊ
		PORT_MT&=~MT12;					//WY£ACZENIE TAŒMY

		//ZAWOR3
		PORT_ME|=ME5|ME6; 	// W£¥CZENIE ZAWORU
		_delay_ms(2000);	// OCZEKIWANIE 2S
		PORT_ME&=~(ME5|ME6);// WY£ACZENIE ZAWORU

		// TAŒMA 3
		PORT_MT|=MT3;		// W£¥CZENIE TAŒMY
		do
		{
		}
		while(!(PIN_KRANCOWKI&K3)); // OCZEKIWANIE NA KRAÑCÓWKÊ
		PORT_MT&=~MT3;		// WY£¥CZENIE TAŒMY

		//PROGRESS BAR2
		PORT_PROG_BAR|=PROG_BAR2; 	// W£¥CZENIE PROGRESS BARA
		_delay_ms(3000);			// OCZEKIWANIE 3S
		PORT_PROG_BAR&=~PROG_BAR2;	// WY£¥CZENIE PROGRESS BARA

		// TAŒMA 123
		PORT_MT|=MT123;			// W£¥CZENIE TAŒMY
		do
		{
		}
		while(!(PIN_KRANCOWKI&K123)); // OCZEKIWANIE NA KRAÑCÓWKÊ
		PORT_MT&=~MT123;		// WY£¥CZENIE TAŒMY
		_delay_ms(2000);		// OCZEKIWANIE 2S

/*
		//PROGRESS BAR3
		PORT_PROG_BAR|=PROG_BAR3;	// W£¥CZENIE PROGRESS BARA
		_delay_ms(3000);			// OCZEKIWANIE 3S
		PORT_PROG_BAR&=~PROG_BAR3; 	// WY£¥CZENIE PROGRESS BARA

*/

/*		//TAŒMA PREZENT
		PORT_MT|=MTP; 				// W£¥CZENIE TAŒMY
		do
		{
		}
		while(!(PIN_KRANCOWKI&KP));	// OCZEKIWANIE NA KRAÑCÓWKÊ
		PORT_MT&=~MTP;				// WY£¥CZENIE TAŒMY
*/

	}
}
	return 0;
}

