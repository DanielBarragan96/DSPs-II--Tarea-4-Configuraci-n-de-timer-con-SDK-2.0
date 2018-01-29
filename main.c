/*
 * Copyright (c) 2017, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    Tarea4-Timer.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "leds.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

void PORTC_IRQHandler()
{
	PORT_ClearPinsInterruptFlags (PORTA, 1<<4);//clear interrupt
	ToogleLedStatus();
}


/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    CLOCK_EnableClock(kCLOCK_PortA);
    CLOCK_EnableClock(kCLOCK_PortB);
    CLOCK_EnableClock(kCLOCK_PortC);
    CLOCK_EnableClock(kCLOCK_PortE);

    // Input pin PORT configuration P-833 SDK
    const port_pin_config_t config =
		{
			kPORT_PullDisable,
			kPORT_FastSlewRate,
			kPORT_PassiveFilterDisable,
			kPORT_OpenDrainDisable,
			kPORT_LowDriveStrength,
			kPORT_MuxAsGpio,
			kPORT_UnlockRegister,
		};
	const port_pin_config_t config_switch =
		{
			kPORT_PullDisable,
			kPORT_FastSlewRate,
			kPORT_PassiveFilterDisable,
			kPORT_OpenDrainDisable,
			kPORT_LowDriveStrength,
			kPORT_MuxAsGpio,
			kPORT_UnlockRegister,
		  };

	// Sets the configuration
	//configure LEDs
    PORT_SetPinConfig(PORTB, 21, &config);
    PORT_SetPinConfig(PORTB, 22, &config);
    PORT_SetPinConfig(PORTE, 26, &config);
    //configure Switches
    PORT_SetPinConfig(PORTA, 4, &config_switch);//SW3
    PORT_SetPinConfig(PORTC, 6, &config_switch);//SW2

    //Output pin configuration
    const gpio_pin_config_t led_config =
		{
			kGPIO_DigitalOutput,//configurar como output
			1,//valor default
		};
    const gpio_pin_config_t switch_config =
		  {
			kGPIO_DigitalInput,//configurar como output
			1,//valor default
		  };
    // Sets the configuration
    GPIO_PinInit(GPIOB, 21, &led_config);
    GPIO_PinInit(GPIOA, 4, &switch_config);

    PORT_SetPinInterruptConfig(PORTA, 4, kPORT_InterruptFallingEdge);
    NVIC_EnableIRQ(PORTA_IRQn);

    /* Enter an infinite loop, just incrementing a counter. */
    while(1)
    {

    }
    return 0 ;
}
