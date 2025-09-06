
#ifndef STACK_H
#define STACK_H

#define MAX_STACK 5

typedef int TYPE_STACK;

typedef struct {
    int top;
    TYPE_STACK elements[MAX_STACK];
}Stack_Arr;


void InitializeStack(Stack_Arr *ptr_stack);

// Push function to add an element to the stack
void Push(Stack_Arr *ptr_stack, TYPE_STACK value);

// Pop function to remove an element from the stack
void Pop(Stack_Arr *ptr_stack);

// PeekStack function to get the top element without removing it
TYPE_STACK PeekStack(Stack_Arr *ptr_stack);

// PrintStack function to show all elements of stack
void PrintStack(Stack_Arr *ptr_stack);

// DeleteStack function to delete all elements from stack
void DeleteStack(Stack_Arr *ptr_stack);

#endif