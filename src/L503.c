#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM 10000

int *nextGreaterElements(int *nums, int numsSize, int *returnSize) {
    /// heap-buf-overflow
    int *res = (int *) calloc(numsSize, sizeof(int));
    memset(res, -1, sizeof(int) * numsSize);
    int *stack = (int *) calloc(numsSize, sizeof(int));//递减栈且栈中保存idx
    memset(stack, -1, sizeof(int) * numsSize);
    int sidx = -1;
    bool find = false;
    bool stackEmpty = true;
    for (int a = 0; a < numsSize; a++) {
        //压栈前尝试弹栈
        while (sidx >= 0 && nums[stack[sidx]] < nums[a]) {
            sidx--;
        }
        //把当前这个大数更新进res,栈全弹光可能一开始就是空的
        if (!stackEmpty) {
            int pop = stack[sidx + 1];
            res[pop] = nums[a];
        }
        //把当前元素idx压栈
        sidx++;
        stack[sidx] = a;
        stackEmpty = false;
        //最后一位因为就循环找,所以..
        if (!find && nums[a] > nums[numsSize - 1]) {
            res[numsSize - 1] = nums[a];
            find = true;
        }
    }
    free(stack);
    *returnSize = numsSize;
    return res;
}

/*
输入: nums = [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 */
int main() {
    int nums[] = {1, 2, 1};
//    int nums[] = {1,2,3,4,3};

    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int *returnSize = (int *) malloc(sizeof(int));
    int *res = nextGreaterElements(nums, numsSize, returnSize);
    for (int a = 0; a < numsSize; a++) {
        printf("%d ", res[a]);
    }
    return 0;
}
