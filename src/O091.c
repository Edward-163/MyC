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
 剑指 Offer II 091. 粉刷房子
假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。
当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x 3 的正整数矩阵 costs
 来表示的。
例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。
请计算出粉刷完所有房子最少的花费成本。

示例 1：
输入: costs = [[17,2,17],[16,16,5],[14,3,19]]
输出: 10
解释: 将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色。
     最少花费: 2 + 5 + 3 = 10。
示例 2：
输入: costs = [[7,6,2]]
输出: 2
 */
#define MAX_COST 21
#define MAX 2001
int g_ans;

void Fn(int **costs, int costsSize, int *costsColSize, int curIdx, int preHousePickIdx, int sum) {
    if (curIdx > costsSize - 1) {
        if (sum < g_ans) {
            g_ans = sum;
        }
        return;
    }
    /// bug 都想抽自己,当时脑子短路了??
//    for (int a = 0; a < costsColSize[curIdx] && a != preHousePickIdx; a++) {
    for (int a = 0; a < costsColSize[curIdx]; a++) {
        // cut
        if (a == preHousePickIdx || sum + costs[curIdx][a] >= g_ans) {
            continue;
        }
        Fn(costs, costsSize, costsColSize, curIdx + 1, a, sum + costs[curIdx][a]);
    }
}

int minCost(int **costs, int costsSize, int *costsColSize) {
    g_ans = MAX;
    Fn(costs, costsSize, costsColSize, 0, -1, 0);
    return g_ans;
}

int main() {
    int arr[][3] = {{17, 2,  17},
                    {16, 16, 5},
                    {14, 3,  19}};
    int costsSize = sizeof(arr) / sizeof(arr[0]);
    int *costColSize = (int *) malloc(sizeof(int) * costsSize);
    int *costs[3];
    for (int i = 0; i < costsSize; ++i) {
        costs[i] = arr[i];
        costColSize[i] = sizeof(arr[i]) / sizeof(arr[i][0]);
    }
    int cost = minCost(costs, costsSize, costColSize);
    printf("%d \n", cost);
    fflush(stdout);
    return 0;
}




















/*

int minCost(int **costs, int costsSize, int *costsColSize)
{
    // dp
    int min = MAX_COST;
    int preHousePickidx;
    for (int i = 0; i < costsColSize[0]; ++i) {
        if (costs[0][i] < min) {
            min = costs[0][i];
            preHousePickidx = i;
        }
    }

    if (costsSize <= 0) {
        return 0;
    }
    int *dp = (int *) malloc(sizeof(int) * costsSize);
    dp[0] = min;
    for (int a = 1; a < costsSize; a++) {
        int min = MAX_COST;
        for (int b = 0; b < costsColSize[a] && b != preHousePickidx; b++) {
            if (costs[a][b] < min) {
                min = costs[a][b];
                preHousePickidx = b;
            }
        }
        /// bug状态转移写错了,不是这么简单的,谁说第一个房子一定要最便宜的?,如a+b,求最小,不一定是a最小
        dp[a] = dp[a - 1] + min;
    }

    return dp[costsSize - 1];
}
 */