#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
// #include "uthash.h"
#include "securec.h"

/**
 符号拓展
 1. 有符号的数据类型，在向高精度扩展时，总是带符号扩展
 2. 无符号的数据类型，在向高精度扩展时，总是无符号扩展
 注意无符号拓展判定是根据变量类型,不是变量的正负数值
 */
void expand()
{
    short s=-1; // 0b 11111111
    unsigned int ui=3;
    unsigned int i = s%ui; // 0b 11111111 11111111 11111111 11111111
    printf("%u \n",UINT_MAX);fflush(stdout);
    unsigned int i1 = UINT_MAX%ui;
    printf("%u \n",i);fflush(stdout);
    printf("%s \n", i==i1?"true":"false");fflush(stdout);
}
int main()
{
    // @formatter:off

    expand();
    return 0;
    // @formatter:on
}
