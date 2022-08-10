#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。
如果方程没有解，请返回 "No solution" 。如果方程有无限解，则返回 “Infinite solutions” 。
题目保证，如果方程中只有一个解，则 'x' 的值是一个整数。
 */
int g_left;

void parse(char *split, int *a, int *b, int *g)
{
    int move = 0;
    int pre = 0;
    int len = strlen(split);
    char *tmp = malloc(sizeof(char) * (len + 1));
    while (!(move > len)) {
        // 首位正负号跳过
        if ((split[move] == '-' || split[move] == '+') && move == 0) {
            move++;
            continue;
        }
        // set a b
        if (split[move] == '-' || split[move] == '+' || move == len) {
            if (split[move - 1] == 'x') {
                if (move - 1 - pre >= 2) {
                    strncpy(tmp, split + pre, sizeof(char) * (move - 1 - pre));
                    int tmpnum = atoi(tmp);
                    *a += tmpnum;
                    pre = move;
                } else if (move - 1 - pre == 0) {
                    pre = move;
                    *a += 1;
                } else {
                    *a += (split[pre] == '+' ? 1 : -1);
                    pre = move;
                }
            } else {
                strncpy(tmp, split + pre, sizeof(char) * (move - pre));
                int tmpnum = atoi(tmp);
                *b += tmpnum;
                pre = move;
                break;
            }
        }

        move++; // step
    }
    if (*g == 0) {
        *a *= -1;
        *b = -1 * (*b); // try try
    }
    if (*g == 1) {
        *g = 0;
    }
}

char *solveEquation(char *equation)
{
    char *split = strtok(equation, "=");
    // ax=b
    int a;
    int b;
    g_left = 1;
    while (split != NULL) {
        parse(split, &a, &b, &g_left);
        split = strtok(NULL, "=");
    }

    if (a == 0) {
        if (b == 0) {
            char ans[] = "Infinite solutions";
            return ans;
        } else {
            char ans[] = "No solution";
            return ans;
        }
    }
    char ans[8];
    sprintf(ans, "x=%d", b / a);
    return ans;
}

int main()
{
    // @formatter:off
    char equation[] = "x+5-3+x=6+x-2";
    char *ans = solveEquation(equation);
    printf("%s \n",ans);fflush(stdout);
    return 0;
    // @formatter:on
}