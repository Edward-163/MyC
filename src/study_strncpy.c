#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */

int main() {
    char dest[99];
    char src[] = "edward";
    // edwar edward edward dward ward
    printf("%s ", strncpy(dest,src,sizeof(char)*5));fflush(stdout);
    printf("%s ", strncpy(dest,src,sizeof(char)*6));fflush(stdout);
    printf("%s ", strncpy(dest,src,sizeof(char)*7));fflush(stdout);
    /// 要灵活,并不一定都是从指针头部开始cpy
    printf("%s ", strcpy(dest,src+1));fflush(stdout);
    printf("%s ", strcpy(dest,src+2));fflush(stdout);
    return 0;
}