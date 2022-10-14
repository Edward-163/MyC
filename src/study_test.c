#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 
 */
void test01(){
    int i=-1;
    // int i=3;
    for(;i<sizeof(int);i++){
        printf("%d \n",i);fflush(stdout);
    }
}
void test02(){
    unsigned int a=6;
    int b=-20;
    int c=a+b;
    printf("a+b=%d \n",a+b);fflush(stdout);
    if(a+b>0){
        printf("大于 \n");fflush(stdout);
    } else{
        printf("小于\n");fflush(stdout);
    }
    if(c>0){
        printf("大于2\n");fflush(stdout);
    } else{
        printf("小于2\n");fflush(stdout);
    }
}
int main()
{
    // @formatter:off
    // test01();
    test02();
    return 0;
    // @formatter:on
}