/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*
 
 */
void swap(int *nums, int left, int right)
{
    int tmp = nums[left];
    nums[left] = nums[right];
    nums[right] = tmp;
}

int cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

void wiggleSort(int *nums, int numsSize)
{

}

int main()
{
    int nums[] = {1, 3, 2, 2, 1, 3};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    wiggleSort(nums, numSize);
    for (int i = 0; i < numSize; ++i) {
        printf("%d ", nums[i]);
        fflush(stdout);
    }
    return 0;
}