/**
 * Apollo board definitions for Cynthion r0.1 and r0.2.
 *
 * This file is part of Apollo.
 *
 * Copyright (c) 2020-2024 Great Scott Gadgets <info@greatscottgadgets.com>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __APOLLO_BOARD_H__
#define __APOLLO_BOARD_H__

#include <sam.h>
#include <hal/include/hal_gpio.h>
#include <stdbool.h>

#define USB_VID 0x1d50
#define USB_PID 0x615c

//#define BOARD_HAS_SHARED_USB

// Indicate that this board features a configuration flash.
#define _BOARD_HAS_CONFIG_FLASH_
#define _BOARD_HAS_DEBUG_SPI

/**
 * GPIO pins for each of the microcontroller LEDs.
 */
typedef enum {
	LED_A = PIN_PA18, // Blue
	LED_B = PIN_PA19, // Pink
	LED_C = PIN_PA20, // White
	LED_D = PIN_PA21, // Pink
	LED_E = PIN_PA22, // Blue

	LED_COUNT = 5
} led_t;



/**
 * Pin locations for the debug SPI connection.
 * Used when using bitbang mode for the debug SPI.
 */

#if (_BOARD_REVISION_MAJOR_ == 0) && (_BOARD_REVISION_MINOR_ == 1)

enum {
	PIN_SCK      = PIN_PA00,

	PIN_SDI      = PIN_PA12,
	PIN_SDO      = PIN_PA14,

	PIN_FPGA_CS  = PIN_PA01,
	PIN_FLASH_CS = PIN_PA04
};

#else

enum {
	PIN_SCK      = PIN_PA13,

	PIN_SDI      = PIN_PA12,
	PIN_SDO      = PIN_PA14,

	PIN_FPGA_CS  = PIN_PA15,
	PIN_FLASH_CS = PIN_PA04
};


#endif


/**
 * GPIO pin numbers.
 */
enum {
	// Each of the JTAG pins.
	TDO_GPIO = PIN_PA10,
	TDI_GPIO = PIN_PA08,
	TCK_GPIO = PIN_PA09,
	TMS_GPIO = PIN_PA11,

	// Sideband PHY USB override.
	SIDEBAND_PHY_RESET = PIN_PB23
};




#endif
