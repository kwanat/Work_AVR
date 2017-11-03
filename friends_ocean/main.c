/*
 * main.c
 *
 *  Created on: 3 lis 2017
 *      Author: Kamil
 */

#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include "peripheral_config.h"
#include "functions.h"

volatile uint8_t pwm1=0;
volatile uint8_t pwm2=0;
volatile uint8_t pwm3=0;
volatile uint8_t pwm4=0;

uint8_t counter=0;

int main(void)
{
	while(1)
	{
		for (uint8_t i=0;i<256;i++)
		{
			pwm1++;
			_delay_ms(10);
		}
		for (uint8_t i=0;i<256;i++)
			{
				pwm2++;
				pwm1--;
				_delay_ms(10);
			}
		for (uint8_t i=0;i<256;i++)
			{
				pwm3++;
				pwm2--;
				_delay_ms(10);
			}
		for (uint8_t i=0;i<256;i++)
					{
						pwm3--;
						pwm4++;
						_delay_ms(10);
					}
	}
	return 0;
}

ISR (TIM0_COMPA_vect)
{
counter++;
if(counter>pwm1) PORTLATARNIA|=LED1; else PORTLATARNIA &=!LED1;
if(counter>pwm2) PORTLATARNIA|=LED2; else PORTLATARNIA &=!LED2;
if(counter>pwm3) PORTLATARNIA|=LED3; else PORTLATARNIA &=!LED3;
if(counter>pwm4) PORTLATARNIA|=LED4; else PORTLATARNIA &=!LED4;
}

