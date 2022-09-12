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
    /// scanf_s对于数组来说要追加上其的字节长度 20220819_z2
    char c;
    int cc[1];
    scanf_s("%d",cc,1); // 1居然可以?? 应该写4 或者稳妥点用sizeof
    // scanf_s("%d",cc,sizeof(cc)); //
    printf("%d \n",cc[0]);fflush(stdout);

    /// https://blog.csdn.net/zhinengxiong6/article/details/111306916 指针不能作为scanf参数
    char* point;
    scanf("%s",point);
    printf("%s \n",point);fflush(stdout);
    /*
    2
    2 130 120
    1 150 150
    6
    150 100
    160 190
    150 200
    200 190
    160 190
    160 190
     */
    /// 返回注入成功字段的个数,一个都没成功,返回eof==-1,实操可以多行一次粘贴,让scanf一行行读
    /// 字符串。这将读取连续字符，直到遇到一个空格字符（空格字符可以是空白、换行和制表符)
    while(scanf("")){

    }


    return 0;
    // @formatter:on
}