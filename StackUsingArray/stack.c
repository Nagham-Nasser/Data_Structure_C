
/*Section: Includes */
#include"stack.h"
#include<stdio.h>

/*Section: Function Definition */

Error_State Stack_Init(Stack_t *ptr_stack){
	Error_State ret = SUCCESS;
	if (NULL == ptr_stack){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		ptr_stack->top = 0;
	}
	return ret;	
}


Error_State Stack_Push(Stack_t *ptr_stack, StackEntry val){
	Error_State ret = SUCCESS;
	if (NULL == ptr_stack){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		bool_t state;
		ret = isFull(ptr_stack,&state);
		if (TRUE == state){
			printf("Stack is Full\n");
			ret = OUT_OF_RANGE;
		}
		else{
			ptr_stack->array[ptr_stack->top] = val;
			ptr_stack->top++;
		}
	}
	return ret;
}

Error_State Stack_Pop (Stack_t *ptr_stack, StackEntry *val){
	Error_State ret = SUCCESS;
	if ((NULL == ptr_stack) && (NULL == val)){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		bool_t state;
		ret = isEmpty(ptr_stack,&state);
		if (TRUE == state){
			printf("Stack is Empty\n");
			ret = OUT_OF_RANGE;
		}
		else{
			ptr_stack->top--;
			*val = ptr_stack->array[ptr_stack->top];
		}
	}
	return ret;
}

Error_State isEmpty   (const Stack_t *ptr_stack, bool_t *pstate){
	Error_State ret = SUCCESS;
	if ((NULL == ptr_stack) && (NULL == pstate)){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		if (0 == ptr_stack->top){
			*pstate = TRUE;
		}
		else{
			*pstate = FALSE;
		}
	}
	return ret;
	
}

Error_State isFull    (const Stack_t *ptr_stack, bool_t *pstate){
	Error_State ret = SUCCESS;
	if ((NULL == ptr_stack) && (NULL == pstate)){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		if (STACKSIZE == ptr_stack->top){
			*pstate = TRUE;
		}
		else{
			*pstate = FALSE;
		}
	}
	return ret;
}

Error_State PrintStack(const Stack_t *ptr_stack){
	Error_State ret = SUCCESS;
	if (NULL == ptr_stack){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		bool_t state;
		ret = isEmpty(ptr_stack,&state);
		if(TRUE == state){
			printf("Stack is Empty\n");
		}
		else{
			sint32 i;
			for (i = (ptr_stack->top-1); i >= 0; i--){
				printf("%d\t",ptr_stack->array[i]);
			}
			printf("\n");
		}
	}
	return ret;	
}

Error_State ClearStack(Stack_t *ptr_stack){
	Error_State ret = SUCCESS;
	if (NULL == ptr_stack){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		ptr_stack->top = 0;
	}
	return ret;	
}

Error_State StackSize (const Stack_t *ptr_stack, uint32 *size){
	Error_State ret = SUCCESS;
	if ((NULL == ptr_stack) && (NULL == size)){
		ret = NULL_Ptr;
	}
	else{
		ret = SUCCESS;
		*size = ptr_stack->top;
	}
	return ret;	
}

