#include "timeDelay.h"

static uint32_t currentTime = 0;

uint32_t getCurrentTime(){
	return HAL_GetTick();
}

int delay(uint32_t delayCycle, uint32_t previousTime){
	if((getCurrentTime() - previousTime) < delayCycle){
		return 0;
	}else{
		return 1;
	}
}


int timeNotExpired(uint32_t previousTime){

	if(delay(120, previousTime)){
		return 1;
	}else{
		return 0;
	}
}
