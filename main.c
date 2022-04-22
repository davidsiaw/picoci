#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
	uint LED_PIN = PICO_DEFAULT_LED_PIN;
	
	stdio_init_all();
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
	
	int state = 0;
	char user_input = 0;

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
		printf("%d\n", state);
		gpio_put(LED_PIN, state);
	}
	return 0;
}

