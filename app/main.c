#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#define turnOnLED1() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET)
#define turnOffLED1() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET)

#define turnOnLED2() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET)
#define turnOffLED2() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET)

#define turnOnLED5() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET)
#define turnOffLED5() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET)

#define turnOnLED6() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET)
#define turnOffLED6() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET)

#define pushButton1() HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)

#define offLED120ms() if(delay(120, previousTime)){state = STATE_A;previousTime = currentTime;}
#define onLED120ms() if(delay(120, previousTime)){state = INITIAL;previousTime = currentTime;}

#define offLED100ms() if(delay(100, previousTime)){state = STATE_A;previousTime = currentTime;}

#define offLED500ms() if(delay(500, previousTime)){state = STATE_A;previousTime = currentTime;}
#define onLED500ms() if(delay(500, previousTime)){state = INITIAL;previousTime = currentTime;}

#define offLED200ms() if(delay(200, previousTime)){state = STATE_A;previousTime = currentTime;}
#define onLED200ms() if(delay(200, previousTime)){state = INITIAL;previousTime = currentTime;}

#define yield(x) state = __LINE__;break; case __LINE__:
#define startTask(x) switch(state){yield(x)}

static uint32_t currentTime = 0;
typedef enum{
	INITIAL,
	STATE_A,
	STATE_B,
}STATE;

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

uint32_t getCurrentTime(){
	static uint32_t counter = 0;
	static uint32_t currentTime = 0;
	if(counter++ >= 100){
		counter = 0;
		currentTime++;
	}
	return currentTime;
}

int delay(uint32_t delayCycle, uint32_t previousTime){
	if(((currentTime = getCurrentTime()) - previousTime) < delayCycle){
		return 0;
	}else{
		return 1;
	}
}

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
			offLED100ms();
		}else{
			onLED500ms();
		break;
		}
	}
}

void SD3(){
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
		if(delay(120, previousTime)){
			state = STATE_B;
			previousTime = currentTime;
			i++;
		}
		break;
	case STATE_B:
		turnOffLED5();
		if(i >= 5){
			if(delay(120, previousTime)){
				state = INITIAL;
				previousTime = currentTime;
			}
		}else if(delay(120, previousTime)){
			state = STATE_A;
			previousTime = currentTime;
		}
		break;
	}
}
/*
void SD4(){
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
}*/

int main(void){

	//initLED();
	//initLED2();
	//initLED5();
	//initLED6();
	//initPushButton1();

    while(1)
    {testing();
    	//SD1();
    	//SD2();
    	//SD3();
    	//SD4();

    }
}

void testing(){
	static int state = 1;
	int here = 0;

	/*switch(state){
	case 1:
		here = 1;
		state = 2;
		break;
	case 2:
		here = 2;
		state = 3;
		break;
	case 3:
		here = 3;
		state = 4;
		break;
	}*/

	switch(state){
	case 1:
		here = 1;
		yield();
		here = 2;
		yield();
	}
}

