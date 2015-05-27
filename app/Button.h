#ifndef Button_H
#define Button_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

void initButton();
int buttonStat();

#endif //Button_H
