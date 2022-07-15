#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
给定n个池子，每个池子有water[i]升水，现在只能每次给任意一个池子加1升水，求想要使得这n个池子中cnt个池子的水是一样多的情况时，浇水的最少次数？
 （计算过程数据如果超过1000000007时，需要对结果进行取模1000000007， 如结果为1000000008，最终得到 1000000008 mod 1000000007 = 1）
 */
#define VALID_RANGE 1000000007

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int minOperations(int *water, int waterSize, int cnt) {
    qsort(water, waterSize, sizeof(int), cmp);

    //presum的变种
    int res = VALID_RANGE;
    long presum = 0;
    for (int a = 0; a < waterSize; ++a) {
        // 0 1 2  cnt-1 cnt
        if (a >= cnt) {
            if (a - cnt >= 0)presum -= water[a - 1] - water[a - cnt];
            //整体"抬升"浇水
            presum += (cnt - 1) * (water[a] - water[a - 1]);
            if (presum % VALID_RANGE < res)res = presum % VALID_RANGE;
        } else {
            presum += water[cnt - 1] - water[a];
            if (a == cnt - 1) {
                if (presum % VALID_RANGE < res)res = presum % VALID_RANGE;
            }
        }
    }
    return res;
}

int main() {
    int water[] = {2, 2, 2, 3, 4};
    int waterSize = sizeof(water) / sizeof(water[0]);
    printf("%d", minOperations(water, waterSize, 3));
    return 0;
}

/*
int myMin(long a,long b){
    if(a>b)return (int)b;
    return (int)a;
}
int minOperations(int* water,int waterSize,int cnt){
    qsort(water,waterSize,sizeof(int),cmp);
    long sum=0;
    int res=VALID_RANGE-1;
    for (int a = 0; a < cnt; ++a) {
        sum+=water[cnt-1]-water[a];
    }
    res = myMin(res % VALID_RANGE, sum % VALID_RANGE);
    for (int a = 0; a < waterSize; ++a) {
        sum+=(cnt-1)*(water[a]-water[a-1])-(water[a-1]-water[a-cnt]);
        res= myMin(res,sum%VALID_RANGE);
    }
    return res;
}
 */