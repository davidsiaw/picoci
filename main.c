#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
	uint LED_PIN = PICO_DEFAULT_LED_PIN;
	
	stdio_init_all();
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
	
	int state = 0;
	while (true)
	{
		printf("blink\n");
		state = (state + 1) % 2;
		gpio_put(LED_PIN, state);
		sleep_ms(250);
	}
	return 0;
}

