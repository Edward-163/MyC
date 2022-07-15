#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*

 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize){
    char** res=(char**)malloc(sizeof(char*)*wordsSize);
    int rlen=0;
    int len=strlen(pattern);
    int wp[26];
    int pw[26];
    for(int a=0;a<wordsSize;a++){
        bool illegal=true;
        memset(wp,-1,sizeof(int)*26);
        memset(pw,-1,sizeof(int)*26);
        for(int b=0;b<len;b++){
            int ww=words[a][b]-'a';
            int pp=pattern[b]-'a';
            if(wp[ww]==-1){
                wp[ww]=pp;
            }else if(wp[ww]!=pp){
                illegal=false;
                break;
            }
            if(pw[pp]==-1){
                pw[pp]=ww;
            }else if(pw[pp]!=ww){
                illegal=false;
                break;
            }
        }
        if(illegal){
            res[rlen]=words[a];
            rlen++;
        }
    }
    *returnSize=rlen;
    return res;
}
int main() {
    char *pattern = "abb";
    int i1=1;
    i1 = strlen(pattern);
//    char arr[][3]={"abb","deq","mee","aqq","dkd","ccc"};
    char arr[][3]={"abb","deq"};
    int wordSize=sizeof(arr)/sizeof(arr[0]);
    char* word[wordSize];
    for (int i = 0; i < wordSize; ++i) {
        word[i]=arr[i];
    }
    int* returnSize=(int*)malloc(sizeof(int));
    char **pString = findAndReplacePattern(word, wordSize, pattern, returnSize);
    for (int i = 0; i < *returnSize; ++i) {
        printf("%s\n",(*pString)[i]);
        fflush(stdout);
    }
    return 0;
}