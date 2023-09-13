# Data_Structure_In_C
This repository contains implementations of common data structures in the C programming language. The implemented data structures are:  
- Stack (Array-based and Linked list-based)
- Queue (Array-based and Linked list-based)
- Doubly Linked List

## Stack  
The stack is a Last-In-First-Out (LIFO) data structure. The stack can be implemented using arrays or linked lists. It supports many operations:  
- push (to insert an element)
- pop (to remove the topmost element)
- printStack (to print all elements )
- clearStack (to remove all elemnts )
- stackSize (to determine the number of elements)
   
#### Array-based Stack  
The array-based stack implementation uses a fixed-size array to store the elements. It maintains a top pointer to keep track of the topmost element in the stack

#### Linked List-based Stack  
The linked list-based stack implementation uses a dynamically allocated linked list to store the elements. It maintains a top pointer that points to the head of the linked list.
 
 ## Queue  
 The queue is a First-In-First-Out (FIFO) data structure. It supports two main operations: enqueue (to insert an element at the rear) and dequeue (to remove the front element). The queue can be implemented using both arrays and linked lists. It supports many operations:  
 -  Intialize Queue (Create an empty queue )
 -  Enqueue element (Add element at the rear)
 -  Dequeue element (Remove the front element)
 -  Print Queue (to print all elements )
 -  Clear Queue (to remove all elemnts )
 -  Queue Size (to determine the number of elements)

#### Array-based Queue
The array-based queue implementation uses a fixed-size array to store the elements. It maintains front and rear pointers to keep track of the front and rear elements in the queue.

#### Linked List-based Queue  
The linked list-based queue implementation uses a dynamically allocated linked list to store the elements. It maintains front and rear pointers that point to the head and tail of the linked list, respectively.
