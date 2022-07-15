#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*

 */
int cmp(const void *a, const void *b)
{
    return *(char *) a - *(char *) b;
}

int nextGreaterElement(int n)
{
    // 133 333 333>>313 333 333>>-1
    /// bug 奇怪的事,本地过,leet heap overflow(对定位压根没啥用,全程靠猜错在哪)
//    char *buf = (char *) malloc(sizeof(char) * 10);
    char *buf = (char *) malloc(sizeof(char) * 11);
    /// 还好发现的早大坑,leet不支持itoa,网友:itoa是Windows平台才有的，要转字符串用sprintf就好了
//    itoa(n,buf,10);
    sprintf(buf, "%d", n);
    int len = strlen(buf);

    /// bug:整个思路不正确
//    int idx = -1;//will to replaced by bigger num
//    char biggeridx;
//    for (int a = 1; a < len; a++) {
//        if (buf[a - 1] < buf[a]) {
//            idx = a - 1;
//            biggeridx = a;
//            break;
//        }
//    }
//    if (idx == -1)return -1;
//    for (int move = idx + 2; move < len; move++) {
//        if (buf[move] > buf[idx] && buf[move] < buf[biggeridx]) {
//            biggeridx = move;
//        }
//    }

    // 从右往左,找bigger 476>>647 本质问题,谁可以替换掉4??递减栈优化 15432>>12345 并且只关心栈顶,空间优化,用一个变量优化
    int stacktopIdx = len - 1;
    // a==will replaced by bigger
    for (int a = len - 2; a >= 0; a--) {
        if (buf[stacktopIdx] > buf[a]) {
            char tmp = buf[a];
            buf[a] = buf[stacktopIdx];
            buf[stacktopIdx] = tmp;

            qsort(buf + a + 1, len - (a + 1), sizeof(char), cmp);
            long long int ans = atoll(buf);
            if (ans > INT_MAX) {
                return -1;
            }
            return ans;
        }
        // push stack
        if (buf[a] < buf[stacktopIdx]) {
            stacktopIdx = a;
        }
    }
//    for (int a = len - 1; a >= 1; a--) {
//        if (buf[a] > buf[a - 1]) {
//            int biggerIdx = a;//暂定a
//            for (int b = a + 1; b < len; b++) {
//                if (buf[b] > buf[a - 1] && buf[b] < buf[biggerIdx]) {
//                    biggerIdx = b;
//                }
//            }
//            char tmp = buf[a - 1];
//            buf[a - 1] = buf[biggerIdx];
//            buf[biggerIdx] = tmp;
//
//            /// bug:二参要排序的个数写错了,导致数组意外被截短了
////            qsort(buf + idx + 1, len - (idx + 1), sizeof(char), cmp);
//            qsort(buf + a, len - a, sizeof(char), cmp);
//            /// bug 忘了C语言中long和int占字节相同,而atol固定返回值是long
////            long ans = atol(buf);
//            long long int ans = atoll(buf);
//            if (ans > INT_MAX) {
//                return -1;
//            }
//            return ans;
//
//        }
//    }

    return -1;
}

int main()
{
//    @formatter:off
//    int n = 3124;
//    int n=3421; // 3421>>4123
//    int n=1234;
//    int n=2147483647;
//    int n=2147483486;
    int n=2147483476;
//    int n=15432;
    printf("%d ",nextGreaterElement(n));fflush(stdout);
    return 0;
//    @formatter:on;
}