/*
 * main.c
 *
 *  Created on: 6 lis 2017
 *      Author: Kamil Wanat
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



		if(game_started==0) //JE�ELI GRA NIE ZOSTA�A ROZPOCZ�TA TO OCZEKUJEMY NA JEJ ROZPOCZ�CIE
		{
			if(!(PINSTART&KEYSTART))
			{
				game_started=1; //ZAZNACZENIE ROZPOCZ�CIA GRY
				for(int i=0;i<20;i++) // 10 KR�TKICH SYGNA��W BRZ�CZYKIEM 1 OZNAJMIA ROZPOCZ�CIE GRY
				{
					BUZZER_PORT^=BUZZER1;
					_delay_ms(20);
				}
				BUZZER_PORT&=~BUZZER1;
				if (!(PIN_KRANCOWKI & KEY_KRAN_START1))   //OCZEKIWANIE AZ OBYDWAJ GRACZE USTAWI� R�CZKI PRZY KRA�C�WCE STARTOWEJ
				{
					if (!(PIN_KRANCOWKI & KEY_KRAN_START2))
					{
						player1state = 1; // STAN NORMALNEJ GRY
						player2state = 1;
					}
				}
			}
		}
		else	//gra rozpoczeta przyciskiem
		{
			if (player1state==0||player2state==0) // JE�ELI GRACZE NIE PRZENIE�LI R�CZEK W POZYCJE STARTOWE
			{
				MUSICPORT^=MUSIC1; //ODTWARZANIE KOMUNIKATU 1
				_delay_ms(50);
				MUSICPORT^=MUSIC1;

				if (!(PIN_KRANCOWKI & KEY_KRAN_START1))
				{
					if (!(PIN_KRANCOWKI & KEY_KRAN_START2)) // JEZELI OBIE R�CZKI W POZYCJI STARTOWEJ - ROZPOCZ�CIE GRY
					{
						player1state = 1;
						player2state = 1;
					}
				}

			}
			if(player1state==1) //normalna gra gracza 1
			{
				if(!(PIN_KRANCOWKI&KEY_KRAN_RACZKA1)) //ZWARCIE R�CZKI Z DRUTEM - PRZZEJ�CIE DO STANU NUMER 2
				{
					player1state=2;
				}

				if(!(PIN_KRANCOWKI&KEY_KRAN_STOP1)) // JE�ELI ZWARCIE R�CZKI Z KRA�C�WK� STP TO PRZEJ�CIE DO STANU 3
				{
					player1state=3;
				}

			}
			if (player2state==1)  //normalna gra gracza 1
			{
				if(!(PIN_KRANCOWKI&KEY_KRAN_RACZKA2)) //ZWARCIE R�CZKI Z DRUTEM - PRZZEJ�CIE DO STANU NUMER 2
				{
					player2state=2;
				}
				if(!(PIN_KRANCOWKI&KEY_KRAN_STOP2)) // JE�ELI ZWARCIE R�CZKI Z KRA�C�WK� STP TO PRZEJ�CIE DO STANU 3
				{
					player2state=3;
				}
			}
			if (player1state==2) //zwarcie gracz 1
			{
				BUZZER_PORT|=BUZZER1;
				if(!(PIN_KRANCOWKI&KEY_KRAN_START1)) //OCZEKIWANIE NA POWR�T DO POZYCJI START
				{
					player1state=1; // PRZEJ�CIE DO STANU NORMALNEGO
					BUZZER_PORT&=~BUZZER1; //GENEROWANIE CI�G�EGO SYGNA�U Z BUZERA 1
				}
			}
			if (player2state==2) //zwarcie gracz 2
			{
				BUZZER_PORT|=BUZZER2;
				if(!(PIN_KRANCOWKI&KEY_KRAN_START2)) //OCZEKIWANIE NA POWR�T DO POZYCJI START
				{
					player2state=1;  // PRZEJ�CIE DO STANU NORMALNEGO
					BUZZER_PORT&=~BUZZER2; //GENEROWANIE CI�G�EGO SYGNA�U Z BUZERA 2
				}
			}
			if (player1state==3) //wygrana  gracz 1
			{
				BUZZER_PORT&=~(BUZZER1|BUZZER2);
				for(int i=0;i<10;i++) //5 KR�TKICH SYGNA��W BRZ�CZYKIEM 1
				{
					BUZZER_PORT^=BUZZER1;
					_delay_ms(20);
				}
				BUZZER_PORT&=~BUZZER1;
				MUSICPORT^=MUSIC2;  //ODTWORZENIE MUZYKI 2 W MODULE D�WI�KOWYM
				_delay_ms(50);
				MUSICPORT^=MUSIC2;
				player1state=0; //WY��CZENIE GRY
				player2state=0;
				game_started=0;

			}
			if (player2state==3) //wygrana  gracz 1
			{
				BUZZER_PORT&=~(BUZZER1|BUZZER2); //5 KR�TKICH SYGNA��W BRZ�CZYKIEM 1
				for(int i=0;i<10;i++)
				{
					BUZZER_PORT^=BUZZER2;
					_delay_ms(20);
				}
				BUZZER_PORT&=~BUZZER2;
				MUSICPORT^=MUSIC3; //ODTWORZENIE MUZYKI 3 W MODULE D�WI�KOWYM
				_delay_ms(50);
				MUSICPORT^=MUSIC3;
				player1state=0;
				player2state=0;   //WY��CZENIE GRY
				game_started=0;

			}
		}

	}
	return 0;
}
