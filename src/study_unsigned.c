#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
// #include "uthash.h"
// #include "securec.h"

/*
 自动类型转换
 注意,a<b 也会触发自动类型转换
 */

int main()
{
    // @formatter:off
    unsigned int a=2;
    int b=1;
    int c=b-a;
    printf("%s \n", c<(unsigned int )b+a?"true":"false");fflush(stdout);
    printf("%s \n", c<(int)(b+a)?"true":"false");fflush(stdout);
    printf("%s \n", c<b+(int)a?"true":"false");fflush(stdout);
    printf("%s \n", c<(b+a)?"true":"false");fflush(stdout);
    return 0;
    // @formatter:on
}
