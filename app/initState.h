#ifndef INIT_STATE_INFO_H
#define INIT_STATE_INFO_H

#include <stdint.h>

#define pushButton1() HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)

#define initTaskBlock(x) 	((x)->state = INITIAL)
#define yield(x) 			((x)->state = __LINE__); return 1; case __LINE__:
#define startTask(x) 		switch((x)->state){ case INITIAL:
#define endTask(x)   		(x)->state = INITIAL;}

typedef enum{
	INITIAL,
	STATE_A,
	STATE_B,
	PRESS_CHECK
}STATE;

typedef struct {
	uint32_t state;
}TaskBlock;

#endif //INIT_STATE_INFO_H
