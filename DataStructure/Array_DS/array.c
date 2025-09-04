#include <stdio.h>
#include <stdlib.h>
#include "array.h"


void CreateArray(array_ds *arr)
{
    printf("Enter the size of Array: ");
    scanf("%d",&arr->size);
    arr->length = 0;
    arr->items = (int*)malloc(sizeof(int) * (arr->size));
    if(arr->items == NULL){
        printf("Memory allocation failed.\n");
        arr->size = 0;
    }
}

void FillArray(array_ds *arr)
{
    printf("\nEnter the num of elements: ");
    scanf("%d",&(arr->length));
    if(arr->length >= arr->size){
        printf("Error: number of elements exceeded the array size!\n");
        return;
    }
    for (int i = 0; i < arr->length; i++)
    {
        printf("Enter #%i : ", i+1);
        scanf("%d", &arr->items[i]);
    }
}

void DisplayArray(array_ds *arr)
{
    for(int i=0; i<arr->length; i++){
        printf("%d\t", arr->items[i]);
    }
    printf("\n");
}

int GetLengthArray(array_ds *arr)
{
    return arr->length;
}

int GetSizeArray(array_ds *arr)
{
    return arr->size;
}

int SearchArray(array_ds *arr)
{
    int item;
    printf("Enter an element to search: ");
    scanf("%d",&item);
    for(int i = 0; i<arr->length; i++){
        if(arr->items[i] == item){
            return i;
        }
    }
    return -1;
}

void AppendArray(array_ds *arr)
{
    int item;
    printf("Enter an element to append: ");
    scanf("%d",&item);
    if(arr->length + 1 >= arr->size){
        return;
    }
    else{
        arr->items[arr->length] = item;
        arr->length += 1;
    }
}

void InsertArray(array_ds *arr)
{
    int item, index;
    printf("Enter an element and index to insert it: ");
    scanf("%d%d",&item, &index);

    if(arr->length + 1 >= arr->size){
        printf("Error: number of elements exceeded the array size!\n");
        return;
    }
    if(index > arr->length){
        printf("Sorry, The index excedded :(");
        return;
    }
    for(int i = arr->length; i > index; i--){
        arr->items[i] = arr->items[i-1];
    }
    arr->items[index] = item;
    arr->length += 1;
    
}

void DeleteArray(array_ds *arr)
{
    int index;
    printf("Enter an index to delete it: ");
    scanf("%d",&index);
    if(index > arr->length){
        printf("Sorry, The index excedded :(");
        return;
    }
    for(int i = index; i < arr->length; i++){
        arr->items[i] = arr->items[i+1];
    }
    arr->length -= 1;
    
}

void EnlargeArray(array_ds *arr)
{
    int newSize;
    printf("\nEnter the size: ");
    scanf("%d", &newSize);
    if(arr->size >= newSize){
        printf("the new size is less or equal the old size\n");
        return;
    }
    arr->items = (int *)realloc(arr->items, sizeof(int) * newSize);
    if (!arr->items) {
        printf("Memory reallocation failed!\n");
        return;
    }
    arr->size = newSize;
}

void MergeArray(array_ds *arr, array_ds *arr1)
{
    if(arr->size <= (arr->length + arr1->length)){
        printf("Error: number of elements exceeded the array size!\n");
        return;
    }
    int oldLength = arr->length;
    for (int i = 0; i < arr1->length; i++)
    {
        arr->items[oldLength + i] = arr1->items[i];
    }
    arr->length += arr1->length;
}