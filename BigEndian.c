#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/***
    基础知识 32位 32位地址线
    无符号int ox12345678 int4字节,32位
    知识点:字节序
    低地址     高地址(存低位字节就是BigEndian,正常从左往右写,就是大端序,也称大字节序)
    ox 12 34 56 78

    // a.c
    const char VRCB[] = "V100R100C00B010";
    // b.c
    extern const char *VRCB;
    void print_version(void) {
        printf("%s\n", VRCB);//A原样输出 B输出V C乱码 D程序异常coreDump
    }

 */




int main() {

    return 0;
}








































//答案D