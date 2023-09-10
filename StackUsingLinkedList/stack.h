#ifndef _STACK_H
#define _STACK_H

/*Section: Includes */
#include "STD_Types.h"

/* Macro Declaration */


/*Section: Macro Function */


/*Section: User Defined Data Type */
typedef uint32 StackEntry;

typedef enum{
	NULL_Ptr     = 1,
	OUT_OF_RANGE = 2,
	SUCCESS      = 3
}Error_State;

typedef enum {
	FALSE = 0,
	TRUE  = 1
}bool_t;

typedef struct MyNode {
	StackEntry data;
	MyNode *ptr_next;
}node_t;

typedef struct StackNode{
	StackNode *top;
}Stack_t;

/*Section: Function Prototype */

Error_State Stack_Init(Stack_t *ptr_stack);
Error_State Stack_Push(Stack_t *ptr_stack, StackEntry val);
Error_State Stack_Pop (Stack_t *ptr_stack, StackEntry *val);
Error_State isEmpty   (const Stack_t *ptr_stack, bool_t *pstate);
Error_State isFull    (const Stack_t *ptr_stack, bool_t *pstate);
Error_State PrintStack(const Stack_t *ptr_stack);
Error_State ClearStack(Stack_t *ptr_stack);
Error_State StackSize (const Stack_t *ptr_stack, uint32 *size);



#endif //_STACK_H