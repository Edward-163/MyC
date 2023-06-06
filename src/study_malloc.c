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
char* testMalloc(){
    char* res=malloc(sizeof(char)*4);
    char name[]="12345";
    strcpy(res,name);
    return res;
}
int main()
{
    // @formatter:off
    char *string = testMalloc();
    printf("%s \n",string);fflush(stdout);
    return 0;
    // @formatter:on
}
