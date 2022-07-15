#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include <regex.h>

/*
lcs longest common subsequence
 */
#define MAX(a, b) (a)>(b)?(a):(b)

int longestCommonSubsequence(char *text1, char *text2) {
    /**
     动态规划也是有套路的：单个数组或者字符串要用动态规划时，可以把动态规划 dp[i] 定义为 nums[0:i] 中想要求的结果；当两个数组或者字符串要用
     动态规划时，可以把动态规划定义成两维的 dp[i][j] ，其含义是在A[0:i] 与 B[0:j] 之间匹配得到的想要的结果
     */

    int len1 = strlen(text1);//row
    int len2 = strlen(text2);//col
    // init dp
    int **dp = (int **) malloc(sizeof(int *) * len1);
    for (int a = 0; a < len1; a++) {
        dp[a] = (int *) malloc(sizeof(int) * len2);
        memset(dp[a], 0, sizeof(int) * len2);
    }
    // first row
    int flag = 0;
    for (int a = 0; a < len2; a++) {
        if (text2[a] == text1[0]) {
            flag++;
        }
        dp[0][a] = flag == 0 ? 0 : 1;
    }
    // first col
    flag = 0;
    for (int a = 0; a < len1; a++) {
        if (text1[a] == text2[0]) {
            flag++;
        }
        dp[a][0] = flag == 0 ? 0 : 1;
    }

    for (int a = 1; a < len1; a++) {
        for (int b = 1; b < len2; b++) {
            if (text1[a] == text2[b]) {
                dp[a][b] = 1 + dp[a - 1][b - 1];
            } else {
                dp[a][b] = MAX(dp[a - 1][b], dp[a][b - 1]);
            }
        }
    }
    return dp[len1 - 1][len2 - 1];
}

int main() {
    char text1[] = "abcde";
    char text2[] = "ace";
    int i = longestCommonSubsequence(text1, text2);
    printf("%d ", i);
    fflush(stdout);
    return 0;
}