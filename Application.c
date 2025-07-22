
#include <stdio.h>
#include <stdlib.h>
#include "leetcode/leetcode.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
}

int main(){
    int nums[] = {2,7,11,15};
    int returnSize;
    int size = sizeof(nums) / sizeof(nums[0]);
    int* result = twoSum(nums, 4, 9, &returnSize);
     printf("[%d, %d]\n", result[0], result[1]);

    return 0;
}