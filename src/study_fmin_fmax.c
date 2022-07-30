#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */

int main()
{
    // @formatter:off
    int a=fmin(-2,0);
    printf("%d \n",a);fflush(stdout);
    int m=fmin(-2,-2);
    printf("%d \n",m);fflush(stdout);

    return 0;
    // @formatter:on
}