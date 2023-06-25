#include <stdlib.h>
#include <stdio.h>

/**
 --------------static知识点
http://c.biancheng.net/view/301.html
1 隐藏
      全局变量虽然属于静态存储方式，但并不是静态变量。全局变量的作用域是整个源程序，当一个源程序由多个源文件组成时，全局变量在各个源文件中都是有效的。
static全局变量仅限于本源文件中使用，在其他源文件中不能引用，也就是说限制其作用域只在定义该变量的源文件内有效，而在同一源程序的其他源文件中不能使用。
2 保持变量内容的持久性
有时候，我们希望函数中局部变量的值在函数调用结束之后不会消失，而仍然保留其原值。即它所占用的存储单元不释放，在下一次调用该函数时，其局部变量的值仍然存在，也就是上一次函数调用结束时的值。
例:static局部变量,在函数内只会赋值一次
3 默认初始化为 0
在静态数据区，内存中所有的字节默认值都是 0x00。静态变量与全局变量也一样，它们都存储在静态数据区中，因此其变量的值默认也为 0。

 4. static函数  internal linkage??
 https://blog.csdn.net/qq_53283658/article/details/122031321
 修饰函数时，与修饰全局变量类似，不仅具有修饰局部变量的性质，但没有了外部链接，只有内部链接，只能在被定义的源文件中被调用

虽然结构体的成员名和变量名不在同一命名空间中，但枚举(编译阶段处理)的成员名却和变量名在同一命名空间中，所以会出现命名冲突。     c编程一站式
 */
int g_golbalvalue1 = 0x5a5a;    /* 已经初始化的全局变量,存放在data段*/
int g_golbalvalue2 = 0;         /* 初始化为零全局变量,存放在bss段*/
int g_golbalvalue3;             /* 未初始化的全局变量,存放在bss段*/
static s_golbalvalue1 = 0x5a5a; /* 已经初始化的静态全局变量,存放在data段*/
static s_golbalvalue2 = 0;      /* 初始化为零的静态全局变量,存放在bss段*/
static s_golbalvalue3;          /* 未初始化的静态全局变量,存放在bss段*/
int main(void)
{
    static int value_slocal_1 = 12345678; /* 已经初始化的静态局部变量,存放在data段*/
    static int value_slocal_2 = 0;        /* 初始化位0的静态局部变量,存放在bss段*/
    static int value_slocal_3;            /*未初始化的静态局部变量,存放在bss段*/
    printf("%d \n",s_golbalvalue3);fflush(stdout);
    char *p = "WelCome to Confence"; /*p为栈数据,存放在栈中,p指向的内容为字符串常量区，存放在字符常量区*/
    char *buf = malloc(100); /* buf为栈数据，存放在栈中，但buf申请的空间为堆数据*/
    printf("addr global value1_Init_None_Zero=0x%llx\n", &g_golbalvalue1);
    printf("addr global value2_Init_Zero=0x%llx\n", &g_golbalvalue2);
    printf("addr global value3_NotInit=0x%llx\n", &g_golbalvalue3);
    printf("addr static value1_Init_None_Zero=0x%llx\n", &s_golbalvalue1);
    printf("addr static value2_Init_Zero=0x%llx\n", &s_golbalvalue2);
    printf("addr static value3_NotInit=0x%llx\n", &s_golbalvalue3);
    printf("addr static local value1_Init_None_Zero=0x%llx\n", &value_slocal_1);
    printf("addr static local value2_Init_Zero=0x%llx\n", &value_slocal_2);
    printf("addr static local value3_NotInit=0x%llx\n", &value_slocal_3);
    printf("addr strack = 0x%llx\n", &p);
    printf("addr const string=0x%llx\n", p);
    printf("addr buf=0x%llx\n", &buf);
    printf("addr Heap=0x%llx\n", buf);
    printf("addr text=0x%llx\n", main);
    return 0;
}
