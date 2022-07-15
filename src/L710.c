//
// Created by hasee on 2022/6/26.
//
//
// Created by hasee on 2022/6/26.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int* big;
    int whitesize;
} Solution;


Solution* solutionCreate(int n, int* blacklist, int blacklistSize) {
    Solution* obj=(Solution*)malloc(sizeof(Solution));
    // 0      n-bs-1     n-bs           n-1
    int* big=(int*)malloc(sizeof(int)*n);
    for(int a=0;a<n;a++){
        big[a]=a;
    }
    for(int a=0;a<blacklistSize;a++){
        int num=blacklist[a];
        big[num]=-1;
    }

//    for (int i = 0; i < n; ++i){
//        printf("%d ", big[i]);fflush(stdout);
//    }
//    printf("\n");fflush(stdout);
    int move=n-blacklistSize;
//    for(int a=0;a<=n-blacklistSize-1;a++){

    /// 问,就是超时
    for(int a=0;a<=blacklistSize-1;a++){
        if(blacklist[a]<=n-blacklistSize-1){
            while(big[move]==-1){
                move++;
            }
            big[blacklist[a]]=move;
            move++;
        }
    }
//    for (int i = 0; i < n; ++i){
//        printf("%d ", big[i]);fflush(stdout);
//    }
//    printf("\n");fflush(stdout);

    obj->big=big;
    obj->whitesize=n-blacklistSize;
    return obj;
}

int solutionPick(Solution* obj) {
//    srand(time(NULL));// 加了这行,直接运行大概率数字相同?????????,去掉,数字不同
    int r=rand()%obj->whitesize;
    return obj->big[r];
}

void solutionFree(Solution* obj) {
    free(obj->big);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(n, blacklist, blacklistSize);
 * int param_1 = solutionPick(obj);

 * solutionFree(obj);
*/

int main() {
//    int n = 7;
//    int black[] = {2, 3, 5};
    int n = 1000000000;
    int black[] = {66666666};
    int blackSize = sizeof(black) / sizeof(black[0]);
    Solution *obj = solutionCreate(n, black, blackSize);
    printf("%d \n", solutionPick(obj));
    fflush(stdout);
    printf("%d \n", solutionPick(obj));
    fflush(stdout);
    printf("%d \n", solutionPick(obj));
    fflush(stdout);
    return 0;
}
/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(n, blacklist, blacklistSize);
 * int param_1 = solutionPick(obj);

 * solutionFree(obj);
*/