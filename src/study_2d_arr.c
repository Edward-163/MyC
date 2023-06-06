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
    // char pc[] = "abcd";
    // char pc2[] = 'abcd'; /// 注意 单引号 会报错

    // int a[2][];
    int b[][3] = { {1,2,3}, {4,5,6}};
    /// 我以为它是错的,实际是对的,会自动从{6}开始忽略掉,不完全初始化补齐的元素值为0
    int c[2][4] = {{1,2,3}, {4,5},{6}};
    int d[][3] = {{1,0,1},{0}, {1,1}};

    int e[][2]={1,2,3,4};
    printf("\n");fflush(stdout);
    int f[2][2]={{1},2,3};
    printf("%d \n");fflush(stdout);

    // int g[][3]={0}{1,2}{1,2,3};

    return 0; // 直接断点看吧
    // @formatter:on
}
