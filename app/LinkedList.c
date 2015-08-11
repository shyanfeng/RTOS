#include "LinkedList.h"
#include <malloc.h>
#include <stdio.h>

void createLinkedList(LinkedList *list){
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
}

/************************************************
 *
 *          Add First
 *
 ***********************************************/
void List_addFirst(LinkedList *list, Element *elem){
	
	if(list->head == NULL && list-> tail == NULL){
		list->head = elem;
		list->tail = elem;
	}else{
		elem->next = list->head;
		list->head = elem;
	}
	list->length++;
}

/************************************************
 *
 *          Add Last
 *
 ***********************************************/
void List_addLast(LinkedList *list, Element *elem){
	Element *currentPtr;
  currentPtr = list->head;

	if(list->head == NULL && list-> tail == NULL){
		list->head = elem;
		list->tail = elem;
	}
  
  if(list->head != list->tail){
    currentPtr = currentPtr->next;
    while(currentPtr != list->tail){
      currentPtr = currentPtr->next;
    }
    if(currentPtr == list->tail){
      list->tail = elem;
      currentPtr->next = elem;
    }
  }else if(list->head == list->tail){
		list->head->next = elem;
		list->tail = elem;
	}

	list->length++;
}

/************************************************
 *
 *          Remove First
 *
 ***********************************************/
Element *List_removeFirst(LinkedList *list){

	Element *address;
	address = list->head;
	
	if(list->head == NULL && list-> tail == NULL){
		return NULL;
	}
	
	if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
	}
	else{
		 list->head = list->head->next;
		 list->tail->next = NULL;
	}
	
	list->length--;
	
	return address;
}

/************************************************
 *
 *          Remove Last
 *
 ***********************************************/
Element *List_removeLast(LinkedList *list){

	Element *address, *currentPtr;
	address = list->head;
	currentPtr = list->head;
	
	if(list->head == NULL && list-> tail == NULL){
		return NULL;
	}
	
	if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
	}else{
    while(currentPtr->next != list->tail){
      currentPtr = currentPtr->next;
    }
    if(currentPtr->next == list->tail){
      list->tail = currentPtr;
      list->tail->next = NULL;
    }
	}
	
	list->length--;
	
	return address;
}
