#include <stdint.h>
#include "Task.h"

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;
Tcb *readyQueue;
Tcb *runningQueue;

CpuContext *cc = (CpuContext *)((uint32_t)(&taskOneStack[1028]) - sizeof(CpuContext));

void taskOne(void){
  return;
}

/***********************************
 *  @brief Initialize all the TCBs
 ***********************************/
void initTcb(){
  mainTcb.name = "main_thread";
  mainTcb.sp = 0x12345678;
  taskOneTcb.name = "thread #1";
  taskOneTcb.sp = (uint32_t)cc;


  cc->R4 = 0xaaaaaaa4;
  cc->R5 = 0xbbbbbbb5;
  cc->R6 = 0xccccccc6;
  cc->R7 = 0xddddddd7;
  cc->R8 = 0xeeeeeee8;
  cc->R9 = 0xabababa9;
  cc->R10 = 0xbcbcbc10;
  cc->R11 = 0xcdcdcd11;
  cc->R1 = 0x11111111;
  cc->R2 = 0x22222222;
  cc->R3 = 0x33333333;
  cc->R12 = 0x12121212;
  cc->LR = 0xFFFFFFFF;
  cc->PC = (uint32_t)taskOne;
  cc->xPSR = 0x01000000;

  runningQueue = &mainTcb;
  readyQueue = &taskOneTcb;
}
