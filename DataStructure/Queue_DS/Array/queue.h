

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX 10

typedef int QUEUE_TYPE;


typedef struct
{
    QUEUE_TYPE Items[QUEUE_MAX];
    int rear;
    int front;
    int length;
}Queue_Arr;



void InitializeQueue(Queue_Arr *queue);
void Enqueue(Queue_Arr *queue, QUEUE_TYPE item);
void PrintQueue(Queue_Arr *queue);
void Dequeue(Queue_Arr *queue);
int IsFound(Queue_Arr *queue, QUEUE_TYPE item);
QUEUE_TYPE PeekQueue(Queue_Arr *queue);
int CountQueue(Queue_Arr *queue);
void ClearQueue(Queue_Arr *queue);



#endif