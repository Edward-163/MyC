#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
/*
给定一个字符串，以数字或空格或'-'组成；
然后按如下格式将字符串格式化，返回格式化后的字符串
1. 首先去除所有的空格和'-'；
2. 然后将剩下的数字每三个一组，每组之间添加'-'；当剩下还有4个数字没有分组，不能分为3+1，要分为2+2，两两一组，不允许出现单个数字一组的情况；

例如：
输入："9 - 8--6 5 43210" 输出："986-543-210"
输入："9 - 8--6 5 4" 输出："986-54"
输入："9 - 8--6 5" 输出："98-65"
 */
char* fn(char* str){
    int len=strlen(str);
    char* res=(char*)malloc(sizeof(char)*len);
    int rlen=0;
    int count=0;
    for(int a=0;a<len;a++){
        if('0'<=str[a] && str[a]<='9'){
            res[rlen]=str[a];
            rlen++;
            count++;
            if(count==3){
                res[rlen]='-';
                rlen++;
                count=0;
            }
        }
    }

    //999- 999-9 999-99
    if(res[rlen-1]=='-'){
        res[rlen-1]='\0';
    }else if(res[rlen-2]=='-'){
        char tmp=res[rlen-3];
        res[rlen-3]=res[rlen-2];
        res[rlen-2]=tmp;
        res[rlen]='\0';
    }else{
        res[rlen]='\0';
    }
    return res;
}

int main() {
//    char str[]="9 - 8--6 5 43210";
//    char str[]="9 - 8--6 5 4";
    char str[]="9 - 8--6 5";
    printf("%s",fn(str));
    return 0;
}