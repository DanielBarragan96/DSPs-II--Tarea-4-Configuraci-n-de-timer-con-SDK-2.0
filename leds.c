
#include "leds.h"
#include "fsl_gpio.h"
#include "MK64F12.h"

//Global variables with initial values
static volatile BooleanType g_reverse = FALSE;
static volatile Status g_leds_status = RUN;
static volatile Color g_current_color = RED;

const Leds_sequence g_fsm_moore[] =
{
		{GREEN, BLUE},
		{BLUE, RED},
		{RED, GREEN}
};

BooleanType updateLeds()
{
	if (g_reverse)
	{
		g_current_color = g_fsm_moore[g_current_color].before;
	}
	else
	{
		g_current_color = g_fsm_moore[g_current_color].next;
	}
	changeColor();
	return TRUE;
}

BooleanType changeColor()
{
	turnLedsOff();

	switch (g_current_color)
		{
		case GREEN:
			{
				GPIO_PinWrite(GPIOB, 21, LED_ON);
				break;
			}
		case RED:
			{
				GPIO_PinWrite(GPIOB, 22, LED_ON);
				break;
			}
		case BLUE:
			{
				GPIO_PinWrite(GPIOE, 26, LED_ON);
				break;
			}
			default:
			{
				g_current_color = RED;
				ToogleLedStatus();
			}
		}
	return TRUE;
}

BooleanType ToogleLedStatus()
{
	g_leds_status = ( g_leds_status == RUN) ? STOP : RUN;
	//TODO Stop/Start PIT
	return TRUE;//there was no error
}

Status getLedStatus()
{
	return g_leds_status;//there was no error
}

BooleanType turnLedsOff()
{
	GPIO_PinWrite(GPIOB, 21, LED_OFF);
	GPIO_PinWrite(GPIOB, 22, LED_OFF);
	GPIO_PinWrite(GPIOE, 26, LED_OFF);
	return TRUE;
}
