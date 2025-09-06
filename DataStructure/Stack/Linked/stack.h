
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int TYPE_STACK;

typedef struct Node_Stack{
    TYPE_STACK element;
    struct Node_Stack *next;
}Node_Stack;

typedef struct{
    Node_Stack *top;
}Stack_Linked;


void InitializeStack(Stack_Linked *ptr_stack);

// Push function to add an element to the stack
void Push(Stack_Linked *ptr_stack, TYPE_STACK value);

// PrintStack function to show all elements of stack
void PrintStack(Stack_Linked *ptr_stack);

// Pop function to remove an element from the stack
int Pop(Stack_Linked *ptr_stack);

// PeekStack function to get the top element without removing it
TYPE_STACK PeekStack(Stack_Linked *ptr_stack);

int CountStack(Stack_Linked *ptr_stack);

int IsFound(Stack_Linked *ptr_stack, int value);


// DeleteStack function to delete all elements from stack
// void DeleteStack(Stack *ptr_stack);

#endif