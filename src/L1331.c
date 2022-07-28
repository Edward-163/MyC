#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。
序号代表了一个元素有多大。序号编号的规则如下：
序号从 1 开始编号。
一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
每个数字的序号都应该尽可能地小。
 
示例 1：
输入：arr = [40,10,20,30]
输出：[4,1,2,3]
解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。
 */
typedef struct {
    int num;
    int idx;
    int sortScore;
} Ele;

int Cmp(Ele *a, Ele *b)
{
    if (a->num == b->num) {
        return a->idx - b->idx;
    }
    return a->num - b->num;
}

int Cmp2(Ele *a, Ele *b)
{
    return a->idx - b->idx;
}

int *arrayRankTransform(int *arr, int arrSize, int *returnSize)
{
    if (arrSize < 0) {
        return NULL;
    }
    Ele *eles = malloc(sizeof(Ele) * arrSize);
    int *ans = malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; ++i) {
        eles[i].num = arr[i];
        eles[i].idx = i;
    }
    qsort(eles, arrSize, sizeof(Ele), Cmp);
    int sortScore = 0;
    int pre = -1000000001;
    for (int i = 0; i < arrSize; ++i) {
        if (eles[i].num != pre) {
            sortScore++;
            pre = eles[i].num;
        }
        ans[eles[i].idx] = sortScore; // 别人优秀:score求出后,直接根据记录的idx往ans[idx]塞入即可
    }
    // qsort(eles, arrSize, sizeof(Ele), Cmp2); // 别人优秀答案是不需要二次排序的
    // for (int i = 0; i < arrSize; ++i) {
    //     ans[i] = eles[i].sortScore;
    // }
    *returnSize = arrSize;
    return ans;
}

int main()
{
    // @formatter:off
    // int arr[]={40,10,20,30};
    // int arr[]={1,1,1};
    int arr[]={37,12,28,9,100,56,80,5,12}; // 输出：[5,3,4,2,8,6,7,1,3]
    int size=sizeof(arr)/sizeof(arr[0]);
    int returnSize;
    int *ans = arrayRankTransform(arr,size,&returnSize);
    for (int i = 0; i < returnSize; ++i){
        printf("%d ",ans[i]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}