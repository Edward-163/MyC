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

/// java是把元素传进来比较,C语言是原数组传进来比较
int cmp3(int **a, int **b)
{
    /// *优先级比[]低    我觉得需要背一下:优先一级的4个 () [] -> .
    if ((*a)[1] == (*b)[1]) {
        return (*a)[2] - (*b)[2];
    }
    return (*a)[1] - (*b)[1];
}
/// L2418
int main()
{
    // @formatter:off
    int arr[]={9,6,3,4};
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    /**
     * 参1 指针,一维数组转指针还好说,二维数组转指针需要额外注意
     * 参2 被排序元素的个数
     * 参3 sizeof(被排序元素)
     * 参4 自定义cmp函数
     */
    qsort(arr,3,sizeof(int),cmp);
    for (int a = 0; a < arrlen; ++a){
       printf("%d ",arr[a] );fflush(stdout);//3 6 9 4
    }
    printf("\n------------\n");fflush(stdout);

    /// 测试从只排序634 测试结果是可以的
    int n=4321;
    char* buf=(char*)malloc(sizeof(char)*4);
    itoa(n,buf,10);
    printf("\n");fflush(stdout);
    qsort(buf+1,3,sizeof(char),cmp2);
    for (int a = 1; a < arrlen; ++a){
        printf("%d ",arr[a] );fflush(stdout);
    }

    printf("\n2D arr qsort---------");fflush(stdout);
    int arr2[][3]= {{4,2,6},{7,2,5},{9,1,8},{9,1,7}};
    // int g_arr[][3]= {{9,3,6},{8,1,7},{6,6,8},{8,4,9},{4,2,9}};
    int size=sizeof(arr2)/sizeof(arr2[0]);
    int* trips[size];
    for (int i = 0; i < size; ++i){
        trips[i] = arr2[i];
    }
    /// 二维数组的qsort额外注意每个元素的大小是sizeof(int*)
    qsort(trips, size, sizeof(int *), cmp3);
    for (int i = 0; i < size; ++i) {
        printf("%d_%d_%d\n", trips[i][0], trips[i][1], trips[i][2]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}
