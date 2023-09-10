#ifndef _QUEUE_H
#define _QUEUE_H

/*Section: Includes */
#include "STD_Types.h"

/* Macro Declaration */



/*Section: Macro Function */


/*Section: User Defined Data Type */
typedef uint32 QueueEntry;

typedef enum{
	NULL_Ptr     = 1,
	OUT_OF_RANGE = 2,
	SUCCESS      = 3
}Error_State;

typedef enum {
	FALSE = 0,
	TRUE  = 1
}bool_t;
typedef struct MyNode{
	QueueEntry data;
	struct MyNode *ptr_next;
}node;
typedef struct {
	node *front;
	node *back;
	uint32 size;
}Queue_t;


/*Section: Function Prototype */

Error_State Queue_Init(Queue_t *ptr_queue);
Error_State Queue_Enqueue(Queue_t *ptr_queue, QueueEntry val);
Error_State Queue_Dequeue (Queue_t *ptr_queue, QueueEntry *val);
Error_State Queue_isEmpty   (const Queue_t *ptr_queue, bool_t *pstate);
Error_State Queue_isFull    (const Queue_t *ptr_queue, bool_t *pstate);
Error_State Queue_PrintQueue(const Queue_t *ptr_queue);
Error_State Queue_ClearQueue(Queue_t *ptr_queue);
Error_State Queue_StackSize (const Queue_t *ptr_queue, uint32 *size);



#endif //_QUEUE_H