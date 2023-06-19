#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "securec.h"

/*
 
 */

int main()
{
    // @formatter:off
    char dest[20]="abc\0efg\0";
    char src[]="hij";
    strcat(dest,src);
    printf("%s \n",dest);fflush(stdout); // abchij

    /**
     * Dest 目的缓冲区 非空，在destMax范围内必须有结束符，不能与strSrc重叠。 输入/输出
     * destMax 目的缓冲区总大小（包括'\0'） (0, SECUREC_STRING_MAX_LEN]，不能超过目的缓冲区的实际长度，且必须大于等于（目的缓冲区原有字符串长度 + 源字符串长度 + 1）。 输入
     * Src 源缓冲区 非空，不能与strDest重叠。
     */
    char dest2[7]="abc\0efg\0"; // dest字符串长度3,src字符串长度3     你要是把7改成6还真的会报错
    char src2[]="hij";
    errno_t i = strcat_s(dest2,sizeof(dest2),src2);
    printf("%d \n",i);fflush(stdout);
    printf("%s \n",dest2);fflush(stdout); // abchij

 
    /// strcat不能用于内存重叠拷贝,win环境下能正常输出?
    char s[10] = "HelloY";
    char *s1 = s;
    char *s2 = &s[2];
    strcat(s1, s2);
    printf("%s\n", s1);fflush(stdout);
 
    return 0;
    // @formatter:on
}
