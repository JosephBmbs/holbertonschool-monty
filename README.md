
<h1 align="center">
	    C - Stacks, Queues - LIFO, FIFO$
</h1>

 --------------------------------------------------------------------------------
This repository contains an implementation of a simple stack and queue data structure in C language. The stack follows the Last In First Out (LIFO) principle, while the queue follows the First In First Out (FIFO) principle.

Objectives
Understand the concepts of LIFO and FIFO and how they apply to stacks and queues.
Implement a simple stack and queue data structure in C language.
Stack
A stack is a data structure where items can only be added and removed from the end. This is a LIFO (Last In, First Out) procedure. In this implementation, the stack is represented by a linked list, and it supports two main operations: push and pall.

Push opcode: Pushes an element onto the stack.

Pall opcode: Prints all the values on the stack, starting from the top of the stack. If the stack is empty, it doesn't print anything.

Queue
A queue is a data structure where items can only be added to the end and removed from the beginning. This is a FIFO (First In, First Out) procedure. In this implementation, the queue is represented by a linked list, and it supports two main operations: enqueue and dequeue.

Enqueue opcode: Adds an element to the end of the queue.

Dequeue opcode: Removes the element from the beginning of the queue.

#### Example
* Here is an example of how to use the implemented stack and queue:
```
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_element {
    int value;
    struct stack_element *next;
} stack_element;

stack_element *push(stack_element *stack, int value);
void pall(stack_element *stack);

int main() {
    stack_element *stack = NULL;

    // Implement push opcode
    stack = push(stack, 1);
    stack = push(stack, 2);
    stack = push(stack, 3);

    // Implement pall opcode
    pall(stack);

    // Free the memory used by the stack elements
    while (stack != NULL) {
        stack_element *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}

stack_element *push(stack_element *stack, int value) {
    stack_element *new_element = (stack_element *)malloc(sizeof(stack_element));
    if (new_element == NULL) {
        printf("Error: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_element->value = value;
    new_element->next = stack;
    return new_element;
}

void pall(stack_element *stack) {
    stack_element *current = stack;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}
```

#### This example will output:

3
2
1

As expected, the pall opcode prints all the values on the stack, starting from the top of the stack.