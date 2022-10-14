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
    char s[10] = "HelloY";
    char *s1 = s;
    char *s2 = &s[2];
    strcat(s1, s2);
    printf("%s\n", s1);
    return 0;
    // @formatter:on
}