#ifndef Mailbox_H
#define Mailbox_H

#include "Semaphore.h"
#include "Mutex.h"

typedef struct {
  int *buffer;
  int size;
  Semaphore slotAvailable;
  Semaphore slotUsed;
  int writeIndex;
  int readIndex;
  Mutex mutexForBuffer;
} Mailbox;

#endif // Mailbox_H
