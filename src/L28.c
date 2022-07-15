#include <string.h>
#include <stdbool.h>
int strStr(char *haystack, char *needle) {
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    // c没有外层标识,别想了,乖乖用flag代替吧
    for (int a = 0; a < hlen - (nlen - 1); a++) {
        bool flag = false;
        for (int b = 0; b < nlen; b++) {
            if (haystack[a + b] != needle[b]) {
                flag = true;
                break;
            }
        }
        if (!flag)return a;
    }
    return -1;
}

int main() {
    strStr("hello", "ll");
    return 0;
}