/*
 *
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*
 题干：
    给定长度为偶数的整数数组nums，由数目相等的正整数和负整数组成，需按要求重排。
 * 要求：
    1. 正整数开头，且任意相邻两个整数符号相反；
    2. 保留各位整数在原nums中的先后顺序
 * 示例1：
    输入：nums = [-1,1,-3,5]
    输出：[1,-1,5,-3]

 * 示例2：
    输入：nums = [-22,1,-3,-40,47,4]
    输出：[1,-22,47,-3,4,-40]
 * 解释：
    nums 中的正整数是 [1,47,4] ，负整数是 [-22,-3,-40] 。
    按照以上条件得到的重排结果是 [1,-22,47,-3,4,-40]。
 * 提示：
    2 <= nums.length <= 2000
    1 < |nums[i]| < 10^5
 */

int *Fn(int *nums, int size)
{
    int *ans = (int *) malloc(sizeof(int) * size);
    int evenidx = 0;
    int oddidx = 1;
    for (int i = 0; i < size; ++i) {
        if (nums[i] > 0) {
            ans[evenidx] = nums[i];
            evenidx += 2;
        } else {
            ans[oddidx] = nums[i];
            oddidx += 2;
        }
    }
    return ans;
}
int main()
{
//    int nums[]={-1,1,-3,5};
    int nums[]={-22,1,-3,-40,47,4};
    int size=sizeof(nums)/sizeof(nums[0]);
    int *pInt = Fn(nums, size);
    for (int i = 0; i < size; ++i){
        printf("%d ",pInt[i] );fflush(stdout);
    }
    return 0;
}