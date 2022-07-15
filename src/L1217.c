#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*

 */
int minCostToMoveChips(int *position, int positionSize) {
    int *posi = malloc(sizeof(int) * positionSize);
    memset(posi, 0, sizeof(int) * positionSize);
    for (int i = 0; i < positionSize; ++i) {
        int idx = position[i] - 1;
        posi[idx]++;
    }
//    for (int i = 0; i < positionSize; ++i){
//        printf("%d ",posi[i] );fflush(stdout);
//    }
//printf("\n");fflush(stdout);
    /**
     1 1 1 1 posi
     0 1 1 2 left
     */
    int *lefttocur = malloc(sizeof(int) * positionSize); // 左侧所有金币移动到curidx所花费步数==left[a-2]+posi[a-1]
    memset(lefttocur, 0, sizeof(int) * positionSize);
    for (int a = 0; a < positionSize; a++) {
        int left = a - 2 >= 0 ? lefttocur[a - 2] : 0;
        int p = a - 1 >= 0 ? posi[a - 1] : 0;
        lefttocur[a] = left + p;
    }

//    for (int i = 0; i < positionSize; ++i){
//        printf("%d ",lefttocur[i] );fflush(stdout);
//    }
//    printf("\n");fflush(stdout);

    int *rightocur = malloc(sizeof(int) * positionSize);
    memset(rightocur, 0, sizeof(int) * positionSize);
    for (int a = positionSize - 1; a >= 0; a--) {
        int righ = a + 2 <= positionSize - 2 ? rightocur[a + 2] : 0;
        int p = a + 1 <= positionSize - 2 ? posi[a + 1] : 0;
        rightocur[a] = righ + p;
    }

//    for (int i = 0; i < positionSize; ++i){
//        printf("%d ",rightocur[i] );fflush(stdout);
//    }
//    printf("\n");fflush(stdout);

    int ans = INT_MAX;
    for (int a = 0; a < positionSize; a++) {
        if (lefttocur[a] + rightocur[a] < ans) {
            ans = lefttocur[a] + rightocur[a];
        }
    }
    return ans;
}

int main() {
    // @formatter:off
//    int position[]={1,2,3};
    int position[]={2,2,2,3,3};
    int size=sizeof(position)/sizeof(position[0]);
    int i = minCostToMoveChips(position,size);
    printf("%d \n",i);fflush(stdout);
    return 0;
    // @formatter:on
}