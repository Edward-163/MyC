#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
//#include "uthash.h"
#include "securec.h"


/*
位域 尽量挨着存储
 */
void test00(){
    struct SS{
        int a:1;
        int b:7; // 输出4
        int :32; // 输出8
//        int:32; //输出8 经过测试发现,若按照4字节=32对齐,上面就是1+7+后续空位,一旦超过32位,我猜1+后续空31位,
    };
    printf("%d \n",sizeof(struct SS));fflush(stdout);
}
int main() {
    // @formatter:off
    test00();
    return 0;
    // @formatter:on
}




