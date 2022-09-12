#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
/*
挪至 考试.txt
 */
void Test_for()
{
    for (int i = 0; i < 1; ++i){
        for (int i = 0; i < 2; ++i){
            for (int i = 0; i < 3; ++i){
                /// 最大深度4==最多3层for/if
                // for (int i = 0; i < 4; ++i){
                //
                // }
            }
        }
    }
}
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
    Test_for();
    return 0;
    // @formatter:on
}