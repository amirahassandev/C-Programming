
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leetcode/leetcode.h"
#include "DataStructure/Stack/stack.h"



int main(){
    Stack s;
    InitializeStack(&s);
    Push(&s, 5);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 7);
    Push(&s, 10);
    Push(&s, 20);
    Push(&s, 30);


    printf("%d\n\n", PeekStack(&s));
    Pop(&s);
    PrintStack(&s);

    return 0;
}