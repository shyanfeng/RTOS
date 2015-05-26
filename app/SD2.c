#include "SD2.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initState.h"

#define turnOnLED2() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET)
#define turnOffLED2() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET)

#define offLED100ms() if(delay(100, previousTime)){state = STATE_A;previousTime = currentTime;}
#define onLED100ms() if(delay(100, previousTime)){state = INITIAL;previousTime = currentTime;}
#define offLED500ms() if(delay(500, previousTime)){state = STATE_A;previousTime = currentTime;}
#define onLED500ms() if(delay(500, previousTime)){state = INITIAL;previousTime = currentTime;}

void SD2(){
	static uint32_t previousTime = 0;
	static STATE state = INITIAL;

	switch(state){
	case INITIAL:
		turnOffLED2();
		if(pushButton1() == 1){
			offLED100ms();
		}else{
			offLED500ms();
		}
		break;
	case STATE_A:
		turnOnLED2();
		if(pushButton1() == 1){
			onLED100ms();
		}else{
			onLED500ms();
		break;
		}
	}
}