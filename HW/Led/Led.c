/*
 * Led.c
 *
 *  Created on: 2022. 10. 18.
 *      Author: kccistc
 */
#include "Led.h"

XGpio	GPIO_LED;

void Led_init()
{
	XGpio_Initialize(&GPIO_LED, XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_SetDataDirection(&GPIO_LED, CHANNEL_1, 0x00);
}

void Led_MakeInst(Led *led, int pinnum)
{
	led->pinNum = pinnum;
}

void Led_GetInstance()
{
	Led_MakeInst(&upLed, LED0);
	Led_MakeInst(&downLed, LED1);
	Led_MakeInst(&rightLed, LED2);
	Led_MakeInst(&blinkLed, LED3);
}

void Led_On(Led *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState | (1 << led->pinNum));
}

void Led_Off(Led *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState & ~(1 << led->pinNum));
}

void Led_Toggle(Led *led)
{
	static int toggleState = 0;
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	toggleState = !toggleState;
	if(toggleState)
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState | (1 << led->pinNum));
	else
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState & ~(1 << led->pinNum));
}

void Led_all_On()
{
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0xff);
}

void Led_all_Off()
{
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0x00);
}

//void Led_Toggle()
//{
//	static int ledState = 0;
//	ledState = !ledState;
//	if(ledState)
//		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0xff);
//	else
//		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0x00);
//
//}

void led_RightShift()
{
	static int count = 0;
	static int shiftCount = 0;
	static int ledright = 0;
	printf("Right Shift Count : %d\n", count);
	count++;
	if(count == 3)
	{
		count = 0;
		ledright = (0x80 >> shiftCount);
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledright);
		shiftCount++;
	}
	if(shiftCount == 8)
	{
		shiftCount = 0;
		ledright = 0;
	}
}

void led_LeftShift()
{
	static int count = 0;
	static int shiftCount = 0;
	static int ledleft = 0;
	printf("Left Shift Count : %d\n", count);
	count++;
	if(count == 3)
	{
		count = 0;
		ledleft = (0x01 << shiftCount);
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledleft);
		shiftCount++;
	}
	if(shiftCount == 8)
	{
		shiftCount = 0;
		ledleft = 0;
	}
}

