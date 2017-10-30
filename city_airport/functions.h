/*
 * functions.h
 *
 *  Created on: 27 paü 2017
 *      Author: Kamil
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_


//makra uzytkownika
#define TIME 100
#define PROGRAM_TIME 60

//makra sprzetowe
//LED ANODES
#define LED1A (1<<PC0)
#define LED2A (1<<PC1)
#define LED3A (1<<PC2)
#define LED4A (1<<PC3)
#define LED5A (1<<PC4)
//#define LED6A (1<<PD5)

//LED CATHODES

#define LED1K (1<<PB1)
#define LED2K (1<<PB2)
#define LED3K (1<<PB3)
#define LED4K (1<<PC4)
#define LED5K (1<<PC5)


//MOTORS
//#define MOTOR1 (1<<PC3)

//#define music (1<<PD6)
#define KEY (1<<PD0)

#define PORTLEDA PORTC
#define DDRLEDA DDRC

#define PORTLEDK PORTB
#define DDRLEDK DDRB

//#define MOTOR_PORT PORTC
//#define MOTOR_DDR DDRC

#define PINKEY PIND
#define PORTKEY PORTD





void init();
void timer_init();
void start_timer();
void stop_timer();

void motor_ON();
void motor_OFF();
void ALL_OFF();


#endif /* FUNCTIONS_H_ */
