#include "RunningLight.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "timeDelay.h"

#define turnOnLED1() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET)
#define turnOffLED1() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET)

#define turnOnLED2() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET)
#define turnOffLED2() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET)

#define turnOnLED5() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET)
#define turnOffLED5() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET)

#define turnOnLED6() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET)
#define turnOffLED6() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET)

void RunningLight (TaskBlock *tb){
	static uint32_t previousTime = 0;
	static STATE state = INITIAL;
	static int i = 0;

	startTask(tb);
		/*if(pushButton1() == 1){
			if(delay(100, previousTime)){
				if(state == INITIAL){
					state = STATE_A;
					turnOffLED2();
					previousTime = updateTimer();
				}else{
					state = INITIAL;
					turnOnLED2();
					previousTime = updateTimer();
				}
			}
		}else{*/
			if(delay(500, previousTime)){
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
		//}
	yield(tb);
	endTask(tb);
}
