#include <stdio.h>

/*
 
 */

int main()
{
    // @formatter:off
    /// C语言中，％f表示保留7位有效数字7位有效数字： 是指 整数部分 和小数部分一共7位
    float a=9.8765432;
    float b=9.8765433;
    printf("%d \n",a==b);fflush(stdout); // 1

    /// 16有效位数
    // double

    /// 19有效位数
    // long double

    return 0;
    // @formatter:on
}
