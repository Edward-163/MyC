#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "securec.h"

/**
A、发生了写越界，程序输出hello wrold!
B、sizeof(“hello world!”)得到的是指针的大小，在32位系统上打印会被截断
C、没有发生写越界，程序正常运行
D、发生写越界，程序可能发生异常也可能不会发生异常
*/
int main()
{
    // @formatter:off
    char array[5] = {0};
    // memcpy(array, "hello", 6*sizeof(char)); // 应该写12个字节,但参3==13,所以多写了字节,写越界了
    // printf("%s\n", array);
    /**
     * dest
     * destMax  目睹缓冲区总大小
     * src
     * cnt      cnt<=destMax 从src中赋值的字节数 字节数 字节数
     * 注意dest src不可重叠
     * 成功返EOK 错误返错误码
     */
    printf("%d \n",sizeof(array));fflush(stdout);
    printf("%d \n",sizeof("hello"));fflush(stdout); // 6
    if(memcpy_s(array,sizeof(array),"hello",sizeof("hello"))!=EOK){
        return -1; // 报错162,安全函数说明文档中解释162就是cnt>destMax
    }
    int dest[1];
    int src[2]={2,3};
    if(memcpy_s(dest,sizeof(dest),src+1,1*sizeof(int))!=EOK){
        return -1;
    }
    printf("%d \n",dest[0]);fflush(stdout);
    return 0;
    // @formatter:on
}








// bc
