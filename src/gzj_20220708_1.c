#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <uthash.h>


/*
 给定一个整数数组arr，以及三个整数A，B，C，如果从数组中取出三元组（g_arr[i],g_arr[j],g_arr[k])
满足下列全部条件，则认为他是平衡三元组
1, 0<=i<j<k<g_arr.length
2,|g_arr[i]-g_arr[j]|<=A
3,|g_arr[j]-g_arr[k]|<=B
4,|g_arr[i]-g_arr[k]|<=C
统计并返回其中平衡三元组的数量
例子：
输入：  g_arr = [4,9,9,8,9,5,3,7]
        numA = 1
        numB = 3
        numC = 0
输出：3
        解释：一共有 3 个平衡三元组：[(9,9,9), (9,8,9), (9,8,9)] 。
        注意：其中两个 (9,8,9) 的第一个 9 在数组 g_arr 中的下标不同，视为 2 个平衡三元组。
 */
#define abs(a, b) ((a)>(b)?(a)-(b):(b)-(a))

int Fn(int *arr, int size, int num[3])
{
    int ans = 0;
    for (int a = 0; a < size - 2; ++a) {
        for (int b = a + 1; b < size - 1; b++) {
            if (abs(arr[a], arr[b]) > num[0]) {
                continue;
            }
            for (int c = b + 1; c < size; c++) {
                if (abs(arr[b], arr[c]) > num[1]) {
                    continue;
                }
                if (abs(arr[a], arr[c]) <= num[2]) {
                    ans++;
                    // printf("%d_%d_%d \n",g_arr[a],g_arr[b],g_arr[c]);fflush(stdout);
                }
            }
        }
    }
    return ans;
}

int main()
{
    // @formatter:off
    int arr[]={4,9,9,8,9,5,3,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int num[3]={1,3,0};
    int i = Fn(arr,size,num);
    printf("%d \n",i);fflush(stdout);
    return 0;
    // @formatter:on
}