/*
 * functions.h
 *
 *  Created on: 27 paü 2017
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


//MOTORS
#define MOTOR1 (1<<PC3)

#define music (1<<PD6)
#define KEY (1<<PB0)
#define PORTLED PORTD
#define DDRLED DDRD

#define MOTOR_PORT PORTC
#define MOTOR_DDR DDRC

#define PINKEY PINB
#define PORTKEY PORTB





void init();
void timer_init();
void start_timer();
void stop_timer();

void motor_ON();
void motor_OFF();
void ALL_OFF();


#endif /* FUNCTIONS_H_ */
