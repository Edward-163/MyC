#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"

/*
 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
 

示例 1：

输入：arr = [1,2,3,4,5], k = 4, x = 3
输出：[1,2,3,4]
示例 2：

输入：arr = [1,2,3,4,5], k = 4, x = -1
输出：[1,2,3,4]

 */
#define ABS(x, y) (x)>(y)?x-y:y-x

int max(int *arr, int move, int k, int x)
{
    int sum=0;
    for (int i = 0; i < k; ++i){
        sum+=ABS(arr[move],x);
    }
    return sum;
}

int *findClosestElements(int *arr, int arrSize, int k, int x, int *returnSize)
{
    if (x < arr[0]) {
        *returnSize = k;
        return arr;
    } else if (x > arr[arrSize - 1]) {
        *returnSize = k;
        return arr + arrSize - k; // idx的小把戏
    }

    int move = arrSize - k;
    int m = max(arr, move, k, x);
    /// 考察重点:滑窗从左往右,还是从右往左
    for (int a = move - 1; a >= 0; a--) {
        int newm = max(arr, a, k, x);
        /// bug 大了是坚决不行,小了可以,相等尝试往左移动(前提是滑窗从右往左,而不是从左往右)
        if (newm > m) {
            break;
        } else {
            m = newm;
            move = a;
        }
    }
    *returnSize = k;
    return arr + move;
}

int main()
{
    // @formatter:off
    // int arr[]={1,2,3,4,6};
    int arr[]={1,1,2,2,2,2,3,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int x=3;
    int rsize;
    int *ans = findClosestElements(arr,size,k,x,&rsize);
    for (int i = 0; i < rsize; ++i){
        printf("%d \n",ans[i]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}