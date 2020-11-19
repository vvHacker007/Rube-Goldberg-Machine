<h1 align=center >Rube-Goldberg-Machine</h1>
A Rube Goldberg machine, named after American cartoonist Rube Goldberg, is a machine intentionally designed to perform a simple task in an indirect and overly complicated way. In 1931, the Merriam-Webster Dictionary added “Rube Goldberg” as an adjective. It meant “accomplishing by complex means what seemingly could be done simply.” 
 In this project we have written the code for a simple rube Goldberg machine using ADT’s which does the following in order:
- It stores the user’s necessary data’s in a queue and converts them into a stack. 
- The stack is then rearranged in a queue in the reversed order. 
- The reverse ordered queue is then converted into a binary tree while allowing the user to see the contents of the tree in pre-order as well as post-order. 
- Using an in-order traversal of the tree, the binary tree is finally converted to a simple linked list.
- The final part is sorting the contents of the list using a quick sort in ascending order and allowing the user to view its contents parallelly.

## ADT’s used:
### 1)	Queue:
   A Queue is a linear structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO). Queue operations may involve initializing or defining the queue, utilizing it, and then completely erasing it from the memory. 
   Some of the basic functions are listed below:
- enqueue() − add (store) an item to the queue.
-	dequeue() − remove (access) an item from the queue.
-	peek() − Gets the element at the front of the queue without removing it.
-	isfull() − Checks if the queue is full.
-	isempty() − Checks if the queue is empty.
### 2)	Stack:
   Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).
   The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added. 
   Some of its basic functions are listed below:
- push() − Pushing (storing) an element on the stack.
-	pop() − Removing (accessing) an element from the stack.
-	peek() − get the top data element of the stack, without removing it.
-	isFull() − check if stack is full.
-	isEmpty() − check if stack is empty.

### 3)	Binary Tree:
   A binary tree is a hierarchical data structure in which each node has at most two children generally referred as left child and right child. Each node contains three components:
-	Pointer to left subtree
-	Pointer to right subtree
-	Data element
#### Some of the basic functions are:
-	Search − Searches an element in a tree.
-	Insert − Inserts an element in a tree.
-	Pre-order Traversal − Traverses a tree in a pre-order manner.
-	In-order Traversal − Traverses a tree in an in-order manner.
-	Post-order Traversal − Traverses a tree in a post-order manner.

### 4)	Linked List:
   A linked list is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. In its most basic form, each node contains: data, and a reference to the next node in the sequence. This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. 
   Some of the basic functions of Linked List are:
- Insertion − Adds an element at the beginning of the list.
-	Deletion − Deletes an element at the beginning of the list.
-	Display − Displays the complete list.
-	Search − Searches an element using the given key.
-	Delete − Deletes an element using the given key.


## Code Explanation:
-	To begin with, the code accepts any number of entries that the user wishes. It first reads the necessary data that the user has provided which includes the first name (30 characters), last name (30 characters), age and date of birth. 
-	As the data is read, it initially stores the data in a queue.
-	Then it dequeues each element from the queue, to print each item, and requeue them again. 
-	An option to proceed further or exit the program is made.
-	Next, the order of the data is reversed in the queue by dequeuing each element and pushing them onto a stack. 
-	Once all the data is dequeued from the queue and pushed on to the stack, each element of the stack is popped off and re-queued into a queue ADT, reversing their order in the queue. 
-	Each element is then dequeued from the queue and printed for the user to view.
-	Each item is requeued to preserve the queue.
-	An option to proceed further or exit the program is again made.
-	Next, the elements are dequeued from the queue and placed into an unordered binary tree. 
-	The elements are added to the tree ADT in the order they were dequeued, adhering to the binary tree shape property.
-	The contents of the tree in pre-order are printed and the user is asked whether they wish to proceed further.
-	The contents of the tree in post-order is then printed and the user is asked whether they wish to proceed further.
-	The data is moved from the unordered binary tree into a linked list ADT using an in-order traversal of the tree. 
-	The contents of the list are printed once again and the user is asked to press any key to continue the process.
-	The contents of the list are then sorted using a quick sort in ascending order. 
-	The contents of the list are printed again and the user is given an option to exit the program or not.
