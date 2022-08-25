#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"

/*
 
 */
bool IsPrefix(char *split, char *searw)
{
    int move = 0;
    while (searw[move] != '\0') {
        if ((split[move] == '\0' && searw[move] != '\0') || (split[move] != searw[move])) {
            return false;
        }
        move++;
    }
    return true;
}

int isPrefixOfWord(char *sentence, char *searchWord)
{
    char *split = strtok(sentence, " ");
    int idx = 1; // begin 1
    while (split != NULL) {
        if (IsPrefix(split, searchWord)) {
            return idx;
        }
        idx++;
        split = strtok(NULL, " ");
    }
    return -1;
}

int main()
{
    // @formatter:off
    char sentence[] = "i love eating burger";
    char searchWord[] = "burg";

    int i = isPrefixOfWord(sentence,searchWord);
    printf("%d \n",i);fflush(stdout);
    return 0;
    // @formatter:on
}