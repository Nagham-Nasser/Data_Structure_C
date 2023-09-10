#ifndef _LIST_H
#define _LIST_H

/*Section: Includes */
#include "STD_Types.h"

/* Macro Declaration */


/*Section: Macro Function */


/*Section: User Defined Data Type */
typedef uint32 ListEntry;

typedef enum{
	NULL_Ptr     = 1,
	OUT_OF_RANGE = 2,
	SUCCESS      = 3
}Error_State;

typedef enum {
	FALSE = 0,
	TRUE  = 1
}bool_t;

typedef struct myNode{
	ListEntry data;
	struct myNode *ptr_next;
	struct myNode *ptr_prev;
}ListNode_t;

typedef struct{
	ListNode_t *ptr_head;
	ListNode_t *ptr_tail;
	uint32 size;
}List_t;


/*Section: Function Prototype */

Error_State List_init(List_t *myList);
Error_State List_insertNode(List_t *myList,ListEntry val);
Error_State List_deletNode(List_t *myList,ListEntry val);
Error_State List_print(const List_t *myList);
Error_State List_size(const List_t *myList,uint32 *size);
Error_State List_freeList(List_t *myList);
Error_State List_searchNode(const List_t *myList,ListEntry val,ListNode_t **pptr_result);


#endif //_LIST_H