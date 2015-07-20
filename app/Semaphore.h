#ifndef Semaphore_H
#define Semaphore_H

typedef struct {
  int counter;
  int size; // counting size
  //LinkedList blockTcb;
} Semaphore;

#endif // Semaphore_H
