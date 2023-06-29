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

struct {
  union {
      int t1;
      int t2;
      struct {
        int p;
        int q;
      }w;
  }u;
  int i;
}x;

int union_litterEndian_bigEndian(){
    /**
     此union占4字节,软件编程知识中有介绍union
     大字节序
     0x 0 0 0 1
     这4个字节代表int a;第一个字节代表char b,显然b==0

     小字节序
     ox 1 0 0 0
     显然b==1
     */
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
    // int w = x.u.w; /// clion提示居然把w当做int??
    printf("%d \n",union_litterEndian_bigEndian());fflush(stdout);
    Test u1;
    printf("u1???????С: %d \n",sizeof(u1));fflush(stdout);
    return 0;
    // @formatter:on
}
