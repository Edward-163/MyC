#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 
 */
int* a(){
    int * aa=malloc(sizeof(int));
    *aa=7;
    return aa;
}
int main()
{
    // @formatter:off
    int b=*a();
    printf("%d \n",b);fflush(stdout);

    int tmp[] = {1, 2, 3, 4};
    int *ptr = &tmp[0];
    // ptr++;
    // int a = *ptr; // 1 2
    int a = *ptr++; //  1 1
    // int a = *(ptr++); //  1 1
    /**
     解释:单目运算 * ++ 的优先级相同,*(ptr++)的意思是,你先使用ptr,用完后++,什么才叫使用呢?这里*prt==1==a解引用就算使用
     我产生误解是因为我把*(prt++)理解为拆成两行,并认为一行效果==两行效果
     */
    printf("%d,%d,*ptr=%d\n", tmp[0], a,*ptr);
    return 0;
    // @formatter:on
}