#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/**
 __attribute__是gcc提供的拓展语法
 __attribute__((aligned(n)))        n字节对齐
 __attribute__((packed))            1字节对齐
 */
struct S {
    char a;
    int b;
}__attribute__((aligned(4)));

int main()
{
    // @formatter:off
    struct S* s0 = malloc(sizeof(struct S));
    printf("%d \n",sizeof(s0));fflush(stdout);
    return 0;
    // @formatter:on
}
