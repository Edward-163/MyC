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
 题干：
    设计运动手环功能如下：
Pedometer(int target)——初始化每天（天从0开始）的目标步数为target。
setTarget(int date, int target)——重设每天的目标步数为target，次日生效，即从date + 1天起生效，但不会修改date及之前的目标步数；
    同一天多次重设目标步数，以最后一次为准；
record(int date, int steps)——在第data天记录新增steps运动步数，返回这一天已累计的步数；
    同一天可能已多次记录，步数进行累加返回；
getMaxCompleteDays(int date)——根据已有记录，返回截止date（含），达标的最长天数；（答案意思是连续达标的最长天数）
    达标：某天的累计步数大于等于当天的目标步数；
输入保证setTarget、record、getMaxCompleteDays、date参数按输入顺序递增
 * 示例1：
    输入：["Pedometer","record","getMaxCompleteDays","record","getMaxCompleteDays","setTarget","getMaxCompleteDays"]
             [[2000],[0,1000],[0],[0,1000],[0],[0,3000],[1]]
    输出：[null,1000,0,2000,1,null,1]

 * 示例2：
输入：
["Pedometer","record","record","record","setTarget",
 "record","record","record","record","getMaxCompleteDays",
 "setTarget" ,"record","setTarget","record","record","getMaxCompleteDays"]
[[1000],[13,600],[13,500],[20,600],[20,500],
 [20,700],[21,300],[22,700],[23,1200],[25],
 [30,4000],[30,1500],[30,2000], [31,2200],[32,3000],[32]]
输出：
 [null,600,1100,600,null,
 1300,300,700,1200,2,
 null,1500,null,2200,3000,3]
 * 提示
    2 <= setTarget, record, getMaxCompleteDays 累计操作数 <= 10^3
    1 <= target <= 10^5
    0 <= date <= 365
    1 <= steps <= 10^5
 */
#define DATE_MAX 365
int *g_target;
int *g_steps;

void Pedometer(int target)
{
    g_steps = (int *) malloc(sizeof(int) * DATE_MAX);
    memset(g_steps, 0, sizeof(int) * DATE_MAX);
    g_target = (int *) malloc(sizeof(int) * DATE_MAX);
    for (int i = 0; i < DATE_MAX; ++i) {
        g_target[i] = target;
    }
    printf("%s ", "null");
    fflush(stdout);
}

void setTarget(int date, int target)
{
    for (int i = date + 1; i < DATE_MAX; ++i) {
        g_target[i] = target;
    }
    printf("%s ", "null");
    fflush(stdout);
}

int record(int date, int steps)
{
    g_steps[date] += steps;
    return g_steps[date];
}

int getMaxCompleteDays(int date)
{
    int ans = 0;
    int sum = 0;
    for (int i = 0; i <= date; ++i) {
        if (g_steps[i] >= g_target[i]) {
            sum++;
            if (sum > ans) {
                ans = sum;
            }
        } else {
            sum = 0;
        }
    }
    return ans;
}

int main()
{
    Pedometer(2000);
    printf("%d ", record(0, 1000));fflush(stdout);
    printf("%d ", getMaxCompleteDays(0));fflush(stdout);
    printf("%d ", record(0, 1000));fflush(stdout);
    printf("%d ", getMaxCompleteDays(0));fflush(stdout);
    setTarget(0, 3000);
    printf("%d ", getMaxCompleteDays(1));fflush(stdout);

    printf("\n");fflush(stdout);
    Pedometer(1000);
    printf("%d ", record(13,600));fflush(stdout);
    printf("%d ", record(13,500));fflush(stdout);
    printf("%d ", record(20,600));fflush(stdout);
    setTarget(20,500);
    printf("\n");fflush(stdout);
    printf("%d ", record(20,700));fflush(stdout);
    printf("%d ", record(21,300));fflush(stdout);
    printf("%d ", record(22,700));fflush(stdout);
    printf("%d ", record(23,1200));fflush(stdout);
    printf("%d ", getMaxCompleteDays(25));fflush(stdout);
    printf("\n");fflush(stdout);
    setTarget(30,4000);
    printf("%d ", record(30,1500));fflush(stdout);
    setTarget(30,2000);
    printf("%d ", record(31,2200));fflush(stdout);
    printf("%d ", record(32,3000));fflush(stdout);
    printf("%d ", getMaxCompleteDays(32));fflush(stdout);

//    for (int i = 0; i <= 32; ++i){
//        printf("%d:%d ",i,g_target[i] );fflush(stdout);
//    }
//        printf("\n");fflush(stdout);
//    for (int i = 0; i <= 32; ++i){
//        printf("%d:%d ",i,g_steps[i] );fflush(stdout);
//    }

    return 0;
}