#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"

/*
 
 */
int main()
{
    // @formatter:off
    // https://blog.csdn.net/qq_40244176/article/details/80765975  网友 倒序 倒着念
    const char * p1; // p1是一个指针,指向const char
    char const * p2; // 同上
    char * const p3; // p3是一个常量指针,指向char

    /// 由于没有 const *的运算，若出现 const * 的形式，则const实际上是修饰前面的 https://www.cnblogs.com/rushuizhijing/archive/2011/08/26/2154737.html
    const char ** p5; // p5是个二级指针,最终内容指向const char
    const char * const * p4; /// 这么绕嘛...我尝试去理解(先理解p5),还是按照倒序,p4是个(由后面可知是二级)指针,指向了另一个(被const修饰)指针B,指针B指向了const char
    (**p4)++; //
    (*p4)++;
    p4++;

    /**
以下关于 devid 描述正确的是（）
1.  typedef int DevId;
2.  typedef DevId* DevIdPtr;
3.  const DevIdPtr devid;
A、指向 const DevId 的指针，指针指向的内容不能被改变
B、指向 const DevId 的指针，指针本身不能被改变
C、指向 DevId 的 const 指针，指针本身不能被改变
D、指向 const DevId 的 const 指针，指针本身和指针指向的内容都不能被改变
答案：C
注意：typedef 和 #define 不能一概而论，typedef 不和 #define 一样直接进行字符替换
typedef DevId* DevIdPtr; 等价于 typedef int* DevIdPtr;
DevIdPtr 代表 int* 整体。(若它强调整体,我再去理解const (int*) devid==int* const devid )
const DevIdPtr devid; 等价于 const (int*) devid; 后者这种写法如果直接放到IDE里面会报错，不符合语法规范；const 无法去限定类型 (int*)，
而是跳过了类型 (int*) 实际上是限定的是变量 devid，即 const 限定的是 devid ，而 devid 的类型是 (int*)。
转换一下等效于 int* const devid; 又因为 typedef int DevId;
最后转换为 DevId* const devid; 对应最开始引用里面 2 的情况，也就是C选项的描述
     */

    return 0;
    // @formatter:on
}
