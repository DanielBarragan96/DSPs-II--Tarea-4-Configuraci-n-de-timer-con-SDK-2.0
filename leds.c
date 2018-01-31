
#include "leds.h"
#include "fsl_gpio.h"
#include "MK64F12.h"

//Global variables with initial values
//indicates when sequence is reversed
static volatile BooleanType g_reverse = FALSE;
//indicates if sequence is stopped
static volatile Status g_leds_status = RUN;
//indicates the current color
static volatile Color g_current_color = RED;

//Finite state machine to store the colors sequence
const Leds_sequence g_fsm_moore[] =
{
		{GREEN, BLUE},//for first color (red)
		{BLUE, RED},//for second color (green)
		{RED, GREEN}//for third color (blue)
};

BooleanType updateLeds()
{
	if (g_reverse)
	{//change the color to the value before
		g_current_color = g_fsm_moore[g_current_color].before;
	}
	else
	{//change the color to the value after
		g_current_color = g_fsm_moore[g_current_color].next;
	}
	changeColor();//update color
	return TRUE;//there was no mistake
}

BooleanType changeColor()
{
	turnLedsOff();
	switch (g_current_color)
		{
		case GREEN:
			{//turn green led on
				GPIO_PinWrite(GPIOB, 21, LED_ON);
				break;
			}
		case RED:
			{//turn red led on
				GPIO_PinWrite(GPIOB, 22, LED_ON);
				break;
			}
		case BLUE:
			{//turn blue led on
				GPIO_PinWrite(GPIOE, 26, LED_ON);
				break;
			}
			default:
			{//reset led color to default and re-call itself
				g_current_color = RED;
				ToogleLedStatus();
			}
		}
	return TRUE;//there was no mistake
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
{//turn all the Kinetis leds off
	GPIO_PinWrite(GPIOB, 21, LED_OFF);
	GPIO_PinWrite(GPIOB, 22, LED_OFF);
	GPIO_PinWrite(GPIOE, 26, LED_OFF);
	return TRUE;//there was no mistake
}
