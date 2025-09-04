#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static int IsEmpty(Stack *ptr_stack){
    return ptr_stack->top == -1;
}

static int IsFull(Stack *ptr_stack){
    return ptr_stack->top == MAX_STACK - 1;
}

void InitializeStack(Stack *ptr_stack){
    ptr_stack->top = -1;
}    

void Push(Stack *ptr_stack, TYPE_STACK value){
    if(!IsFull(ptr_stack)){
        ptr_stack->elements[++ptr_stack->top] = value;
    }
    else{
        printf("Error: Cannot push %d to stack. The stack is full (maximum size: %d).\n", value, MAX_STACK);
    }
}

void Pop(Stack *ptr_stack){
    if(!IsEmpty(ptr_stack)){
        ptr_stack->top--;
    }
    else{
        printf("Error: Cannot pop from stack. The stack is empty.\n");
    }
}

TYPE_STACK PeekStack(Stack *ptr_stack){
    if(!IsEmpty(ptr_stack)){
        return ptr_stack->elements[ptr_stack->top];
    }
    else{
        printf("Error: The stack is empty.\n");
        return -1;
    }
}


// Note => We use %d for printing TYPE_STACK because TYPE_STACK is defined as int.
void PrintStack(Stack *ptr_stack){
    for(unsigned int i = ptr_stack->top; i>=0; i--){
        printf("%d\n", ptr_stack->elements[i]);
    }
}

void DeleteStack(Stack *ptr_stack){
    free(ptr_stack);
    ptr_stack->top = -1;
}