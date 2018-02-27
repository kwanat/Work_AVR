/*
 * peripheral_config.h
 *
 *  Created on: 10 lis 2017
 *      Author: Kamil
 */

#ifndef PERIPHERAL_CONFIG_H_
#define PERIPHERAL_CONFIG_H_

#define PROGRAM_TIME 15 // LICZBA PRZEJSC PROGRAMU


// MAKRA DOTYCZ�CE LATARNI
# define DDR_LANTERN DDRA
# define PORT_LANTERN PORTA

#define LANTERN1 (1<<PA6)
#define LANTERN2 (1<<PA7)

// MAKRA OTYCZ�CE DI�D STATYCZNYCH
# define DDR_STATIC_LED DDRA
# define PORT_STATIC_LED PORTA

#define STATIC_LED1 (1<<PA4)

// MAKRA DOTYCZ�CE DI�D KOLOROWYCH
#define DDR_LED DDRA
#define PORT_LED PORTA

#define LED1 (1<<PA0)
#define LED2 (1<<PA1)
#define LED3 (1<<PA2)
#define LED4 (1<<PA3)

// MAKRA DOTYCZ�CE PRYCISK�W
#define PINKEY PINB
#define PORTKEY PORTB

#define KEY (1<<PB0)
#define KEY1 (1<<PB1)
#endif /* PERIPHERAL_CONFIG_H_ */
