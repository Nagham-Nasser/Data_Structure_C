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

## Doubly Linked List
The doubly linked list is a data structure that consists of a sequence of elements, where each element contains references to the previous and next elements. It supports various operations such as insertion, deletion, and traversal. It supports many operations: 

- Intialize doubly linked list (Create an empty doubly linked list)
- Insert node (an element at any position)
- Delete node (an elementat any position)
- Print the list (to print all elements )
- List Size (to determine the number of elements)
- Free List (to remove all elemnts )
- Search at node (Search at specific data)

# Usage
To compile and run the project, follow these steps:

    1-Install a C compiler (e.g., GCC) on your system if you haven't already(Notepad++,CodeBlocks,eclipse,...).
    2-Download the source code file.
    3-Open a terminal or command prompt and navigate to the project directory.
    4-Compile the source code using the command:  
       - gcc main.c List.c    /* For Doubly linked list */
       - gcc main.c queue.c   /* For Queue */
       -gcc main.c Stack.c    /* For Stack */
    5-Run the compiled executable.
    
# Contributing  
Contributions to this repository are welcome. If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.
