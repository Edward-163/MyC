
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"
#define MAX 26
char GetDifferentLetter(char *inputStr, char *targetStr)
{
    if (strlen(inputStr) == 0) {
        return targetStr[0];
    }
    int input[MAX] = {0};
    int target[MAX] = {0};
    int iidx = 0;
    while (inputStr[iidx] != '\0') {
        input[inputStr[iidx] - 'a']++;
        iidx++;
    }
    int tidx = 0;
    while (targetStr[tidx] != '\0') {
        target[targetStr[tidx] - 'a']++;
        tidx++;
    }

    int ans = 0;
    for (int i = 0; i < MAX; ++i) {
        if (target[i] == input[i] + 1) {
            ans = i;
            break;
        }
    }
    return 'a' + ans;
}

int main()
{
    // @formatter:off
    // char inputStr[] = "khijk";
    // char targetStr[] = "kjhkia";
    // char inputStr[] = "";
    // char targetStr[] = "x";
    char inputStr[] = "z";
    char targetStr[] = "zz";
    // 输出："a"
    char ans = GetDifferentLetter(inputStr,targetStr);
    printf("%c \n",ans);fflush(stdout);
    
    // 解释：'a' 是那个被添加的字母。
    //
    // 输入：inputStr = "", targetStr = "x"
    // 输出："x"
    //
    // 输入：inputStr = "z", targetStr = "zz"
    // 输出："z"
    return 0;
    // @formatter:on
}