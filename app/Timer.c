#include "Timer.h"
static uint32_t currentTime = 0;

uint32_t getCurrentTime(){
	static uint32_t counter = 0;

	if(counter++ >= 100){
		counter = 0;
		currentTime++;
	}
	return currentTime;
}

void delay(uint32_t delayCycle){
	static uint32_t previousTime = 0;

	while( (getCurrentTime() - previousTime) < delayCycle);
		previousTime = getCurrentTime();
}

int waitForDelay(int delayMilliSecond)	{
	static int previousTime = 0;

	if((getCurrentTime() - previousTime) > delayMilliSecond)	{
		previousTime = getCurrentTime();
		return 1;
	}
	return 0;
}

int halfSecHasNotExpired()	{
	static int previousTime = 0;

	if((getCurrentTime() - previousTime) > 500)	{
		previousTime = getCurrentTime();
		return 0;
	}
	return 1;
}

int oneHundredMiliSecHasNotExpired()	{
	static int previousTime = 0;

	if((getCurrentTime() - previousTime) > 100)	{
		previousTime = getCurrentTime();
		return 0;
	}
	return 1;
}

int threeHundredSecHasNotExpired()	{
	static int previousTime = 0;

	if((getCurrentTime() - previousTime) > 600)	{
		previousTime = getCurrentTime();
		return 0;
	}
	return 1;
}

