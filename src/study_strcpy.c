// #include <string.h>
#include <stdio.h>
#include "securec.h"

/*
 
 */

int main()
{
    // @formatter:off
    char dest[99];


    /// strcnpy的参3 count    不像strcpy()，strncpy()不会向dest追加结束标记\0
    // char destSix[6]="123456";
    char destSix[6];
    char src0[] = "hello";
    printf("%s\n", strncpy(destSix,"hello",5));fflush(stdout);

    /**
     char* strcpy(char* dest,const char* src)
     测试标明返回的char*是dest
     */
    /// 要灵活,并不一定都是从指针头部开始cpy
    // printf("%s\n ", strcpy(dest,src+1));fflush(stdout); // dward
    // printf("%s\n ", strcpy(dest,src+2));fflush(stdout); // ward

    // edwar edward edward
    char src[] = "a b cd\0efg\0";
    printf("虽然src自带两个\\0,但是末尾的时候还是会被添加\\0 %d \n",sizeof(src));fflush(stdout);
    printf("%s\n", strncpy(dest,src,4));fflush(stdout); //
    printf("%s\n", strncpy(dest,src,5));fflush(stdout);
    printf("%s\n", strncpy(dest,src,6));fflush(stdout);
    printf("%s\n", strncpy(dest,src,7));fflush(stdout);

    /**
     errorno_t strcpy_s(char* dest,size_t destMaxBytes,const char* src)
     返回成功与否的状态,    参2 Dest目标缓冲区字节大小,注意: 包括\0
     */
    strcpy_s(dest,sizeof(dest),src);
    printf("strcpy_s: %s\n", dest);fflush(stdout);
    /**
     * errorno_t strcpy_s(char* dest,size_t destMaxBytes,const char* src, size_t n)
     * n 从src缓冲区中复制的字符数,注意: 不包括\0
     */
    // int n=999;
    int n=4;
    strncpy_s(dest,sizeof(dest),src,n);
    printf("strncpy_s: %s\n", dest);fflush(stdout);

    return 0;
    // @formatter:on
}
