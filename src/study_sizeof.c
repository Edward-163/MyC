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
void sizeof_bool(){
    bool b;
    printf("sizeof(bool)=%d \n",sizeof(b));fflush(stdout);
}
void test(){
    char *str1="123456789";
    char str2[]="123456789";
    printf("%d %d\n",sizeof(str1),sizeof(str2));fflush(stdout);
}
int main()
{
    // @formatter:off
    sizeof_bool();
    test();
    
    char arr[]="ab";
    printf("%d \n",sizeof(arr));fflush(stdout); // 3
    return 0;
    // @formatter:on
}
