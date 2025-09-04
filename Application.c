
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leetcode/leetcode.h"
// #include "DataStructure/Stack/Linked/stack.h"
#include "DataStructure/Array_DS/array.h"



int main(){
    array_ds arr, arr1;
    CreateArray(&arr);
    FillArray(&arr);
    DisplayArray(&arr);
    printf("\n\n");
    printf("Search: %d\n",SearchArray(&arr));
    AppendArray(&arr);
    printf("Length: %d\n",GetLengthArray(&arr));
    DisplayArray(&arr);
    printf("\n\n");
    InsertArray(&arr);
    printf("Length: %d\n",GetLengthArray(&arr));
    DisplayArray(&arr);
    printf("\n\n");
    DeleteArray(&arr);
    printf("Length: %d\n",GetLengthArray(&arr));
    DisplayArray(&arr);
    EnlargeArray(&arr);
    printf("Size: %d\n", GetSizeArray(&arr));
    DisplayArray(&arr);

    CreateArray(&arr1);
    FillArray(&arr1);
    DisplayArray(&arr1);
    printf("\n\n");
    MergeArray(&arr, &arr1);

    DisplayArray(&arr);


    // GetSizeArray(&arr);


    return 0;
}