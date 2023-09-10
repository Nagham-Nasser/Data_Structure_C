/*Section: Includes */
#include"List.h"
#include<stdio.h>
#include<stdlib.h>

/*Section: Helper Function Prototypes*/
static Error_State List_isEmpty(const List_t *myList,bool_t *state);

/*Section: Function Definition */

Error_State List_init(List_t *myList){
	Error_State ret = SUCCESS;
	if (NULL == myList){
		ret = NULL_Ptr;
	}
	else{
		myList->ptr_head = NULL;
		myList->ptr_tail = NULL;
		myList->size     = 0;
	}
	return ret;
}

static Error_State List_isEmpty(const List_t *myList,bool_t *state){
	Error_State ret = SUCCESS;
	if ((NULL == myList) && (NULL == state)){
		ret = NULL_Ptr;
	}
	else{
		if (NULL == myList->ptr_head){
			*state = TRUE;
		}
		else{
			*state = FALSE;
		}
	}
	return ret;
}

Error_State List_insertNode(List_t *myList,ListEntry val){
	Error_State ret = SUCCESS;
	if (NULL == myList){
		ret = NULL_Ptr;
	}
	else{
		ListNode_t *pn=(ListNode_t *)malloc(sizeof(ListNode_t));
		if (NULL == pn){
			printf("HEap is Full");
		}
		else{
			bool_t state;
			ret = List_isEmpty(myList,&state);
			pn->data = val;
			pn->ptr_next = NULL;
			pn->ptr_prev = NULL;
			myList->size++;
			if (TRUE == state){
				myList->ptr_head = pn;
				myList->ptr_tail = pn;
			}
			else{
				ListNode_t *temp = myList->ptr_head;
				while((NULL != temp) && (temp->data < val)){
					temp = temp->ptr_next;
				}
				if(temp == myList->ptr_head){	//head
					pn->ptr_next = myList->ptr_head;
					temp->ptr_prev = pn;
					myList->ptr_head = pn;
				}
				else if(NULL == temp){			//tail
					pn->ptr_prev = myList->ptr_tail;
					myList->ptr_tail->ptr_next = pn;
					myList->ptr_tail = pn;
				}
				else{							//Middle
					pn->ptr_next = temp;
					pn->ptr_prev = temp->ptr_prev;
					temp->ptr_prev->ptr_next = pn;
					temp->ptr_prev = pn;
					
				}
			}
		}
	}
	return ret;
}

Error_State List_deletNode(List_t *myList,ListEntry val){
	Error_State ret = SUCCESS;
	if (NULL == myList){
		ret = NULL_Ptr;
	}
	else{
		bool_t state;
		ret =List_isEmpty(myList,&state);
		if(TRUE == state){
			printf("List Is Empty. Cannot Delete..\n");
		}
		else{
			ListNode_t *temp = NULL;
			ret = List_searchNode(myList,val,&temp);
			if(NULL == temp){
				printf("NOT FOUND VALUE...\n");
			}
			else{
				if(myList->ptr_tail == myList->ptr_head){	//only one node
					myList->ptr_head = NULL;
					myList->ptr_tail = NULL;
					myList->size = 0;
				}
				else if(myList->ptr_head == temp){			// at head
					myList->ptr_head = myList->ptr_head->ptr_next;
					free(myList->ptr_head->ptr_prev);
					myList->ptr_head->ptr_prev = NULL;
					myList->size--;
					
				}
				else if(myList->ptr_tail == temp){			//at tail
					myList->ptr_tail = myList->ptr_tail->ptr_prev;
					free(myList->ptr_tail->ptr_next);
					myList->ptr_tail->ptr_next = NULL;
					myList->size--;
				}
				else{										// at middle
					temp->ptr_prev->ptr_next = temp->ptr_next;
					temp->ptr_next->ptr_prev = temp->ptr_prev;
					temp->ptr_next = NULL;
					temp->ptr_prev = NULL;
					free(temp);
					myList->size--;
				}
			}
		}
	}
	return ret;
}

Error_State List_print(const List_t *myList){
	Error_State ret = SUCCESS;
	if (NULL == myList){
		ret = NULL_Ptr;
	}
	else{
		bool_t state;
		ret = List_isEmpty(myList,&state);
		if (TRUE == state){
			printf("List is Empty!!!!!!\n");
		}
		else{
			printf("********Assending*********\n");
			ListNode_t *temp = myList->ptr_head;
			while(NULL != temp){
				printf("%d\t",temp->data);
				temp = temp->ptr_next;
			}
			printf("\n");
			printf("********Desending*********\n");
			temp = myList->ptr_tail;
			while(NULL != temp){
				printf("%d\t",temp->data);
				temp = temp->ptr_prev;
			}
			printf("\n");
		}
	}
	return ret;
}

Error_State List_size(const List_t *myList,uint32 *size){
	Error_State ret = SUCCESS;
	if ((NULL == myList) && (NULL == size)){
		ret = NULL_Ptr;
	}
	else{
		*size = myList->size;
		
	}
	return ret;
}

Error_State List_freeList(List_t *myList){
	Error_State ret = SUCCESS;
	if (NULL == myList){
		ret = NULL_Ptr;
	}
	else{
		bool_t state;
		ret = List_isEmpty(myList,&state);
		if(TRUE == state){
			printf("THe List is Empty. Cannot Free..\n");
		}
		else{
			ListNode_t *current = myList->ptr_head;
			ListNode_t *prev = myList->ptr_head;
			while(NULL != current){
				current = current->ptr_next;
				free(prev);
				prev = current;
			}
			free(prev);
			myList->ptr_tail = NULL;
			myList->ptr_head = NULL;
			myList->size = 0;
		}
	}
	return ret;
}

Error_State List_searchNode(const List_t *myList,ListEntry val,ListNode_t **pptr_result){
	Error_State ret = SUCCESS;
	if (NULL == myList){
		ret = NULL_Ptr;
	}
	else{
		bool_t state;
		ret =List_isEmpty(myList,&state);
		if(TRUE == state){
			printf("List Is Empty. Cannot Search..\n");
		}
		else{
			ListNode_t *temp = myList->ptr_head;
			while((NULL != temp) && (temp->data != val)){
				temp = temp->ptr_next;
			}
			*pptr_result = temp;
		}
	}
	return ret;
}





