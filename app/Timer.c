#include "Timer.h"

uint32_t getCurrentTime(){
	static uint32_t counter = 0;
	static uint32_t currentTime = 0;

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

int waitWithoutDelay ( int previousTime, int delayMilliSecond){
	if(getCurrentTime() - previousTime > delayMilliSecond)
		return 1;
	return 0;
}
