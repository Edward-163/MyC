
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
    int i=0;
    i=1,2;
    printf("%d \n",i);fflush(stdout);

    double a=22;
    int x,k=0,b=11;
    x = k++, ++b;
    x = !a;
    x = a+k <= b+k;
    // x = a%11; // C语言中  %两侧只能是整形中选取,short int long longlong

    int m=---1;


    return 0;
    // @formatter:on
}