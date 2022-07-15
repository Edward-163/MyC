#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "uthash.h"

typedef struct {
    char *key;
    int val;
    UT_hash_handle hh;
} Hashlist;

Hashlist *g_hashlist = NULL;

bool wordPattern(char *pattern, char *s) {


    char *tmp = strtok(s, " ");
    while (tmp != NULL) {
        printf("%s\n", tmp);
        tmp = strtok(NULL, " ");
    }
    return true;
}

int main() {
    /**
     * 下面程序编译没有问题，但是运行时弹出SIGSEGV。此例中，”hello world”作为一个常量字符串，
     * 在编译后会被放在.rodata节（GCC），最后链接生成目标程序时.rodata节会被合并到text segment与代码段放在一起，故其所处内存区域是只读的。这就是错误的访问类型引起的SIGSEGV
     */
    char* str="h y j";//bug
//    char str[] = "hello world";//right
    wordPattern(NULL, str);
    return 0;
}