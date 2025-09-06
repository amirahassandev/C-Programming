#include "queue.h"
#include <stdlib.h>

void InitializeQueue(Queue_Linked *ptr_queue){
    ptr_queue->front = NULL;
    ptr_queue->rear = NULL;
}

static int IsEmpty(Queue_Linked *ptr_queue){
    return ptr_queue->front == NULL;
}

void Enqueue(Queue_Linked *ptr_queue, QUEUE_TYPE item){
    NodeQueue *newNode = (NodeQueue*)malloc(sizeof(NodeQueue));
    if(!newNode){
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->item = item;
    newNode->next = NULL;
    if(IsEmpty(ptr_queue)){
        ptr_queue->rear = newNode;
        ptr_queue->front = newNode;
    }
    else{
        ptr_queue->rear->next = newNode;
        ptr_queue->rear = newNode;
    }
}

void PrintQueue(Queue_Linked *queue){
    NodeQueue *tempNode = queue->front;
    if(IsEmpty(queue)){
        printf("Queue is empty. \n");
        return;
    }
    while (tempNode)
    {
        printf("%d\n", tempNode->item);
        tempNode = tempNode->next;
    }
    printf("\n");
}

void Dequeue(Queue_Linked *queue){
    NodeQueue *delPtr = queue->front;
    if(IsEmpty(queue)){
        printf("Queue is empty. \n");
        return;
    }
    else if(queue->front == queue->rear){
        queue->front = queue->rear = NULL;
    }
    else{
        queue->front = delPtr->next; 
    }
    free(delPtr);
}

int IsFound(Queue_Linked *queue, QUEUE_TYPE item){
    int found = 0;
    NodeQueue *tempNode = queue->front;
    while (tempNode)
    {
        if(item == tempNode->item){
            found = 1;
            return found;
        }
        tempNode = tempNode->next;
    }
}

QUEUE_TYPE PeekQueue(Queue_Linked *queue){
    return queue->front->item;
}

int CountQueue(Queue_Linked *queue){
    NodeQueue *tempNode = queue->front;
    int count = 0;
    while (tempNode)
    {
        count++;
        tempNode = tempNode->next;
    }
    return count;
}

int ClearQueue(Queue_Linked *queue){
    while (!IsEmpty(queue))
    {
        // NodeQueue *delPtr = queue->front;
        // queue->front = delPtr->next;
        // free(delPtr);

        Dequeue(queue);
    }
}