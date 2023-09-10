#include <stdio.h>
#include "stack.h"


int main(){
	Stack_t s1;
	Error_State ret;
	StackEntry x;
	uint32 size;
	ret = Stack_Init(&s1);
	ret = Stack_Push(&s1,1);
	ret = Stack_Push(&s1,2);
	ret = Stack_Push(&s1,3);
	ret = StackSize(&s1,&size);
	printf("THe size = %d\n",size);
	ret = Stack_Push(&s1,4);
	ret = ClearStack(&s1);
	ret = PrintStack(&s1);
	ret = Stack_Push(&s1,5);
	ret = Stack_Push(&s1,6);
	ret = PrintStack(&s1);
	ret = Stack_Pop(&s1,&x);
	printf("%d\n",x);
	ret = Stack_Pop(&s1,&x);
	printf("%d\n",x);
	ret = StackSize(&s1,&size);
	printf("THe size = %d\n",size);
	ret = Stack_Pop(&s1,&x);
	printf("%d\n",x);
	ret = Stack_Pop(&s1,&x);
	printf("%d\n",x);
	ret = Stack_Pop(&s1,&x);
	printf("%d\n",x);
	ret = StackSize(&s1,&size);
	printf("THe size = %d\n",size);
	ret = Stack_Pop(&s1,&x);
	printf("%d\n",x);
}