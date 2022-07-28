#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 gcd greatest common divisor(除数,)证明过程bili上有
 dividend 被除数
 */
#define ABS(a) ((a) > 0 ? (a) : -(a))

int Gcd(long long a, long long b)
{
    return b == 0 ? a : Gcd(b, a % b);
}

char *fractionAddition(char *expr)
{
    int dividend = 0;
    int divisor = 1;
    int move = 0;
    int len = strlen(expr);
    if (len < 0) {
        return NULL;
    }
    char *dest = malloc(sizeof(char) * (len + 3));
    int exproffset = 0;
    int count = 0; // 0 dividend divisor num count
    int dividend2;
    int divisor2;
    /// bug 整个解法建立在利用idx切割,下面这个while永远切不出最后一个数字
    // while (expr[move] != '\0') {
    while (move <= len) {
        if (move >= 1 && (move == len || expr[move] == '-' || expr[move] == '+' || expr[move] == '/')) {
            memcpy(dest, expr + exproffset, sizeof(char) * (move - exproffset));
            dest[move - exproffset] = '\0';
            printf("%s \n", dest);fflush(stdout);
            if (count == 0) {
                dividend2 = atoi(dest);
                count++;
            } else if (count == 1) {
                divisor2 = atoi(dest);
                dividend = dividend * divisor2 + divisor * dividend2;
                divisor *= divisor2;
                count = 0;
            }
            exproffset = move; // step
            if (expr[move] == '/') {
                exproffset++;
            }
        }
        // step
        move++;
    }

    int i = Gcd(ABS(dividend), divisor);
    sprintf(dest, "%d/%d", dividend / i, divisor / i);
    return dest;
}

int main()
{
    // @formatter:off
    // char expression[] = "-1/2+1/2"; // 输出: "0/1"
    // char expression[] = "-1/2+1/2+1/3"; // 输出: "1/3"
    // char expression[] = "1/3-1/2"; // 输出: "1/3"
    char expression[] = "-7/3"; //
    char *s = fractionAddition(expression);
    printf("%s \n",s);fflush(stdout);
    return 0;
    // @formatter:on
}