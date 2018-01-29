
#include "leds.h"

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
	//TODO Turn leds off

	switch (g_current_color)
		{
			GREEN:
			{

			}
			RED:
			{

			}
			BLUE:
			{

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

	return TRUE;//there was no error
}

Status getLedStatus()
{
	return g_leds_status;//there was no error
}
