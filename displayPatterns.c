#include <stdio.h>

#include "AB2016.h"
#include "gpio.h"

void GPIO_setValue(const char*, int);
void timer_handler(void);

static int ON = 0;


void timer_handler (void)
{

	if (rx == 'a') {

		if (ON == 0) {
			GPIO_setValue(testled, 1);
			ON = 1;
		} else {
			GPIO_setValue(testled, 0);
			ON = 0;
		}
	}

		else {
			GPIO_setValue(testled, 1);
		}
}
