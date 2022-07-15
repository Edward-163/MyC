/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
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
    int size;
    char **dict;
} MagicDictionary;


MagicDictionary *magicDictionaryCreate()
{
    MagicDictionary *obj = malloc(sizeof(MagicDictionary));
    return obj;
}

bool oneCharDiff(char *ele, char *search)
{
    int elen = strlen(ele);
    int slen = strlen(search);
    if (elen != slen) {
        return false;
    }
    int count = 0;
    for (int i = 0; i < elen; ++i) {
        if (ele[i] != search[i]) {
            count++;
            if (count > 1) {
                return false;
            }
        }
    }
    return count == 1;

}

void magicDictionaryBuildDict(MagicDictionary *obj, char **dictionary, int dictionarySize)
{
    obj->size = dictionarySize;
//    char** dict=malloc(sizeof(char*)*dictionarySize);
    obj->dict = dictionary;
}

bool magicDictionarySearch(MagicDictionary *obj, char *searchWord)
{
    for (int i = 0; i < obj->size; ++i) {
        if (oneCharDiff((obj->dict)[i], searchWord)) {
            return true;
        }
    }
    return false;
}

void magicDictionaryFree(MagicDictionary *obj)
{
    free(obj->dict);
    free(obj);
}

int main()
{
    // @formatter:off
    char* arr[]={{"hello"},{"leet"}};
    int size=sizeof(arr)/sizeof(arr[0]);
    MagicDictionary *obj = magicDictionaryCreate();
    magicDictionaryBuildDict(obj,arr,size);
    char s1[]="hello";
    char s2[]="helll";
    printf("%d \n",magicDictionarySearch(obj,s1));fflush(stdout);
    printf("%d \n",magicDictionarySearch(obj,s2));fflush(stdout);
    return 0;
    // @formatter:on
}