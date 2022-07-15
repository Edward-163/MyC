#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */

int main() {
    int val=16;
    char dstBuf[99];
//    char dstBuf[1];/// 故意缩短,奇怪的是到转10进制的时候才报错??
    int binaryRaidx=2;
    int octalRaidx=8;
    int decimal=10;
    int hexadecimal=16;
    // 10000 20 16 10
    /// 因为linux下stdlib(标准c,leet也是如此)没有itoa,所以建议学习sprintf兜底                  但是有atoi等
//    printf("%s \n",itoa(val,dstBuf,binaryRaidx) );fflush(stdout);
//    printf("%s \n",itoa(val,dstBuf,octalRaidx) );fflush(stdout);
//    printf("%s \n",itoa(val,dstBuf,decimal) );fflush(stdout);
//    printf("%s \n",itoa(val,dstBuf,hexadecimal) );fflush(stdout);
//    printf("%s \n",itoa(val,dstBuf,3) );fflush(stdout);/// 转成3进制也是对的

    sprintf(dstBuf,"%d",10);
    printf("%s \n",dstBuf );fflush(stdout);
    sprintf(dstBuf,"%d@%d",10,9);
    printf("%s \n",dstBuf );fflush(stdout);

    char test[]="hyj";
    /// stdlib.h 如果没有执行有效的转换，则返回零
    printf("%d \n", atoi(test));fflush(stdout);

    return 0;
}