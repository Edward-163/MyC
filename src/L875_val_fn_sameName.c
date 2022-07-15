#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/**
  题翻译:在<=h的时间内以k的速度吃光数组,以>h的时间才能吃光数组是绝对不行的.
 从第一次解答来看,压根没往二分上去想,只是单纯暴力求解
 */
int diff(int elval, int divided) {
    int res = elval / divided;
    if (elval % divided != 0)res++;
    return res - 1;
}

int minEatingSpeed(int *piles, int pilesSize, int h) {
    int min = 1;
    int max = piles[0];
    for (int a = 1; a < pilesSize; a++) {
        if (piles[a] > max) {
            max = piles[a];
        }
    }

    int difftotal = h - pilesSize;
    int mid;
    int sum;
    do {
        sum = 0;
        mid = (min + max) / 2;
        for (int a = 0; a < pilesSize; a++) {
            sum += diff(piles[a], mid);
        }
        // 耗时太多,吃的太慢,k太小,绝对不行
        if (sum > difftotal) {
            min = mid;
        } else {
            //耗时刚好or太少,吃得刚好or太快,k刚好or太大,可以是可以,尝试降低k
            max = mid;
        }
    } while (min + 1 != max);//总会有2个相邻的min(太慢)和max(刚好or太快),

    /// bug没有考虑min不全是>,min也可以<=
    int sum2 = 0;
    for (int a = 0; a < pilesSize; a++) {
        sum2 += diff(piles[a], min);
    }
    if (sum2 <= difftotal) {
        return min;
    } else {
        return max;
    }
}

int main() {
//    int piles[]={3,6,7,11};
    int piles[] = {30, 11, 23, 4, 20};
    int pilesSize = sizeof(piles) / sizeof(piles[0]);
    int h = 6;
    printf("%d\n", minEatingSpeed(piles, pilesSize, h));
    return 0;
}


/*

int diff(int elval,int devide){
    int res=elval/devide;
    if(elval%devide!=0)res++;
    return res-1;
}
int cmp(const void*a,const void *b){
    return *(int*)a-*(int*)b;
}
int minEatingSpeed(int* piles, int pilesSize, int h){
    qsort(piles,pilesSize,sizeof(int),cmp);

    /// bug c语言中,同域(文件?)下变量和函数不能同名,不同域可以
    int difftotal=h-pilesSize;
    /// bug 我想当与从len-2开始向左,只有一个元素的情况我没有考虑,
    int n=1;
    int sum=0;
    bool flag = true;
    do{
        n++;
        for(int a=pilesSize-n;a<pilesSize;a++){
            sum+=diff(piles[a],piles[pilesSize-n]);
        }
        if(sum<difftotal){
            sum=0;
        }else{
            /// bug我是期望找到sum>=diff的,但sum>diff这种情况可能遍历玩数组也没找到
            flag=false;
        }
    }while(flag);

    int left=piles[pilesSize-n];
    int sum2=0;
    bool flag2=true;
    do{
        for(int a=0;a<pilesSize;a++){
            sum2+=diff(piles[a],left);
        }
        if(sum2==difftotal){
            break;
        } else{
            left++;
            sum2=0;
            /// bug flag用错了
            //flag2=true;
        }
    }while(flag2);

    return left;
}
 */