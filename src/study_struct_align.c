#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
结构体对齐
结构体的第一个成员总是存储在结构体变量开辟的空间的起始地址。
其它成员变量要存储在一个名叫对齐数的整数倍的地址。
 https://blog.csdn.net/weixin_54076783/article/details/126694593
注意:字节对齐和编译器有关,甚至可以设置2,4,8,16,如vs默认8字节对齐,但这个设置好像不起作用,有int还是按照4字节来??涉及实际对齐字节
有指定按指定,不指定按下面算出来??
    预编译指令#pragma pack(n)手动设置     n取1 2 4 8 16


成员顺序排列,因为成员要按字节对齐,所以中间可能留有空白,顺序会影响结构体大小
short地址通常是2的倍数
int地址通常是4的倍数        // 被推翻掉了呀,#pragma pack(1)这种紧凑排列,它才不管int地址是不是4的倍数,似乎指定对齐就可以忽略"倍数规则"
double地址通常是8的倍数
终极大招:预定义#pragma pack(n) 来强制修改编译器字节对齐

结构体A应从offset为A内部最大成员的整数倍的地方开始存储
结构体嵌套有点绕!!
 */
/// 以下n代表内存补齐填充空格
// #pragma pack(2)
// #pragma pack(1)
struct s00 {
    int i; 
    char c[]; /// 不确定长度的数组一定要在结构体最后,放前面会报错,且sizeof计算时不会计算c的大小
};
struct s0 {
    /*
     c c n n
     i i i i
     */
    char c1;
    char c2;
    int i; /// 按4对齐 (1+1+2,4)
};
struct s1 {
    /*
     c n n n
     i i i i
     c n n n
     */
    char c1;
    int i; /// 按4对齐 (1+3,4,1+3)
    char c2;
};
struct s2 {
    /*
     i i i i
     s s c c
     c c c n
     */
    int i;
    short s;
    char c1[5]; /// 实践证明,char[5] char[8]对齐单位还是1,只不过实际大小才和5,8相关,例:这里随便加个int,就按4对齐
};
struct s3 {
    /*
     c c c c
     c n s s
     i i i i
     */
    char c1[5]; // 假设从0x0000到0x0004地址全被占用,因为有int,按4字节对齐,留白3字节(地址0x0005开始)
    short s; // short从哪里开始分配??0x0005还是0x0006开始??因为short地址必须是2的倍数,所以从0x0006开始,留白1字节(地址0x0005)
    int i;
};
struct s16{
    // double d;
    // char c;
    int i;
    int i2;
    int i3;
    int i4;
};
struct ss{
    char c;
    struct s16 s; /// 如果s16按8对齐,ss里面的成员最大只能按4对齐,最终按8对齐,如果s16按4对齐,ss里面的成员最大只能按4对齐,最终按4对齐
    int i;
};

void sizeof_struct()
{
    printf("s00大小是%d \n", sizeof(struct s0));fflush(stdout);
    printf("s0大小是%d \n", sizeof(struct s0));fflush(stdout);
    printf("s1大小是%d \n", sizeof(struct s1));fflush(stdout);
    printf("s2大小是%d \n", sizeof(struct s2));fflush(stdout);
    printf("s3大小是%d \n", sizeof(struct s3));fflush(stdout);
    printf("s16=%d \n",sizeof(struct s16));fflush(stdout);
    printf("ss=%d \n",sizeof(struct ss));fflush(stdout);
}

void struct_nest()
{
#pragma pack(8)
    struct A {
        /*
         ss ss n  n  n n n n
         ii ii ii ii n n n n
         */
        short ss;
        int ii;
    };
    struct B {
        /*
         c c i i i i s s
         A
         d d d d d d d d 
         */
        char c[2];
        int i; /// 指定8对齐 (1*2+4+2,8+8,8) 这里的int也是直接跟随在char数组后面,这里int地址就不是4的倍数
        short s;
        struct A aa;
        double d;
    };
    printf("B大小是%d \n", sizeof(struct B));fflush(stdout);
}
/**
 pragma 美 [p'ræɡmə] 英 [p'ræɡmə]
n.〔计〕杂注
网络编译指示；显示编译指示；特殊指令
 */
void pragma_pack1()
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
void IsPadding(){
    #pragma pack(4)
    typedef struct {
        short s;
        char c[6]; // 我错误认为会新起一行,4字节,然后下一行2字节,实际2个字节直接跟在s后面
        int i;
    }Abc;
    printf("IsPadding: %d \n",sizeof(Abc));fflush(stdout);
}
int main()
{
    // @formatter:off
    IsPadding();
    sizeof_struct();
    struct_nest();
    pragma_pack1();
    return 0;
    // @formatter:on
}
