#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"

/*
 
 */

int main()
{
    // @formatter:off
    /**
     char * gets(char *str) 函数的功能是从输入缓冲区中读取"一行字符串"存储到字符指针变量 str 所指向的内存空间
     succ 返回buffer  fail返回null


     char * gets_s(char *str,size_t numOfElements)
     numberOfElements 缓冲区buffer的大小（包括'\0'）
     */
    char buffer[5];
    gets(buffer);
    printf("%s \n",buffer);fflush(stdout);

    char dest[99];
    if(gets_s(dest,sizeof(dest))==NULL){
        return -1;
    }
    printf("%s \n",dest);fflush(stdout);
    return 0;
    // @formatter:on
}
