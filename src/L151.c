#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverseWords(char *s) {
    int slen = strlen(s);
    /***
     bug:heap overflow 新手常见的堆溢出,一般要检查是否数组越界了
     后来想了想,如"hi"求反转,我的代码默认res数组的元素后面接个空格,显然我会在最后一个空格赋值的时候越界
     */
//    char* res=(char*)malloc(sizeof(char)*slen);
    char *res = (char *) malloc(sizeof(char) * (slen + 1));
    int ridx = 0;
    for (int a = slen - 1; a >= 0; a--) {
        if (s[a] != ' ') {
            int aa = a;
            while (aa - 1 >= 0 && s[aa - 1] != ' ') {
                aa--;
            }
            for (int m = aa; m <= a; m++) {
                res[ridx++] = s[m];
            }
            res[ridx++] = ' ';
            a = aa;
        }
    }
    res[ridx - 1] = '\0';
    return res;
}

int main() {
    char s[] = "a hello world ";
    char *res = reverseWords(s);
    printf("%s", res);
    return 0;
}