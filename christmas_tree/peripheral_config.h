/*
 * peripheral_config.h
 *
 *  Created on: 6 lis 2017
 *      Author: Kamil
 */

#ifndef PERIPHERAL_CONFIG_H_
#define PERIPHERAL_CONFIG_H_

#define DDRLEVEL1 DDRC
#define DDRLEVEL2 DDRC
#define DDRLEVEL3 DDRB
#define DDRLEVEL4 DDRD
#define DDRLEVEL5 DDRD

#define PORTLEVEL1 PORTC
#define PORTLEVEL2 PORTC
#define PORTLEVEL3 PORTB
#define PORTLEVEL4 PORTD
#define PORTLEVEL5 PORTD

#define LED1 (1<<PC)
#define LED1_2
#define LED1_3

#define LED2_1
#define LED2_2
#define LED2_3
#define LED2_4

#define LED3_1
#define LED3_2
#define LED3_3
#define LED3_4

#define LED4_1
#define LED4_2
#define LED4_3
#define LED4_4

#define LED5_1
#define LED5_2
#define LED5_3
#define LED5_4

#define KEY (1<<PB0)

#define PINKEY PINB
#define PORTKEY PORTB

#endif /* PERIPHERAL_CONFIG_H_ */
