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
void swap(int *target, int l, int r) {
    while (l < r) {
        int tmp = target[l];
        target[l] = target[r];
        target[r] = tmp;
        l++;
        r--;
    }
}

bool canBeEqual(int *target, int targetSize, int *arr, int arrSize) {
    if (targetSize == 0) {
        return target[0] == arr[0];
    }
    if (target[targetSize - 1] == arr[arrSize - 1]) {
        return canBeEqual(target, targetSize - 1, arr, arrSize - 1);
    } else {
        for (int l = arrSize - 2; l >= 0; l--) {
            if (arr[l] == target[targetSize - 1]) {
                swap(arr, l, arrSize - 1);
                return canBeEqual(target, targetSize - 1, arr, arrSize - 1);
            }
        }
        return false;
    }
}

int main() {
    // @formatter:off
//    int tar[]={1,2,3,4};
//    int arr[]={2,4,1,3};
    int tar[]={1,2,3,4,5};
    int arr[]={2,4,1,3,6};
    int tsize=sizeof(tar)/sizeof (tar[0]);
    int asize=sizeof(arr)/sizeof (arr[0]);
    bool b = canBeEqual(tar,tsize,arr,asize);
    printf("%d \n", b);fflush(stdout);
//    swap(arr,0,2);
//    for (int i = 0; i < 3; ++i){
//        printf("%d \n", arr[i]);fflush(stdout);
//    }
    return 0;
    // @formatter:on
}