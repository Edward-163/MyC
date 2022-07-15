#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */
int cmp(const void* a,const void* b){
    return *(int*)a-*(int*)b;
}
int cmp2(const void* a,const void* b){
    return *(char*)a-*(char*)b;
}
int main() {
    int arr[]={9,6,3,4};
    int arrlen = sizeof(arr) / sizeof(arr[0]);
//    qsort(arr,3,sizeof(int),cmp);
//    for (int a = 0; a < arrlen; ++a){
//        printf("%d ",arr[a] );fflush(stdout);//3 6 9 4
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
    return 0;
}