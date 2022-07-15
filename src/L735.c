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
#define ABS(a) (a>0?a:-a)
int* asteroidCollision(int* asteroids, int size, int* returnSize){
    int* stack=malloc(sizeof(int)*size); // desc stack 所有负数当-1,所有正数当1
    int slen=0;
    for(int a=0;a<size;a++){
        // 栈空时不管数字正负,直接压栈,正数也是直接压栈,
        if(slen==0 || asteroids[a]>0){
            stack[slen++]=asteroids[a];
            continue;
        }
        // 只有当负数压栈前才可能要弹栈
        int top=stack[slen-1];
        while(slen-1>=0 && top>0 && ABS(asteroids[a])>ABS(top)){
            slen--;
            /// bug slen已经为0,下面越界
            if(slen>0){
                top=stack[slen-1];
            }
        }
        /// bug 没考虑清楚,其实可以对上面while取反
        if(slen==0 || top<0){
            stack[slen++]=asteroids[a];
        }else if(asteroids[a]==-top){
            slen--; // 同归于尽
        }
    }
    *returnSize=slen;
    return stack;
}
int main()
{
    // @formatter:off
    int arr[]={10,2,-5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int returnSize=0;
    int *stack = asteroidCollision(arr,size,&returnSize);
    for (int i = 0; i < returnSize; ++i){
        printf("%d ",stack[i]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}