#ifndef TIME_DELAY_H
#define DELAY_H

#include <stdint.h>

uint32_t getCurrentTime();
int delay(uint32_t delayCycle, uint32_t previousTime);
uint32_t updateTimer();
int timeNotExpired(uint32_t previousTime);

#endif //TIME_DELAY_H
