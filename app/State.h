#ifndef State_H
#define State_H

typedef enum{
	INITIAL,
	ON_LED1,
	OFF_LED1,
	ON_LED2,
	OFF_LED2,
	ON_LED3,
	OFF_LED3,
	BUTTON_STAT,
	COUNTER,
	HALT,
	FINAL
}State;

#endif //State_H
