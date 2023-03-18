#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int removeElement(int* nums, int numsSize, int val){
    size_t len = 0;
    size_t deleted = 0;
    while(len + deleted < numsSize)
    {
        if(len + deleted + 1 >= numsSize)
        {
            for(int i = 0; i < len; ++i)
            {
                printf("%d", nums[i]);
            }
            if(nums[len + deleted] == val)
                return len;
        }
        if(nums[len] == val)
        {
            nums[len] = nums[len + deleted + 1];
            ++deleted;
            continue;
        }
        ++len;
        if(len + deleted >= numsSize)
            break;
        nums[len] = nums[len + deleted];
    }
    for(int i = 0; i < len; ++i)
    {
        printf("%d", nums[i]);
    }
    return len;
}


int main(int argc, char *argv[]) {
    int nums[] = {3, 3};
    int amount = removeElement(nums, 2, 5);

    return 0;
}