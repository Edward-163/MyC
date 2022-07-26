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
    return *(int *) a - *(int *) b;
}

int cmp2(const void *a, const void *b)
{
    return *(char *) a - *(char *) b;
}

int cmp3(int **a, int **b)
{
    /// *优先级比[]低
    if ((*a)[1] == (*b)[1]) {
        return (*a)[2] - (*b)[2];
    }
    return (*a)[1] - (*b)[1];
}

int main()
{
    // @formatter:off
    int arr[]={9,6,3,4};
    int arrlen = sizeof(arr) / sizeof(arr[0]);
//    qsort(g_arr,3,sizeof(int),cmp);
//    for (int a = 0; a < arrlen; ++a){
//        printf("%d ",g_arr[a] );fflush(stdout);//3 6 9 4
//    }

    /// 测试从只排序634 测试结果是可以的
    int n=4321;
    char* buf=(char*)malloc(sizeof(char)*4);
    itoa(n,buf,10);
    printf("\n");fflush(stdout);
    qsort(buf+1,3,sizeof(char),cmp2);
    for (int a = 1; a < arrlen; ++a){
        printf("%d ",arr[a] );fflush(stdout);
    }

    int arr2[][3]= {{9,3,4},{9,1,7},{4,2,4},{7,4,5}};
    // int g_arr[][3]= {{9,3,6},{8,1,7},{6,6,8},{8,4,9},{4,2,9}};
    int size=sizeof(arr2)/sizeof(arr2[0]);
    int* trips[size];
    for (int i = 0; i < size; ++i){
        trips[i]=arr[i];
    }
    /// 二维数组的qsort额外注意每个元素的大小是sizeof(int*)
    qsort(trips, size, sizeof(int *), cmp3);
    for (int i = 0; i < size; ++i) {
        printf("%d_%d_%d\n", trips[i][0], trips[i][1], trips[i][2]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}