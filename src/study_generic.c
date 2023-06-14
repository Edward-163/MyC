#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/**
 https://blog.csdn.net/qq_37151416/article/details/113203701
    在泛型_Generic的语句中，++ 、*=、 = 等操作都不会让变量发生改变
 */
int add_int(int a,int b)
{
    printf("%d + %d = %d\n",a,b,a+b);
    fflush(stdout);
    return a+b;
}
float add_float(float a,float b)
{
    printf("%f + %f = %f\n",a,b,a+b);
    fflush(stdout);
    return a+b;
}
void unsupport()
{
    printf("unsupport type\n");
    fflush(stdout);
}
#define ADD(x,y) _Generic((x),int:add_int,float:add_float,default:unsupport)
int main()
{
    // @formatter:off

    int a=10;
    int b=0,c=0;
    _Generic(a+0.1f,int:b,float:c,default:b)++; // int+float触发类型转换,所以当float处理,此行==c++
    printf("b=%d,c=%d\n",b,c);fflush(stdout);

    _Generic(a+=1.1f,int:b,float:c,default:b)++; // +=不触发类型转换,所以a当int处理,此行==b++
    printf("a=%d,b=%d,c=%d\n",a,b,c);fflush(stdout);

    // int a=1;
    // float d = a+0.1f;
    // a+=0.1f;
    ADD(1,2);
    ADD(1.1,2.2);
    return 0;
    // @formatter:on
}
