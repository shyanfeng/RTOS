#include "SD2.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "timeDelay.h"

#define turnOnLED2() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET)
#define turnOffLED2() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET)

void SD2(TaskBlock *tb){
	static uint32_t previousTime = 0;
	static STATE state = INITIAL;

	startTask(tb);
		if(pushButton1() == 1){
			if(delay(100, previousTime)){
				if(state == INITIAL){
					state = STATE_A;
					turnOffLED2();
					previousTime = getCurrentTime();
				}else{
					state = INITIAL;
					turnOnLED2();
					previousTime = getCurrentTime();
				}
			}
		}else{
			if(delay(500, previousTime)){
				if(state == INITIAL){
					state = STATE_A;
					turnOffLED2();
					previousTime = getCurrentTime();
				}else{
					state = INITIAL;
					turnOnLED2();
					previousTime = getCurrentTime();
				}
			}
		}
	yield(tb);
	endTask(tb);
}
