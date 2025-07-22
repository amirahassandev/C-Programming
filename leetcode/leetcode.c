

#include <stdio.h>
#include <stdlib.h>
#include "leetcode.h"

char* makeFancyString(char* s) {
    int read = 0, write = 0, countRepeated = 0;
    while (s[read] != '\0')
    {
        
        if(s[read] == s[read+1])
        {
            countRepeated++;
            if(countRepeated >= 2){
                read++;
            }else{
                s[write++] = s[read++];
            }
        }
        else{
            s[write++] = s[read++];
            countRepeated = 0;
        }
    }
    s[write] = '\0';
    return s;
    
}

// two-sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    for(int i =0; i<numsSize; i++){
        for(int x =i+1; x<numsSize; x++){
            if((nums[i] + nums[x]) == target){
                result[0] = i;
                result[1] = x; 
                *returnSize = 2; 
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}