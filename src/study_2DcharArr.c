#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"

/*
 
 */

int main()
{
    // @formatter:off
    char tmp[9]; // 因为这是定义(分配空间),要区分c和java的声明定义
    // char tmp[9];
    for (int i = 0; i < 9; ++i){
        printf("%c ",tmp[i]);fflush(stdout);
    }
    printf("字符数组不初始化,会分配空间,有随机内容,存放区域??已知初始化的字符数组存放于栈 <<<<<<<<<<<<<<\n");fflush(stdout);
    /** 之前还在苦恼c的二维数组的动态列长度,今天误打误撞再套一层{},结果是可行的,猜测{}在c中就是返回指针的意思??,char str[]="hyj" L648
        char* str={"hyj"}; // 悟了悟了
     */
    char* dict[]={{"a"},{"ab"},{"b"}}; /// 20220916_g2特意考察过二维字符数组的列宽度
    // char* dict[]={{"cat"},{"bat"},{"rat"}}; /// 注意这种传给char**不会sig,但类似int* g_arr[]传给int**铁定sig,L815
    int size=sizeof(dict)/sizeof(dict[0]);
    char sentence[]="by the battery"; // "the cat was rat by the bat" 可以正常打印,但tok时会sig
    return 0;
    return 0;
    // @formatter:on
}
