
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leetcode/leetcode.h"
#include "DataStructure/Stack/Linked/stack.h"
#include "DataStructure/Array_DS/array.h"
// #include "DataStructure/LinkedList_DS/linkedlist.h"




int main(){
    
    Stack_Linked stack;
    InitializeStack(&stack);
    Push(&stack, 10);
    PrintStack(&stack);

    Push(&stack, 20);
    PrintStack(&stack);

    Push(&stack, 50);
    PrintStack(&stack);

    Pop(&stack);
    PrintStack(&stack);

    printf("PeekStack: %d\n",PeekStack(&stack));
    printf("IsFound: %d",IsFound(&stack, 10));





    return 0;
}