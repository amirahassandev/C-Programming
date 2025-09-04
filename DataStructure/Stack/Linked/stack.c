#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static int IsEmpty(Stack *ptr_stack){
    return ptr_stack->top->next == NULL;
}

void InitializeStack(Stack *ptr_stack){
    ptr_stack->top->next = NULL;
}    

void Push(Stack *ptr_stack, TYPE_STACK value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->element = value;
    newNode->next = ptr_stack->top->next;

    ptr_stack->top = newNode;

    ptr_stack->top->next = NULL;
}

// void Pop(Stack *ptr_stack){
//     if(!IsEmpty(ptr_stack)){
//         ptr_stack->top = NULL;
//     }
//     else{
//         printf("Error: Cannot pop from stack. The stack is empty.\n");
//     }
// }

TYPE_STACK PeekStack(Stack *ptr_stack){
    if(!IsEmpty(ptr_stack)){
        return ptr_stack->top->element;
    }
    else{
        printf("Error: The stack is empty.\n");
        return -1;
    }
}


// Note => We use %d for printing TYPE_STACK because TYPE_STACK is defined as int.
// void PrintStack(Stack *ptr_stack){
//     Node *currentNode = (Node*)malloc(sizeof(Node));
//     if(!currentNode){
//         printf("Memory allocation failed!\n");
//         return;
//     }

//     currentNode->next = ptr_stack->top
//     while(ptr){
//         printf("%d\n", ptr_stack->top->element);
//     }
// }

// void DeleteStack(Stack *ptr_stack){
//     free(ptr_stack);
//     ptr_stack->top = -1;
// }