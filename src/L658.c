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

int *findClosestElements(int *arr, int arrSize, int k, int x, int *returnSize) {
    if (x < arr[0]) {
        *returnSize = k;
        return arr;
    }

    // arrs-k arrs-k+1.. arrs-1 arrs
    int ansidx = arrSize - k;

    /// 考察重点:滑窗从左往右,还是从右往左
    /// bug 大了是坚决不行,小了可以,相等尝试往左移动(前提是滑窗从右往左,而不是从左往右)
    for (int a = arrSize - k - 1; a >= 0; a--) {
        int addLeftNum = ABS(arr[a], x);
        int subRighNum = ABS(arr[a + k], x);
        if (addLeftNum - subRighNum <= 0) {
            ansidx = a;
        } else {
            break;
        }
    }
    *returnSize = k;
    return arr + ansidx;
}

int main() {
    // @formatter:off
//     int arr[]={1,2,3,4,5};
    int arr[]={1,1,2,2,2,2,3,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int x=3;
    int rsize;
    int *ans = findClosestElements(arr,size,k,x,&rsize);
    for (int i = 0; i < rsize; ++i){
        printf("%d \n",ans[i]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}