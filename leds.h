/**
 * @brief this module is used to control and configurate the leds in the Kinetis
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "DataTypeDefinitions.h"

//This enum is used to manage the colors in sequence
typedef enum
{
	RED,
	GREEN,
	BLUE
}Colors;

typedef enum
{
	RUN,
	STOP
}Status;

uint8 initiLeds();

uint8 ToogleLedStatus();

Status getLedStatus();





#endif //LEDS_H_
