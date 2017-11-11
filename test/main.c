/*
 * main.c
 *
 *  Created on: 27 paü 2017
 *      Author: techf
 */
#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>



int main(void) {


DDRB = 0xFF;
while(1){
PORTB ^= (1<<PB1);
_delay_ms(200);

}
return 0;
}
