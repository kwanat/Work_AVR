/*
 * functions.h
 *
 *  Created on: 23 paü 2017
 *      Author: Kamil
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_


//MAKRA DOTYCZ•CE PASU LED WZD£UØ WYBIEGU
#define LED1 (1<<PD0)
#define LED2 (1<<PD1)
#define LED3 (1<<PD2)
#define LED4 (1<<PD3)
#define LED5 (1<<PD4)
#define LED6 (1<<PD5)

#define PORTLED PORTD
#define DDRLED DDRD

// MAKRA DOTYCZ•CE STATYCZNYCH DIOD LED
#define STATIC_LED (1<<PD7)

//MAKRA DOTYCZ•CE MIGAJ•CYCH DI”D LED
#define DISCO_LED1 (1<<PC0)
#define DISCO_LED2 (1<<PC1)
#define DISCO_LED3 (1<<PC2)

#define PORT_DISCO PORTC
#define DDR_DISCO DDRC

// MAKRA DOTYCZ•CE SILNIK”W
#define MOTOR1 (1<<PC3)

#define MOTOR_PORT PORTC
#define MOTOR_DDR DDRC

// MAKRA DOTYCZ•CE TRIGERA MUZYKI
#define music (1<<PD6)

// MAKRA DOTYCZ•CE PRZYCISKU
#define KEY (1<<PB0)

#define PINKEY PINB
#define PORTKEY PORTB

void init();
void timer_init();
void start_timer();
void stop_timer();
void PWM_init();
void PWM_start();
void PWM_stop();

void static_LED_ON();
void static_LED_OFF();
void disco_LED_OFF();
void motor_ON();
void motor_OFF();
void ALL_OFF();


#endif /* FUNCTIONS_H_ */
