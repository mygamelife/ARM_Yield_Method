#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "LED.h"
#include "Timer.h"
#include "Button.h"
#include "State.h"
#include "Yield.h"

int main(void)	{
	static int *state_LED1 = INITIAL, *state_LED2 = INITIAL, *state_LED3 = INITIAL;
	TaskBlock tb,tb2,tb3;

	configureLED();
	initButton();
	initTaskBlock(&tb);
	initTaskBlock(&tb2);
	initTaskBlock(&tb3);

    while(1)	{
    	//LED1(&tb);
    	//LED2(&tb2);
    	LED3(&tb3);
    }
}

void LED1(TaskBlock *tb)	{

	startTask(tb);
	while(1)	{
		turnOnLED1();

		while(halfSecHasNotExpired())	{
			yield(tb);
		}

		turnOffLED1();

		while(halfSecHasNotExpired())	{
			yield(tb);
		}
	}
	endTask(x);
}

void LED2(TaskBlock *tb2)	{

	startTask(tb2);
	while(1)	{
		turnOnLED2();

		while(oneHundredMiliSecHasNotExpired())	{
			yield(tb2);
		}

		turnOffLED2();

		while(oneHundredMiliSecHasNotExpired())	{
			yield(tb2);
		}
	}
	endTask(x);
}

void LED3(TaskBlock *tb3)	{
	static int i = 0, count = 0;

	turnOffLED3();

	startTask(tb3);

	while(1)	{
		if(buttonStat())	{

			while(count < 5)	{
				turnOnLED3();

				while(halfSecHasNotExpired())	{
					yield(tb3);
				}

				turnOffLED3();

				while(halfSecHasNotExpired())	{
					yield(tb3);
				}

				count++;
			}
			count = 0;
			while(buttonStat())	{
				yield(tb3);
			}
		}

		yield(tb3);
	}
	endTask(x);
}
