#include <stdio.h>

/*
 
 */

int main()
{
    // @formatter:off
    /**
     * int getchar() 只能读取用户输入缓存区的一个字符，包括回车。
     * int putchar(int char) 把参数 char 指定的字符（一个无符号字符）写入到标准输出 stdout 中
     */
    int c;
    // while((c = getchar()) != EOF){
    //     putchar(c);
    // }

    // scanf() 可输入不包含空格的字符串，不读取回车，空格和回车表示输入完毕。
    char a[100];
    // printf("请输入： ");
    // scanf("%s",&a);
    // printf("str的值为：%s \n",a);fflush(stdout);

    printf("请输入： ");
    c= getchar();
    printf("%c",c);
    c= getchar();
    printf("%c",c);
    c= getchar();
    printf("%c",c);
    return 0;
    // @formatter:on
}
