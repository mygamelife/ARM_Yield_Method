#ifndef Button_H
#define Button_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#define buttonPressed() HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);

void initButton();
#endif //Button_H
