#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
自己定义
 <=stack 代表非严格增栈
 <stack       严格

 */
int maxProfit(int *prices, int pricesSize) {
    int *stack = malloc(sizeof(int) * pricesSize); // >= stack
    int slen = 0;

    int ans = 0;
    for (int a = 0; a < pricesSize; a++) {
        if (slen == 0) {
            stack[slen++] = prices[a];
        } else {
            if (prices[a] >= stack[slen - 1]) {
                stack[slen++] = prices[a];
            } else {
                ans += stack[slen - 1] - stack[0];
                slen = 0;
                stack[slen++] = prices[a];
            }
        }
    }
    if (slen != 0) {
        ans += stack[slen - 1] - stack[0];
    }
    return ans;
}

int main() {
    // @formatter:off
    int pri[]={7,1,5,3,6,4};
    int size=sizeof(pri)/sizeof(pri[0]);
    int i = maxProfit(pri,size);
    printf("%d \n", i);fflush(stdout);
    return 0;
    // @formatter:on
}