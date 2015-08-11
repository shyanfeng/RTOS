#include "initGPIO.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

/********************************
 *    Initialize Push Button    *
 *******************************/
void initPushButton1(){
	GPIO_InitTypeDef	GpioInfo;

	__GPIOA_CLK_ENABLE();

	GpioInfo.Mode = GPIO_MODE_INPUT;
	GpioInfo.Pin = GPIO_PIN_0;
	GpioInfo.Pull = GPIO_NOPULL;
	GpioInfo.Speed = GPIO_SPEED_HIGH;

	// Init LED on PA13
	HAL_GPIO_Init(GPIOA, &GpioInfo);
}

/********************************
 *    Initialize LED 1          *
 *******************************/
void initLED(){
	GPIO_InitTypeDef	GpioInfo;

	__GPIOG_CLK_ENABLE();

	GpioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GpioInfo.Pin = GPIO_PIN_13;
	GpioInfo.Pull = GPIO_NOPULL;
	GpioInfo.Speed = GPIO_SPEED_HIGH;
	GpioInfo.Alternate = GPIO_MODE_AF_PP;

	// Init LED on PG13
	HAL_GPIO_Init(GPIOG, &GpioInfo);

}

/********************************
 *    Initialize LED 2          *
 *******************************/
void initLED2(){
	GPIO_InitTypeDef	GpioInfo;

	__GPIOG_CLK_ENABLE();

	GpioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GpioInfo.Pin = GPIO_PIN_14;
	GpioInfo.Pull = GPIO_NOPULL;
	GpioInfo.Speed = GPIO_SPEED_HIGH;
	GpioInfo.Alternate = GPIO_MODE_AF_PP;

	// Init LED on PG13
	HAL_GPIO_Init(GPIOG, &GpioInfo);

}

/********************************
 *    Initialize LED 5          *
 *******************************/
void initLED5(){
	GPIO_InitTypeDef	GpioInfo;

	__GPIOB_CLK_ENABLE();

	GpioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GpioInfo.Pin = GPIO_PIN_13;
	GpioInfo.Pull = GPIO_NOPULL;
	GpioInfo.Speed = GPIO_SPEED_HIGH;
	GpioInfo.Alternate = GPIO_MODE_AF_PP;

	// Init LED on PB13
	HAL_GPIO_Init(GPIOB, &GpioInfo);

}

/********************************
 *    Initialize LED 6          *
 *******************************/
void initLED6(){
	GPIO_InitTypeDef	GpioInfo;

	__GPIOC_CLK_ENABLE();

	GpioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GpioInfo.Pin = GPIO_PIN_5;
	GpioInfo.Pull = GPIO_NOPULL;
	GpioInfo.Speed = GPIO_SPEED_HIGH;
	GpioInfo.Alternate = GPIO_MODE_AF_PP;

	// Init LED on PC5
	HAL_GPIO_Init(GPIOC, &GpioInfo);

}
