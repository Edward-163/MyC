#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 逗号运算
 */
int main()
{
    // @formatter:off
    int a;
    /// 注意:相当于a=1;2;
    /// 注意:相当于a=1;2;
    /// 注意:相当于a=1;2;
    a=1,2; 
    printf("%d \n",a);fflush(stdout);
    int b=(3,4); // 逗号运算从左到右,左边都是准备,最右边才是结果
    printf("%d \n",b);fflush(stdout);

    int c;
    printf("%d \n",(c=1,c+2));fflush(stdout); // 相当于直接打印3
    printf("%d \n",((c=1,c+2),c+3));fflush(stdout); // (3,c+3)的结果是c+3,但是请注意c一直是1,c+2并没有改变c的值,所以打印4
    return 0;
    // @formatter:on
}
