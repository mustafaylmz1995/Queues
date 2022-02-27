/****************************************************
 *  embed_queue.h                                         
 *  Created on: 26-Þub-2022 23:40:18                      
 *  Implementation of the Class embed_queue       
 *  Original author: mustafa                     
 ****************************************************/

#if !defined(__EMBED_QUEUE_H__)
#define __EMBED_QUEUE_H__


#ifdef __cplusplus
extern "C" {
#endif

#include "thread.h"

typedef struct Node_st
{
	struct Node_st *next_p_st ;
	uint32_t *val_p ;
}  Node_st;


typedef struct
{
	Node_st *front_st ;
	Node_st *rear_st ;
}  LinkedList;

LinkedList *EQ_Dequeue(LinkedList *LL);
LinkedList *EQ_Enqueue(LinkedList *LL, uint32_t *adrVal);
Node_st *EQ_Peek(LinkedList *LL);
/**
 * Call to create queue as linked list 
 */
LinkedList *createLL(LinkedList *Queue);


#ifdef __cplusplus
}
#endif


#endif /*!defined(__EMBED_QUEUE_H__)*/
