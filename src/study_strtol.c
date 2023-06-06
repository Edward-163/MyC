#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
// #include "uthash.h"
// #include "securec.h"

/*
 long int strtol(char * str,char ** enptr,int base)
    str是要转换的字符
    enptr是指向第一个不可转换的字符位置的指针
    base的基数，表示转换成为几进制的数

    参数base的范围为2~36,和0；它决定了字符串以被转换为整数的进制数。
    可以被转换的合法字符依据base而定，举例来说，当base为2时，合法字符为‘0’，‘1’；base为8时，合法字符为‘0’，‘1’，……‘7’；base为10时，合法字符为‘0’，‘1’，……‘9’；
    base 为16时，合法字符为‘0’，‘1’，……‘9’，‘a’，……‘f’；base为24时，合法字符为‘0’，……‘9’，‘a’，……‘n’，base为36时，合法字符为‘0’，……‘9’，‘a’，……‘z’；等等。其中，不区分大小写
 */

int main()
{
    // @formatter:off
    char arr[99]="41FF";
    long i = strtol(arr,NULL,16);
    printf("%d \n",i);fflush(stdout);
    return 0;
    // @formatter:on
}
