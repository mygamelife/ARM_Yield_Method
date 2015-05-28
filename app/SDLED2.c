#include "LED.h"
#include "Timer.h"
#include "State.h"

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
