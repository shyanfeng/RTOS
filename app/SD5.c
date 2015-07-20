#include "SD5.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "timeDelay.h"

#define turnOnLED5() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET)
#define turnOffLED5() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET)

void SD5(TaskBlock *tb){
	static uint32_t previousTime = 0;
	static STATE state = INITIAL;
	static int i = 0;

	switch(tb->state){
	case INITIAL:
	turnOffLED5();
    if(pushButton1() == 1){
			tb->state = STATE_A;
			previousTime = getCurrentTime();
			i = 0;
		}
		break;

	case STATE_A:
		turnOnLED5();
		if(delay(200, previousTime)){
			tb->state = STATE_B;
			previousTime = getCurrentTime();
			i++;
		}
		break;

	case STATE_B:
		turnOffLED5();
		if(i >= 5){
      if(delay(200, previousTime)){
        tb->state = PRESS_CHECK;
        previousTime = getCurrentTime();
      }
		}else if(delay(200, previousTime)){
			tb->state = STATE_A;
			previousTime = getCurrentTime();
		}
		break;

  case PRESS_CHECK:
    if(pushButton1() == 1){
      tb->state = PRESS_CHECK;
    }else
      tb->state = INITIAL;

	}
}
