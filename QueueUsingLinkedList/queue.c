
/*Section: Includes */
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
/*Section: Function Definition */

Error_State Queue_Init(Queue_t *ptr_queue){
	Error_State ret;
	if (NULL == ptr_queue){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		ptr_queue->front = NULL;
		ptr_queue->back  = NULL;
		ptr_queue->size  = 0;
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
		node *pn = (node *)malloc (sizeof(node));
		if(NULL == pn){
			printf("Heap is full\n");
		}
		else{
			pn->data = val;
			pn->ptr_next = NULL;
			bool_t state;
			ret = Queue_isEmpty(ptr_queue,&state);
			if(TRUE == state){
				ptr_queue->front = pn;
				ptr_queue->back  = pn;
			}
			else{
				ptr_queue->back->ptr_next = pn;
				ptr_queue->back  = pn;
				
			}
			ptr_queue->size ++;
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
				*val = ptr_queue->front->data;
				free(ptr_queue->front);
				ptr_queue->front = NULL;
				ptr_queue->back = NULL;
				ptr_queue->size = 0;
			}
			else{
				node *temp = ptr_queue->front->ptr_next;
				ptr_queue->size--;
				*val = ptr_queue->front->data;
				free(ptr_queue->front);
				ptr_queue->front = temp;
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
		if (NULL == ptr_queue->front ){
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
			node *temp = ptr_queue->front;
			while(temp != NULL){
				printf("%d\t",temp->data);
				temp = temp->ptr_next;
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
		node *temp1 = ptr_queue->front;
		node *temp2 = ptr_queue->front;
		while(NULL != temp1){
			temp1 = temp1->ptr_next;
			free(temp2);
			temp2 = temp1;
		}
		ptr_queue->front = NULL;
		ptr_queue->back = NULL;
		ptr_queue->size = 0;
	}
	return ret;
}
Error_State Queue_StackSize (const Queue_t *ptr_queue, uint32 *size){
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
			*size = ptr_queue->size;
		}
	}

}
