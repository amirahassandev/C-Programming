
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leetcode/leetcode.h"
// #include "DataStructure/Stack/Linked/stack.h"
#include "DataStructure/Array_DS/array.h"
#include "DataStructure/LinkedList_DS/linkedlist.h"




int main(){
    
    Linkedlist list;
    CreateLinkedList(&list);
    InsertFirstLinkedList(&list);
    // InsertFirstLinkedList(&list);
    // InsertFirstLinkedList(&list);

    // InsertBeforeLinkedList(&list);
    AppendInLinkedList(&list);
    AppendInLinkedList(&list);
    DeleteFromLinkedList(&list);
    
    TraverseLinkedList(&list);
    // InsertBeforeLinkedList(&list);
    DeleteFromLinkedList(&list);
    TraverseLinkedList(&list);
    DeleteFromLinkedList(&list);
    TraverseLinkedList(&list);


    // printf("%d\n",SearchLinkedList(&list));




    return 0;
}