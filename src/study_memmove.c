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

int main()
{
    // @formatter:off
    int arr[3]={1,2,3};
    if(memmove_s(arr+1,2*sizeof(int),arr,1*sizeof(int))!=EOK){
        return -1;
    }
    for (int i = 0; i < 3; ++i){
        printf("%d \n",arr[i]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}
