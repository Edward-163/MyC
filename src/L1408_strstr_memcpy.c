#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ** stringMatching(char ** words, int wordsSize, int* returnSize){
    char** res=(char**)malloc(sizeof(char*)*wordsSize);
    int ridx=0;
    /**
     bug:注意scanned和search顺序,现在还有bug
     */
    for(int a=0;a<wordsSize;a++){
        for (int b = 0; b < wordsSize; ++b) {
            if(a!=b){
                /// scannedStr searchStr    找到了返回指针,否则null
                if (strstr(words[a], words[b])!=NULL) {
                    /// 还要再开一块内存??是不是因为上面res经过malloc后才能[]?!!
                    res[ridx] = (char *) malloc(sizeof(char) * (strlen(words[b]) + 1));
                    memcpy(res[ridx],words[b],sizeof(char) * (strlen(words[b]) + 1));
                    ridx++;
                }
            }
        }
    }

    *returnSize=ridx;
    return res;
}

int main(){
//    char* arr[]={"mass","as","hero","superhero"};
    char* arr[]={"leetcode","et","code"};
    char** words;

    int wordsSize = sizeof(arr) / sizeof(arr[0]);
    int* returnSize = (int *) malloc(sizeof(char));
    char** res=stringMatching(arr,wordsSize,returnSize);
    for(int a=0;a<*returnSize;a++){
        printf("%s ",res[a]);
    }
    return 0;
}