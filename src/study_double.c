#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 
 */

int main()
{
    // @formatter:off
    double PI = 3.14159;
    /// 计算机表达10的幂是一般是用E或e
    double val = 1.0E100; // 天文数字
    /// 等于val,原因未知
    double add = val + PI;
    printf("add - val = %1.5lf\n", add - val); // 0

    return 0;
    // @formatter:on
}