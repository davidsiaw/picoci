#include <stdio.h>
#include "pico/stdlib.h"

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

	while (true)
	{
		user_input = getchar();
		if (user_input == '1')
		{
			state = 1;
		}
		else if (user_input == '0')
		{
			state = 0;
		}
		printf("usersent %d\n", state);
		gpio_put(LED_PIN, state);
		sleep_ms(1000);
	}
	return 0;
}

