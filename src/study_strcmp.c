#include <string.h>
#include <stdio.h>

/*
 
 */

int main() {
    /**
     * 两个字符串自左向右逐个字符相比（按 ASCII 值大小相比较），直到出现不同的字符或遇 \0 为止。如：
        "A"<"B"
        "A"<"AB"
        "Apple"<"Banana"
        "A"<"a"
        "compare"<"computer"
     */
    // char str1[]="hyj11";
    // char str2[]="hyj22";
    char str1[]="A";
    char str2[]="a";
    // char str1[]="44";
    // char str2[]="5";
    // char str1[]=""; /// 早结束的str,也算是短的
    // char str2[]="5";
    printf("strcmp: %d \n", strcmp(str1,str2));fflush(stdout); // 前面小返回负数
    printf("strncmp: %d \n", strncmp(str1,str2,sizeof(char)*3));fflush(stdout);
    printf("%d \n", strncmp(str1,str2,sizeof(char)*4));fflush(stdout);

    return 0;
}
