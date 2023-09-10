
/*Section: Includes */
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>

/*Section: Function Definition */

Error_State Stack_Init(Stack_t *ptr_stack){
	Error_State ret = NULL_Ptr;
	if(NULL == ptr_stack){
	}
	else{
		ret = SUCCESS;
		ptr_stack->top = NULL;
	}
	return ret;
	
}
Error_State Stack_Push(Stack_t *ptr_stack, StackEntry val){
	Error_State ret = NULL_Ptr;
	if(NULL == ptr_stack){
		
	}
	else{
		ret = SUCCESS;
		Stack_t *pn= (Stack_t *)malloc(sizeof(node_t));
		pn->data = val;
		pn->ptr_next=NULL;
		bool_t state;
		ret = isEmpty   (ptr_stack, &state);
		if (TRUE == state){
			ptr_stack->top = pn;
		}else{
			pn->next = ptr_stack->top;
			ptr_stack->top = pn;
		}
		
	}
	return ret;
	
}
Error_State Stack_Pop (Stack_t *ptr_stack, StackEntry *val){
	Error_State ret = NULL_Ptr;
	if((NULL == ptr_stack) && (NULL == val)){
		
	}
	else{
		bool_t state;
		ret = isEmpty   (ptr_stack, &state);
		if (TRUE == state){
			ptr_stack->top = pn;
		}else{
			*val = ptr_stack->top;
			Stack_t *temp = ptr_stack->top->ptr_next;
			free(ptr_stack->top);
			ptr_stack->top = temp;
		}
	}
	return ret;
	
}
Error_State isEmpty   (const Stack_t *ptr_stack, bool_t *pstate){
	Error_State ret = NULL_Ptr;
	if((NULL == ptr_stack) && (NULL == pstate)){
		
	}
	else{
		ret = SUCCESS;
		if (NULL == ptr_stack->top){
			*pstate = TRUE;
		}
		else{
			*pstate = FALSE;
		}
	}
	return ret;
	
}
Error_State isFull    (const Stack_t *ptr_stack, bool_t *pstate){
	Error_State ret = NULL_Ptr;
	if((NULL == ptr_stack) && (NULL == pstate)){
		
	}
	else{
		
	}
	return ret;
	
}
Error_State PrintStack(const Stack_t *ptr_stack){
	Error_State ret = NULL_Ptr;
	if(NULL == ptr_stack){
		
	}
	else{
		
	}
	return ret;
	
}
Error_State ClearStack(Stack_t *ptr_stack){
	Error_State ret = NULL_Ptr;
	if(NULL == ptr_stack){
		
	}
	else{
		StackNode *temp = ptr_stack->top;
		while(NULL !=temp){
			printf("%d\t",temp->data);
			temp = temp->ptr_next;
		}
	}
	return ret;
	
}
Error_State StackSize (const Stack_t *ptr_stack, uint32 *size){
	Error_State ret = NULL_Ptr;
	if((NULL == ptr_stack) && (NULL == size)){
		
	}
	else{
		
	}
	return ret;
	
}