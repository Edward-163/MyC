#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"

/**
声明定义 声明 定义(声明==仅命名 定义==分配空间,赋值==把值存入空间,初始化==定义+赋值  by linux c 编程一站式)
C语言中的声明(declaration)和定义(definition)是两个容易混淆的概念。
声明只是给变量、函数、结构体、联合体命名，表明程序有该变量、函数、结构体、联合体。
定义是具体给变量分配存储空间、给出函数的具体实现、指明结构体和联合体成员。
声明可以出现多次，定义有且只能出现一次。
定义必须有，且只能出现一次。
https://zhuanlan.zhihu.com/p/162578969#:~:text=C%E8%AF%AD%E8%A8%80%E4%B8%AD%E7%9A%84%E5%A3%B0%E6%98%8E%20%28declaration%29%E5%92%8C%E5%AE%9A%E4%B9%89%20%28definition%29%E6%98%AF%E4%B8%A4%E4%B8%AA%E5%AE%B9%E6%98%93%E6%B7%B7%E6%B7%86%E7%9A%84%E6%A6%82%E5%BF%B5%E3%80%82,%E5%A3%B0%E6%98%8E%E5%8F%AA%E6%98%AF%E7%BB%99%E5%8F%98%E9%87%8F%E3%80%81%E5%87%BD%E6%95%B0%E3%80%81%E7%BB%93%E6%9E%84%E4%BD%93%E3%80%81%E8%81%94%E5%90%88%E4%BD%93%E5%91%BD%E5%90%8D%EF%BC%8C%E8%A1%A8%E6%98%8E%E7%A8%8B%E5%BA%8F%E6%9C%89%E8%AF%A5%E5%8F%98%E9%87%8F%E3%80%81%E5%87%BD%E6%95%B0%E3%80%81%E7%BB%93%E6%9E%84%E4%BD%93%E3%80%81%E8%81%94%E5%90%88%E4%BD%93%E3%80%82%20%E5%AE%9A%E4%B9%89%E6%98%AF%E5%85%B7%E4%BD%93%E7%BB%99%E5%8F%98%E9%87%8F%E5%88%86%E9%85%8D%E5%AD%98%E5%82%A8%E7%A9%BA%E9%97%B4%E3%80%81%E7%BB%99%E5%87%BA%E5%87%BD%E6%95%B0%E7%9A%84%E5%85%B7%E4%BD%93%E5%AE%9E%E7%8E%B0%E3%80%81%E6%8C%87%E6%98%8E%E7%BB%93%E6%9E%84%E4%BD%93%E5%92%8C%E8%81%94%E5%90%88%E4%BD%93%E6%88%90%E5%91%98%E3%80%82%20%E7%AE%80%E5%8D%95%E7%90%86%E8%A7%A3%EF%BC%9A%E5%A6%82%E6%9E%9C%E7%A8%8B%E5%BA%8F%E4%B8%AD%E4%BB%85%E4%BB%85%E6%9C%89%E5%A3%B0%E6%98%8E%EF%BC%8C%E7%BC%BA%E5%B0%91%E5%AE%9A%E4%B9%89%E5%AE%9E%E7%8E%B0%EF%BC%8C%E6%9C%80%E7%BB%88%E6%97%A0%E6%B3%95%E7%94%9F%E6%88%90%E5%8F%AF%E6%89%A7%E8%A1%8C%E7%9A%84%E7%A8%8B%E5%BA%8F%EF%BC%8C%E5%9B%A0%E4%B8%BA%E4%BF%A1%E6%81%AF%E4%B8%8D%E5%AE%8C%E6%95%B4%EF%BC%8C%E6%97%A0%E6%B3%95%E5%AE%8C%E6%88%90%E7%BC%96%E8%AF%91%E5%85%A8%E8%BF%87%E7%A8%8B%E3%80%82

 */
void test(int d[3]){

}
int main()
{
    // @formatter:off
    extern int a; // 声明a,具体a的实现不在此文件
    extern int a; // redundant declaration

    /// 大多数前面几个0,后面元素多了就随机了,原因待解释
    int b[1];
    // int b[1]; // redefinition

    int d[3]={0};
    // int d[3]={0}; // redefinition
    /// 数组不能相互赋值或初始化,也不能作为函数的参数或返回值     c编程一站式,刷新我的错误认知
    // int d2[3]=d;

    extern int c[3];
    extern int c[3]; // redundant declaration

    char c2 = "Hello, world.\n"[0];
    /// 字面量是只读,不允许修改,下面编译错误     一站式
    "Hello, world.\n"[0] = 'A';
    return 0;
    // @formatter:on
}
