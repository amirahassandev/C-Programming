
#ifndef STACK_H
#define STACK_H


typedef int TYPE_STACK;

typedef struct{
    TYPE_STACK element;
    Node *next;
}Node;

typedef struct{
    Node *top;
}Stack;


void InitializeStack(Stack *ptr_stack);

// Push function to add an element to the stack
void Push(Stack *ptr_stack, TYPE_STACK value);

// Pop function to remove an element from the stack
// void Pop(Stack *ptr_stack);

// PeekStack function to get the top element without removing it
TYPE_STACK PeekStack(Stack *ptr_stack);

// PrintStack function to show all elements of stack
// void PrintStack(Stack *ptr_stack);

// DeleteStack function to delete all elements from stack
// void DeleteStack(Stack *ptr_stack);

#endif