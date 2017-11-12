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

uint8_t t_counter =0;
uint8_t p_counter = 0;
uint8_t seq_counter=0;
int main(void) {
	uint8_t key_lock=0;
	init();
	_delay_ms(20);
	while (1) {

		_delay_ms(20);


		if (!key_lock && !(PINKEY & KEY)) {
			timer_start();

			key_lock = 1;
			//reakcja na wcisniecie klawisza
		} else if (key_lock && (PINKEY & KEY))
			key_lock++;
	}
	return 0;
}

ISR (TIMER0_COMPA_vect)
{
	t_counter ++;
	if(seq_counter<5){
	if (t_counter==1)
	{
		PORTLEVEL5|=LED5_1|LED5_2|LED5_3|LED5_4;
	}
	else if (t_counter==2)
	{
		PORTLEVEL4|=LED4_1|LED4_2|LED4_3|LED4_4;
	}
	else if (t_counter==3)
		{
		PORTLEVEL3|=LED3_1|LED3_2|LED3_3|LED3_4;
		}
	else if (t_counter==4)
		{
		PORTLEVEL2|=LED2_1|LED2_2|LED2_3|LED2_4;
		}
	else if (t_counter==5)
		{
		PORTLEVEL1|=LED1_1|LED1_2;
		}
	else if (t_counter==6)
		{
			PORTSTAR|=STAR;
		}
	else if (t_counter==7)
		{
			clear_all();
			seq_counter++;
			t_counter=0;
	//		t_counter=0;
			p_counter++;
		}
	}
	else if(seq_counter<10){


	if (t_counter==8)
		{
			PORTLEVEL5|=LED5_1;
		}

	else if (t_counter==9)
		{
		PORTLEVEL5|=LED5_2;
		}

	else if (t_counter==10)
		{
		PORTLEVEL5|=LED5_3;
		}

	else if (t_counter==11)
		{
		PORTLEVEL5|=LED5_4;
		}

	else if (t_counter==12)
		{
		PORTLEVEL4|=LED4_1;
		}
	else if (t_counter==13)
		{
		PORTLEVEL4|=LED4_2;
		}
	else if (t_counter==14)
		{
		PORTLEVEL4|=LED4_3;
		}
	else if (t_counter==15)
		{
		PORTLEVEL4|=LED4_4;
		}
	else if (t_counter==16)
		{
		PORTLEVEL3|=LED3_1;
		}
	else if (t_counter==17)
		{
		PORTLEVEL3|=LED3_2;
		}
	else if (t_counter==18)
		{
		PORTLEVEL3|=LED3_3;
		}

	else if (t_counter==19)
		{
		PORTLEVEL3|=LED3_4;
		}

	else if (t_counter==20)
		{
		PORTLEVEL2|=LED2_1;
		}

	else if (t_counter==21)
		{
		PORTLEVEL2|=LED2_2;
		}

	else if (t_counter==22)
		{
		PORTLEVEL2|=LED2_3;
		}

	else if (t_counter==23)
		{
		PORTLEVEL2|=LED2_4;
		}

	else if (t_counter==24)
		{
		PORTLEVEL1|=LED1_1;
		}

	else if (t_counter==25)
		{
		PORTLEVEL1|=LED1_2;
		}

	else if (t_counter==26)
		{
		PORTSTAR|=STAR;
		}

	else if (t_counter==27)
		{
	//clear_all();
	t_counter=7;
	p_counter++;
	seq_counter++;
		}

	}
	else
		seq_counter=0;


	if (p_counter>=PROGRAM_TIME)
	{
		//timer_stop();
		p_counter=0;
	}
}
