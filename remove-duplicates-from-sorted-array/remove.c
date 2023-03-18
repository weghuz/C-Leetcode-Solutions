#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int removeDuplicates(int* nums, int numsSize){
    if(numsSize <= 1) return numsSize;
    int index = 0;
    bool swapback = false;
    for(int i = 1; i < numsSize; ++i)
    {
        if(nums[i] > nums[index])
        {
            if(swapback)
            {
                nums[++index] = nums[i];
                i = index;
                swapback = false;
                continue;
            }
            index = i;
        }
        swapback = true;
    }
    return index;
}

int main(int argc, char *argv[]) {
    int nums[] = {1,1,2};
    int amount = removeDuplicates(nums, 3);

    return 0;
}