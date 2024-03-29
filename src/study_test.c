#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 
 */

void test02()
{
    unsigned int a = 6;
    int b = -20;
    int c = a + b;
    printf("a+b=%d \n", a + b);fflush(stdout);
    if (a + b > 0) {
        printf("大于 \n");fflush(stdout);
    } else {
        printf("小于\n");fflush(stdout);
    }
    if (c > 0) {
        printf("大于2\n");fflush(stdout);
    } else {
        printf("小于2\n");fflush(stdout);
    }
}

#pragma pack(2)
// #pragma pack(1)
struct s0 {
    char c1;
    char c2;
    int a;
};
struct s1 {
    char c1;
    int a;
    char c2;
};
struct s2 {
    char c1[5];
    int i;
    short s;
};
struct s3 {
    char c1[5]; // 假设从0x0000到0x0004地址全被占用,因为有int,按4字节对齐,留白3字节(地址0x0005开始)
    short s; // short从哪里开始分配??0x0005还是0x0006开始??因为short地址必须是2的倍数,所以从0x0006开始,留白1字节(地址0x0005)
    int i;
};

void test03()
{
    printf("s0大小是%d \n", sizeof(struct s0));fflush(stdout);
    printf("s1大小是%d \n", sizeof(struct s1));fflush(stdout);
    printf("s2大小是%d \n", sizeof(struct s2));fflush(stdout);
    printf("s3大小是%d \n", sizeof(struct s3));fflush(stdout);
}

void test04()
{
#pragma pack(8)
    struct A {
        short a;
        int b;
    };
    struct B {
        char e[2];
        int f;
        short g;
        struct A j;
        double i;
    };
    printf("B大小是%d \n", sizeof(struct B));fflush(stdout);
}

void test05()
{
#pragma pack(1) // 尽管字段有int,这里甚至可以强制指定按1字节对齐
    struct A {
        char z;
        int b; // 注释掉后面2字段,总占6字节,把int地址必须是4的倍数推翻了呀
        // short int a;
        // char d[3];
    };
    printf("B大小是%d \n", sizeof(struct A));fflush(stdout);
}

void test06()
{
    int i = 0;
    i = 1, 2, 3;
    printf("%d \n", i);fflush(stdout);
}

void test07()
{
    char *str="aa bbb cc";
    int i=0;
    int len=0;
    char c;
    /// 留意这个++ 正确答案7 10
    while ((c = str[i++]) != '\0') {
        if(c==' ')continue;
        len++;
    }
    printf("len: %d i: %d\n",len,i);fflush(stdout);
}

int main()
{
    // @formatter:off
    test07();
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
//    test06();
    return 0;
    // @formatter:on
}
