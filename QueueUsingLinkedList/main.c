#include <stdio.h>
#include "queue.h"


int main(){
	Queue_t q;
	Error_State ret;
	QueueEntry val;
	uint32 size;
	ret = Queue_Init(&q);
	ret = Queue_Enqueue(&q,5);
	ret = Queue_Enqueue(&q,6);
	ret = Queue_Enqueue(&q,7);
	ret = Queue_Enqueue(&q,8);
	ret = Queue_Enqueue(&q,9);
	ret = Queue_Enqueue(&q,1);
	ret = Queue_Enqueue(&q,2);
	ret = Queue_Enqueue(&q,3);
	ret = Queue_Dequeue(&q,&val);
	printf("\n val = %d\n",val);
	ret = Queue_PrintQueue(&q);
	ret = Queue_StackSize(&q,&size);
	printf("Size = %d\n",size);
	ret= Queue_ClearQueue(&q);
	ret = Queue_PrintQueue(&q);
	ret = Queue_StackSize(&q,&size);
	printf("Size = %d\n",size);
}