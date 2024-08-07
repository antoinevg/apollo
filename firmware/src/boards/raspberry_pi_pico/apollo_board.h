/**
 * Apollo board definitions for Raspberry Pi Pico
 *
 * Copyright (c) 2020-2024 Great Scott Gadgets <info@greatscottgadgets.com>
 * Copyright (c) 2024 Markus Blechschmidt <marble@computer-in.love>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __APOLLO_BOARD_H__
#define __APOLLO_BOARD_H__

#include <stdbool.h>

#include "boards/pico.h"
#include "bsp/rp2040/board.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/sync.h"


/* pid.codes test VID/PID */
#define USB_VID 0x1209
#define USB_PID 0x0010

#define __NOP() {asm volatile("nop");}


typedef unsigned int gpio_t;


typedef enum gpio_direction{
	GPIO_DIRECTION_IN = GPIO_IN,
	GPIO_DIRECTION_OUT = GPIO_OUT,
} gpio_direction_t;


typedef enum gpio_pull_mode {
	GPIO_PULL_OFF,
	GPIO_PULL_UP,
	GPIO_PULL_DOWN,
} gpio_pull_mode_t;


/**
 * GPIO pins for each of the microcontroller LEDs.
 */
typedef enum {
	LED_A = LED_PIN, // Green

	LED_COUNT = 1,
} led_t;

/**
 * GPIO pin numbers.
 */



enum {
	// // Each of the JTAG pins. SPI0
	TMS_GPIO = 5,
	TDI_GPIO = 3, // MOSI
	TDO_GPIO = 4, // MISO
	TCK_GPIO = 6, // SCK

	// // Connected to orangecrab pins 0 and 1. SERCOM0
	UART_RX = UART_RX_PIN,
	UART_TX = UART_TX_PIN,

	// Connected to orangecrab RSTFPGA_RESET, ecp5 PROGRAMN
	PIN_PROG = 7,
};


static inline void gpio_set_pin_level(const gpio_t gpio_pin, bool level) {
	gpio_put(gpio_pin, level);
}


static inline bool gpio_get_pin_level(const gpio_t gpio_pin) {
	return gpio_get(gpio_pin);
}


static inline void gpio_toggle_pin_level(const gpio_t gpio_pin) {
	gpio_set_pin_level(gpio_pin, !gpio_get_pin_level(gpio_pin));
}


static inline void gpio_set_pin_direction(const gpio_t gpio_pin, const enum gpio_direction direction) {
	gpio_init(gpio_pin);
	gpio_set_dir(gpio_pin, direction);
}


static inline void gpio_set_pin_pull_mode(const gpio_t gpio_pin, const gpio_pull_mode_t pull_mode) {
	switch(pull_mode) {
		case GPIO_PULL_OFF: {
			gpio_disable_pulls(gpio_pin);
		} break;
		case GPIO_PULL_UP: {
			gpio_pull_up(gpio_pin);
		} break;
		case GPIO_PULL_DOWN: {
			gpio_pull_down(gpio_pin);
		} break;
		default: {

		} break;
	}
}


#endif
