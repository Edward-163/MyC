#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */
/// 二维数组排序规律
int cmp(char **a, char **b)
{
    return strlen(*a) - strlen(*b);
}

char **stringMatching(char **words, int wordsSize, int *returnSize)
{
    qsort(words, wordsSize, sizeof(char *), cmp);
    char **ans = malloc(sizeof(char *) * wordsSize);
    int alen = 0;
    for (int i = 0; i < wordsSize; ++i) {
        for (int j = i + 1; j < wordsSize; ++j) {
            if (strstr(words[j], words[i])) {
                ans[alen++] = words[i];
                break;
            }
        }
    }
    *returnSize = alen;
    return ans;
}

int main()
{
    // @formatter:off
    char* arr[]={{"mass"},{"as"},{"hero"},{"superhero"}};
    int size=sizeof(arr)/sizeof(arr[0]);
    int rsize;
    char **ans = stringMatching(arr,size,&rsize);
    for (int i = 0; i < rsize; ++i){
        printf("%s \n",ans[i]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}