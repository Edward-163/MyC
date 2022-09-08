#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"
#include "securec.h"


/*

 */
char * reorderSpaces(char * s){
    int sidx=0;
    int spaceCount=0;
    int wordCount=0;
    while (s[sidx]!='\0'){
        if(s[sidx]==' '){
            spaceCount++;
        }else if(sidx-1<0 || s[sidx-1]==' '){ // 开头字母算一个单词or此字母前面刚好是空格也算是一个单词
            wordCount++;
        }
        sidx++;
    }

    int spacePadding=spaceCount/ fmax(wordCount-1,1); /// fmax

    char* ans=malloc(sizeof(char)*(sidx+1));
    for (int i = 0; i < sidx + 1; ++i){
        ans[i]=' ';
    }
    ans[sidx] = '\0';

    int aidx=0;
    for (int i = 0; i < sidx; ++i){
        if(s[i]!=' '){
            ans[aidx++]=s[i];
        }else if(i-1>=0 && s[i-1]!=' '){ // 此字母是空格且前字母是非空格时,开始填充spacePadding个空格
            for (int a = 0; a < spacePadding && spaceCount>=1; ++a){
                ans[aidx++]=' ';
                spaceCount--;
            }
        }
    }
    return ans;
}
int main() {
    // @formatter:off
    char text[]="  this   is  a sentence ";
    char* ans=reorderSpaces(text);
    printf("%s \n",ans );fflush(stdout);
    return 0;
    // @formatter:on
}