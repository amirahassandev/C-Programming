
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DataStructure/Queue_DS/Array/queue.h"



int main(){
    Queue_Arr queue;
    InitializeQueue(&queue);

    Enqueue(&queue, 4);
    PrintQueue(&queue);

    Enqueue(&queue, 7);
    PrintQueue(&queue);

    Dequeue(&queue);
    PrintQueue(&queue);

    printf("IsFound: %d\n", IsFound(&queue, 7));
    printf("IsFound: %d\n", IsFound(&queue, 8));
    printf("Peek: %d\n", PeekQueue(&queue));
    ClearQueue(&queue);
    printf("Count: %d\n", CountQueue(&queue));




    return 0;
}