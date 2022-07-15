#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int minDeletionSize(char **strs, int strsSize) {
    int res = 0;
    int colLen = strlen(strs[0]);
    for (int col = 0; col < colLen; col++) {
        for (int row = 0; row < strsSize - 1; row++) {
            char i = strs[row][col];
            char i1 = strs[row + 1][col];
            if (i > i1) {
                res++;
                break;
            }
        }
    }
    return res;
}

bool fn(char *first, char *second, int idx, int idx1, int count) {
    if (count > 1)return false;
    if (idx == 0) {
        if (count == 0 && idx1<=1){
            //减少
            if(second[0]==first[0] || second[1]==first[0])return true;
            //换
            if(idx1==0)return true;
        }
        if (count == 1 && idx1 == 0 && first[idx] == second[idx1])return true;
        return false;
    }

    if (first[idx] == second[idx1]) {
        return fn(first, second, idx - 1, idx1 - 1, count);//相同均缩小一位
    } else {
        //不同second可以减
        if (fn(first, second, idx, idx1 - 1, count + 1))return true;
        //不同second可以换,换后当相同处理,但count+1
        if (fn(first, second, idx - 1, idx1 - 1, count + 1))return true;
        return false;
    }
}

bool oneEditAway(char *first, char *second) {
    int len = strlen(first);
    int len1 = strlen(second);
    if (len == 0 || len1 == 0) {
        if (len + len1 <= 1)return true;
        else return false;
    }
    if (len < len1) {
        return fn(first, second, len - 1, len1 - 1, 0);
    } else {
        return fn(second, first, len1 - 1, len - 1, 0);
    }
}

/// 面试题 01.05. 一次编辑
int main() {
//    char* strs[]={"rrjk","furt","guzm"};
//    printf("%d",minDeletionSize(strs,3));
    printf("%d", oneEditAway("ab", "abdd"));
    return 0;
}
