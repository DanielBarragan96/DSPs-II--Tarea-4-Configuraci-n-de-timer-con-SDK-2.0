/**
 * @brief this module is used to control and configurate the leds in the Kinetis
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "DataTypeDefinitions.h"

#define STATE_MACHINE_SIZE 3

/* This definition is used to manage the colors in sequence */
typedef enum
{
	RED = 0,
	GREEN,
	BLUE
}Color;
/* This definition is used to indicate whether the LEDs are changing or not */
typedef enum
{
	RUN,
	STOP
}Status;

typedef struct
{
	Color next;
	Color before;
	BooleanType g_reverse;
	Status g_leds_status;
}Leds_sequence;


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 This function changes the LEDs to the next color.
 	 \return TRUE if there was no problem
 */
BooleanType updateLeds();
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Update the LED color according to the g_current_color variable.
 	 \return TRUE if there was no problem
 */
BooleanType changeColor();
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Function to change the status of the LEDs from start to stop
 	 \return TRUE if there was no problem
 */
BooleanType ToogleLedStatus();
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 This function returns the status of the LEDs
 	 \return TRUE if there was no problem
 */
Status getLedStatus();

#endif //LEDS_H_
