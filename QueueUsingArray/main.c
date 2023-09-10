#include <stdio.h>
#include "queue.h"


int main(){
	Error_State ret;
	uint32 size;
	QueueEntry val;
	Queue_t q;
	ret = Queue_Init(&q);
	ret = Queue_Enqueue(&q,5);
	ret = Queue_Enqueue(&q,6);
	ret = Queue_Enqueue(&q,7);
	ret = Queue_Enqueue(&q,8);
	ret = Queue_PrintQueue(&q);
	ret = Queue_QueueSize(&q,&size);
	printf("\nSize = %d",size);
	ret = Queue_Dequeue(&q,&val);
	printf("\n Val = %d\n",val);
	ret = Queue_PrintQueue(&q);
	ret = Queue_QueueSize(&q,&size);
	printf("\nSize = %d",size);
	ret = Queue_Dequeue(&q,&val);
	ret = Queue_Dequeue(&q,&val);
	ret = Queue_Dequeue(&q,&val);
	ret = Queue_Dequeue(&q,&val);
	
}