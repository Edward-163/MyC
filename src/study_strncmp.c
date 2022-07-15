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
    char str1[]="hyj11";
    char str2[]="hyj22";
    printf("%d ", strncmp(str1,str2,sizeof(char)*3));fflush(stdout);
    printf("%d ", strncmp(str1,str2,sizeof(char)*4));fflush(stdout);
    return 0;
}