#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 调用函数的传参过程相当于用实参定义并初始化形参        一站式23.2
 */
void swap(char* s1,char* s2){
    char* tmp=s1;
    s1=s2;
    s2=tmp;
}
void swap2(char** s1,char** s2){
    char *tmp=*s1;
    *s1=*s2;
    *s2=tmp;
}
void swap3(char* s1,char* s2){
    char *tmp=s1;
    *s1=s2;
    *s2=*tmp;
}
int main()
{
    // @formatter:off
    char s1[]="one";
    char s2[]="two"; // (gdb) p &s1 $2 = (char (*)[4]) 0xc8e87ff64c(gdb) p &s2 $3 = (char (*)[4]) 0xc8e87ff648
    /// 目前网上海尔解决办法是,开辟新空间,利用strcpy交换
    // swap(s1,s2);
    // swap2(s1,s2);
    swap2(&s1,&s2);
    // swap3(&s1,&s2);
    printf("%s   %s",s1,s2);fflush(stdout);
    return 0;
    // @formatter:on
}
