#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
 
 */

int main()
{
    // @formatter:off
    char a[20]="abc\0efg\0";
    char b[]="hij";
    strcat(a,b);
    printf("%s \n",a);fflush(stdout); // abchij
    return 0;
    // @formatter:on
}