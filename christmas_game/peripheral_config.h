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

#define PORTSTART PORTB
#define PINSTART PINB
#define KEYSTART (1<<PB0)

#define PORT_KRANCOWKI PORTC
#define PIN_KRANCOWKI PINC
#define KEY_KRAN_START1 (1<<PC5)
#define KEY_KRAN_START2 (1<<PC4)
#define KEY_KRAN_STOP1 (1<<PC3)
#define KEY_KRAN_STOP2 (1<<PC2)
#define KEY_KRAN_RACZKA1 (1<<PC1)
#define KEY_KRAN_RACZKA2 (1<<PC0)




#define MUSICDDR DDRD
#define MUSICPORT PORTD
#define MUSIC1 (1<<PD2)
#define MUSIC2 (1<<PD3)
#define MUSIC3 (1<<PD4)
#define MUSIC4 (1<<PD5)




#define BUZZER_DDR DDRD
#define BUZZER_PORT PORTD
#define BUZZER1 (1<<PD0)
#define BUZZER2 (1<<PD1)


#define KEY (1<<PB0)

#define PINKEY PINB
#define PORTKEY PORTB

#endif /* PERIPHERAL_CONFIG_H_ */
