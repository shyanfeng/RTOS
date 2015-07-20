#ifndef Mutex_H
#define Mutex_H

void initMutex();
void acquireMutex();
void releaseMutex();

typedef struct {
  //Tcb *owner;
  int counter;
  //LindkedList blockTcb;
} Mutex;

#endif // Mutex_H
