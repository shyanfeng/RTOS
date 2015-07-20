#include "SD1.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "timeDelay.h"

#define turnOnLED1() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET)
#define turnOffLED1() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET)



void SD1(TaskBlock *tb){
	static uint32_t previousTime = 0;
	static STATE state = INITIAL;

	startTask(tb);
	turnOnLED1();
	while(timeNotExpired(previousTime) != 1){
		yield(tb);
	}
	previousTime = getCurrentTime();
	turnOffLED1();
	while(timeNotExpired(previousTime) != 1){
		yield(tb);
	}
	previousTime = getCurrentTime();
	endTask(tb);
}



/*
  	startTask(tb);
	if(delay(120, previousTime)){
		if(state == INITIAL){
			state = STATE_A;
			turnOnLED1();
			previousTime = updateTimer();
		}else{
			state = INITIAL;
			turnOffLED1();
			previousTime = updateTimer();
		}
	}
	yield(tb);
	endTask(tb);
 */
