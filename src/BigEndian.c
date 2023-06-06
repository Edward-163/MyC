#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/***
    基础知识 32位 32位地址线
    无符号int ox12345678 int4字节,32位

    大字节序
    低地址(高位字节)     高地址
    int a = 0x 12 34 56 78 赋值给32位机器上的int a
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


void test()
{
    /// 小端环境,输入123 456 789
    char s[100] = {0x0};
    int i = 0;
    int c = 0xa1a2a3a4;
    scanf("%c", &c); // 字符对应的asic码(10进制)   '0'==48 'A'==65 'a'==97
    scanf("%d", &i);
    scanf("%s", s);
    printf("%c,%d,%s,0x%x\n", c, i, s, c);
}

int main()
{
    test();

    int i = 0x12345678;
    char c = (char) i;
    /// 指针变量存的是地址,那么就应该把i的地址赋值给p
    char *p = (char *) &i;
    /// 下面也侧面说明了,截断是直接舍去高位地址,保留低位地址
    printf("%x \n", c);
    fflush(stdout); // 打印12是大端,打印78是小端(本机)
    printf("%x \n", *p);
    fflush(stdout); // 打印12是大端,打印78是小端
    return 0;
}








































//答案D
