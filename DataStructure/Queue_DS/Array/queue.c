#include "queue.h"

void InitializeQueue(Queue_Arr *queue)
{
    queue->front = 0;
    queue->rear = -1;
    queue->length = 0;
}

static int IsEmpty(Queue_Arr *queue){
    return queue->length == 0;
}

static int IsFull(Queue_Arr *queue){
    return queue->length == QUEUE_MAX;
}

void Enqueue(Queue_Arr *queue, QUEUE_TYPE item)
{
    if(IsFull(queue)){
        printf("Queue is full. \n");
        return;
    }
    queue->rear = queue->rear % QUEUE_MAX;
    queue->Items[++queue->rear] = item;
    queue->length++;
}

void PrintQueue(Queue_Arr *queue){
    if(IsEmpty(queue)){
        printf("Queue is empty. \n");
        return;
    } 
    int count = queue->length;
    int index = queue->front;
    while (count--) {
        printf("%d ", queue->Items[index]);
        index = (index + 1) % QUEUE_MAX;
    }
    printf("\n\n");
}

void Dequeue(Queue_Arr *queue){
    if(IsEmpty(queue)){
        printf("Queue is empty. \n");
        return;
    }
    queue->front = (queue->front + 1) % QUEUE_MAX;
    queue->length--;
}

int IsFound(Queue_Arr *queue, QUEUE_TYPE item)
{
    int found = 0;
    int count = queue->length;
    int index = queue->front;
    while (count--) {
        if(item == queue->Items[index]){
            found = 1;
            return found;
        }
        index = (index + 1) % QUEUE_MAX;
    }
    return found;
}

QUEUE_TYPE PeekQueue(Queue_Arr *queue){
    if(IsEmpty(queue)){
        printf("Queue is empty. \n");
        return 0;
    }
    return queue->Items[queue->front];
}

int CountQueue(Queue_Arr *queue){
    return queue->length;
}

void ClearQueue(Queue_Arr *queue){
    queue->front = 0;
    queue->rear = -1;
    queue->length = 0;
}