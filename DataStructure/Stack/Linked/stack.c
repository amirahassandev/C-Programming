#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static int IsEmpty(Stack_Linked *ptr_stack){
    return ptr_stack->top == NULL;
}

static int IsFull(Stack_Linked *ptr_stack){
    Node_Stack *node = (Node_Stack*)malloc(sizeof(Node_Stack));
    if(!node){
        printf("Memory allocation failed!\n");
        return 0;
    }
    return 1;
}


void InitializeStack(Stack_Linked *ptr_stack){
    ptr_stack->top = NULL;
}    

void Push(Stack_Linked *ptr_stack, TYPE_STACK value){
    Node_Stack *newNode = (Node_Stack*)malloc(sizeof(Node_Stack));
    if(!newNode){
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->element = value;
    newNode->next = NULL;

    if(IsEmpty(ptr_stack)){
        ptr_stack->top = newNode;
    }
    else{
        newNode->next = ptr_stack->top;
        ptr_stack->top = newNode;
    }
}

// Note => We use %d for printing TYPE_STACK because TYPE_STACK is defined as int.
void PrintStack(Stack_Linked *ptr_stack){
    Node_Stack *tempNode = ptr_stack->top;
    while (tempNode)
    {
        printf("%d\n", tempNode->element);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int Pop(Stack_Linked *ptr_stack){
    if(IsEmpty(ptr_stack)){
        printf("Error: Cannot pop from stack. The stack is empty.\n");
        return 0;
    }
    else{
        Node_Stack *delPtr = ptr_stack->top;
        ptr_stack->top = delPtr->next;
        free(delPtr);
    }
    return ptr_stack->top->element;
}

TYPE_STACK PeekStack(Stack_Linked *ptr_stack){
    if(!IsEmpty(ptr_stack)){
        return ptr_stack->top->element;
    }
    else{
        printf("Error: The stack is empty.\n");
        return -1;
    }
}

int CountStack(Stack_Linked *ptr_stack){
    int count = 0;
    Node_Stack *tempNode = ptr_stack->top;
    while (tempNode)
    {
        count++;
        tempNode = tempNode->next;
    }
    return count;
}

int IsFound(Stack_Linked *ptr_stack, int value){
    int found = 0;
    Node_Stack *tempNode = ptr_stack->top;
    while (tempNode)
    {
        if(value == tempNode->element){
            found = 1;
            return found;
        }
        tempNode = tempNode->next;
    }
    return found;
}

// void DeleteStack(Stack *ptr_stack){
//     free(ptr_stack);
//     ptr_stack->top = -1;
// }