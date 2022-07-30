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
    int a=1;
    if(a==0){
        printf("%d \n",0);fflush(stdout);
    }else if(a==1){
        printf("%d \n",1);fflush(stdout);
    }else if(a==2){
        printf("%d \n",2);fflush(stdout);
    }else{
        printf("%d \n",666);fflush(stdout);
    }
    /// 测试表明圈复杂度不降,但cca圈复杂度大幅降低
    // switch (a) {
    //     case 0 :
    //     printf("%d \n",0);fflush(stdout);
    //     break;
    //     case 1 :
    //     printf("%d \n",1);fflush(stdout);
    //     break;
    //     case 2 :
    //     printf("%d \n",2);fflush(stdout);
    //     break;
    //     default :
    //     printf("%d \n",666);fflush(stdout);
    // }
    return 0;
    // @formatter:on
}