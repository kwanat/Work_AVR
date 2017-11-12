/*
 * main.c
 *
 *  Created on: 10 lis 2017
 *      Author: Kamil
 */


#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include "peripheral_config.h"
#include "functions.h"

uint8_t t_counter =0;
uint8_t p_counter =0;

int main(void)
{
	uint8_t key_lock=0;
	init();
	_delay_ms(20);
	while(1)
	{
		_delay_ms(20);


		if (!key_lock && !(PINKEY & KEY)) {
			static_led_on();
			lantern_on();
			timer_start();

			key_lock = 1;
			//reakcja na wcisniecie klawisza
		} else if (key_lock && (PINKEY & KEY))
			key_lock++;
	}
	return 0;
}



ISR (TIM0_COMPA_vect)
{
	t_counter++;
	if(t_counter==1)
	{
		PORT_LED|=LED1;
	}
	else if(t_counter==2)
	{
		PORT_LED&=~LED1;
		PORT_LED|=LED2;
	}
	else if(t_counter==3)
		{
			PORT_LED&=~LED2;
			PORT_LED|=LED3;
		}
	else if(t_counter==4)
		{
			PORT_LED&=~LED3;
			PORT_LED|=LED4;
		}
	else if(t_counter==5)
		{
			PORT_LED&=~LED4;
			PORT_LED|=LED3;
		}
	else if(t_counter==6)
		{
			PORT_LED&=~LED3;
			PORT_LED|=LED2;
		}
	else if(t_counter==7)
		{
			PORT_LED&=~LED2;
			PORT_LED|=LED1;
		}
	else if(t_counter==8)
	{
		PORT_LED&=~LED1;
		t_counter=0;
		p_counter++;
		//clear_all();
	}
	if (p_counter>=PROGRAM_TIME)
	{
		clear_all();
		timer_stop();
		p_counter=0;
	}

}
