#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "LED.h"
#include "Timer.h"
#include "Button.h"
#include "State.h"

typedef struct	{
	State state;
}TaskBlock;

#define initTaskBlock(x)	((x)->state = 0)
#define yield(x)			state = __LINE__; break; case __LINE__:;
#define beginTask(x)		switch(state)	{ case 0:
#define endTask(x)			}

int main(void)	{
	static int *state_LED1 = INITIAL, *state_LED2 = INITIAL, *state_LED3 = INITIAL;
	configureLED();
	initButton();

    while(1)	{
    	SDLED1(&state_LED1);
    	SDLED2(&state_LED2);
    	SDLED3(&state_LED3);
    	//test();
    }
}

void test()	{
	static int state = 0;
	static int here = 0;

	/*switch(state)	{
	case 1:*/
	beginTask();

	here = 0;
	yield();

	here = 1;
	yield();

	here = 2;
	yield();

	endTask();
}
