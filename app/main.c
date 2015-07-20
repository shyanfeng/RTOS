#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initGPIO.h"
#include "SD1.h"
#include "SD2.h"
#include "SD5.h"
#include "SD6.h"
#include "initState.h"
#include "Task.h"
#include "main.h"

void testFunc();

void initSysTick(){
	if(SysTick_Config(SystemCoreClock / 1000)){
		while(1);
	}
}

int dummy(int value){
	return value * 3;
}

int main(void){
	//TaskBlock tb_LED1;
	//TaskBlock tb_LED2;
	//TaskBlock tb_LED5;
	//initLED();
	//initLED2();
	//initLED5();
	//initLED6();
	//initPushButton1();
	//initTaskBlock(&tb_LED1);
	//initTaskBlock(&tb_LED2);
	//initTaskBlock(&tb_LED5);

	initSysTick();
	initTcb();
	//taskSwitch();
	//testFunc();

  while(1){
	//RunningLight(&tb_LED1);
	//SD1(&tb_LED1);
    //SD2(&tb_LED2);
    //SD5(&tb_LED5);
    //SD6();
  }
}

