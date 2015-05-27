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
    	//SDLED1(&state_LED1);
    	//SDLED2(&state_LED2);
    	SDLED3(&state_LED3);
    	//test();
    }
}

//State Diagram for LED1
void SDLED1(State *state)	{
	static uint32_t previousTime = 0;

	switch (*state)
	{
		case INITIAL:
			turnOffLED1();
			*state = ON_LED1;
			break;

		case ON_LED1:
			if(getCurrentTime() - previousTime > ONE_HUNDRED_TWENTY_MILI_SEC)	{
				previousTime = getCurrentTime();
				turnOnLED1();
				*state = OFF_LED1;
			}
			break;

		case OFF_LED1:
			if(getCurrentTime() - previousTime > ONE_HUNDRED_TWENTY_MILI_SEC)	{
				previousTime = getCurrentTime();
				turnOffLED1();
				*state = FINAL;
			}
			break;

		case FINAL:
			*state = ON_LED1;
			break;

		default:
			break;
	}
}

//State Diagram for LED2
void SDLED2(State *state)	{
	static uint32_t previousTime = 0;
	static uint32_t delayTime = 0;

	switch (*state)
	{
		case INITIAL:
			turnOffLED2();
			*state = BUTTON_STAT;
			break;

		case BUTTON_STAT:
			if(buttonStat())
				delayTime = ONE_HUNDRED_MILI_SEC;
			else
				delayTime = ONE_SEC;

			*state = ON_LED2;
			break;

		case ON_LED2:
			if(getCurrentTime() - previousTime > delayTime)	{
				previousTime = getCurrentTime();
				turnOnLED2();
				*state = OFF_LED2;
			}
			break;

		case OFF_LED2:
			if(getCurrentTime() - previousTime > delayTime)	{
				previousTime = getCurrentTime();
				turnOffLED2();
				*state = FINAL;
			}
			break;

		case FINAL:
			*state = BUTTON_STAT;
			break;

		default:
			break;
	}
}

//State Diagram for LED3
void SDLED3(State *state)	{
	static uint32_t previousTime = 0;
	static uint32_t counter = 0;

	switch (*state)
	{
		case INITIAL:
			turnOffLED3();
			*state = BUTTON_STAT;
			break;

		case BUTTON_STAT:
			if(buttonStat() == 1)	{
				counter = 0;
				*state = ON_LED3;
			}
			else	*state = BUTTON_STAT;

		case ON_LED3:
			if(getCurrentTime() - previousTime > 0)	{
				previousTime = getCurrentTime();
				turnOnLED3();
				*state = OFF_LED3;
			}
			break;

		case OFF_LED3:
			if(getCurrentTime() - previousTime > 0)	{
				previousTime = getCurrentTime();
				turnOffLED3();
				*state = COUNTER;
			}
			break;

		case COUNTER:
			counter++;

			if(counter == 5)
				*state = HALT;
			else *state = BUTTON_STAT;

			break;

		case HALT:

			if(buttonStat())
				*state = HALT;
			else {
				*state = BUTTON_STAT;
			}

			break;

		default:	*state = INITIAL; break;
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
