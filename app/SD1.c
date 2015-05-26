#include "SD1.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "timeDelay.h"
#include "initState.h"

#define turnOnLED1() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET)
#define turnOffLED1() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET)

#define offLED120ms() if(delay(120, previousTime)){state = STATE_A;previousTime = currentTime;}
#define onLED120ms() if(delay(120, previousTime)){state = INITIAL;previousTime = currentTime;}

void SD1(){
	static uint32_t previousTime = 0;
	static STATE state = INITIAL;

	switch(state){
	case INITIAL:
		turnOffLED1();
		offLED120ms();
		break;
	case STATE_A:
		turnOnLED1();
		onLED120ms();
	}

}