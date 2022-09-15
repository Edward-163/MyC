#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"
#include "securec.h"


/*

 */
int cmp(int* a,int* b){
    return *a-*b;
}
double trimMean(int* arr, int arrSize){
    qsort(arr,arrSize,sizeof(int),cmp);
    int num=arrSize*5/100;
    printf("%d ",num);
    double sum=0;
    for(int a=1+num;a<=arrSize-num;a++){
        sum+=arr[a-1];
    }
    printf("%d ",sum);
    printf("%d ",arrSize-2*num);
    return sum/(arrSize-2*num);
}
int main() {
    // @formatter:off
    int arr[]={1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    int ans=trimMean(arr,size);
    printf("%d \n",ans);fflush(stdout);
    return 0;
    // @formatter:on
}