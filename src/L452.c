/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*
 
 */
int cmp(const void *a, const void *b)
{
    /// bug 习惯性用相减,但极限下,-21亿-21亿,溢出了
    //    return (*(int **) a)[1] - (*(int **) b)[1];
    return (*(int **) a)[1] < (*(int **) b)[1] ? -1 : 1;
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize)
{
    qsort(points, pointsSize, sizeof(int *), cmp);
    int left = 0;
    int right = 1;
    int ans = 1;
    while (right <= pointsSize - 1) {
        if (points[right][0] <= points[left][1]) {
            right++;
        } else {
            ans++;
            left = right;
            right = left + 1;
        }
    }
    return ans;
}

int main()
{
    // @formatter:off
    int arr[][2]={{1,2},{2,3},{3,4},{4,5}};
//    int g_arr[][2]={{1,2},{3,4},{5,6},{7,8}};
    int size=sizeof(arr)/sizeof(arr[0]);
    int* points[size];
    for (int i = 0; i < size; ++i){
        points[i]=arr[i];
    }
    int ans = findMinArrowShots(points,size,NULL);
    printf("%d \n",ans );fflush(stdout);
    return 0;
    // @formatter:on
}