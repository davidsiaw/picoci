#include <stdio.h>
#include <pico/stdlib.h>

#include "state.h"

#define EOI 255

int main()
{
	uint LED_PIN = PICO_DEFAULT_LED_PIN;

	stdio_init_all();

	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	int state = 0;
	int user_input = 0;

	printf("hello\n");
	gpio_put(LED_PIN, 1);

	sleep_ms(1000);
	gpio_put(LED_PIN, 0);

	sleep_ms(1000);
	gpio_put(LED_PIN, 1);

	// spinloop and wait for the user to press
	// the keys 1 or 0. though it responds
	// to just about any key. try it!
	while (true)
	{
		user_input = getchar();
		state = state_from_char(user_input);
		printf("usersent %d\n", state);
		gpio_put(LED_PIN, state);
		sleep_ms(100);
	}
	return 0;
}
