#include <iostream>

#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"

void enable_debug()
{
#ifndef NDEBUG
	// workaround for CMSIS-DAP,
	// see: https://github.com/raspberrypi/pico-sdk/issues/1152
	timer_hw->dbgpause = 0;
#endif
}

int main()
{
	enable_debug();
	stdio_init_all();
	constexpr int LED_PIN = 24;
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	while(1)
	{
		gpio_put(LED_PIN, 0);
		sleep_ms(250);
		gpio_put(LED_PIN, 1);
		std::cout << "Hello Word\n";
		sleep_ms(1000);
	}
}