#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 
 */

int main()
{
    // @formatter:off
    /**
     0x80 000 000转二进制 1000 0000 0000 0000 0000 0000 0000 0000,这不就是把32位有符号int给拉满了再加1嘛
     32位有符号int的max==2147483647
     */
    int i=0;
    while(1){
        /// c11 泛型???
        // unsigned int i1 = 0x80000000;
        // if(i>=0x80000000)break; // int 型 loop 和 unsigned int 型的 0x80000000 比较时会将类型提升为 unsigned int 型，所以最后 loop 可以等于 0x80000000 而正常退出
        if(i>=2147483648)break; // dead loop
        i++;
    }
    printf("%d \n",i);fflush(stdout);
    return 0;
    // @formatter:on
}
