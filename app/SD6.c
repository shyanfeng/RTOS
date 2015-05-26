#include "SD6.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initState.h"

#define turnOnLED6() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET)
#define turnOffLED6() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET)

void SD6(){
	static uint32_t previousTime = 0;
	static STATE state = INITIAL;

	switch(state){
	case INITIAL:
		turnOffLED6();
		offLED500ms();
		break;
	case STATE_A:
		turnOnLED6();
		onLED500ms();
		break;
	}
}