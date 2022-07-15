#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*

 */
typedef struct {
    int* numarr;
    int* countarr;
    int psum;
    int len;
} RLEIterator;


RLEIterator* rLEIteratorCreate(int* encoding, int encodingSize) {
    RLEIterator* rle=(RLEIterator*)malloc(sizeof(RLEIterator));
    int* numarr=(int*)malloc(sizeof(int)*encodingSize/2);
    int* countarr=(int*)malloc(sizeof(int)*encodingSize/2);

    int psum=0;
    for(int a=0;a<encodingSize;a+=2){
        int count=encoding[a];
        int num=encoding[a+1];
        numarr[a/2]=num;
        psum+=count;
        countarr[a/2]=psum;
    }
    rle->numarr=numarr;
    rle->countarr=countarr;
    rle->psum=0;
    rle->len=encodingSize/2;
    return rle;
}

int rLEIteratorNext(RLEIterator* obj, int n) {
    obj->psum+=n;
    for(int a=0;a<obj->len;a++){
        if(obj->psum<=obj->countarr[a]){
            return obj->numarr[a];
        }
    }
    return -1;
}

void rLEIteratorFree(RLEIterator* obj) {
    free(obj->numarr);
    free(obj->countarr);
    free(obj);
}

int main() {
    int encoding[]={3, 8, 0, 9, 2, 5};
    int encodingSize=sizeof(encoding)/sizeof(encoding[0]);
    RLEIterator *obj = rLEIteratorCreate(encoding, encodingSize);
    printf("% ", rLEIteratorNext(obj,2) );fflush(stdout);
    printf("% ", rLEIteratorNext(obj,1) );fflush(stdout);
    printf("% ", rLEIteratorNext(obj,1) );fflush(stdout);
    return 0;
}