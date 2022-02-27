/****************************************************
 *  embed_queue.c                                         
 *  Created on: 26-Þub-2022 23:40:18                      
 *  Implementation of the Class embed_queue       
 *  Original author: mustafa                     
 ****************************************************/

#include "embed_queue.h"

LinkedList *EQ_Dequeue(LinkedList *LL)
{
	if (LL->front_st == NULL) {
		//printf("Underflow!\n");
	
	}
	else {
		Node_st* newNode_st;
		newNode_st = (Node_st*)malloc(sizeof(Node_st));
	
		newNode_st = LL->front_st;
		LL->front_st = LL->front_st->next_p_st;
	
		free(newNode_st);
	
	}
	return LL;
}

LinkedList *EQ_Enqueue(LinkedList *LL, uint32_t *adrVal)
{
	Node_st* newNode_st;
	newNode_st = (Node_st*)malloc(sizeof(Node_st));
	
	newNode_st->next_p_st = NULL;
	newNode_st->val_p = adrVal;
	
	if (LL->front_st == NULL) {
	
		LL->rear_st = newNode_st;
		LL->front_st = newNode_st;
	
	}
	else {
		LL->rear_st->next_p_st = newNode_st;
		LL->rear_st = newNode_st;
	
	}
	
	return LL;
	
}

Node_st *EQ_Peek(LinkedList *LL)
{
	if (LL->front_st == NULL) {
		//printf("Queue is Empty!\n");
		return NULL;
	}
	else {
		//printf("Peek value: %d\n", front->val);
		return LL->front_st;
	}
}

/**
 * Call to create queue as linked list 
 */
LinkedList *createLL(LinkedList *Queue)
{
	Queue = (LinkedList*)malloc(sizeof(LinkedList));
	
	
	Queue->front_st = NULL;
	Queue->rear_st	= NULL;
	
	return Queue;
} 

