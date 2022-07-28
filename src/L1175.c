/*
 *
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*
 
 */
#define MOD 1000000007
bool isflag(int n){
    if(n<2)return false;
    double d = sqrt(n);
//    for(int a=2;a<=(int)d;a++){
    /// 这种优雅
    for(int a=2;a*a<=d;a++){
        if(n%a==0){
            return false;
        }
    }
    return true;
}
int numPrimeArrangements(int n){
    int count=0;
    for(int a=1;a<=n;a++){
        if(a>=2 && isflag(a)){
            count++;
        }
    }

    int ans=1;
    int nocount=n-count;
    while(nocount>1){
        ans*=nocount;
        nocount--;
    }
    while(count>1){
        ans*=count;
        count--;
    }
    return ans%MOD;
}
int main()
{
    int i = numPrimeArrangements(5);
    printf("%d ", i);fflush(stdout);
    return 0;
}