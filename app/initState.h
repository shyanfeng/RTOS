#ifndef INIT_STATE_INFO_H
#define INIT_STATE_INFO_H

#define pushButton1() HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)

#define initTaskBlock(x) 	((x)->state = 0)
#define yield(x) 			((x)->state = __LINE__); return 1; case __LINE__:
#define startTask(x) 		switch((x)->state){ case 0:
#define endTask(x)   		(x)->state = 0;}

typedef enum{
	INITIAL,
	STATE_A,
	STATE_B
}STATE;

typedef struct {
	uint32_t state;
}TaskBlock;

#endif //INIT_STATE_INFO_H