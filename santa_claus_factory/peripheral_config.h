/*

 * peripheral_config.h
 *
 *  Created on: 6 lis 2017
 *      Author: Kamil
 *
 *  SILNIKI TASM PD 0-5
 *  SILNIKI ELFOW PC 0-3
 *  WYPROWADZENIA NA ATTINY PA 0-5
 *  KRANCOWKI PB 0-5
 */

#ifndef PERIPHERAL_CONFIG_H_
#define PERIPHERAL_CONFIG_H_




#define PROGRAM_TIME 10
#define SEQUENCE_TIME 20

//SILNIKI TASM
#define DDR_MT DDRD
#define PORT_MT PORTD

#define MT1 (1<<PD0)
#define MT2 (1<<PD1)
#define MT12 (1<<PD2)
#define MT3 (1<<PD6)
#define MT123 (1<<PD4)
#define MTP (1<<PD5)

//SILNIKI ELFOW
#define DDR_ME DDRC
#define PORT_ME PORTC

#define ME1 (1<<PC0)
#define ME2 (1<<PC1)
#define ME3 (1<<PC2)
#define ME4 (1<<PC5)
#define ME5 (1<<PC6)
#define ME6 (1<<PC7)

//KRANCOWKI
#define DDR_KRANCOWKI DDRB
#define PORT_KRANCOWKI PORTB
#define PIN_KRANCOWKI PINB

#define K1 (1<<PB0)
#define K2 (1<<PB1)
#define K12 (1<<PB2)
#define K3 (1<<PB3)
#define K123 (1<<PB4)
#define KP (1<<PB5)


#define DDR_PROGRAM DDRC
#define PORT_PROGRAM PORTC
#define PIN_PROGRAM PINC

#define KPROGRAM (1<<PB7)

//PROGRESS BAR
#define DDR_PROG_BAR DDRA
#define PORT_PROG_BAR PORTA

#define PROG_BAR1 (1<<PA0)
#define PROG_BAR2 (1<<PA1)
#define PROG_BAR3 (1<<PA2)
#define PROG_BAR4 (1<<PA3)
#define PROG_BAR5 (1<<PA4)
#define PROG_BAR6 (1<<PA5)


#endif /* PERIPHERAL_CONFIG_H_ */
