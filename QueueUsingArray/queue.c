
/*Section: Includes */
#include"queue.h"
#include<stdio.h>

/*Section: Function Definition */

Error_State Queue_Init(Queue_t *ptr_queue){
	Error_State ret;
	if (NULL == ptr_queue){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		ptr_queue->front = -1;
		ptr_queue->back  = -1;
	}
	return ret;
}
Error_State Queue_Enqueue(Queue_t *ptr_queue, QueueEntry val){
	Error_State ret;
	if (NULL == ptr_queue){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		bool_t state;
		ret = Queue_isFull(ptr_queue,&state);
		if(TRUE == state){
			ret = OUT_OF_RANGE;
			printf("\nQueue is Full");
		}
		else{
			ret = Queue_isEmpty(ptr_queue,&state);
			if (TRUE == state){
				ptr_queue->front = 0;
				ptr_queue->back  = 0;
				ptr_queue->array[ptr_queue->back] = val;
			}
			else{
				ptr_queue->back++;
				ptr_queue->array[ptr_queue->back] = val;
			}
		}
	}
	return ret;
	
}
Error_State Queue_Dequeue (Queue_t *ptr_queue, QueueEntry *val){
	Error_State ret;
	if ((NULL == ptr_queue)||(NULL == val)){}
	else{
		bool_t state;
		ret = Queue_isEmpty(ptr_queue,&state);
		if(TRUE == state){
			ret = OUT_OF_RANGE;
			printf("\nQueue is Empty");
		}
		else{
			ret = SUCCESS;
			if(ptr_queue->back == ptr_queue->front){
				*val = ptr_queue->array[ptr_queue->front];
				ptr_queue->front = -1;
				ptr_queue->back = -1;
			}
			else{
				*val = ptr_queue->array[ptr_queue->front];
				ptr_queue->front++;
			}
		}
		return ret;
	}
}
Error_State Queue_isEmpty   (const Queue_t *ptr_queue, bool_t *pstate){
	Error_State ret;
	if (NULL == ptr_queue){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		if (-1 == ptr_queue->front ){
			*pstate = TRUE;
		}
		else{
			*pstate = FALSE;
		}
	}
	return ret;
}
Error_State Queue_isFull    (const Queue_t *ptr_queue, bool_t *pstate){
	Error_State ret;
	if (NULL == ptr_queue){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		if ((QUEUESIZE - 1) == ptr_queue->back){
			*pstate = TRUE;
		}
		else{
			*pstate = FALSE;
		}
	}
	return ret;
}
Error_State Queue_PrintQueue(const Queue_t *ptr_queue){
	Error_State ret;
	if (NULL == ptr_queue){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		uint32 i;
		bool_t state;
		ret = Queue_isEmpty(ptr_queue,&state);
		if (TRUE == state){
			printf("Stack is Empty");
		}
		else{
			for(i=ptr_queue->front; i<=ptr_queue->back;i++){
				printf("%d\t",ptr_queue->array[i]);
			}
		}
		
	}
	return ret;
}
Error_State Queue_ClearQueue(Queue_t *ptr_queue){
	Error_State ret;
	if (NULL == ptr_queue){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		ptr_queue->front = -1;
		ptr_queue->back  = -1;
	}
	return ret;
}
Error_State Queue_QueueSize (const Queue_t *ptr_queue, uint32 *size){
	Error_State ret;
	if (NULL == ptr_queue){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		uint32 i;
		bool_t state;
		ret = Queue_isEmpty(ptr_queue,&state);
		if (TRUE == state){
			*size = 0;
		}
		else{
			*size = (ptr_queue->back - ptr_queue->front) + 1;
		}
	}

}
