#include "SD5.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initState.h"

#define turnOnLED5() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET)
#define turnOffLED5() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET)

void SD5(){
	static uint32_t previousTime = 0;
	static STATE state = INITIAL;
	static int i = 0;

	switch(state){
	case INITIAL:
		if(pushButton1() == 1){
			state = STATE_A;
			previousTime = currentTime;
			i = 0;
		}

		break;
	case STATE_A:
		turnOnLED5();
		if(delay(200, previousTime)){
			state = STATE_B;
			previousTime = currentTime;
			i++;
		}
		break;
	case STATE_B:
		turnOffLED5();
		if(i >= 5){
			if(delay(200, previousTime)){
				state = INITIAL;
				previousTime = currentTime;
			}
		}else if(delay(200, previousTime)){
			state = STATE_A;
			previousTime = currentTime;
		}
		break;
	}
}