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

uint8_t game_started=0;
uint8_t player1state=0;
uint8_t player2state=0;

int main(void) {

	init();
	_delay_ms(100);

	while(1)
	{



		if(game_started==0)
		{
			if(!(PINSTART&KEYSTART))
			{
				game_started=1;
				for(int i=0;i<20;i++)
				{
					BUZZER_PORT^=BUZZER1;
					_delay_ms(20);
				}
				BUZZER_PORT&=~BUZZER1;
				if (!(PIN_KRANCOWKI & KEY_KRAN_START1))
				{
					if (!(PIN_KRANCOWKI & KEY_KRAN_START2))
					{
						player1state = 1;
						player2state = 1;
					}
				}
			}
		}
		else	//gra rozpoczeta przyciskiem
		{
			if (player1state==0||player2state==0)
			{
				MUSICPORT^=MUSIC1;
				_delay_ms(50);
				MUSICPORT^=MUSIC1;

				if (!(PIN_KRANCOWKI & KEY_KRAN_START1))
				{
					if (!(PIN_KRANCOWKI & KEY_KRAN_START2))
					{
						player1state = 1;
						player2state = 1;
					}
				}

			}
			if(player1state==1) //normalna gra gracza 1
			{
				if(!(PIN_KRANCOWKI&KEY_KRAN_RACZKA1))
				{
					player1state=2;
				}

				if(!(PIN_KRANCOWKI&KEY_KRAN_STOP1))
				{
					player1state=3;
				}

			}
			if (player2state==1)  //normalna gra gracza 1
			{
				if(!(PIN_KRANCOWKI&KEY_KRAN_RACZKA2))
				{
					player2state=2;
				}
				if(!(PIN_KRANCOWKI&KEY_KRAN_STOP2))
				{
					player2state=3;
				}
			}
			if (player1state==2) //zwarcie gracz 1
			{
				BUZZER_PORT|=BUZZER1;
				if(!(PIN_KRANCOWKI&KEY_KRAN_START1))
				{
					player1state=1;
					BUZZER_PORT&=~BUZZER1;
				}
			}
			if (player2state==2) //zwarcie gracz 2
			{
				BUZZER_PORT|=BUZZER2;
				if(!(PIN_KRANCOWKI&KEY_KRAN_START2))
				{
					player2state=1;
					BUZZER_PORT&=~BUZZER2;
				}
			}
			if (player1state==3) //wygrana  gracz 1
			{
				BUZZER_PORT&=~(BUZZER1|BUZZER2);
				for(int i=0;i<10;i++)
				{
					BUZZER_PORT^=BUZZER1;
					_delay_ms(20);
				}
				BUZZER_PORT&=~BUZZER1;
				MUSICPORT^=MUSIC2;
				_delay_ms(50);
				MUSICPORT^=MUSIC2;
				player1state=0;
				player2state=0;
				game_started=0;

			}
			if (player2state==3) //wygrana  gracz 1
			{
				BUZZER_PORT&=~(BUZZER1|BUZZER2);
				for(int i=0;i<10;i++)
				{
					BUZZER_PORT^=BUZZER2;
					_delay_ms(20);
				}
				BUZZER_PORT&=~BUZZER2;
				MUSICPORT^=MUSIC3;
				_delay_ms(50);
				MUSICPORT^=MUSIC3;
				player1state=0;
				player2state=0;
				game_started=0;

			}
		}

	}
	return 0;
}




















ISR (TIMER0_COMPA_vect)
{
//	t_counter ++;
}
