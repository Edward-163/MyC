#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 
 */

int main()
{
    // @formatter:off
    // int a[2][];
    int b[][3] = { {1,2,3}, {4,5,6}};
    int c[2][4] = {{1,2,3}, {4,5},{6}}; /// 我以为它是错的,实际是对的,会自动从{6}开始忽略掉
    int d[][3] = {{1,0,1},{0}, {1,1}};

    return 0; // 直接断点看吧
    // @formatter:on
}