/*
 * Led.h
 *
 *  Created on: 2022. 10. 18.
 *      Author: kccistc
 */

#ifndef SRC_HW_LED_LED_H_
#define SRC_HW_LED_LED_H_

#include "xgpio.h"
#include "sleep.h"
#include <stdio.h>

#define CHANNEL_1	1
#define INPUT		1
#define OUTPUT		0

#define LED0		0
#define LED1		1
#define LED2		2
#define LED3		3
#define LED4		4
#define LED5		5
#define LED6		6
#define LED7		7

#define LEDOFF			0
#define LEDON			1
#define LEDTOGGLE		2
#define LEDRIGHTSHIFT	3
#define LEDLEFTSHIFT	4

typedef struct _led
{
	int pinNum;
}Led;

Led upLed, downLed, rightLed, blinkLed;

void Led_init();
void Led_MakeInst(Led *led, int pinnum);
void Led_GetInstance();
void Led_all_On();
void Led_all_Off();
void Led_Toggle(Led *led);
//void Led_Toggle();
void led_RightShift();
void led_LeftShift();
void Led_On(Led *led);
void Led_Off(Led *led);

#endif /* SRC_HW_LED_LED_H_ */
