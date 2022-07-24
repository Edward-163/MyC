#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 给一个数num，求出1到num的所有的数的权重，按照权重的的值将权重相同的值放在同一个数组，求出数组元素最多的数组的个数，权重的定义是数组的每一位的和，比如123的权重是1+2+3=6；
输入：12;
输出：3;
1的权重1,2的权重2,3的权重为3...10的权重1,11的权重2,12的权重3
因此1权重对应的数组为[1,10],2权重对应的数组为[2,11],3权重对应的数组为[3,12]，即数组最长的长度为2，公有3个，输出3；
 */
int Qu(int num)
{
    int qu = 0;
    while (num / 10 != 0) {
        qu += num % 10;
        num /= 10; // 10 divide num
    }
    qu += num;
    return qu;
}

int Fn(int num)
{
    int numcpy = num;
    int numlen = 1;
    while (numcpy / 10 != 0) {
        numlen++;
        // step
        numcpy /= 10; // 10 divide num
    }
    int *arr = malloc(sizeof(int) * (9 * numlen + 1)); // 9*len
    memset(arr, -1, sizeof(int) * (9 * numlen + 1));
    for (int a = 1; a < num; a++) {
        int i = Qu(a);
        arr[i] = i;
    }
    int ans;
    for (int a = 1; a <= 9 * numlen + 1; a++) {
        if (arr[a] > ans) {
            ans = arr[a];
        } else if (arr[a] == ans) {
            ans++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}