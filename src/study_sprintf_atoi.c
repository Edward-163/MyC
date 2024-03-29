#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "securec.h"

void ru_men()
{
    printf("%s \n","sprintf------------");fflush(stdout);
    /*
     sprintf(char* destBuf,const char* format,...) 把...数据按照format格式化后塞入destBuf中,注意: 会追加\0
     */
    char dstBuf[9];
    sprintf(dstBuf,"%d",12);
    printf("%s \n",dstBuf );fflush(stdout);
    sprintf(dstBuf,"%d@%d",10,9);
    printf("%s \n",dstBuf );fflush(stdout);
}
void secure(){
    printf("%s \n","sprintf_s------------");fflush(stdout);
    /*
     sprint_s(char* destBuf,size_t destMax,const char* format,...) 注意destMax包含\0
        succ返回写入字符数,
        fail返回-1
     */
    char dstBuf[9];
    /// snprintf_s新增参2:dstBufMax 参3变更,不包含结尾\0
    printf("写入字符数=%d \n",snprintf_s(dstBuf,sizeof(dstBuf),2,"%d",123));fflush(stdout);
    printf("destBuf=%s \n",dstBuf );fflush(stdout);

    /// 新增参2: 理论值为参1的字节大小,参2不能随便给个intMax,会造成缓冲区溢出       注意: 会追加\0
    printf("写入字符数=%d \n",sprintf_s(dstBuf,sizeof(dstBuf),"%d",123));fflush(stdout);
    printf("destBuf=%s \n",dstBuf );fflush(stdout);

    /// 参2:拷贝的字节数,如果格式化后的字符串长度大于等于 size，超过 size 的部分会被截断，只将其中的 (size-1) 个字符复制到 str 中，并给其后添加一个字符串结束符 \0，返回值为欲写入的字符串长度。
    printf("写入字符数=%d \n",snprintf(dstBuf,2,"%d",123));fflush(stdout);
    printf("destBuf=%s \n",dstBuf );fflush(stdout);

}
int main()
{
    // @formatter:off
    ru_men();
    secure();

    /// 首字母不是数组会直接返0  实践证明:"尽可能多地"解析出数字,一旦出现非数字字符就中断解析
    int i = atoi("a50asdfasdfasd9");
    printf("%d \n",i);fflush(stdout);
    /// 因为linux下stdlib(标准c,leet也是如此)没有itoa,所以建议学习sprintf兜底                  但是有atoi等
//    char dstBuf[1];/// 故意缩短,奇怪的是到转10进制的时候才报错??
//     int binaryRaidx=2;
//     int octalRaidx=8;
//     int decimal=10;
//     int hexadecimal=16;
    // 10000 20 16 10
//    printf("%s \n",itoa(val,dstBuf,binaryRaidx) );fflush(stdout);
//    printf("%s \n",itoa(val,dstBuf,octalRaidx) );fflush(stdout);
//    printf("%s \n",itoa(val,dstBuf,decimal) );fflush(stdout);
//    printf("%s \n",itoa(val,dstBuf,hexadecimal) );fflush(stdout);
//    printf("%s \n",itoa(val,dstBuf,3) );fflush(stdout);/// 转成3进制也是对的
    return 0;
    // @formatter:off
}
