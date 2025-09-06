
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int item;
    struct Node *next;
}Node;

typedef struct{
    Node *head;
    int length;
}Linkedlist;

void CreateLinkedList(Linkedlist *list);
void InsertFirstLinkedList(Linkedlist *list);
void InsertBeforeLinkedList(Linkedlist *list);
void AppendInLinkedList(Linkedlist *list);
void DeleteFromLinkedList(Linkedlist *list);
void TraverseLinkedList(Linkedlist *list);
int SearchLinkedList(Linkedlist *list);





#endif

