#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 
 */
#define T1 int*
typedef int* T2;

int main()
{
    // @formatter:off
    T1 a,b;
    T2 c,d;
    printf("%d %d %d %d \n",sizeof(a),sizeof(b),sizeof(c),sizeof(d));fflush(stdout);
    return 0;
    /**
     宏仅仅就是替换
     int *a,b; // 一个int*,一个int
     int *c,*d; // 两个int*
     */
    // @formatter:on
}