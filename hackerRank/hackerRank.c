#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hackerRank.h"

void DynamicArrayInC(){

    /*
    * This stores the total number of books in each shelf.
    */
    int* total_number_of_books;

    /*
    * This stores the total number of pages in each book of each shelf.
    * The rows represent the shelves and the columns represent the books.
    */
    int** total_number_of_pages;
    
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    total_number_of_books = (int*)calloc(total_number_of_shelves, sizeof(int));
    total_number_of_pages = (int**)calloc(total_number_of_shelves, sizeof(int*));
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
            * Process the query of first type here.
            */
            int x, y;
            scanf("%d %d", &x, &y); // x > number of shelves,    y > count of book pages
            

            if (x >= 0 && x < total_number_of_shelves) {
                if (total_number_of_pages[x] == NULL) {
                    total_number_of_pages[x] = (int*)malloc(1100 * sizeof(int)); // max 1100 books per shelf
                }
                
                int end_book = total_number_of_books[x];
                if (end_book < 1100) {
                    total_number_of_pages[x][end_book] = y; // Add book with page count
                    total_number_of_books[x]++;            // Increment book count
                }
            }

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }

}


static int lexicographic_sort(const char* a, const char* b) {
    int i = 0;

    // Compare characters one by one
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) {
            return -1; // a comes before b
        } else if (a[i] > b[i]) {
            return 1; // a comes after b
        }
        i++;
    }

    // Handle case where one string is a prefix of the other
    if (a[i] == '\0' && b[i] == '\0') {
        return 0; // Strings are identical
    } else if (a[i] == '\0') {
        return -1; // a is shorter, so it comes first
    } else {
        return 1; // b is shorter, so it comes first
    }
}

static int sort_by_number_of_distinct_characters_error(const char* a, const char* b) {
//     int lenA = 0, lenDistnictA = 0, lenB = 0, lenDistnictB = 0;
//     while (a[lenA++] != '\0');
//     for(int i=0; i < a[i] != '\0'; i++){
//         for(int x=i+1; x< a[x] != '\0'; x++){
//             if(a[i] == a[x]){
//                 lenDistnictA++;
//             }
//         }
//     }

//     lenA = lenA - lenDistnictA;

//     while (b[lenB++] != '\0');
//     for(int i=0; i < b[i] != '\0'; i++){
//         for(int x=i+1; x< b[x] != '\0'; x++){
//             if(b[i] == b[x]){
//                 lenDistnictB++;
//             }
//         }
//     }

//     lenB = lenB - lenDistnictB;

//     if(lenA < lenB){
//         return -1;
//     }else if(lenA > lenB){
//         return 1;
//     }else{
//         return lexicographic_sort(a, b);
//     }
    
}

static int lexicographic_sort_reverse(const char* a, const char* b) {
    return (-1 * lexicographic_sort(a, b));
}

static int count_distinct_characters(const char* str) {
    int char_count[256] = {0}; // Array to count occurrences of each character
    int distinct_count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (char_count[(unsigned char)str[i]] == 0) {
            distinct_count++;
        }
        char_count[(unsigned char)str[i]]++;
    }

    return distinct_count;
}

static int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int countA = count_distinct_characters(a);
    int countB = count_distinct_characters(b);

    if (countA != countB) {
        return countA - countB; // Sort by distinct character count
    }

    // If the counts are equal, fall back to lexicographic sorting
    return lexicographic_sort(a, b);
}

static int sort_by_length(const char* a, const char* b) {
    int lenA = 0, lenB = 0;
    while (a[lenA++] != '\0');
    while (b[lenB++] != '\0');
    if(lenA < lenB){
        return -1;
    }else if(lenA > lenB){
        return 1;
    }else{
        return lexicographic_sort(a, b);
    }
}

static void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int sentence = 0; sentence < len - 1; sentence++) {
        for (int word = 0; word < len - sentence - 1; word++) {
            if (cmp_func(arr[word], arr[word + 1]) > 0) {
                char* temp = arr[word];
                arr[word] = arr[word + 1];
                arr[word + 1] = temp;
            }
        }
    }
}


void SortingArrayOfString(){
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

}




