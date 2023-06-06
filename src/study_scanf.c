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
void scanf_() {
    /// 入门,严格来说,参2参3...应该是内存地址,而不是指针
    int a;
    int b;
    scanf("%d %d",&a,&b); // 标准输入按format格式读取后,赋值到参2参3...中
    scanf("%d %*d %d",&a,&b); // 中间加个*代表忽略掉(不解析中间)
    printf("%d %d\n",a,b);
    fflush(stdout);
}
int main()
{
    // @formatter:off

    /// https://blog.csdn.net/zhinengxiong6/article/details/111306916 指针指向常量字符串时不能作为scanf参数,因为字符常量不可修改
    // char* point="ab";
    // char* point;
    // char* point=malloc(sizeof(char)*3);
    // scanf("%s",point);
    // printf("%s \n",point);fflush(stdout);

    /// scanf_s对于char,char数组来说要追加上其的字节长度 20221021_z2_other 注意: ints不属于字符类,根本不需要参3
    // char c;
    // int ints[1];
    // scanf_s("%d",ints,1); // 错的,不需要3参

    /**
     * scanf_s(format,&arr,可能存在的参3) 成功:返回解析了几个字段 失败:-1
     * 注意: 参3 最多读取n个字节(包括输入的结束符\0) 注意 实测输入"ab换行"才能正常打印ab,输入其他的abc会异常退出 注意 _s一定要检查读取了几个参数,1个2个n个??
     * 注意: 必须校验返回读取了几个字段?如 "%s" "%d" 理论会读取到一个字段,"%s%d" 理论会读取到两个字段;读取错误返回-1
     * %2x format详解如下,也是要学的!!!!!!!!!!!!!!!!!!!!!!!!
     * https://blog.csdn.net/m0_46299442/article/details/115611205
     */
    char arr[3];
    if(scanf_s("%s",arr,sizeof(arr))!=1){ // 输入abc 输入ab
        return -1;
    }
    printf("%s \n",arr);fflush(stdout);


    /**
     * sscanf_s(str,format,&arr,可能存在的参4)
     * 上面输入源是标准输入;参1代表输入源是str
     */
    char *pstr="ab";
    char buf[9];
    /// 多了参1代替标准输入源, 注意: 当读入的类型是整数或其它长度可以确定的类型时，不能在类型后面跟上长度，但是对于字符串类型(char *)长度无法得知则必须在类型后面明确指出字符串的最大长度(即可以容纳的空间)
    // sscanf(pstr,"%s",&buf);
    /// 和scanf_s类似,当最多只能读2个字节的时候,要确保最后读取的是\0才能正常打印
    // sscanf_s(pstr,"%s",&buf,2);
    sscanf_s(pstr,"%s",&buf,3);
    printf("buf: %s \n",buf);fflush(stdout);

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
