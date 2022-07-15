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
    /// 另外c隐式转换:字节少向字节多转,有符号向无符号转,
    int a=-1;
    unsigned int b=10;
    hyj:
    if(a>b){
        printf("big \n");fflush(stdout);
//        goto hyj;
    }else{
        printf("small \n");fflush(stdout);
    }
    return 0;
    // @formatter:on
}