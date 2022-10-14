#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/***
    基础知识 32位 32位地址线
    无符号int ox12345678 int4字节,32位

    知识点:字节序
    低地址     高地址
    优先介绍大字节序,如 ox 12 34 56 78 赋值给32位机器上的int a
    int a = 00000001 00000010 ...剩余6端省略
    转换成16进制表示
    int a = 0x 1 2 3 4 5 6 7 8
    也就是说低地址位 存放 高位数字


    小端序并不是直接倒叙!!!,16进制中,2位2位倒着来的.
    小端 1234 7856 -> 0x56 78 34 12
    小端 7856 1234 -> 0x34 12 56 78

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