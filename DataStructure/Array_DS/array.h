
#ifndef ARRAY_H
#define ARRAY_H

typedef struct 
{
    int size;
    int length;
    int *items;
}array_ds;


void CreateArray(array_ds *arr);
void FillArray(array_ds *arr);
void DisplayArray(array_ds *arr);
int GetLengthArray(array_ds *arr);
int GetSizeArray(array_ds *arr);
int SearchArray(array_ds *arr);
void AppendArray(array_ds *arr);
void InsertArray(array_ds *arr);
void DeleteArray(array_ds *arr);
void EnlargeArray(array_ds *arr);
void MergeArray(array_ds *arr, array_ds *arr1);






#endif