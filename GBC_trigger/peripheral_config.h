/*
 * peripheral_config.h
 *
 *  Created on: 12 lut 2018
 *      Author: Kamil
 */

#ifndef PERIPHERAL_CONFIG_H_
#define PERIPHERAL_CONFIG_H_


// MAKRA DEFINIUJ¥CE PORTY SILNIKÓW
#define DDR1 DDRC
#define DDR2 DDRD

#define PORT1 PORTC
#define PORT2 PORTD

// MAKRA DEFINIUJ¥CE PIN PRZYCISKU
#define KEY (1<<PB0)
#define PINKEY PINB
#define PORTKEY PORTB




#endif /* PERIPHERAL_CONFIG_H_ */
