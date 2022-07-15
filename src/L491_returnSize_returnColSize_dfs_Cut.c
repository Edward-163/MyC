#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/**
 int* returnSize和int** returnColumnSizes
 ans是返回的二维数组,以int**形式返回,好理解
 int main(){// leet的main可能是这么写的
    int returnSize;// 就是个记录二维数组的行数的数字,但直接传值给函数,改变不了该数字的内容,所以传址
    int **returnColumnSize;// leet是不会帮你初始化它的,就是个数组[ans第1行列数,ans第2行列数,...,ans第n行列数,],但直接int*传值给函数,改变不了该数组的内容,所以传址int**
    int **g_ans = threeSum(nums, numsSize, &returnSize, returnColumnSizes);

 https://leetcode.cn/circle/discuss/V3ozv1/
因为题目中returnColumnSizes，并不会帮你初始化，你需要自己根据行数来初始化这个变量，如果用一级指针，初始化后是传不出去的。其实这个不要理解成二级指针，要理解成一维指针的指针!!!
大佬解释到这,悟了,所以在理解returnSize的基础上,再加上leet不初始化int** returnColSize

    官方题解中returnco的初始化这块我觉得它错了,
    (*returnColumnSizes) = (int *)malloc(sizeof(int*) * (*returnSize));
    应该是下面这种
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    // 本题中每行的列数都是3
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 3;
    }
 */
int** g_ans;
int ansSize;
int* temp;
int tempSize;

void dfs(int cur, int last, int* nums, int numsSize, int** returnColumnSizes) {
    if (cur == numsSize) {
        if (tempSize >= 2) {
            /// 学到了,对于二级指针,最开始是赋值了一次int**,但在填充里面元素时候还得再赋值一次
            g_ans[ansSize] = malloc(sizeof(int) * tempSize);
            memcpy(g_ans[ansSize], temp, sizeof(int) * tempSize);
            (*returnColumnSizes)[ansSize++] = tempSize;
        }
        return;
    }
    if (nums[cur] >= last) {
        temp[tempSize++] = nums[cur];
        dfs(cur + 1, nums[cur], nums, numsSize, returnColumnSizes);//选择cur,那么last会被更新
        tempSize--;
    }
    /// 这个剪枝去重太666,这题我大概通过话树可以大致理解,但还是没有理解其去重的精髓
    if (nums[cur] != last) {
        dfs(cur + 1, last, nums, numsSize, returnColumnSizes);//不选cur,那么last还是上次的last
    }
}

int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    g_ans = (int**)malloc(sizeof(int*) * 32768);//2^15==32768
    /// 有点悟了,带return的在leet上全要自己构造出来并return
    /// ???? int* res=malloc(sizeof(int*)*n) 不理解这里为啥要解引用呀??!!
//    *returnColumnSizes = malloc(sizeof(int*) * 32768);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 32768);
    temp = malloc(sizeof(int) * numsSize);
    ansSize = tempSize = 0;
    dfs(0, INT_MIN, nums, numsSize, returnColumnSizes);
    *returnSize = ansSize;
    return g_ans;
}

int main() {
//    int nums[]={3,4,1,2};
//    int nums[]={3,4,4};
    int nums[]={4,4};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    /// 这种写法虽然可以,算是没有理解returnSize前的写法,建议以后改正.
    int* returnSize=(int*)malloc(sizeof(int) * 32768);
    /// 写NULL会sig,这个为啥要用二级指针??!!如何理解它??
    int** returnColumnSize=(int**)malloc(sizeof(int*) * 32768);
    int **pInt = findSubsequences(nums, numsSize, returnSize, returnColumnSize);
    for (int a = 0; a < *returnSize; ++a) {
        for (int b = 0; b <(*returnColumnSize)[a]; ++b) {
            printf("% ", pInt[a][b]);fflush(stdout);
        }
        printf("\n" );fflush(stdout);
    }
    return 0;
}