

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int QUEUE_TYPE;

typedef struct NodeQueue
{
    QUEUE_TYPE item;
    struct NodeQueue *next;
}NodeQueue;

typedef struct
{
    NodeQueue *front;
    NodeQueue *rear;
}Queue_Linked;



void InitializeQueue(Queue_Linked *queue);
void Enqueue(Queue_Linked *queue, QUEUE_TYPE item);
void PrintQueue(Queue_Linked *queue);
void Dequeue(Queue_Linked *queue);
int IsFound(Queue_Linked *queue, QUEUE_TYPE item);
QUEUE_TYPE PeekQueue(Queue_Linked *queue);
int CountQueue(Queue_Linked *queue);
void ClearQueue(Queue_Linked *queue);



#endif