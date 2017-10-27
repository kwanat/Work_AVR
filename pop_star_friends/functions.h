/*
 * functions.h
 *
 *  Created on: 23 pa� 2017
 *      Author: Kamil
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_


//makra uzytkownika
#define il_migniec 8
#define czas_migniecia 40
#define czas_calosci 18

//makra sprzetowe
//LED PAS
#define LED1 (1<<PD0)
#define LED2 (1<<PD1)
#define LED3 (1<<PD2)
#define LED4 (1<<PD3)
#define LED5 (1<<PD4)
#define LED6 (1<<PD5)

//LED STATIC
#define STATIC_LED (1<<PD7)
//DISCO LED
#define DISCO_LED1 (1<<PC0)
#define DISCO_LED2 (1<<PC1)
#define DISCO_LED3 (1<<PC2)

//MOTORS
#define MOTOR1 (1<<PC3)

#define music (1<<PD6)
#define KEY (1<<PB0)
#define PORTLED PORTD
#define DDRLED DDRD
#define PORT_DISCO PORTC
#define DDR_DISCO DDRC
#define MOTOR_PORT PORTC
#define MOTOR_DDR DDRC

#define PINKEY PINB
#define PORTKEY PORTB

uint8_t d1;
uint8_t d2;
uint8_t d3;
uint8_t d4;
uint8_t d5;
uint8_t d6;


//progi PWM
#define prog_0 230
#define prog_1 205
#define prog_2 180
#define prog_3 155
#define prog_4 130
#define prog_5 105
#define prog_6 80
#define prog_7 55
#define prog_8 30
#define prog_9 15



void init();
void timer_init();
void start_timer();
void stop_timer();
void PWM_init();
void PWM_start();
void PWM_stop();

char LED_przelicz_jasnosc(char wartosc);
void static_LED_ON();
void static_LED_OFF();
void disco_LED_OFF();
void motor_ON();
void motor_OFF();
void ALL_OFF();


#endif /* FUNCTIONS_H_ */