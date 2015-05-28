#include "LED.h"
#include "Timer.h"
#include "State.h"

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
			if(buttonStat())	{
				*state = ON_LED3;
			}
			else	{
				*state = BUTTON_STAT;
			}
			break;

		case ON_LED3:
			if(getCurrentTime() - previousTime > ONE_HUNDRED_MILI_SEC)	{
				previousTime = getCurrentTime();
				turnOnLED3();
				*state = OFF_LED3;
			}
			break;

		case OFF_LED3:
			if(getCurrentTime() - previousTime > ONE_HUNDRED_MILI_SEC)	{
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
			if(buttonStat()) // waiting button to release
				*state = HALT;
			else {
				counter = 0;
				*state = BUTTON_STAT; //check button status again after button is released
			}
			break;

		default:	*state = INITIAL; break;
	}
}
