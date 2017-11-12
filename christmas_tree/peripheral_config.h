/*
 * peripheral_config.h
 *
 *  Created on: 6 lis 2017
 *      Author: Kamil
 */

#ifndef PERIPHERAL_CONFIG_H_
#define PERIPHERAL_CONFIG_H_




#define PROGRAM_TIME 10
#define SEQUENCE_TIME 20



#define DDRSTAR DDRB
#define DDRLEVEL1 DDRC
#define DDRLEVEL2 DDRC
#define DDRLEVEL3 DDRB
#define DDRLEVEL4 DDRD
#define DDRLEVEL5 DDRD


#define PORTSTAR PORTB
#define PORTLEVEL1 PORTC
#define PORTLEVEL2 PORTC
#define PORTLEVEL3 PORTB
#define PORTLEVEL4 PORTD
#define PORTLEVEL5 PORTD

#define STAR (1<<PB6)
#define LED1_1 (1<<PC5)
#define LED1_2 (1<<PC4)

#define LED2_1 (1<<PC0)
#define LED2_2 (1<<PC1)
#define LED2_3 (1<<PC2)
#define LED2_4 (1<<PC3)

#define LED3_1 (1<<PB1)
#define LED3_2 (1<<PB2)
#define LED3_3 (1<<PB3)
#define LED3_4 (1<<PB4)

#define LED4_1 (1<<PD0)
#define LED4_2 (1<<PD1)
#define LED4_3 (1<<PD2)
#define LED4_4 (1<<PD3)

#define LED5_1 (1<<PD4)
#define LED5_2 (1<<PD5)
#define LED5_3 (1<<PD6)
#define LED5_4 (1<<PD7)

#define KEY (1<<PB0)

#define PINKEY PINB
#define PORTKEY PORTB

#endif /* PERIPHERAL_CONFIG_H_ */
