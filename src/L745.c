/*
 *
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*
 
 */
typedef struct {
    char **words;
    int wordsSize;
} WordFilter;


WordFilter *wordFilterCreate(char **words, int wordsSize)
{
    WordFilter *wf = malloc(sizeof(WordFilter) * wordsSize);
    wf->words = words;
    wf->wordsSize = wordsSize;
    return wf;
}

int wordFilterF(WordFilter *obj, char *pref, char *suff)
{
    for (int a = obj->wordsSize - 1; a >= 0; a--) {
        int len = strlen(obj->words[a]);
        int plen=strlen(pref);
        if(len<plen){
            continue;
        }
        bool flag=true;
        for (int move = 0; move < plen; ++move){
            if(obj->words[a][move]!=pref[move]){
                flag=false;
                break;
            }
        }
        if (flag == false) {
            continue;
        }

        int slen = strlen(suff);
        if (len < slen) {
            continue;
        }
        bool match = true;
        for (int move = slen - 1; move >= 0; move--) {
            if (obj->words[a][len - 1 - (slen - 1 - move)] != suff[move]) {
                match = false;
                break;
            }
        }
        if (match) {
            return a;
        }
    }
    return -1;
}

void wordFilterFree(WordFilter *obj)
{
    free(obj->words);
    free(obj);
}

int main()
{
    // @formatter:off
    char* words[]={{"apple"},{"aee"}};
    int size=sizeof(words)/sizeof(words[0]);
    WordFilter *wf = wordFilterCreate(words,size);
    char pref[]="a";
    char suff[]="e";
    int i = wordFilterF(wf,pref,suff);
    printf("%d ",i);fflush(stdout);
    return 0;
    // @formatter:on
}