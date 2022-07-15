#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 1.       问题描述：
给出一个m*n的格子，每个各自有一定数量的豆子，现在要求小熊从左下角出发，每次走一格并拿走那一格的所有豆子，且每次只能向上或向右前进，最终到达右上角，要求求出小熊最多吃到多少豆子。
输入：
第一行有两个数值m, n（2 <= m+n <=24）；
然后是m行n列数值（非负整数，不大于1000）
输出：
能吃到的最多的豆子。
例:
输入：
2 3
1 2 3
4 5 6
输出：
18
 */
int main() {

    return 0;
}































/*
#include<stdio.h>
#define MAX 24
void main() {
	//获取矩阵大小，m行n列
	int m, n;
	scanf_s("%d %d", &m, &n);
	int pea[MAX][MAX] = { 0 };
	//获取矩阵的值
	int dp[MAX][MAX] = { 0 };
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &pea[i][j]);
		}
	}
	//左下角值确定
	dp[m - 1][0] = pea[m - 1][0];
	//计算第一列
	for (int i = m - 2; i >= 0; i--) {
		dp[i][0] = dp[i - 1][0] + pea[i][0];
	}
	//计算最后一行
	for (int i = 1; i < n; i++) {
		dp[m - 1][i] = dp[m - 1][i - 1] + pea[m - 1][i];
	}
	//计算其他位置
	for (int i = 1; i < n; i++) {
		for (int j = m - 2; j >= 0; j--) {
			dp[j][i] = (dp[j+1][i]>dp[j][i-1]?dp[j+1][i]:dp[j][i-1]) + pea[j][i];
		}
	}
	printf("%d\n", dp[0][n-1]);
	system("pause");
}
 */