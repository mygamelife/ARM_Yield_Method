#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "LED.h"

void configureLED()	{
  GPIO_InitTypeDef GpioInfo ;

  __GPIOG_CLK_ENABLE();
  GpioInfo.Mode = GPIO_MODE_OUTPUT_PP ;
  GpioInfo.Pin = GPIO_PIN_13 | GPIO_PIN_14; // Init PG13 and PG14
  GpioInfo.Pull = GPIO_NOPULL ;
  GpioInfo.Speed = GPIO_SPEED_HIGH ;
  HAL_GPIO_Init(GPIOG,&GpioInfo);  //Init LED1 on PG13 , lED 2 on PG14

  __GPIOB_CLK_ENABLE();
  GpioInfo.Mode = GPIO_MODE_OUTPUT_PP ;
  GpioInfo.Pin = GPIO_PIN_13;
  GpioInfo.Pull = GPIO_NOPULL ;
  GpioInfo.Speed = GPIO_SPEED_HIGH ;
  HAL_GPIO_Init(GPIOB,&GpioInfo); //Init LED3 on PB13

  __GPIOC_CLK_ENABLE();
  GpioInfo.Mode = GPIO_MODE_OUTPUT_PP ;
  GpioInfo.Pin = GPIO_PIN_5;
  GpioInfo.Pull = GPIO_NOPULL ;
  GpioInfo.Speed = GPIO_SPEED_HIGH ;
  HAL_GPIO_Init(GPIOC,&GpioInfo); //Init LED4 on PC5
}
