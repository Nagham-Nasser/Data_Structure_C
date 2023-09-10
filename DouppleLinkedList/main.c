#include<stdio.h>
#include"List.h"

#define INSERT    1
#define DELETE    2
#define SEARCH    3
#define LISTSIZE  4
#define PRINTLIST 5 
#define FREELIST  6
#define EXIT      7

int main(){
	uint32 choice;
	List_t L1;
	ListEntry data,search_val;
	Error_State ret;
	ListNode_t **search_Result;
	uint32 size;
	bool_t flag = 0;
	
	printf("1-Insert..\n2-Delete..\n3-Search..\n");
	printf("4-List Size..\n5-Print List..\n6-Free..\n");
	printf("7-Exit..\n");
	printf("\nPLease Enter Your Choice : \n");
	fflush(stdin);
	scanf("%d",&choice);
	ret = List_init(&L1);
	
	do{
		switch (choice){
			case INSERT:
				printf("\nInsert Data : ");
				fflush(stdin);
				scanf ("%d",&data);
				ret = List_insertNode(&L1,data);
				break;
			case DELETE:
				printf("\nInsert Deleted Value : ");
				fflush(stdin);
				scanf ("%d",&data);
				ret = List_deletNode(&L1,data);
				break;
			case SEARCH:
				printf("\nInsert Search Value : ");
				fflush(stdin);
				scanf ("%d",&search_val);
				ret = List_searchNode(&L1,search_val,search_Result);
				printf("\nThe value %d is at %d\n",**search_Result,*search_Result);
				if(NULL == search_Result){printf("Not Found\n");}
				else{printf("Found\n");}
				break;
			case LISTSIZE:
				ret = List_size(&L1,&size);
				printf("\nThe Size of The Linked List = %d\n",size);
				break;
			case PRINTLIST:
				ret = List_print(&L1);
				break;
			case FREELIST:
				ret = List_freeList(&L1);
				break;
			case EXIT:
				flag = 1;
				break;
			default:
				printf("Wrong Choice !!!!!!!\n");
				break;
		}
		if (flag){}
		else {
			printf("********************************************\n");
			printf("1-Insert..\n2-Delete..\n3-Search..\n");
			printf("4-List Size..\n5-Print List..\n6-Free..\n");
			printf("7-Exit..\n");
			printf("\nPLease Enter Your Choice : \n");
			fflush(stdin);
			scanf("%d",&choice);
		}
		
	}while(7 != choice);
	
}
