#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
// #include "uthash.h"
#include "securec.h"

/*
 Argument 专用于 Actual Argument（实际参数，实参），Parameter 专用于 Formal Parameter（形式参数，形参
 数组形参  形参数组  可以不指定长度?
 形参数组大小可以不指定, 即便指定了也可以与实参数组大小不一致,因为c编译器对形参数组大小不做检查,只是将参数组的首地址传递给形参数组
 */
void test(int aa[]){
// void test(int* aa){
    int idx=0;
    while(aa[idx]!='\0'){
        printf("%d \n",aa[idx++]);fflush(stdout);
    }
}
int main()
{
    // @formatter:off
    int arr[]={1,2,3};
    test(arr);
    return 0;
    // @formatter:on
}
