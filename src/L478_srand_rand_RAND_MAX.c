#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
//#include <uthash.h>
#include <time.h>

/**
rand()产生一个0到0x7ffff即0到32767之间的随机数
RAND_MAX即为0x7ffff。
所以rand()/RAND_MAX可表示为在[0,1]区间内的随机数
rand()/(RAND_MAX+1)可表示为在[0,1)区间内的随机数
[0,1]—rand()*1.0/RAND_MAX
[0,1)—rand()*1.0/(RAND_MAX+1)
[a,b]—rand()*1.0/RAND_MAX(b-a)+a
[a,b)—rand()*1.0/(RAND_MAX+1)(b-a)+a
(a,b]—(rand()+1)*1.0/(RAND_MAX+1)(b-a)+a
(a,b)—(rand()+1)*1.0/(RAND_MAX+2)(b-a)+a
 
我疑惑的是:既然rand可以直接随机,那要srand干啥?
 */
typedef struct {
    double r;
    double x;
    double y;
} Solution;


Solution *solutionCreate(double radius, double x_center, double y_center) {
    Solution *sol = (Solution *) malloc(sizeof(Solution));
    sol->r = radius;
    sol->x = x_center;
    sol->y = y_center;
    return sol;
}

double *solutionRandPoint(Solution *obj, int *retSize) {
    double *res = (double *) malloc(sizeof(double) * 2);
    double xdiff;
    double ydiff;
    double xrand;
    double yrand;
    do {
        // 已知原点(x,y),则左下角(x-r,y-r)
        // [0,1]
        /// bug
        //int xrand=rand()*1.0/RAND_MAX;
        xrand = rand() * 1.0 / RAND_MAX;
        yrand = rand() * 1.0 / RAND_MAX;
        xdiff = 2 * (obj->r) * xrand - (obj->r);
        ydiff = 2 * (obj->r) * yrand - (obj->r);
    } while (xdiff * xdiff + ydiff * ydiff > (obj->r) * (obj->r));
    res[0] = (obj->x) - (obj->r) + 2 * (obj->r) * xrand;
    res[1] = (obj->y) - (obj->r) + 2 * (obj->r) * yrand;
    *retSize = 2;
    return res;
}

void solutionFree(Solution *obj) {
    free(obj);
}

int main() {
    double d = rand() * 1.0 / RAND_MAX;
    int a=0;
    int b=2;
    for (int i = 0; i < 10; ++i){
//        d = rand() * 1.0 / (RAND_MAX + 1)*(b - a) + a;
        d = (rand() + 1)  / (RAND_MAX + 1)*(b - a) + a;
    //    d = (rand() + 1) * 1.0 / (RAND_MAX + 2)*(b - a) + a;
        printf("%d\n",(int)d);
    }
//    time_t time1 = time(NULL);
//    srand((unsigned int) time1);


//    Solution *sol = solutionCreate(1, 0, 0);
//    int *retSize = (int *) malloc(sizeof(int));
//    double *res = solutionRandPoint(sol, retSize);
//    printf("%f %f\n", res[0], res[1]);
    fflush(stdout);
    return 0;
}