
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DataStructure/Queue_DS/Linked/queue.h"



int main(){
    Queue_Linked queue;
    InitializeQueue(&queue);

    Enqueue(&queue, 4);
    PrintQueue(&queue);

    Enqueue(&queue, 7);
    PrintQueue(&queue);

    printf("IsFound: %d\n", IsFound(&queue, 4));
    printf("IsFound: %d\n", IsFound(&queue, 8));
    printf("Peek: %d\n", PeekQueue(&queue));
    ClearQueue(&queue);
    printf("Count: %d\n", CountQueue(&queue));




    return 0;
}