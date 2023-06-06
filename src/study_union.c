#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 
 */
typedef union {
    char c;
    unsigned long k;
    int i;
}Test;

int check(){
    union w{
        int a;
        char b;
    }c;
    c.a=1;
    return c.b==1;
}

int main()
{
    // @formatter:off
    /**
     此union占4字节,软件编程知识中有介绍union
     大字节序
     0x 0 0 0 1
     这4个字节代表int a;第一个字节代表char b,显然b==0

     小字节序
     ox 1 0 0 0
     显然b==1
     */
    // printf("%d \n",check());fflush(stdout);

    /// ?ж?32λ 64λ
    printf("??????%dλ \n",8*sizeof(char*));fflush(stdout);
    printf("??????%dλ \n",sizeof(unsigned long));fflush(stdout); // ?????,????:??win???? ???й??
    Test u1;
    printf("u1???????С: %d \n",sizeof(u1));fflush(stdout);
    return 0;
    // @formatter:on
}
