/*

 * peripheral_config.h
 *
 *  Created on: 6 lis 2017
 *      Author: Kamil
 *
 *MOTORS PB 1-2
 *INPUT SIGNAL PB0
 *LEDS PA 0-7
 */

#ifndef PERIPHERAL_CONFIG_H_
#define PERIPHERAL_CONFIG_H_

// MAKRA ZWI¥ZANE Z DIODAMI LED
#define DDR_LED DDRA
#define PORT_LED PORTA

#define LED1 (1<<PA7)
#define LED2 (1<<PA6)
#define LED3 (1<<PA5)
#define LED4 (1<<PA4)
#define LED5 (1<<PA3)
#define LED6 (1<<PA2)
#define LED7 (1<<PA1)
#define LED8 (1<<PA0)


#endif /* PERIPHERAL_CONFIG_H_ */
