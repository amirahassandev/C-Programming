#include "linkedlist.h"

static void InsertFirst(Linkedlist *list, int item, Node *newNode);

void CreateLinkedList(Linkedlist *list)
{
    list->head = NULL;
    list->length = 0;
}

void InsertFirstLinkedList(Linkedlist *list)
{
    int item;
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the item: ");
    scanf("%d", &item);
    InsertFirst(list, item, newNode);
}

void InsertBeforeLinkedList(Linkedlist *list)
{
    int item, index, i = 0;
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the item and index: ");
    scanf("%d%d", &item, &index);

    if(index == 0){
        InsertFirst(list, item, newNode); 
        return;
    }

    newNode->item = item;
    
    Node *tempNode = list->head;
    while (tempNode && index-1 > i)
    {
        tempNode = tempNode->next;
        i++;
    }
    if(tempNode == NULL){
        printf("Sorry, the index doesn`t exist :(");
        return;
    }
    newNode->next = tempNode->next;
    tempNode->next = newNode;
    list->length += 1;
}

void AppendInLinkedList(Linkedlist *list)
{
    int item, i = 0;
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the item: ");
    scanf("%d", &item);
    newNode->item = item;
    Node *tempNode = list->head;
    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
    newNode->next = NULL;
}

void DeleteFromLinkedList(Linkedlist *list)
{
    int index, i = 0;
    printf("Enter the position: ");
    scanf("%d",&index);

    Node *tempNode = list->head;
    if(index == 0){
        list->head = tempNode->next;
        free(tempNode);
    }
    else{
        while (tempNode && index-1 > i)
        {
            tempNode = tempNode->next;
            i++;
        }
        if(tempNode == NULL){
            printf("Sorry, the index doesn`t exist :(\n");
            return;
        }
        Node *removeNode = NULL;
        removeNode = tempNode->next;
        tempNode->next = removeNode->next;
        free(removeNode);
    }
    list->length -= 1;
}

void TraverseLinkedList(Linkedlist *list)
{
    Node *tempNode = list->head;
    while (tempNode)
    {
        printf("%d\t", tempNode->item);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int SearchLinkedList(Linkedlist *list)
{
    int item;
    printf("Enter Item to search it in linkedList: ");
    scanf("%d",&item);

    Node *tempNode = list->head;
    int index = 0;
    while (tempNode)
    {
        if(tempNode->item == item){
            return index;
        }
        tempNode = tempNode->next;
        index++;
    }
    return -1;
}






static void InsertFirst(Linkedlist *list, int item, Node *newNode){
    newNode->item = item;
    newNode->next = NULL;

    if(list->length == 0){
        list->head = newNode;        
    }else{
        newNode->next = list->head;
        list->head = newNode;
    }

    list->length += 1;
}