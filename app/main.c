#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initGPIO.h"
#include "SD1.h"
#include "SD2.h"
#include "SD5.h"
#include "SD6.h"
#include "initState.h"

int main(void){
	TaskBlock tb;
	initLED();
	initLED2();
	initLED5();
	initLED6();
	initPushButton1();
	initTaskBlock(&tb);

  while(1){
    testing(&tb);
    SD1();
    SD2();
    SD5();
    SD6();
  }
}

void testing(TaskBlock *tb){
	static int here = 0;

	startTask(tb);
		here = 0;
		yield(tb);
		here = 1;
		yield(tb);
		here = 2;
		yield(tb);
		here = 3;
		yield(tb);
	endTask(tb);


}

