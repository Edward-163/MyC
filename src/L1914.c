/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <uthash.h>
/*
 车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向）
给定整数 capacity 和一个数组 trips ,  trip[i] = [numPassengersi, fromi, toi] 表示第 i 次旅行有 numPassengersi 乘客，
 接他们和放他们的位置分别是 fromi 和 toi 。这些位置是从汽车的初始位置向东的公里数。
当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。
 
示例 1：
输入：trips = [[2,1,5],[3,3,7]], capacity = 4
输出：false
示例 2：
输入：trips = [[2,1,5],[3,3,7]], capacity = 5
输出：true
 */
/*
 可信资料用差分解此题,但做过类似的,其实用的是贪心,题意中的公司数也可以理解为从1->n的车站,因为从左往右遍历,贪心按toi公里数(车站)排升序
 */
#define MAX 10001

bool carPooling(int **trips, int size, int *colsize, int cap)
{
    int max = 0;
    int *arr = malloc(sizeof(int) * MAX);
    memset(arr, 0, sizeof(int) * MAX);
    for (int i = 0; i < size; ++i) {
        if (trips[i][2] > max) {
            max = trips[i][2];
        }
        arr[trips[i][1]] += trips[i][0];
        arr[trips[i][2]] -= trips[i][0];
    }
    int sum = 0;
    for (int i = 0; i <= max; ++i) {
        sum += arr[i];
        if (sum > cap) {
            return false;
        }
    }
    return true;
}

int main()
{
    // @formatter:off
    int arr[][3]= {{2,1,5},{3,3,7}}; // 4 false 5 true
    // int arr[][3]= {{2,2,6},{2,4,7},{8,6,7}};
    // int arr[][3]= {{9,3,4},{9,1,7},{4,2,4},{7,4,5}}; // 23 true
    // int arr[][3]= {{9,3,6},{8,1,7},{6,6,8},{8,4,9},{4,2,9}}; // 28 false
    
    int size=sizeof(arr)/sizeof(arr[0]);
    int* colsize=malloc(sizeof(int*)*size);
    int* trips[size];
    for (int i = 0; i < size; ++i){
        trips[i]=arr[i];
        colsize[i]=sizeof(arr[i])/sizeof(arr[i][0]);
    }
    int cap=28;
    bool b = carPooling(trips,size,colsize,cap);
    printf("%d \n",b);fflush(stdout);
    return 0;
    // @formatter:on
}