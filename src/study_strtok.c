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
    char str[] = "a b  c";
    /**
     * strtok入门, https://blog.csdn.net/jay_zzs/article/details/106883832  注意: 参2是字符串指针,字符串中每个字符都可以作为分隔符!!!
     */
    // char* split = strtok(str," ");
    // while(split!=NULL){
    //     printf("%s \n",split);fflush(stdout);
    //     split = strtok(NULL," ");
    // }

    /**
     * strtok_s
     */
    char* context=NULL; // strtok_s多了一个参数next_token，strtok_s把剩下的字符串写到next_token里，这样内部就不用记录子字符串等信息了，从而是线程安全的函数。
    char* split2 = strtok_s(str," ",&context);
    while(split2!=NULL){
        printf("%s \n",split2);fflush(stdout);
        split2 = strtok_s(NULL," ",&context);
    }
    return 0;
    // @formatter:on
}
