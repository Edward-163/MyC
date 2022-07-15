/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*
 
 */

int main()
{
    // @formatter:off
    /** 之前还在苦恼c的二维数组的动态列长度,今天误打误撞再套一层{},结果是可行的,猜测{}在c中就是返回指针的意思??,char str[]="hyj" L648
        char* str={"hyj"}; // 悟了悟了
     */
//    char* dict[]={{"a"},{"ab"},{"b"}};
    char* dict[]={{"cat"},{"bat"},{"rat"}}; /// 注意这种传给char**不会sig,但类似int* arr[]传给int**铁定sig,L815
    int size=sizeof(dict)/sizeof(dict[0]);
    char sentence[]="by the battery"; // "the cat was rat by the bat" 可以正常打印,但tok时会sig
    return 0;
    // @formatter:on
}