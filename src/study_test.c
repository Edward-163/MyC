#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 
 */
void test01(){
    int i=-1;
    // int i=3;
    for(;i<sizeof(int);i++){
        printf("%d \n",i);fflush(stdout);
    }
}
void test02(){
    unsigned int a=6;
    int b=-20;
    int c=a+b;
    printf("a+b=%d \n",a+b);fflush(stdout);
    if(a+b>0){
        printf("大于 \n");fflush(stdout);
    } else{
        printf("小于\n");fflush(stdout);
    }
    if(c>0){
        printf("大于2\n");fflush(stdout);
    } else{
        printf("小于2\n");fflush(stdout);
    }
}
#pragma pack(1)
struct s0{
    char c1;
    char c2;
    int a;
};
struct s1{
    char c1;
    int a;
    char c2;
};
struct s2{
    char c1[5];
    int i;
    short s;
};
struct s3{
    char c1[5]; // 假设从0x0000到0x0004地址全被占用,因为有int,按4字节对齐,留白3字节(地址0x0005开始)
    short s; // short从哪里开始分配??0x0005还是0x0006开始??因为short地址必须是2的倍数,所以从0x0006开始,留白1字节(地址0x0005)
    int i;
};
void test03(){
    printf("s0大小是%d \n",sizeof(struct s0));fflush(stdout);
    printf("s1大小是%d \n",sizeof(struct s1));fflush(stdout);
    printf("s2大小是%d \n",sizeof(struct s2));fflush(stdout);
    printf("s3大小是%d \n",sizeof(struct s3));fflush(stdout);
}
void test04(){
    #pragma pack(8)
    struct A {
        short a;
        int b;
    };
    struct B{
        char e[2];
        int f;
        short g;
        struct A j;
        double i;
    };
    printf("B大小是%d \n",sizeof(struct B));fflush(stdout);
}
int main()
{
    // @formatter:off
    // test01();
    // test02();
    // test03();
    test04();
    return 0;
    // @formatter:on
}