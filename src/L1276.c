#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
//#include <uthash.h>


/*

 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize){
    double t=tomatoSlices;
    double c=cheeseSlices;
    if(t<2*c || t>4*c || (tomatoSlices&1)==1){
        *returnSize=0;
        return NULL;
    }
    int* res=(int*)malloc(sizeof(int)*2);
    int tnum=0;
    int cnum=cheeseSlices;
    double diff=tomatoSlices-2*cheeseSlices;
    while(diff>0){
        tnum++;
        cnum--;
        diff-=2;
    }

    res[0]=tnum;
    res[1]=cnum;
    *returnSize=2;
    return res;
}
int main() {
    int* rs=(int*) malloc(sizeof(int));
    numOfBurgers(16,7,rs);
    return 0;
}