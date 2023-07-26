#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"
#include "securec.h"


/**
C语言 if else 我真是草了
 else总是匹配前面未匹配的if 而且还要注意,多加一句fflush都不行,真是血马坑
 */
void test00(){
    int x=1;
    int y=2;
    int z=3;
    if(x==0)
//        if(y==2)printf("%d \n",y);fflush(stdout);
        if(y==2)printf("%d \n",y);
    else {
        printf("%d \n",z);fflush(stdout);
    }
}
int main() {
    // @formatter:off
    test00();
    return 0;
    // @formatter:on
}