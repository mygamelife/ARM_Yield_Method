#include "LED.h"
#include "Timer.h"
#include "State.h"

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
