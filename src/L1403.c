#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */
int cmp(int *a, int *b)
{
    return *b - *a;
}

int *minSubsequence(int *nums, int numsSize, int *returnSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int sum = 0;
    for (int a = 0; a < numsSize; a++) {
        sum += nums[a];
    }
    int ss = 0;
    int *ans = malloc(sizeof(int) * numsSize);
    int alen = 0;
    for (int a = 0; a < numsSize; a++) {
        ss += nums[a];
        ans[alen++] = nums[a];
        if (ss * 2 > sum) { // 2 double

            break;
        }
    }
    *returnSize = alen;
    return ans;
}

int main()
{
    // @formatter:off
    
    return 0;
    // @formatter:on
}